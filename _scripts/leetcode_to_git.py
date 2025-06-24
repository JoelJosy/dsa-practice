import os
import requests
import browser_cookie3
import time
from datetime import datetime
from pathlib import Path

# === CONFIG ===
REPO_DIR = Path("dsa-practice")  # folder where files will be saved
REPO_DIR.mkdir(exist_ok=True)

# === COOKIES (from Chrome/Firefox session) ===
cookies = browser_cookie3.chrome(domain_name="leetcode.com")

headers = {
    "Referer": "https://leetcode.com",
    "Content-Type": "application/json",
}

def get_submissions(offset=0, limit=20):
    url = f"https://leetcode.com/api/submissions/?offset={offset}&limit={limit}"
    r = requests.get(url, cookies=cookies, headers=headers)
    if r.status_code != 200:
        print("❌ Error: Could not fetch submissions. Are you logged into LeetCode?")
        return []
    return r.json().get("submissions_dump", [])

def extension_map(lang):
    return {
        "python3": "py",
        "cpp": "cpp",
        "java": "java",
        "javascript": "js",
        "c": "c",
        "csharp": "cs",
        "golang": "go",
    }.get(lang.lower(), "txt")

def sanitize_title(title):
    return title.lower().replace(' ', '_').replace('-', '_').replace("'", '')

def save_and_commit(submission, slug_cache):
    title = submission["title"]
    slug = submission["title_slug"]

    if slug in slug_cache:
        return  # skip duplicates

    date_ts = submission["timestamp"]
    lang = submission["lang"]
    code = submission["code"]

    ext = extension_map(lang)
    date_str = datetime.utcfromtimestamp(int(date_ts)).strftime('%Y-%m-%d')
    filename = f"{date_str}_{sanitize_title(title)}.{ext}"
    filepath = REPO_DIR / filename

    # Save file with header
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(f"# {title}\n")
        f.write(f"# https://leetcode.com/problems/{slug}/\n\n")
        f.write(code)

    # Git commands
    os.system(f"cd {REPO_DIR} && git add '{filename}'")
    os.system(
        f"cd {REPO_DIR} && "
        f"GIT_COMMITTER_DATE='{date_str} 12:00:00' "
        f"git commit --date='{date_str} 12:00:00' "
        f"-m 'Solved {title}'"
    )

    print(f"✅ {filename} committed")
    slug_cache.add(slug)

def main():
    os.system(f"cd {REPO_DIR} && git init")

    offset = 0
    limit = 20
    total = 0
    seen_slugs = set()

    while True:
        submissions = get_submissions(offset, limit)
        if not submissions:
            break

        accepted = [s for s in submissions if s["status_display"] == "Accepted"]

        for s in accepted:
            save_and_commit(s, seen_slugs)
            total += 1

        if len(submissions) < limit:
            break  # no more pages
        offset += limit
        
        # Add delay between API requests to be respectful to LeetCode's servers
        time.sleep(1)

    print(f"\n🎉 Done. {len(seen_slugs)} unique accepted submissions saved and committed.")

if __name__ == "__main__":
    main()
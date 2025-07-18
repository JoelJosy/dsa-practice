// 355. Design Twitter
// https://leetcode.com/problems/design-twitter/

// Optimal Soln

class Twitter {
public:
    int time;
    unordered_map<int, vector<pair<int, int>>> tweetMap;  // {userId, list of (time, tweetId)}
    unordered_map<int, unordered_set<int>> followMap;     // {userId, set of followees}

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    struct TweetInfo {
        int time;
        int tweetId;
        int userId;
        int idx; // Index in tweetMap[userId]
    };

    struct Compare {
        bool operator()(const TweetInfo& a, const TweetInfo& b) const {
            return a.time < b.time;  // Max-heap: larger time first
        }
    };

    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        priority_queue<TweetInfo, vector<TweetInfo>, Compare> heap;

        unordered_set<int> followees = followMap[userId];
        followees.insert(userId);

        for (int followee : followees) {
            auto& tweets = tweetMap[followee];
            if (!tweets.empty()) {
                int idx = tweets.size() - 1;
                heap.push({tweets[idx].first, tweets[idx].second, followee, idx});
            }
        }

        while (!heap.empty() && res.size() < 10) {
            TweetInfo top = heap.top(); heap.pop();
            res.push_back(top.tweetId);

            if (top.idx > 0) {
                int nextIdx = top.idx - 1;
                auto& tweets = tweetMap[top.userId];
                heap.push({tweets[nextIdx].first, tweets[nextIdx].second, top.userId, nextIdx});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followMap[followerId].count(followeeId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};

// My Soln
class Twitter {
public:
    int time;
    // {userId, list of tweets (time, tweetId)}
    unordered_map<int, vector<pair<int, int>>> tweetMap;

    // {userId, set of following userIds}
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweetMap[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                                greater<pair<int, int>>> heap;
        unordered_set<int> followeeSet = followMap[userId];
        followeeSet.insert(userId);

        for (int followee : followeeSet) {
            for (auto& tweet : tweetMap[followee]) {
                heap.push(tweet);
                if (heap.size() > 10) heap.pop(); 
            }
        }
        while (!heap.empty()) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        reverse(res.begin(), res.end()); // min heap has oldest at top
        // so we need to reverse to get latest first
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followMap[followerId].count(followeeId))
            followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
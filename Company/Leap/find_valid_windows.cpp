Here’s the clean text version of the problem:

⸻

🧩 Problem: Consistent Learner Detection

On a learning platform, each student’s daily study activity is recorded as an integer score between 0 and 100, representing their engagement for that day.

A student is considered a consistent learner if there exists a contiguous subarray (window) of K consecutive days such that:
	1.	The average engagement over those K days is greater than or equal to T, and
	2.	Every single day in that window has engagement greater than or equal to F (a minimum floor value)

⸻

📥 Input
	•	An integer array engagement of size n, where engagement[i] is the score on day i
	•	Integers:
	•	K → window size
	•	T → threshold for average
	•	F → minimum allowed daily engagement

⸻

📤 Output

Return a list of all starting indices of subarrays of size K that satisfy both conditions.

⸻

🧪 Example

Input:
engagement = [40, 80, 90, 85, 20, 75, 78, 82, 80, 79]
K = 4, T = 78, F = 60

Output:
[5, 6]


⸻

💡 Explanation
	•	Window starting at index 5 → [75, 78, 82, 80]
	•	Average = 78.75 ≥ 78 ✅
	•	All values ≥ 60 ✅
	•	Window starting at index 6 → [78, 82, 80, 79]
	•	Average = 79.75 ≥ 78 ✅
	•	All values ≥ 60 ✅

⸻

// sum >= K * T

vector<int> findValidWindows(vector<int>& arr, int K, int T, int F) {
    int n = arr.size();
    vector<int> result;
    
    long long window_sum = 0;
    deque<int> dq; // increasing → min at front

    for (int i = 0; i < n; i++) {
        window_sum += arr[i];

        // remove element leaving window (for sum)
        if (i >= K) {
            window_sum -= arr[i - K];
        }

        // remove out-of-window index (for deque)
        if (!dq.empty() && dq.front() == i - K) {
            dq.pop_front();
        }

        // maintain increasing order (min deque)
        while (!dq.empty() && arr[i] < arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= K - 1) {
            int start = i - K + 1;
            if (window_sum >= 1LL * K * T && arr[dq.front()] >= F) {
                result.push_back(start);
            }
        }
    }

    return result;
}


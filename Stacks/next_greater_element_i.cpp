class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res;
        stack<int> st;
        unordered_map<int, int> map;

        for (int i = 0; i < n2; i++) {
            while (!st.empty() && nums2[i] > st.top()) {
                map[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        while (!st.empty()) {
            int num = st.top();
            map[num] = -1;
            st.pop();
        }

        for (int num: nums1) {
            res.push_back(map[num]);
        }
        return res;
    }
};
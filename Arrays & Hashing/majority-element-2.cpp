// T: O(n)
// S: O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }

        for (auto [n, f]: freq) {
            if (f > nums.size() / 3) 
                res.push_back(n);
        }
        return res;
    }
};

// T: O(n)
// S: O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int mincount = n / 3;

        int n1 = -1, n2 = -1, c1 = 0, c2 = 0;

        for (int num: nums) {
            if (num == n1) 
                c1++;
            else if (num == n2)
                c2++;
            else if (c1 == 0) {
                c1++;
                n1 = num;
            } else if (c2 == 0) {
                c2++;
                n2 = num;
            } else {
                c1--;
                c2--;
            }
        }

        c1 = 0, c2 = 0;
        for (int num: nums) {
            if (num == n1) {
                c1++;
            } else if (num == n2) {
                c2++;
            }
        }
        
        if (c1 > mincount) {
            res.push_back(n1);
        }
        if (c2 > mincount) {
            res.push_back(n2);
        }

        return res;
    }
};
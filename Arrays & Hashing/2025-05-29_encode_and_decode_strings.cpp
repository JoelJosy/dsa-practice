# Encode and Decode Strings
# https://neetcode.io/problems/string-encode-and-decode?list=neetcode150

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (string str: strs) {
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
    
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            int len = stoi(s.substr(i, j - i)); 
            i = j + 1; 
            string word = s.substr(i, len);
            res.push_back(word);
            i += len; 
        }
        return res;
    }
};

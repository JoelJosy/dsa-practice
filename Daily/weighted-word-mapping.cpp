// O(n*l) l-> len of longest word
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;

        for (string w: words) {
            int sum = 0;
            for (char c: w) {
                sum += weights [c - 'a'];
            }
            sum %= 26;
            res += 'z' - sum;
        }
        return res;
    }
};
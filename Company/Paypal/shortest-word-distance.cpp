// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

// Example:
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Input: word1 = “coding”, word2 = “practice”
// Output: 3

// Input: word1 = "makes", word2 = "coding"
// Output: 1
//  You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.




class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int i1, i2;
        int minDist = INT_MAX;

        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                i1 = i;
                if (i2 >= 0) {
                    minDist = min(minDist, abs(i1 - i2));
                }
            } else if (wordsDict[i] == word2) {
                i2 = i;
                if (i1 >= 0) {
                    minDist = min(minDist, abs(i1 - i2));
                }
            }
        }
        return minDist;
    }
};


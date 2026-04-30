class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;

        string str = "122";
        int r = 2;
        int count = 1;
        char nextChar = '1';

        while (str.size() < n) {
            char ch = str[r];
            int times = ch - '0';
            
            for (int i = 0; i < times; i++) {
                str += nextChar;
                if (nextChar=='1' && str.size() <= n) {
                    count++;
                }
            }

            nextChar = (nextChar=='1') ? '2' : '1';
            r++;
        }
        return count;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int l = 0;
        int r = 0;

        char curr = chars[l];
        int count;
        while (r < n) {
            curr = chars[r];
            count = 0;
        
            while (r < n && chars[r] == curr) {
                count++;
                r++;
            }

            chars[l] = curr;
            l++;

            if (count > 1) {
                string str = to_string(count);
                for (char c : str) {
                    chars[l] = c;
                    l++;
                }
            }
        }   
        return l; 
    }
};

int main() {
    int n;
    cin >> n;
    vector<char> chars(n);
    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }
    int ans = compress(chars);
    cout << "Result: " << ans << endl;

    for (char c: chars) {
        cout << c << " ";
    }

    return 0;
}
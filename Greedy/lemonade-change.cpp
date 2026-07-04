class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;

        for (int b: bills) {
            switch (b) {
                case 5:
                    fives++;
                    break;
                case 10:
                    tens++;
                    if (fives == 0) return false;
                    fives--;
                    break;
                case 20:
                    if (fives > 0 && tens > 0) {
                        fives--;
                        tens--;
                    } else if (fives >= 3)
                        fives -= 3;
                    else 
                        return false;
                    break;
            }
        }
        return true;
    }
};
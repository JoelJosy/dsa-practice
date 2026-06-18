class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAng = (minutes / 60.0) * 360;
        double hrAng = (hour * 30.0);
        hrAng += ((minutes / 60.0) * 30.0);

        double res = abs(hrAng - minAng);
        return min(res, 360 - res);
    }
};
// 1041. Robot Bounded In Circle
// https://leetcode.com/problems/robot-bounded-in-circle/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        char dirn = 'n';
        int x = 0, y = 0;
        for (char c: instructions) {
            if (c == 'G') {
                if (dirn == 'n') y++;
                else if (dirn == 's') y--;
                else if (dirn == 'w') x--;
                else x++;
            } else if (c == 'L') {
                if (dirn == 'n') dirn='w';
                else if (dirn == 's') dirn='e';
                else if (dirn == 'w') dirn='s';
                else dirn='n';
            } else {
                if (dirn == 'n') dirn='e';
                else if (dirn == 's') dirn='w';
                else if (dirn == 'w') dirn='n';
                else dirn='s';
            }
        }

        return (x==0 && y==0 || dirn!='n');
    }
};



// Alternative solution using direction vectors
class Solution {
public:
    bool isRobotBounded(string instructions) {      
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // North, East, South, West
        int x = 0, y = 0;
        int dirIndex = 0; // Start facing North

        for (char c : instructions) {
            if (c == 'G') {
                x += directions[dirIndex].first;
                y += directions[dirIndex].second;
            } else if (c == 'L') {
                dirIndex = (dirIndex + 3) % 4; // Turn left
            } else { // c == 'R'
                dirIndex = (dirIndex + 1) % 4; // Turn right
            }
        }

        return (x == 0 && y == 0) || (dirIndex != 0);
    }
};
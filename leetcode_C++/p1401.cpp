#include <math.h>

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        double dist = 0.;
        if (xCenter < x1 || xCenter > x2) {
            dist += std::min((xCenter - x1) * (xCenter - x1), (xCenter - x2) * (xCenter - x2));
        }
        if (yCenter < y1 || yCenter > y2) {
            dist += std::min((yCenter - y1) * (yCenter - y1), (yCenter - y2) * (yCenter - y2));
        }
        return dist <= radius * radius;
    }
};
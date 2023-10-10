#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> index;
        // 遍历记录即可
        for (int i = 0; i < restaurants.size(); ++i) {
            vector<int> &restaurant = restaurants[i];
            if (veganFriendly == 1 && restaurant[2] == 0) { // 素食
                continue;
            }
            if (restaurant[3] > maxPrice || restaurant[4] > maxDistance) {
                continue;
            }
            index.push_back(i);
        }
        sort(index.begin(), index.end(), [&](int i, int j) {
            if (restaurants[i][1] > restaurants[j][1]) {
                return true;
            } else if (restaurants[i][1] == restaurants[j][1])
                return restaurants[i][0] > restaurants[j][0];
            return false;
        });
        for (auto &idx : index) {
            idx = restaurants[idx][0];
        }
        return index;
    }
};
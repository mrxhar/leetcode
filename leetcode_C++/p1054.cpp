
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes) {
        int length = barcodes.size();

        if (length < 2) return barcodes;

        unordered_map<int, int> counts;
        int maxCount = 0;
        for (int &b : barcodes) maxCount = max(maxCount, ++counts[b]);

        int evenIndex = 0, oddIndex = 1, halfLength = length / 2;
        vector<int> res(length);
        for (auto &[x, cx] : counts) {
            while (cx > 0 && cx <= halfLength && oddIndex < length) {
                res[oddIndex] = x;
                cx--;
                oddIndex += 2; // 奇数数进行填写 这时候我们填写 所有的 cx 前面半部分
            }
            while (cx > 0) {
                res[evenIndex] = x;
                cx--;
                evenIndex += 2;
            }
        }
        return res;
    }
};
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        // 记录字符的个数
        unordered_map<char, int> record;
        for (auto ch : text) {
            record[ch]++;
        }

        int res;
        for (int i = 0; i < text.size();) {
            int j = i;
            while (j < text.size() && text[j] == text[i]) {
                j++;
            }
            int cur = j - i;

            if (cur < record[text[i]] && (j < text.size() || i > 0)) {
                res = max(res, cur + 1);
            }

            int k = j + 1;
            while (k < text.size() && text[k] == text[i]) {
                k++;
            }
            res = max(res, min(k - i, record[text[i]]));
            i = j;
        }

        return res;
    }
};
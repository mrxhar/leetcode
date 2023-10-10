#include <vector>
using namespace std;
class StockSpanner {
    // 需要一个加速，顺便记录下一个效益对应值的长度
    vector<pair<int, int>> price_count;
    // 个数
    int nums;

public:
    StockSpanner() {
        price_count.push_back({0, 0});
        nums = 0;
    }

    int next(int price) {
        // 倒叙排序
        int start = nums;
        // 我们需要记录start 开始位置
        while (start != 0 && price >= price_count[start].first) {
            // 我们再往前多少步
            start = price_count[start].second;
        }
        // 到达不能在大于的位置，添加进取
        price_count.push_back({price, start});
        nums++;

        return nums - start;
    }
};

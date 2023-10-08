/*
@file: name
@description:
@author: mrxhar
@date: 2023-10-08 09:53:05
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
using std::pair;
using std::vector;
using std::unordered_map;
using std::priority_queue;

// 类别名
typedef pair<int, int> pii;

class StockPrice {
public:
    StockPrice() {
        this->maxTimestamp = 0;
    }

    void update(int timestamp, int price) {
        maxTimestamp = std::max(maxTimestamp, timestamp);
        timePriceMap[timestamp] = price;
        // 入队列，价格为主要排序根据
        pqMax.emplace(price, timestamp);
        pqMin.emplace(price, timestamp);
    }

    int current() {
        return timePriceMap[maxTimestamp];
    }

    int maximum() {
        while (true) {
            int price = pqMax.top().first, timestamp = pqMax.top().second;
            if (timePriceMap[timestamp] == price) {
                return price;
            }
            pqMax.pop(); // 删除过期数据
        }
    }

    int minimum() {
        while (true) {
            int price = pqMin.top().first, timestamp = pqMin.top().second;
            if (timePriceMap[timestamp] == price) {
                return price;
            }
            pqMin.pop(); // 删除过期数据
        }
    }

private:
    int maxTimestamp;
    unordered_map<int, int> timePriceMap;                   // 用于记录时间和股票价格的哈希表
    priority_queue<pii, vector<pii>, std::less<pii>> pqMax; // 优先队列
    priority_queue<pii, vector<pii>, std::greater<pii>> pqMin;
};

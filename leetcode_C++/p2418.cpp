
/*
@file: name
@description:
@author: mrxhar
@date: 2023-09-19 09:12:47
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/

#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        int n = names.size();
        vector<int> indice(n);
        iota(indice.begin(), indice.end(), 0);

        sort(indice.begin(), indice.end(), [&](int x, int y) {
            return heights[x] > heights[y];
        });
        vector<string> res;
        for (int i = 0; i < n; i++) {
            res[i] = names[indice[i]];
        }
        return res;
    }
};
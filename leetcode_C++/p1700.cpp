/*
@Author: mrxhar
@Date:   2023-08-30 09:45:01
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/
*/

#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        /*可以简单看出来，三明治顺序是固定的，学生可以进行流动，当两种喜好的学生都存在时，三明治的数量必能减少。当只剩余一种喜好的学生时，三明治数量就是不是这个喜好的种类后面的数量*/
        int s1 = accumulate(students.begin(), students.end(), 0);
        int s0 = students.size() - s1;
        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (sandwiches[i] == 0 && s0 > 0)
            {
                s0--;
            }
            else if (sandwiches[i] == 1 && s1 > 0)
            {
                s1--;
            }
            else
            {
                break;
            }
        }
        return s1 + s0;
    }
};
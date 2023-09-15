/*
@Author: mrxhar
@Date:   2023-09-05 09:48:01
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/remove-comments/?envType=daily-question&envId=2023-09-05
*/

#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution
{
public:
    vector<string> removeComments(vector<string> &source)
    {
        vector<string> res;
        string new_line = "";
        bool in_block = false;
        for (auto &line : source)
        {
            for (int i = 0; i < line.size(); i++)
            {
                if (in_block)
                {
                    // 省略这些字符
                    if (i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/')
                    {
                        in_block = false;
                        i++;
                    }
                }
                else
                {
                    // 不在块注释里面
                    if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*')
                    {
                        in_block = true;
                        i++;
                    }
                    else if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/')
                    {
                        break; // 后面的不在遍历，全部抛弃
                    }
                    else
                    {
                        new_line += line[i];
                    }
                }
            }
            // 如果不在块中并且 行不为空才加入res，重置这一行
            if (!in_block && new_line != "")
            {
                res.push_back(new_line);
                new_line = "";
            }
                }
        return res;
    }
};
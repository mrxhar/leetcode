from typing import List


class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)

        first_min_sum, second_min_sum = 0, 0
        first_min_index = -1
        for i in range(n):
            cur_first_min_sum, cur_second_min_sum = 10 ** 9, 10 ** 9
            # cur_second_min_sum 是为了避免最小值和当前的值位于同一列
            cur_first_min_index = -1
            for j in range(n):
                cur_sum = grid[i][j]
                if j != first_min_index:
                    cur_sum += first_min_sum
                else:
                    cur_sum += second_min_sum

                if cur_sum < cur_first_min_sum:
                    cur_second_min_sum, cur_first_min_sum = cur_first_min_sum, cur_sum
                    cur_first_min_index = j
                elif cur_sum < cur_second_min_sum:
                    cur_second_min_sum = cur_sum
            first_min_sum, second_min_sum = cur_first_min_sum, cur_second_min_sum
            first_min_index = cur_first_min_index

        return first_min_sum

﻿#include "leetcode.hpp"

/* 1351. 统计有序矩阵中的负数

给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。

请你统计并返回 grid 中 负数 的数目。

示例 1：
输入：grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
输出：8
解释：矩阵中共有 8 个负数。

示例 2：
输入：grid = [[3,2],[1,0]]
输出：0

示例 3：
输入：grid = [[1,-1],[-1,-1]]
输出：3

示例 4：
输入：grid = [[-1]]
输出：1

提示：
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 100
  -100 <= grid[i][j] <= 100
*/

int countNegatives(vector<vector<int>>& A)
{
	int rows = static_cast<int>(A.size());
	int cols = static_cast<int>(A[0].size());
	int sum = 0, w = cols - 1;
	for (int h = 0; h < rows; ++h) {
		while (w >= 0 && A[h][w] < 0)
			--w;
		sum += cols - w - 1;
	}
	return sum;
}

int main()
{
}

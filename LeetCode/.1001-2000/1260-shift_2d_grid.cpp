﻿#include "leetcode.hpp"

/* 1260. 二维网格迁移

给你一个 m 行 n 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。

每次「迁移」操作将会引发下述活动：
  位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
  位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
  位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。

请你返回 k 次迁移操作后最终得到的 二维网格。

示例 1：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/16/e1-1.png
输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
输出：[[9,1,2],[3,4,5],[6,7,8]]

示例 2：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/16/e2-1.png
输入：grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
输出：[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

示例 3：
输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
输出：[[1,2,3],[4,5,6],[7,8,9]]

提示：
  1 <= grid.length <= 50
  1 <= grid[i].length <= 50
  -1000 <= grid[i][j] <= 1000
  0 <= k <= 100
*/

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
{
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	int total = rows * cols;
	k %= total;
	vector<vector<int>> D = grid;
	for (int i = 0; i < total; ++i) {
		int dy = i / cols;
		int dx = i % cols;
		int si = (i - k + total) % total;
		int sy = si / cols;
		int sx = si % cols;
		D[dy][dx] = grid[sy][sx];
	}
	return D;
}

int main()
{
}

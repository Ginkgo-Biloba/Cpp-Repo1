﻿#include "leetcode.hpp"

/* 2428. 沙漏的最大总和

给你一个大小为 m x n 的整数矩阵 grid 。

按以下形式将矩阵的一部分定义为一个 沙漏 ：
https://assets.leetcode.com/uploads/2022/08/21/img.jpg

返回沙漏中元素的 最大 总和。

注意：沙漏无法旋转且必须整个包含在矩阵中。

示例 1：
https://assets.leetcode.com/uploads/2022/08/21/1.jpg
输入：grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
输出：30
解释：上图中的单元格表示元素总和最大的沙漏：6 + 2 + 1 + 2 + 9 + 2 + 8 = 30 。

示例 2：
https://assets.leetcode.com/uploads/2022/08/21/2.jpg
输入：grid = [[1,2,3],[4,5,6],[7,8,9]]
输出：35
解释：上图中的单元格表示元素总和最大的沙漏：1 + 2 + 3 + 5 + 7 + 8 + 9 = 35 。

提示：
  m == grid.length
  n == grid[i].length
  3 <= m, n <= 150
  0 <= grid[i][j] <= 10^6
*/

int maxSum(vector<vector<int>> const& grid)
{
	int rows = static_cast<int>(grid.size());
	int cols = static_cast<int>(grid[0].size());
	int ans = 0;
	for (int h = 1; h < rows - 1; ++h) {
		int const *A = grid[h - 1].data(),
							*B = grid[h].data(),
							*C = grid[h + 1].data();
		for (int w = 1; w < cols - 1; ++w)
			ans = max(ans,
				A[w - 1] + A[w] + A[w + 1] + B[w] + C[w - 1] + C[w] + C[w + 1]);
	}
	return ans;
}

int main()
{
	ToOut(maxSum({{6, 2, 1, 3}, {4, 2, 1, 5}, {9, 2, 8, 7}, {4, 1, 2, 9}}));
	ToOut(maxSum({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}));
}

﻿#include "leetcode.hpp"

/* 1030. 距离顺序排列矩阵单元格

给出 R 行 C 列的矩阵，其中的单元格的整数坐标为 (r, c)，满足 0 <= r < R 且 0 <= c < C。

另外，我们在该矩阵中给出了一个坐标为 (r0, c0) 的单元格。

返回矩阵中的所有单元格的坐标，并按到 (r0, c0) 的距离从最小到最大的顺序排，其中，两单元格(r1, c1) 和 (r2, c2) 之间的距离是曼哈顿距离，|r1 - r2| + |c1 - c2|。
你可以按任何满足此条件的顺序返回答案。

示例 1：
输入：R = 1, C = 2, r0 = 0, c0 = 0
输出：[[0,0],[0,1]]
解释：从 (r0, c0) 到其他单元格的距离为：[0,1]

示例 2：
输入：R = 2, C = 2, r0 = 0, c0 = 1
输出：[[0,1],[0,0],[1,1],[1,0]]
解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2]
[[0,1],[1,1],[0,0],[1,0]] 也会被视作正确答案。

示例 3：
输入：R = 2, C = 3, r0 = 1, c0 = 2
输出：[[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2,2,3]
其他满足题目要求的答案也会被视为正确，例如 [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]。

提示：
  1 <= R <= 100
  1 <= C <= 100
  0 <= r0 < R
  0 <= c0 < C
*/

// https://leetcode.com/problems/matrix-cells-in-distance-order/discuss/278986/4ms-O(n)-Java-Counting-Sort-()-Solution
// 抄的计数排序
vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
{
	vector<vector<int>> ans(R * C);
	vector<int> count(R + C + 1);
	for (int h = 0; h < R; ++h)
		for (int w = 0; w < C; ++w) {
			int d = abs(h - r0) + abs(w - c0);
			++(count[d + 1]);
		}
	for (int i = 1; i <= R + C; ++i)
		count[i] += count[i - 1];
	for (int h = 0; h < R; ++h)
		for (int w = 0; w < C; ++w) {
			int d = abs(h - r0) + abs(w - c0);
			int i = count[d];
			ans[i].push_back(h);
			ans[i].push_back(w);
			++(count[d]);
		}
	return ans;
}

int main()
{
	ToOut(allCellsDistOrder(1, 2, 0, 0));
	ToOut(allCellsDistOrder(2, 2, 0, 1));
	ToOut(allCellsDistOrder(2, 3, 1, 2));
}

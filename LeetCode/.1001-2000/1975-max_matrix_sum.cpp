﻿#include "leetcode.hpp"

/* 1975. 最大方阵和

给你一个 n x n 的整数方阵 matrix 。你可以执行以下操作 任意次 ：
  选择 matrix 中 相邻 两个元素，并将它们都 乘以 -1 。

如果两个元素有 公共边 ，那么它们就是 相邻 的。

你的目的是 最大化 方阵元素的和。
请你在执行以上操作之后，返回方阵的 最大 和。

示例 1：
https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex1.png
输入：matrix = [[1,-1],[-1,1]]
输出：4
解释：我们可以执行以下操作使和等于 4 ：
- 将第一行的 2 个元素乘以 -1 。
- 将第一列的 2 个元素乘以 -1 。

示例 2：
https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex2.png
输入：matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
输出：16
解释：我们可以执行以下操作使和等于 16 ：
- 将第二行的最后 2 个元素乘以 -1 。

提示：
  n == matrix.length == matrix[i].length
  2 <= n <= 250
  -10^5 <= matrix[i][j] <= 10^5
*/

long long maxMatrixSum(vector<vector<int>>& matrix)
{
	long long sum = 0;
	int neg = 0, val = INT_MAX;
	for (auto& row : matrix)
		for (auto& tmp : row) {
			sum += abs(tmp);
			neg += tmp < 0;
			val = min(val, abs(tmp));
		}
	if (neg & 1)
		sum -= 2 * val;
	return sum;
}

int main() { }

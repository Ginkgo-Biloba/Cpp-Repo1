﻿#include "leetcode.hpp"

/* 1901. 找出顶峰元素 II

一个 2D 网格中的 顶峰元素 是指那些 严格大于 其相邻格子(上、下、左、右)的元素。

给你一个 从 0 开始编号 的 m x n 矩阵 mat ，其中任意两个相邻格子的值都 不相同 。
找出 任意一个 顶峰元素 mat[i][j] 并 返回其位置 [i,j] 。

你可以假设整个矩阵周边环绕着一圈值为 -1 的格子。

要求必须写出时间复杂度为 O(m log(n)) 或 O(n log(m)) 的算法

示例 1:
https://assets.leetcode.com/uploads/2021/06/08/1.png
输入: mat = [[1,4],[3,2]]
输出: [0,1]
解释: 3和4都是顶峰元素，所以[1,0]和[0,1]都是可接受的答案。

示例 2:
https://assets.leetcode.com/uploads/2021/06/07/3.png
输入: mat = [[10,20,15],[21,30,14],[7,16,32]]
输出: [1,1]
解释: 30和32都是顶峰元素，所以[1,1]和[2,2]都是可接受的答案。

提示：
  m == mat.length
  n == mat[i].length
  1 <= m, n <= 500
  1 <= mat[i][j] <= 10^5
  任意两个相邻元素均不相等.
*/

vector<int> findPeakGrid(vector<vector<int>>& src)
{
	int rows = static_cast<int>(src.size());
	int cols = static_cast<int>(src[0].size());
	int a = 0, b = cols - 1;
	while (a <= b) {
		int r = 0, m = (a + b) / 2;
		for (int h = 0; h < rows; ++h) {
			if (src[h][m] >= src[r][m])
				r = h;
		}
		bool L = (m - 1 >= a) && (src[r][m - 1] > src[r][m]);
		bool R = (m + 1 <= b) && (src[r][m + 1] > src[r][m]);
		if (!L && !R)
			return vector<int> {r, m};
		if (R)
			a = m + 1;
		else
			b = m - 1;
	}
	return vector<int> {-1, -1};
}

int main() { }

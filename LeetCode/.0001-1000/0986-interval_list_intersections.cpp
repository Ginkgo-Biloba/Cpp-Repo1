﻿#include "leetcode.hpp"

/* 986. 区间列表的交集

给定两个由一些闭区间组成的列表，每个区间列表都是成对不相交的，并且已经排序。

返回这两个区间列表的交集。

形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b。
两个闭区间的交集是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3]。

示例：
输入：A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
注意：输入和所需的输出都是区间对象组成的列表，而不是数组或列表。
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/02/interval1.png

提示：
  0 <= A.length < 1000
  0 <= B.length < 1000
  0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
*/

vector<vector<int>>
intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)
{
	int nA = static_cast<int>(A.size());
	int nB = static_cast<int>(B.size());
	int a = 0, b = 0, L, R;
	vector<vector<int>> ans;
	while (a < nA && b < nB) {
		L = max(A[a][0], B[b][0]);
		R = min(A[a][1], B[b][1]);
		if (L <= R)
			ans.push_back({L, R});
		if (A[a][1] < B[b][1])
			++a;
		else
			++b;
	}
	return ans;
}

int main()
{
	vector<vector<int>>
		a = {{0, 2}, {5, 10}, {13, 23}, {24, 25}},
		b = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
	ToOut(intervalIntersection(a, b));
}

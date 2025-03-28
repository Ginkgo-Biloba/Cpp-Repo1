﻿#include "leetcode.hpp"

/* 667. 优美的排列 II

给定两个整数 n 和 k，你需要实现一个数组，这个数组包含从 1 到 n 的 n 个不同整数，同时满足以下条件：

① 如果这个数组是 [a1, a2, a3, ... , an] ，那么数组 [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数；.

② 如果存在多种答案，你只需实现并返回其中任意一种.

示例 1:
输入: n = 3, k = 1
输出: [1, 2, 3]
解释: [1, 2, 3] 包含 3 个范围在 1-3 的不同整数， 并且 [1, 1] 中有且仅有 1 个不同整数 : 1

示例 2:
输入: n = 3, k = 2
输出: [1, 3, 2]
解释: [1, 3, 2] 包含 3 个范围在 1-3 的不同整数， 并且 [2, 1] 中有且仅有 2 个不同整数: 1 和 2

提示:
  n 和 k 满足条件 1 <= k < n <= 104.
*/

// https://leetcode.com/problems/beautiful-arrangement-ii/discuss/166827/Java-Solution.-Everyone-else's-code-is-way-too-convoluted-to-understand
// 抄的
vector<int> constructArray(int n, int k)
{
	vector<int> v;
	v.reserve(n);
	int L = 1, R = n;
	for (; n > 0; --n) {
		// 如果 k 是偶数，左边+1，否则右边-1.
		// 二者可以交换，因为整体反转，如 1243 和 3421 是等价的
		if (k & 1)
			v.push_back(R--);
		else
			v.push_back(L++);
		// 交换方向，直到交换了 k-1 次
		// 剩下的数字，全部按递增或递减顺序写下
		if (k > 1)
			--k;
	}
	return v;
}

int main()
{
	ToOut(constructArray(3, 1));
	ToOut(constructArray(3, 2));
}

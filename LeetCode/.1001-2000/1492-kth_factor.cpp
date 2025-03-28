﻿#include "leetcode.hpp"

/* 1492. n 的第 k 个因子

给你两个正整数 n 和 k 。

如果正整数 i 满足 n % i == 0 ，那么我们就说正整数 i 是整数 n 的因子。

考虑整数 n 的所有因子，将它们 升序排列 。
请你返回第 k 个因子。
如果 n 的因子数少于 k ，请你返回 -1 。

示例 1：
输入：n = 12, k = 3
输出：3
解释：因子列表包括 [1, 2, 3, 4, 6, 12]，第 3 个因子是 3 。

示例 2：
输入：n = 7, k = 2
输出：7
解释：因子列表包括 [1, 7] ，第 2 个因子是 7 。

示例 3：
输入：n = 4, k = 4
输出：-1
解释：因子列表包括 [1, 2, 4] ，只有 3 个因子，所以我们应该返回 -1 。

示例 4：
输入：n = 1, k = 1
输出：1
解释：因子列表包括 [1] ，第 1 个因子为 1 。

示例 5：
输入：n = 1000, k = 3
输出：4
解释：因子列表包括 [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000] 。

提示：
  1 <= k <= n <= 1000
*/

int kthFactor(int n, int k)
{
	vector<int> A, B;
	int a, b;
	int m = static_cast<int>(sqrt(n));
	if (m * m <= n)
		++m;
	for (a = 1; a < m; ++a) {
		b = n / a;
		if (a * b == n) {
			A.push_back(a);
			if (a < b)
				B.push_back(b);
		}
	}
	a = static_cast<int>(A.size());
	b = static_cast<int>(B.size());
	if (a + b < k)
		return -1;
	return (k <= a) ? A[k - 1] : B[a + b - k];
}

int main()
{
	ToOut(kthFactor(12, 3));
	ToOut(kthFactor(7, 2));
	ToOut(kthFactor(4, 4));
	ToOut(kthFactor(1, 1));
	ToOut(kthFactor(1000, 3));
}

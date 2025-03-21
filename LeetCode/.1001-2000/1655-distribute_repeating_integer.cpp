﻿#include "leetcode.hpp"

/* 1655. 分配重复整数

给你一个长度为 n 的整数数组 nums ，这个数组中至多有 50 个不同的值。
同时你有 m 个顾客的订单 quantity ，其中，整数 quantity[i] 是第 i 位顾客订单的数目。
请你判断是否能将 nums 中的整数分配给这些顾客，且满足：
  第 i 位顾客 恰好 有 quantity[i] 个整数。
  第 i 位顾客拿到的整数都是 相同的 。
  每位顾客都满足上述两个要求。

如果你可以分配 nums 中的整数满足上面的要求，那么请返回 true ，否则返回 false 。

示例 1：
输入：nums = [1,2,3,4], quantity = [2]
输出：false
解释：第 0 位顾客没办法得到两个相同的整数。

示例 2：
输入：nums = [1,2,3,3], quantity = [2]
输出：true
解释：第 0 位顾客得到 [3,3] 。整数 [1,2] 都没有被使用。

示例 3：
输入：nums = [1,1,2,2], quantity = [2,2]
输出：true
解释：第 0 位顾客得到 [1,1] ，第 1 位顾客得到 [2,2] 。

示例 4：
输入：nums = [1,1,2,3], quantity = [2,2]
输出：false
解释：尽管第 0 位顾客可以得到 [1,1] ，第 1 位顾客没法得到 2 个一样的整数。

示例 5：
输入：nums = [1,1,1,1,1], quantity = [2,3]
输出：true
解释：第 0 位顾客得到 [1,1] ，第 1 位顾客得到 [1,1,1] 。

提示：
  n == nums.length
  1 <= n <= 10^5
  1 <= nums[i] <= 1000
  m == quantity.length
  1 <= m <= 10
  1 <= quantity[i] <= 10^5
  nums 中至多有 50 个不同的数字。
*/

// https://leetcode.com/problems/distribute-repeating-integers/discuss/935824/C%2B%2B-State-Compression-DP-O(50*3m)
// 抄的
class Solution {
	vector<array<char, 1024>> dp, ok;

public:
	bool canDistribute(vector<int>& nums, vector<int>& quantity)
	{
		vector<int> A;
		map<int, int> M;
		for (int i : nums)
			M[i] += 1;
		for (auto const& kv : M)
			A.push_back(kv.second);

		int alen = static_cast<int>(A.size());
		int qlen = static_cast<int>(quantity.size());
		int mask = (1 << qlen) - 1;
		dp.resize(alen + 1);
		ok.resize(alen + 1);
		memset(dp.data(), 0, dp.size() * sizeof(dp[0]));
		memset(ok.data(), 0, ok.size() * sizeof(ok[0]));
		for (int i = 1; i <= alen; ++i)
			for (int m = 0; m <= mask; ++m) {
				int s = 0;
				for (int k = 0; k < qlen; ++k) {
					if (m & (1 << k))
						s += quantity[k];
				}
				if (s <= A[i - 1])
					ok[i][m] = 1;
			}

		dp[0][mask] = 1;
		for (int i = 1; i <= alen; ++i)
			for (int m = 0; m <= mask; ++m) {
				int need = (~m) & mask;
				dp[i][m] = dp[i - 1][m];
				for (int s = need; s; s = (s - 1) & need) {
					if (ok[i][s])
						dp[i][m] = dp[i][m] || dp[i - 1][m | s];
				}
			}

		return dp[alen][0] != 0;
	}
};

int main()
{
	vector<int>
		a = {1, 2, 3, 4},
		b = {2},
		c = {1, 2, 3, 3},
		d = {2},
		e = {1, 1, 2, 2},
		f = {2, 2},
		g = {1, 1, 2, 3},
		h = {2, 2},
		i = {1, 1, 1, 1, 1},
		j = {2, 3};
	Solution s;
	ToOut(s.canDistribute(a, b));
	ToOut(s.canDistribute(c, d));
	ToOut(s.canDistribute(e, f));
	ToOut(s.canDistribute(g, h));
	ToOut(s.canDistribute(i, j));
}

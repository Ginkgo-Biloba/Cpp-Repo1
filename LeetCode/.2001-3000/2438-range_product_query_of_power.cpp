﻿#include "leetcode.hpp"

/* 2438. 二的幂数组中查询范围内的乘积

给你一个正整数 n ，你需要找到一个下标从 0 开始的数组 powers ，它包含 最少 数目的 2 的幂，且它们的和为 n 。
powers 数组是 非递减 顺序的。
根据前面描述，构造 powers 数组的方法是唯一的。

同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] ，其中 queries[i] 表示请你求出满足 lefti <= j <= righti 的所有 powers[j] 的乘积。

请你返回一个数组 answers ，长度与 queries 的长度相同，其中 answers[i]是第 i 个查询的答案。
由于查询的结果可能非常大，请你将每个 answers[i] 都对 10^9 + 7 取余 。

示例 1：
输入：n = 15, queries = [[0,1],[2,2],[0,3]]
输出：[2,4,64]
解释：
对于 n = 15 ，得到 powers = [1,2,4,8] 。没法得到元素数目更少的数组。
第 1 个查询的答案：powers[0] * powers[1] = 1 * 2 = 2 。
第 2 个查询的答案：powers[2] = 4 。
第 3 个查询的答案：powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64 。
每个答案对 10^9 + 7 得到的结果都相同，所以返回 [2,4,64] 。

示例 2：
输入：n = 2, queries = [[0,0]]
输出：[2]
解释：
对于 n = 2, powers = [2] 。
唯一一个查询的答案是 powers[0] = 2 。答案对 10^9 + 7 取余后结果相同，所以返回 [2] 。

提示：
  1 <= n <= 10^9
  1 <= queries.length <= 10^5
  0 <= starti <= endi < powers.length
*/

vector<int> productQueries(int n, vector<vector<int>> const& queries)
{
	int const mod = static_cast<int>(1e9 + 7);
	vector<int> mods(32 * 17);
	mods[0] = 1;
	for (size_t i = 1; i < mods.size(); ++i)
		mods[i] = (mods[i - 1] * 2) % mod;
	vector<int> powers, prefix;
	for (int i = 0; i < 31; ++i)
		if (n & (1 << i))
			powers.push_back(i);
	prefix.resize(powers.size() + 1);
	for (size_t i = 0; i < powers.size(); ++i)
		prefix[i + 1] = prefix[i] + powers[i];
	vector<int> ans;
	for (auto& q : queries) {
		int d = prefix[q[1] + 1] - prefix[q[0]];
		ans.push_back(mods[d]);
	}
	return ans;
}

int main()
{
	ToOut(productQueries(15, {{0, 1}, {2, 2}, {0, 3}}));
	ToOut(productQueries(2, {{0, 0}}));
}

﻿#include "leetcode.hpp"

/* 2538. 最大价值和与最小价值和的差值

给你一个 n 个节点的无向无根图，节点编号为 0 到 n - 1 。
给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间有一条边。

每个节点都有一个价值。
给你一个整数数组 price ，其中 price[i] 是第 i 个节点的价值。

一条路径的 价值和 是这条路径上所有节点的价值之和。

你可以选择树中任意一个节点作为根节点 root 。
选择 root 为根的 开销 是以 root 为起点的所有路径中，价值和 最大的一条路径与最小的一条路径的差值。

请你返回所有节点作为根节点的选择中，最大 的 开销 为多少。

示例 1：
https://assets.leetcode.com/uploads/2022/12/01/example14.png
输入：n = 6, edges = [[0,1],[1,2],[1,3],[3,4],[3,5]], price = [9,8,7,6,10,5]
输出：24
解释：上图展示了以节点 2 为根的树。左图（红色的节点）是最大价值和路径，右图（蓝色的节点）是最小价值和路径。
- 第一条路径节点为 [2,1,3,4]：价值为 [7,8,6,10] ，价值和为 31 。
- 第二条路径节点为 [2] ，价值为 [7] 。
最大路径和与最小路径和的差值为 24 。24 是所有方案中的最大开销。

示例 2：
https://assets.leetcode.com/uploads/2022/11/24/p1_example2.png
输入：n = 3, edges = [[0,1],[1,2]], price = [1,1,1]
输出：2
解释：上图展示了以节点 0 为根的树。左图（红色的节点）是最大价值和路径，右图（蓝色的节点）是最小价值和路径。
- 第一条路径包含节点 [0,1,2]：价值为 [1,1,1] ，价值和为 3 。
- 第二条路径节点为 [0] ，价值为 [1] 。
最大路径和与最小路径和的差值为 2 。2 是所有方案中的最大开销。

提示：
  1 <= n <= 10^5
  edges.length == n - 1
  0 <= ai, bi <= n - 1
  edges 表示一棵符合题面要求的树。
  price.length == n
  1 <= price[i] <= 10^5
*/

// https://leetcode.cn/problems/difference-between-maximum-and-minimum-price-sum/solutions/2062782/by-endlesscheng-5l70/
// 抄的
pair<int64_t, int64_t> dfs(int u, int from, vector<vector<int>> const& adj,
	vector<int> const& price, int64_t& ans)
{
	int64_t val = price[u];
	int64_t max1 = val, max2 = 0;
	for (int v : adj[u])
		if (v != from) {
			pair<int64_t, int64_t> p = dfs(v, u, adj, price, ans);
			int64_t cur1 = p.first, cur2 = p.second;
			ans = max(ans, max(max1 + cur2, max2 + cur1));
			max1 = max(max1, val + cur1);
			max2 = max(max2, val + cur2);
		}
	return {max1, max2};
}

long long maxOutput(int n,
	vector<vector<int>> const& edges, vector<int> const& price)
{
	vector<vector<int>> adj(n);
	for (auto& e : edges)
		adj[e[0]].push_back(e[1]),
			adj[e[1]].push_back(e[0]);

	int64_t ans = 0;
	dfs(0, -1, adj, price, ans);
	return static_cast<long long>(ans);
}

int main()
{
	ToOut(maxOutput(6,
		{{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}},
		{9, 8, 7, 6, 10, 5}));
	ToOut(maxOutput(3,
		{{0, 1}, {1, 2}},
		{1, 1, 1}));
}

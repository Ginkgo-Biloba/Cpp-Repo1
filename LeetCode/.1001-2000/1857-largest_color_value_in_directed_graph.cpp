﻿#include "leetcode.hpp"

/* 1857. 有向图中最大颜色值

给你一个 有向图 ，它含有 n 个节点和 m 条边。
节点编号从 0 到 n - 1 。

给你一个字符串 colors ，其中 colors[i] 是小写英文字母，表示图中第 i 个节点的 颜色 （下标从 0 开始）。
同时给你一个二维数组 edges ，其中 edges[j] = [aj, bj] 表示从节点 aj 到节点 bj 有一条 有向边 。

图中一条有效 路径 是一个点序列 x1 -> x2 -> x3 -> ... -> xk ，对于所有 1 <= i < k ，从 xi 到 xi+1 在图中有一条有向边。
路径的 颜色值 是路径中 出现次数最多 颜色的节点数目。

请你返回给定图中有效路径里面的 最大颜色值 。
如果图中含有环，请返回 -1 。

示例 1：
https://assets.leetcode.com/uploads/2021/04/21/leet1.png
输入：colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
输出：3
解释：路径 0 -> 2 -> 3 -> 4 含有 3 个颜色为 "a" 的节点（上图中的红色节点）。

示例 2：
https://assets.leetcode.com/uploads/2021/04/21/leet2.png
输入：colors = "a", edges = [[0,0]]
输出：-1
解释：从 0 到 0 有一个环。


提示：
  n == colors.length
  m == edges.length
  1 <= n <= 10^5
  0 <= m <= 10^5
  colors 只含有小写英文字母。
  0 <= aj, bj < n
*/

// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/discuss/1200575/Topological-Sort-vs.-DFS-vs.-Dijkstra
// 抄的
int largestPathValue(string colors, vector<vector<int>>& edges)
{
	int len = static_cast<int>(colors.size());
	vector<vector<int>> adj(len);
	vector<array<int, 26>> num(len);
	vector<int> ind(len);
	memset(num.data(), 0, sizeof(num[0]) * len);
	for (auto const& e : edges) {
		adj[e[0]].push_back(e[1]);
		++(ind[e[1]]);
	}

	vector<int> pre, cur;
	int ans = 0, visit = 0;
	for (int i = 0; i < len; ++i) {
		if (ind[i] == 0)
			cur.push_back(i);
	}
	while (cur.size()) {
		cur.swap(pre);
		cur.clear();
		for (int i : pre) {
			++visit;
			ans = max(ans, ++(num[i][colors[i] - 'a']));
			for (int j : adj[i]) {
				for (int k = 0; k < 26; ++k)
					num[j][k] = max(num[j][k], num[i][k]);
				if (--(ind[j]) == 0)
					cur.push_back(j);
			}
		}
	}
	return (visit == len) ? ans : -1;
}

int main()
{
}

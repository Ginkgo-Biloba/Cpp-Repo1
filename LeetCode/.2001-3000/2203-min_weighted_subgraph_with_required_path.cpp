﻿#include "leetcode.hpp"

/* 2203. 得到要求路径的最小带权子图

给你一个整数 n ，它表示一个 带权有向 图的节点数，节点编号为 0 到 n - 1 。

同时给你一个二维整数数组 edges ，其中 edges[i] = [fromi, toi, weighti] ，表示从 fromi 到 toi 有一条边权为 weighti 的 有向 边。

最后，给你三个 互不相同 的整数 src1 ，src2 和 dest ，表示图中三个不同的点。

请你从图中选出一个 边权和最小 的子图，使得从 src1 和 src2 出发，在这个子图中，都 可以 到达 dest 。如果这样的子图不存在，请返回 -1 。

子图 中的点和边都应该属于原图的一部分。
子图的边权和定义为它所包含的所有边的权值之和。

示例 1：
https://assets.leetcode.com/uploads/2022/02/17/example1drawio.png
输入：n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5
输出：9
解释：
上图为输入的图。
蓝色边为最优子图之一。
注意，子图 [[1,0,3],[0,5,6]] 也能得到最优解，但无法在满足所有限制的前提下，得到更优解。

示例 2：
https://assets.leetcode.com/uploads/2022/02/17/example2-1drawio.png
输入：n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
输出：-1
解释：
上图为输入的图。
可以看到，不存在从节点 1 到节点 2 的路径，所以不存在任何子图满足所有限制。

提示：
  3 <= n <= 10^5
  0 <= edges.length <= 10^5
  edges[i].length == 3
  0 <= fromi, toi, src1, src2, dest <= n - 1
  fromi != toi
  src1 ，src2 和 dest 两两不同。
  1 <= weight[i] <= 10^5
*/

class Solution {
	enum : int64_t { LARGE = LLONG_MAX / 3 };

	vector<long long> dijstra(vector<vector<pair<int, int>>>& adj, int n, int src)
	{
		vector<int> visit(n);
		vector<long long> ans(n, LARGE);
		priority_queue<pair<long long, int>> Q;
		Q.emplace(0, src);
		ans[src] = 0;
		while (Q.size()) {
			auto q = Q.top();
			Q.pop();
			if (visit[q.second])
				continue;
			visit[q.second] = 1;
			for (auto const& tw : adj[q.second]) {
				long long d = tw.second - q.first;
				if (d < ans[tw.first]) {
					ans[tw.first] = d;
					Q.emplace(-d, tw.first);
				}
			}
		}
		return ans;
	}

public:
	long long minimumWeight(int n,
		vector<vector<int>>& edges, int src1, int src2, int dest)
	{
		vector<vector<pair<int, int>>> adj(n);
		for (auto& e : edges)
			adj[e[0]].emplace_back(e[1], e[2]);
		vector<long long> a = dijstra(adj, n, src1);
		vector<long long> b = dijstra(adj, n, src2);
		if (a[dest] == LARGE || b[dest] == LARGE)
			return -1;
		for (auto& j : adj)
			j.clear();
		for (auto& e : edges)
			adj[e[1]].emplace_back(e[0], e[2]);
		vector<long long> c = dijstra(adj, n, dest);
		long long ans = LARGE;
		for (int i = 0; i < n; ++i)
			ans = min(ans, a[i] + b[i] + c[i]);
		return ans;
	}
};

int main()
{
	Solution s;
	vector<vector<int>>
		a = {{0, 2, 2}, {0, 5, 6}, {1, 0, 3}, {1, 4, 5}, {2, 1, 1}, {2, 3, 3}, {2, 3, 4}, {3, 4, 2}, {4, 5, 1}},
		b = {{0, 1, 1}, {2, 1, 1}};
	ToOut(s.minimumWeight(6, a, 0, 1, 5));
	ToOut(s.minimumWeight(3, b, 0, 1, 2));
}

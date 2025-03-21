﻿#include "leetcode.hpp"

/* 1707. 与数组中元素的最大异或值

给你一个由非负整数组成的数组 nums 。
另有一个查询数组 queries ，其中 queries[i] = [xi, mi] 。

第 i 个查询的答案是 xi 和任何 nums 数组中不超过 mi 的元素按位异或（XOR）得到的最大值。
换句话说，答案是 max(nums[j] XOR xi) ，其中所有 j 均满足 nums[j] <= mi 。
如果 nums 中的所有元素都大于 mi，最终答案就是 -1 。

返回一个整数数组 answer 作为查询的答案，其中 answer.length == queries.length 且 answer[i] 是第 i 个查询的答案。

示例 1：
输入：nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
输出：[3,3,7]
解释：
1) 0 和 1 是仅有的两个不超过 1 的整数。0 XOR 3 = 3 而 1 XOR 3 = 2 。二者中的更大值是 3 。
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.

示例 2：
输入：nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
输出：[15,-1,5]

提示：
  1 <= nums.length, queries.length <= 10^5
  queries[i].length == 2
  0 <= nums[j], xi, mi <= 10^9
*/

// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/discuss/988132/Python-clean-trie-+-two-pointers-solution-O(sort)/800628
// 抄的
class Trie {
	struct Node {
		Node* child[2];
		Node() { child[0] = child[1] = nullptr; }
	};

	Node root;
	vector<Node*> buffer;

public:
	~Trie()
	{
		for (Node* node : buffer)
			delete node;
	}

	void insert(int val)
	{
		Node* node = &root;
		for (int i = 30; i >= 0; --i) {
			int bit = (val >> i) & 1;
			if (!(node->child[bit])) {
				buffer.push_back(new Node());
				node->child[bit] = buffer.back();
			}
			node = node->child[bit];
		}
	}

	int query(int val)
	{
		Node* node = &root;
		if (!(node->child[0] || node->child[1]))
			return -1;
		int ans = 0;
		for (int i = 30; i >= 0; --i) {
			int bit = (val >> i) & 1;
			if (node->child[1 - bit]) {
				node = node->child[1 - bit];
				ans |= 1 << i;
			} else
				node = node->child[bit];
		}
		return ans;
	}
};

class Solution {
public:
	vector<int> maximizeXor(vector<int>& A, vector<vector<int>>& queries)
	{
		int len = static_cast<int>(A.size());
		int nqr = static_cast<int>(queries.size());
		vector<array<int, 3>> Q;
		vector<int> ans(nqr);
		for (int i = 0; i < nqr; ++i)
			Q.push_back({queries[i][1], queries[i][0], i});
		sort(A.begin(), A.end());
		sort(Q.begin(), Q.end());

		Trie trie;
		int i = 0, k = 0;
		for (; k < nqr; ++k) {
			int* q = Q[k].data();
			for (; i < len && A[i] <= q[0]; ++i)
				trie.insert(A[i]);
			ans[q[2]] = trie.query(q[1]);
		}
		return ans;
	}
};

int main()
{
}

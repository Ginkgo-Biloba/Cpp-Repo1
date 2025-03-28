﻿#include "leetcode.hpp"

/* 2096. 从二叉树一个节点到另一个节点每一步的方向

给你一棵 二叉树 的根节点 root ，这棵二叉树总共有 n 个节点。
每个节点的值为 1 到 n 中的一个整数，且互不相同。
给你一个整数 startValue ，表示起点节点 s 的值，和另一个不同的整数 destValue ，表示终点节点 t 的值。

请找到从节点 s 到节点 t 的 最短路径 ，并以字符串的形式返回每一步的方向。
每一步用 大写 字母 'L' ，'R' 和 'U' 分别表示一种方向：

  'L' 表示从一个节点前往它的 左孩子 节点。
  'R' 表示从一个节点前往它的 右孩子 节点。
  'U' 表示从一个节点前往它的 父 节点。

请你返回从 s 到 t 最短路径 每一步的方向。

示例 1：
https://assets.leetcode.com/uploads/2021/11/15/eg1.png
输入：root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
输出："UURL"
解释：最短路径为：3 → 1 → 5 → 2 → 6 。

示例 2：
https://assets.leetcode.com/uploads/2021/11/15/eg2.png
输入：root = [2,1], startValue = 2, destValue = 1
输出："L"
解释：最短路径为：2 → 1 。

提示：
  树中节点数目为 n 。
  2 <= n <= 10^5
  1 <= Node.val <= n
  树中所有节点的值 互不相同 。
  1 <= startValue, destValue <= n
  startValue != destValue
*/

// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/solutions/1612105/3-steps/
// 抄的
class Solution {
	bool find(TreeNode* n, int val, string& path)
	{
		if (n->val == val)
			return true;
		if (n->left && find(n->left, val, path))
			path.push_back('L');
		else if (n->right && find(n->right, val, path))
			path.push_back('R');
		return !path.empty();
	}

public:
	string getDirections(TreeNode* root, int startValue, int destValue)
	{
		string s, d;
		find(root, startValue, s);
		find(root, destValue, d);
		while (!s.empty() && !d.empty() && s.back() == d.back()) {
			s.pop_back();
			d.pop_back();
		}
		return string(s.size(), 'U') + string(rbegin(d), rend(d));
	}
};

int main() { }

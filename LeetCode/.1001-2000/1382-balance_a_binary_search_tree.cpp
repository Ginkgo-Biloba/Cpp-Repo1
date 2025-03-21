﻿#include "leetcode.hpp"

/* 1382. 将二叉搜索树变平衡

给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。

如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。

如果有多种构造方法，请你返回任意一种。

示例：
输入：root = [1,null,2,null,3,null,4,null,null]
输出：[2,1,3,null,null,null,4]
解释：这不是唯一的正确答案，[3,1,4,null,2,null,null] 也是一个可行的构造方案。

提示：
  树节点的数目在 1 到 10^4 之间。
  树节点的值互不相同，且在 1 到 10^5 之间。
*/

// https://leetcode.com/problems/balance-a-binary-search-tree/discuss/539686/JavaC%2B%2B-Sorted-Array-to-BST-O(N)-Clean-code
// 抄的
class Solution {
	vector<TreeNode*> A;

	void inorder(TreeNode* node)
	{
		if (node->left)
			inorder(node->left);
		A.push_back(node);
		if (node->right)
			inorder(node->right);
	}

	TreeNode* bst(int s, int e)
	{
		if (s > e)
			return NULL;
		int m = (s + e) / 2;
		TreeNode* r = A[m];
		r->left = bst(s, m - 1);
		r->right = bst(m + 1, e);
		return r;
	}

public:
	TreeNode* balanceBST(TreeNode* root)
	{
		A.clear();
		inorder(root);
		root = bst(0, static_cast<int>(A.size()) - 1);
		return root;
	}
};

int main()
{
}

﻿#include "leetcode.hpp"

/* 1325. 删除给定值的叶子节点

给你一棵以 root 为根的二叉树和一个整数 target，请你删除所有值为 target 的 叶子节点 。

注意，一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。

也就是说，你需要重复此过程直到不能继续删除。

示例 1：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/16/sample_1_1684.png
输入：root = [1,2,3,2,null,2,4], target = 2
输出：[1,null,3,null,4]
解释：
上面左边的图中，绿色节点为叶子节点，且它们的值与 target 相同（同为 2 ），它们会被删除，得到中间的图。
有一个新的节点变成了叶子节点且它的值与 target 相同，所以将再次进行删除，从而得到最右边的图。

示例 2：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/16/sample_2_1684.png
输入：root = [1,3,3,3,2], target = 3
输出：[1,3,null,null,2]

示例 3：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/16/sample_3_1684.png
输入：root = [1,2,null,2,null,2], target = 2
输出：[1]
解释：每一步都删除一个绿色的叶子节点（值为 2）。

示例 4：
输入：root = [1,1,1], target = 1
输出：[]

示例 5：
输入：root = [1,2,3], target = 1
输出：[1,2,3]

提示：
  1 <= target <= 1000
  每一棵树最多有 3000 个节点。
  每一个节点值的范围是 [1, 1000]。
*/

class Solution {
	int T;

	TreeNode* dfs(TreeNode* node)
	{
		if (node == nullptr)
			return nullptr;
		node->left = dfs(node->left);
		node->right = dfs(node->right);
		if (node->left == nullptr
			&& node->right == nullptr
			&& node->val == T)
			node = nullptr;
		return node;
	}

public:
	TreeNode* removeLeafNodes(TreeNode* root, int target)
	{
		T = target;
		return dfs(root);
	}
};

int main()
{
}

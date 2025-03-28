﻿#include "leetcode.hpp"

/* 337. 打家劫舍 III

在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。

这个地区只有一个入口，我们称之为“根”。
除了“根”之外，每栋房子有且只有一个“父“房子与之相连。

一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

>     3
>    / \
>   2   3
>    \   \
>     3   1

输出: 7
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.

示例 2:

输入: [3,4,5,1,3,null,1]

>     3
>    / \
>   4   5
>  / \   \
> 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
*/

// https://leetcode.com/problems/house-robber-iii/discuss/79330/Step-by-step-tackling-of-the-problem
// 抄的
class Solution {
	typedef array<int, 2> rettype;

	rettype dfs(TreeNode* node)
	{
		rettype ret = {0, 0};
		if (!node)
			return ret;
		rettype a = dfs(node->left);
		rettype b = dfs(node->right);
		// 带孩子不带自己
		ret[0] = max(a[0], a[1]) + max(b[0], b[1]);
		// 不带孩子带自己
		ret[1] = a[0] + b[0] + node->val;
		return ret;
	}

public:
	int rob(TreeNode* root)
	{
		rettype ret = dfs(root);
		return max(ret[0], ret[1]);
	}
};

int main()
{
}

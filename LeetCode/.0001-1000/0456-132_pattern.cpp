﻿#include "leetcode.hpp"

/* 456. 132模式

给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。
注意：n 的值小于15000。

示例1:
输入: [1, 2, 3, 4]
输出: False
解释: 序列中不存在132模式的子序列。

示例 2:
输入: [3, 1, 4, 2]
输出: True
解释: 序列中有 1 个132模式的子序列： [1, 4, 2].

示例 3:
输入: [-1, 3, 2, 0]
输出: True
解释: 序列中有 3 个132模式的的子序列: [-1, 3, 2], [-1, 3, 0] 和 [-1, 2, 0].
*/

// https://leetcode.com/problems/132-pattern/discuss/94071/Single-pass-C%2B%2B-O(n)-space-and-time-solution-(8-lines)-with-detailed-explanation.
// 抄的
bool find132pattern(vector<int> const& nums)
{
	int len = static_cast<int>(nums.size());
	int s3 = INT_MIN;
	vector<int> stk;
	stk.reserve(len);
	for (int i = len - 1; i >= 0; --i) {
		if (nums[i] < s3)
			return true;
		while (!stk.empty() && nums[i] > stk.back()) {
			s3 = stk.back();
			stk.pop_back();
		}
		stk.push_back(nums[i]);
	}
	return false;
}

int main()
{
	ToOut(find132pattern({8, 10, 4, 6, 5}));
}

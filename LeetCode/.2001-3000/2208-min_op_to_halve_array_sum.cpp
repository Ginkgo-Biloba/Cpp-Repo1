﻿#include "leetcode.hpp"

/* 2208. 将数组和减半的最少操作次数

给你一个正整数数组 nums 。
每一次操作中，你可以从 nums 中选择 任意 一个数并将它减小到 恰好 一半。
（注意，在后续操作中你可以对减半过的数继续执行操作）

请你返回将 nums 数组和 至少 减少一半的 最少 操作数。

示例 1：
输入：nums = [5,19,8,1]
输出：3
解释：初始 nums 的和为 5 + 19 + 8 + 1 = 33 。
以下是将数组和减少至少一半的一种方法：
选择数字 19 并减小为 9.5 。
选择数字 9.5 并减小为 4.75 。
选择数字 8 并减小为 4 。
最终数组为 [5, 4.75, 4, 1] ，和为 5 + 4.75 + 4 + 1 = 14.75 。
nums 的和减小了 33 - 14.75 = 18.25 ，减小的部分超过了初始数组和的一半，18.25 >= 33/2 = 16.5 。
我们需要 3 个操作实现题目要求，所以返回 3 。
可以证明，无法通过少于 3 个操作使数组和减少至少一半。

示例 2：
输入：nums = [3,8,20]
输出：3
解释：初始 nums 的和为 3 + 8 + 20 = 31 。
以下是将数组和减少至少一半的一种方法：
选择数字 20 并减小为 10 。
选择数字 10 并减小为 5 。
选择数字 3 并减小为 1.5 。
最终数组为 [1.5, 8, 5] ，和为 1.5 + 8 + 5 = 14.5 。
nums 的和减小了 31 - 14.5 = 16.5 ，减小的部分超过了初始数组和的一半， 16.5 >= 31/2 = 15.5 。
我们需要 3 个操作实现题目要求，所以返回 3 。
可以证明，无法通过少于 3 个操作使数组和减少至少一半。

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 10^7
*/

int halveArray(vector<int> const& nums)
{
	if (nums.size() == 1)
		return 1;
	int ans = 0;
	double d = 0, s = 0;
	vector<double> A;
	for (int i : nums) {
		s += i;
		A.push_back(i);
	}
	std::make_heap(A.begin(), A.end());
	for (s /= 2; d < s; ++ans) {
		std::pop_heap(A.begin(), A.end());
		A.back() /= 2;
		d += A.back();
		std::push_heap(A.begin(), A.end());
	}
	return ans;
}

int main()
{
	ToOut(halveArray({5, 19, 8, 1}));
	ToOut(halveArray({3, 8, 20}));
}
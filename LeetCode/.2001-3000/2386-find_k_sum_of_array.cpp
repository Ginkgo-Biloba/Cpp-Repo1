﻿#include "leetcode.hpp"

/* 2386. 找出数组的第 K 大和

给你一个整数数组 nums 和一个 正 整数 k 。
你可以选择数组的任一 子序列 并且对其全部元素求和。

数组的 第 k 大和 定义为：可以获得的第 k 个 最大 子序列和（子序列和允许出现重复）

返回数组的 第 k 大和 。

子序列是一个可以由其他数组删除某些或不删除元素派生而来的数组，且派生过程不改变剩余元素的顺序。

注意：空子序列的和视作 0 。

示例 1：
输入：nums = [2,4,-2], k = 5
输出：2
解释：所有可能获得的子序列和列出如下，按递减顺序排列：
6、4、4、2、2、0、0、-2
数组的第 5 大和是 2 。

示例 2：
输入：nums = [1,-2,3,4,-10,12], k = 16
输出：10
解释：数组的第 16 大和是 10 。

提示：
  n == nums.length
  1 <= n <= 10^5
  -10^9 <= nums[i] <= 10^9
  1 <= k <= min(2000, 2^n)
*/

long long kSum(vector<int> const& nums, int k)
{
	int n = static_cast<int>(nums.size());
	vector<int> vals;
	long long sum = 0;
	for (int i : nums) {
		sum += max(i, 0);
		vals.push_back(abs(i));
	}
	if (k < 2) return sum;
	std::sort(vals.begin(), vals.end());
	priority_queue<pair<long long, int>> Q;
	Q.push({-vals[0], 0});
	for (--k; --k;) {
		auto q = Q.top();
		Q.pop();
		q.second += 1;
		if (q.second < n) {
			q.first -= vals[q.second];
			Q.push(q);
			Q.push({q.first + vals[q.second - 1], q.second});
		}
	}
	return sum + Q.top().first;
}

int main()
{
	ToOut(kSum({2, 4, -2}, 5));
	ToOut(kSum({1, -2, 3, 4, -10, 12}, 16));
	ToOut(kSum({-530219056, 353285209, 493533664}, 6));
}

﻿#include "leetcode.hpp"

/* 53. 最大子序和

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

进阶:
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

int maxSubArray(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	int ans = INT_MIN, cur = 0;
	for (int i = 0; i < len; ++i) {
		cur += A[i];
		ans = max(ans, cur);
		cur = max(cur, 0);
	}
	return ans;
}

int main()
{
	vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	ToOut(maxSubArray(a));
}

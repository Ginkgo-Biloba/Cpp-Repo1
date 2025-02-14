﻿#include "leetcode.hpp"

/* 2342. 数位和相等数对的最大和

给你一个下标从 0 开始的数组 nums ，数组中的元素都是 正 整数。
请你选出两个下标 i 和 j（i != j），且 nums[i] 的数位和 与  nums[j] 的数位和相等。

请你找出所有满足条件的下标 i 和 j ，找出并返回 nums[i] + nums[j] 可以得到的 最大值 。

示例 1：
输入：nums = [18,43,36,13,7]
输出：54
解释：满足条件的数对 (i, j) 为：
- (0, 2) ，两个数字的数位和都是 9 ，相加得到 18 + 36 = 54 。
- (1, 4) ，两个数字的数位和都是 7 ，相加得到 43 + 7 = 50 。
所以可以获得的最大和是 54 。

示例 2：
输入：nums = [10,12,19,14]
输出：-1
解释：不存在满足条件的数对，返回 -1 。

提示：
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9
*/

int maximumSum(vector<int> const& nums)
{
	size_t len = nums.size();
	vector<pair<int, int>> dv;
	for (int i : nums) {
		int x = i, s = 0;
		for (; x; x /= 10)
			s += x % 10;
		dv.push_back({s, i});
	}
	std::sort(dv.begin(), dv.end());
	int ans = -1;
	for (size_t i = 1; i < len; ++i)
		if (dv[i - 1].first == dv[i].first)
			ans = max(ans, dv[i - 1].second + dv[i].second);
	return ans;
}

int main()
{
	ToOut(maximumSum({18, 43, 36, 13, 7}));
	ToOut(maximumSum({10, 12, 19, 14}));
}

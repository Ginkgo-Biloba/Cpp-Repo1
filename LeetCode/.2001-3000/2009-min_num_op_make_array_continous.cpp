﻿#include "leetcode.hpp"

/* 2009. 使数组连续的最少操作数

给你一个整数数组 nums 。
每一次操作中，你可以将 nums 中 任意 一个元素替换成 任意 整数。

如果 nums 满足以下条件，那么它是 连续的 ：
  nums 中所有元素都是 互不相同 的。
  nums 中 最大 元素与 最小 元素的差等于 nums.length - 1 。

比方说，nums = [4, 2, 5, 3] 是 连续的 ，但是 nums = [1, 2, 3, 5, 6] 不是连续的 。

请你返回使 nums 连续 的 最少 操作次数。

示例 1：
输入：nums = [4,2,5,3]
输出：0
解释：nums 已经是连续的了。

示例 2：
输入：nums = [1,2,3,5,6]
输出：1
解释：一个可能的解是将最后一个元素变为 4 。
结果数组为 [1,2,3,5,4] ，是连续数组。

示例 3：
输入：nums = [1,10,100,1000]
输出：3
解释：一个可能的解是：
- 将第二个元素变为 2 。
- 将第三个元素变为 3 。
- 将第四个元素变为 4 。
结果数组为 [1,2,3,4] ，是连续数组。

提示：
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 10^9
*/

int minOperations(vector<int>& A)
{
	int n = static_cast<int>(A.size());
	int l = 0, r = 1, ans = n;
	sort(A.begin(), A.end());
	for (; r < n; ++r) {
		if (A[l] != A[r])
			A[++l] = A[r];
	}
	int q = l + 1;
	for (l = r = 0; l < q; ++l) {
		while (r < q && A[l] + n > A[r])
			++r;
		ans = min(ans, n - (r - l));
	}
	return ans;
}

int main()
{
	vector<int>
		a = {4, 2, 3, 5},
		b = {1, 2, 3, 5, 6},
		c = {1, 10, 100, 1000},
		d = {8, 10, 16, 18, 10, 10, 16, 13, 13, 16};
	ToOut(minOperations(a));
	ToOut(minOperations(b));
	ToOut(minOperations(c));
	ToOut(minOperations(d));
}

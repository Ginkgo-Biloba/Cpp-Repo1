﻿#include "leetcode.hpp"

/* 2163. 删除元素后和的最小差值

给你一个下标从 0 开始的整数数组 nums ，它包含 3 * n 个元素。

你可以从 nums 中删除 恰好 n 个元素，剩下的 2 * n 个元素将会被分成两个 相同大小 的部分。

  前面 n 个元素属于第一部分，它们的和记为 sumfirst 。
  后面 n 个元素属于第二部分，它们的和记为 sumsecond 。

两部分和的 差值 记为 sumfirst - sumsecond 。

  比方说，sumfirst = 3 且 sumsecond = 2 ，它们的差值为 1 。
  再比方，sumfirst = 2 且 sumsecond = 3 ，它们的差值为 -1 。

请你返回删除 n 个元素之后，剩下两部分和的 差值的最小值 是多少。

示例 1：
输入：nums = [3,1,2]
输出：-1
解释：nums 有 3 个元素，所以 n = 1 。
所以我们需要从 nums 中删除 1 个元素，并将剩下的元素分成两部分。
- 如果我们删除 nums[0] = 3 ，数组变为 [1,2] 。两部分和的差值为 1 - 2 = -1 。
- 如果我们删除 nums[1] = 1 ，数组变为 [3,2] 。两部分和的差值为 3 - 2 = 1 。
- 如果我们删除 nums[2] = 2 ，数组变为 [3,1] 。两部分和的差值为 3 - 1 = 2 。
两部分和的最小差值为 min(-1,1,2) = -1 。

示例 2：
输入：nums = [7,9,5,8,1,3]
输出：1
解释：n = 2 。所以我们需要删除 2 个元素，并将剩下元素分为 2 部分。
如果我们删除元素 nums[2] = 5 和 nums[3] = 8 ，剩下元素为 [7,9,1,3] 。和的差值为 (7+9) - (1+3) = 12 。
为了得到最小差值，我们应该删除 nums[1] = 9 和 nums[4] = 1 ，剩下的元素为 [7,5,8,3] 。和的差值为 (7+5) - (8+3) = 1 。
观察可知，最优答案为 1 。

提示：
  nums.length == 3 * n
  1 <= n <= 10^5
  1 <= nums[i] <= 10^5
*/

long long minimumDifference(vector<int> const& A)
{
	int len = static_cast<int>(A.size());
	int n = len / 3;
	vector<int64_t> L(len), R(len);
	{
		int64_t sum = 0;
		priority_queue<int> Q;
		for (int i = 0; i < len; ++i) {
			sum += A[i];
			Q.push(A[i]);
			if (i >= n) {
				sum -= Q.top();
				Q.pop();
			}
			L[i] = sum;
		}
	}
	{
		int64_t sum = 0;
		priority_queue<int, vector<int>, std::greater<int>> Q;
		for (int i = len; i--;) {
			sum += A[i];
			Q.push(A[i]);
			if (i < 2 * n) {
				sum -= Q.top();
				Q.pop();
			}
			R[i] = sum;
		}
	}
	int64_t ans = INT64_MAX;
	for (int i = n - 1; i < 2 * n; ++i)
		ans = min(ans, L[i] - R[i + 1]);
	return ans;
}

int main()
{
	ToOut(minimumDifference({3, 1, 2}));
	ToOut(minimumDifference({7, 9, 5, 8, 1, 3}));
}

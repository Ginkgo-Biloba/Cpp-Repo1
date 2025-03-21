﻿#include "leetcode.hpp"

/* 1235. 规划兼职工作

你打算利用空闲时间来做兼职工作赚些零花钱。

这里有 n 份兼职工作，每份工作预计从 startTime[i] 开始到 endTime[i] 结束，报酬为 profit[i]。

给你一份兼职工作表，包含开始时间 startTime，结束时间 endTime 和预计报酬 profit 三个数组，请你计算并返回可以获得的最大报酬。

注意，时间上出现重叠的 2 份工作不能同时进行。

如果你选择的工作在时间 X 结束，那么你可以立刻进行在时间 X 开始的下一份工作。

示例 1：
输入：startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
输出：120
解释：
我们选出第 1 份和第 4 份工作，
时间范围是 [1-3]+[3-6]，共获得报酬 120 = 50 + 70。

示例 2：
输入：startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
输出：150
解释：
我们选择第 1，4，5 份工作。
共获得报酬 150 = 20 + 70 + 60。

示例 3：
输入：startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
输出：6

提示：
  1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
  1 <= startTime[i] < endTime[i] <= 10^9
  1 <= profit[i] <= 10^4
*/

// https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409009/JavaC%2B%2BPython-DP-Solution
// 抄的
class Solution {
	typedef array<int, 3> elem;

public:
	int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit)
	{
		int len = static_cast<int>(start.size());
		std::map<int, int> dp;
		vector<elem> job;

		job.reserve(len);
		for (int i = 0; i < len; ++i)
			job.push_back({end[i], start[i], profit[i]});
		sort(job.begin(), job.end());

		dp[0] = 0;
		for (elem e : job) {
			int cur = prev(dp.upper_bound(e[1]))->second + e[2];
			if (cur > dp.rbegin()->second)
				dp[e[0]] = cur;
		}
		return dp.rbegin()->second;
	}
};

int main()
{
	Solution s;
	vector<int>
		a = {1, 2, 3, 3},
		b = {3, 4, 5, 6},
		c = {50, 10, 40, 70},
		d = {1, 2, 3, 4, 6},
		e = {3, 5, 10, 6, 9},
		f = {20, 20, 100, 70, 60},
		g = {1, 1, 1},
		h = {2, 3, 4},
		i = {5, 6, 4};
	ToOut(s.jobScheduling(a, b, c));
	ToOut(s.jobScheduling(d, e, f));
	ToOut(s.jobScheduling(g, h, i));
}

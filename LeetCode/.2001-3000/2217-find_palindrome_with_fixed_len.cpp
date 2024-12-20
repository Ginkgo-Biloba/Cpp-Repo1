﻿#include "leetcode.hpp"

/* 2217. 找到指定长度的回文数

给你一个整数数组 queries 和一个 正 整数 intLength ，请你返回一个数组 answer ，其中 answer[i] 是长度为 intLength 的 正回文数 中第 queries[i] 小的数字，如果不存在这样的回文数，则为 -1 。

回文数 指的是从前往后和从后往前读一模一样的数字。回文数不能有前导 0 。

示例 1：
输入：queries = [1,2,3,4,5,90], intLength = 3
输出：[101,111,121,131,141,999]
解释：
长度为 3 的最小回文数依次是：
101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, ...
第 90 个长度为 3 的回文数是 999 。

示例 2：
输入：queries = [2,4,6], intLength = 4
输出：[1111,1331,1551]
解释：
长度为 4 的前 6 个回文数是：
1001, 1111, 1221, 1331, 1441 和 1551 。

提示：
  1 <= queries.length <= 5 * 10^4
  1 <= queries[i] <= 10^9
  1 <= intLength <= 15
*/

vector<long long> kthPalindrome(vector<int> const& queries, int intLength)
{
	int seg = (intLength + 1) / 2;
	int start = static_cast<int>(pow(10.0, seg - 1)) - 1;
	int limit = static_cast<int>(pow(10.0, seg) - 1);
	vector<long long> ans;
	for (int q : queries) {
		int val = start + q;
		if (val > limit) {
			ans.push_back(-1);
			continue;
		}
		char s[32] = {0};
		int bit = snprintf(s, sizeof(s), "%d", val);
		int i = seg - 1 - (intLength % 2);
		for (; i >= 0; --i)
			s[bit++] = s[i];
		ans.push_back(atoll(s));
	}
	return ans;
}

int main()
{
	ToOut(kthPalindrome({1, 2, 3, 4, 5, 90}, 3));
	ToOut(kthPalindrome({2, 4, 6}, 4));
}

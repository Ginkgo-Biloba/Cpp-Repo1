﻿#include "leetcode.hpp"

/* 1849. 将字符串拆分为递减的连续值

给你一个仅由数字组成的字符串 s 。

请你判断能否将 s 拆分成两个或者多个 非空子字符串 ，使子字符串的 数值 按 降序 排列，且每两个 相邻子字符串 的数值之 差 等于 1 。

  例如，字符串 s = "0090089" 可以拆分成 ["0090", "089"] ，数值为 [90,89] 。
  这些数值满足按降序排列，且相邻值相差 1 ，这种拆分方法可行。

  另一个例子中，字符串 s = "001" 可以拆分成 ["0", "01"]、["00", "1"] 或 ["0", "0", "1"] 。
  然而，所有这些拆分方法都不可行，因为对应数值分别是 [0,1]、[0,1] 和 [0,0,1] ，都不满足按降序排列的要求。

如果可以按要求拆分 s ，返回 true ；否则，返回 false 。

子字符串 是字符串中的一个连续字符序列。

示例 1：

输入：s = "1234"
输出：false
解释：不存在拆分 s 的可行方法。

示例 2：

输入：s = "050043"
输出：true
解释：s 可以拆分为 ["05", "004", "3"] ，对应数值为 [5,4,3] 。
满足按降序排列，且相邻值相差 1 。

示例 3：
输入：s = "9080701"
输出：false
解释：不存在拆分 s 的可行方法。

示例 4：
输入：s = "10009998"
输出：true
解释：s 可以拆分为 ["100", "099", "98"] ，对应数值为 [100,99,98] 。
满足按降序排列，且相邻值相差 1 。

提示：
  1 <= s.length <= 20
  s 仅由数字组成
*/

// https://leetcode-cn.com/problems/splitting-a-string-into-descending-consecutive-values/
// 抄的
bool splitString(string A)
{
	// 子串对应数值的上限
	int64_t const INF = static_cast<int64_t>(1e10);
	int64_t num = 0;
	int len = static_cast<int>(A.size());
	// 枚举第一个子字符串对应的初始值，第一个子字符串不能包含整个字符串
	for (int i = 0; i < len - 1 && num < INF; ++i) {
		// 循环验证当前的初始值是否符合要求
		num = num * 10 + (A[i] - '0');
		int64_t pre = num, cur = 0;
		int idx = i + 1;
		for (int j = i + 1; j < len && cur < INF; ++j) {
			// 如果上一个值为 1，那么剩余字符串对应的数值只能为 0
			if (pre == 1) {
				while (idx < len && A[idx] == '0')
					++idx;
				if (idx == len)
					return true;
				else
					break;
			}
			cur = cur * 10 + (A[j] - '0');
			// 不符合要求，提前结束
			if (cur > pre - 1)
				break;
			else if (cur == pre - 1) {
				// 已经遍历到末尾
				if (j + 1 == len)
					return true;
				pre = cur;
				cur = 0;
				idx = j + 1;
			}
		}
	}
	return false;
}

int main()
{
}

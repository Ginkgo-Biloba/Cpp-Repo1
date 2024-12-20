﻿#include "leetcode.hpp"

/* 2223. 构造字符串的总得分和

你需要从空字符串开始 构造 一个长度为 n 的字符串 s ，构造的过程为每次给当前字符串 前面 添加 一个 字符。
构造过程中得到的所有字符串编号为 1 到 n ，其中长度为 i 的字符串编号为 si 。

比方说，s = "abaca" ，s1 == "a" ，s2 == "ca" ，s3 == "aca" 依次类推。

si 的 得分 为 si 和 sn 的 最长公共前缀 的长度（注意 s == sn ）。
给你最终的字符串 s ，请你返回每一个 si 的 得分之和 。

示例 1：
输入：s = "babab"
输出：9
解释：
s1 == "b" ，最长公共前缀是 "b" ，得分为 1 。
s2 == "ab" ，没有公共前缀，得分为 0 。
s3 == "bab" ，最长公共前缀为 "bab" ，得分为 3 。
s4 == "abab" ，没有公共前缀，得分为 0 。
s5 == "babab" ，最长公共前缀为 "babab" ，得分为 5 。
得分和为 1 + 0 + 3 + 0 + 5 = 9 ，所以我们返回 9 。

示例 2 ：
输入：s = "azbazbzaz"
输出：14
解释：
s2 == "az" ，最长公共前缀为 "az" ，得分为 2 。
s6 == "azbzazb" ，最长公共前缀为 "azb" ，得分为 3 。
s9 == "azbazbzaz" ，最长公共前缀为 "azbazbzaz" ，得分为 9 。
其他 si 得分均为 0 。
得分和为 2 + 3 + 9 = 14 ，所以我们返回 14 。

提示：
  1 <= s.length <= 10^5
  s 只包含小写英文字母。
*/

/* https://leetcode.com/problems/sum-of-scores-of-built-strings/solutions/1914743/lps-kmp-vs-z-function/
Let's use "bababbababb" as the example . LPS and count arrays are as follows:
  [0, 0, 1, 2, 3, 1, 2, 3, 4, 5, 6]
  [0, 0, 1, 1, 2, 1, 1, 2, 2, 3, 2]
Indeed, the letter b in position 8 appears in 3 prefixes: bababb, bab and b. Letter b in position 9 appears in bababb and b.
*/
// 抄的
long long sumScores(string s)
{
	int n = static_cast<int>(s.size());
	vector<int> lps(n);
	for (int i = 1, k = 0; i < n; ++i) {
		while (k > 0 && s[k] != s[i])
			k = max(0, lps[k - 1]);
		k += s[k] == s[i];
		lps[i] = k;
	}
	vector<int> cnt;
	for (int i : lps)
		cnt.push_back(i == 0 ? 0 : cnt[i - 1] + 1);
	long long ans = n;
	for (int i = 0; i < n; ++i)
		ans += cnt[i];
	return ans;
}

int main()
{
	ToOut(sumScores("babab"));
	ToOut(sumScores("azbazbzaz"));
}

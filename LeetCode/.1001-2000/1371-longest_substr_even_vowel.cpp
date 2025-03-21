﻿#include "leetcode.hpp"

/* 1371. 每个元音包含偶数次的最长子字符串

给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。

示例 1：
输入：s = "eleetminicoworoep"
输出：13
解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。

示例 2：
输入：s = "leetcodeisgreat"
输出：5
解释：最长子字符串是 "leetc" ，其中包含 2 个 e 。

示例 3：
输入：s = "bcbcbc"
输出：6
解释：这个示例中，字符串 "bcbcbc" 本身就是最长的，因为所有的元音 a，e，i，o，u 都出现了 0 次。

提示：
  1 <= s.length <= 5 x 10^5
  s 只包含小写英文字母。
*/

// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/discuss/531840/JavaC%2B%2BPython-One-Pass
// 抄的
int findTheLongestSubstring(string s)
{
	int len = static_cast<int>(s.size());
	int ans = 0, cur = 0;
	vector<int> idx(128, -1);
	idx['a'] = 0;
	idx['e'] = 1;
	idx['i'] = 2;
	idx['o'] = 3;
	idx['u'] = 4;
	unordered_map<int, int> M;
	M.emplace(0, -1);
	for (int i = 0; i < len; ++i) {
		cur ^= (1 << (idx[s[i]] + 1)) >> 1;
		auto it = M.find(cur);
		if (it == M.end())
			M.emplace(cur, i);
		else
			ans = max(ans, i - it->second);
	}
	return ans;
}

int main()
{
	ToOut(findTheLongestSubstring("eleetminicoworoep"));
	ToOut(findTheLongestSubstring("leetcodeisgreat"));
	ToOut(findTheLongestSubstring("bcbcbc"));
	ToOut(findTheLongestSubstring(""));
}

﻿#include "leetcode.hpp"

/* 828. 独特字符串

如果一个字符在字符串 S 中有且仅有出现一次，那么我们称其为独特字符。

例如，在字符串 S = "LETTER" 中，"L" 和 "R" 可以被称为独特字符。

我们再定义 UNIQ(S) 作为字符串 S 中独特字符的个数。

那么，在 S = "LETTER" 中， UNIQ("LETTER") =  2。

对于给定字符串 S，计算其所有非空子串的独特字符的个数（即 UNIQ(substring)）之和。

如果在 S 的不同位置上出现两个甚至多个相同的子串，那么我们认为这些子串是不同的。

考虑到答案可能会非常大，规定返回格式为：结果 mod 10 ^ 9 + 7。


示例 1:
输入: "ABC"
输出: 10
解释:
  所有可能的子串为："A","B","C","AB","BC" 和 "ABC"。
  其中，每一个子串都由独特字符构成。
  所以其长度总和为：1 + 1 + 1 + 2 + 2 + 3 = 10

示例 2:
输入: "ABA"
输出: 8
解释: 除了子串 UNIQ('ABA') = 1，其余与示例1相同。

说明: 0 <= S.length <= 10000。
*/

// https://leetcode.com/problems/unique-letter-string/discuss/128952/One-pass-O(N)-Straight-Forward
// 抄的
int uniqueLetterString(string S)
{
	int const Mod = static_cast<int>(1e9 + 7);
	int len = static_cast<int>(S.length());
	// 记住每个字符最后两次出现的位置
	int pos[26][2], sum = 0;
	memset(pos, 0xff, sizeof(pos));

	for (int i = 0; i < len; ++i) {
		int c = S[i] - 'A';
		int s = (i - pos[c][1]) * (pos[c][1] - pos[c][0]);
		sum = (sum + s) % Mod;
		pos[c][0] = pos[c][1];
		pos[c][1] = i;
	}

	for (int i = 0; i < 26; ++i) {
		int s = (len - pos[i][1]) * (pos[i][1] - pos[i][0]);
		sum = (sum + s) % Mod;
	}
	return sum;
}

int main()
{
	ToOut(uniqueLetterString("ABA"));
	ToOut(uniqueLetterString("ABC"));
	ToOut(uniqueLetterString("ABACA"));
}

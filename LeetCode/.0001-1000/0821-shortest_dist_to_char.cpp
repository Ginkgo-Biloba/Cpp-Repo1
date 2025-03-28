﻿#include "leetcode.hpp"

/* 821. 字符的最短距离

给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。

示例 1:
输入: S = "loveleetcode", C = 'e'
输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

说明:
  字符串 S 的长度范围为 [1, 10000]。
  C 是一个单字符，且保证是字符串 S 里的字符。
  S 和 C 中的所有字母均为小写字母。
*/

vector<int> shortestToChar(string S, char C)
{
	int len = static_cast<int>(S.size());
	int E;
	vector<int> D(len);

	E = -len;
	for (int i = 0; i < len; ++i) {
		if (S[i] == C) {
			E = i;
			D[i] = 0;
		} else
			D[i] = i - E;
	}

	E = len * 2;
	for (int i = len - 1; i >= 0; --i) {
		if (S[i] == C) {
			E = i;
			D[i] = 0;
		} else
			D[i] = std::min(D[i], E - i);
	}

	return D;
}

int main()
{
	ToOut(shortestToChar("loveleetcode", 'e'));
}

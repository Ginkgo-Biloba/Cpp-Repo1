﻿#include "leetcode.hpp"

/* 459. 重复的子字符串

给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:
输入: "abab"
输出: True
解释: 可由子字符串 "ab" 重复两次构成。

示例 2:
输入: "aba"
输出: False

示例 3:
输入: "abcabcabcabc"
输出: True
解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
*/

// https://leetcode.com/problems/repeated-substring-pattern/discuss/94334/Easy-python-solution-with-explaination
// 抄的
bool repeatedSubstringPattern(string const& s)
{
	string t = s.substr(1);
	size_t len = t.size();
	t.reserve(len * 2);
	for (size_t i = 0; i < len; ++i)
		t.push_back(s[i]);

	return t.find(s) != string::npos;
}

int main()
{
	ToOut(repeatedSubstringPattern("abcabcabc"));
}
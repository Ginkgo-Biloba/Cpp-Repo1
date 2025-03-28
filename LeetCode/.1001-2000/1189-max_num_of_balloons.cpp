﻿#include "leetcode.hpp"

/* 1189. “气球” 的最大数量

给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。

字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。

示例 1：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/14/1536_ex1_upd.jpeg
输入：text = "nlaebolko"
输出：1

示例 2：
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/14/1536_ex2_upd.jpeg
输入：text = "loonbalxballpoon"
输出：2

示例 3：
输入：text = "leetcode"
输出：0

提示：
  1 <= text.length <= 10^4
  text 全部由小写英文字母组成
*/

int maxNumberOfBalloons(string text)
{
	int T[128] = {0}, n = INT_MAX;
	for (char t : text)
		T[static_cast<int>(t)] += 1;
	n = min(n, T['a']);
	n = min(n, T['b']);
	n = min(n, T['n']);
	n = min(n, T['l'] / 2);
	n = min(n, T['o'] / 2);
	return n;
}

int main()
{
	ToOut(maxNumberOfBalloons("nlaebolko"));
	ToOut(maxNumberOfBalloons("loonbalxballpoon"));
	ToOut(maxNumberOfBalloons("leetcode"));
}

﻿#include "leetcode.hpp"

/* 481. 神奇字符串

神奇的字符串 S 只包含 '1' 和 '2'，并遵守以下规则：

字符串 S 是神奇的，因为串联字符 '1' 和 '2' 的连续出现次数会生成字符串 S 本身。

字符串 S 的前几个元素如下：S = “1221121221221121122 ......”

如果我们将 S 中连续的 1 和 2 进行分组，它将变成：

1 22 11 2 1 22 1 22 11 2 11 22 ......

并且每个组中 '1' 或 '2' 的出现次数分别是：

1 2 2 1 1 2 1 2 2 1 2 2 ......

你可以看到上面的出现次数就是 S 本身。

给定一个整数 N 作为输入，返回神奇字符串 S 中前 N 个数字中的 '1' 的数目。
注意：N 不会超过 100,000。

示例：
输入：6
输出：3
解释：神奇字符串 S 的前 6 个元素是 “12211”，它包含三个 1，因此返回 3。
*/

int magicalString(int n)
{
	if (n < 4)
		return (n != 0);

	int i = 2, len = 3;
	int val = 2;
	string m("122");
	m.reserve(n + 2);

	for (; len < n; ++i) {
		val = (val & 1) + 1;
		char c = static_cast<char>(val + '0');
		int curlen = m[i] - '0';
		len += curlen;
		for (; curlen > 0; --curlen)
			m.push_back(c);
	}

	val = i = 0;
	for (; i < n; ++i)
		val += (m[i] == '1');
	return val;
}

int main()
{
	ToOut(magicalString(60));
}

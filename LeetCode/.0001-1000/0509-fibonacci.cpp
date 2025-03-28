﻿#include "leetcode.hpp"

/* 509. 斐波那契数

斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.

给定 N，计算 F(N)。

示例 1：
输入：2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1.

提示：
    0 ≤ N ≤ 30
*/

int fib(int N)
{
	int ary[2] = {0, 1};
	if (N < 2)
		return ary[N];
	for (int n = 1; n < N; ++n) {
		int t = ary[0] + ary[1];
		ary[0] = ary[1];
		ary[1] = t;
	}
	return ary[1];
}

int main()
{
	ToOut(fib(2));
}

﻿#include "leetcode.hpp"

/* 1287. 有序数组中出现次数超过25%的元素

给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。

请你找到并返回这个整数

示例：
输入：arr = [1,2,2,6,6,6,6,7,10]
输出：6

提示：
  1 <= arr.length <= 10^4
  0 <= arr[i] <= 10^5
*/

int findSpecialInteger(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	int h = 0, i = 0;
	while (h < len) {
		i = h + 1;
		while ((i < len) && (A[h] == A[i]))
			++i;
		if (4 * (i - h) > len)
			return A[h];
		h = i;
	}
	return A[len - 1];
}

int main()
{
}

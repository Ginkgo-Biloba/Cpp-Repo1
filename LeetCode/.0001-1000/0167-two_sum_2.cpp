﻿#include "leetcode.hpp"

/* 167. 两数之和 II - 输入有序数组

给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:
  返回的下标值（index1 和 index2）不是从零开始的。
  你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

示例:
输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
*/

vector<int> twoSum(
	vector<int> const& A, int dst)
{
	int len = static_cast<int>(A.size());
	vector<int> r = {0, len - 1};
	while (r[0] < r[1]) {
		int t = A[r[0]] + A[r[1]];
		if (t < dst)
			r[0] += 1;
		else if (t > dst)
			r[1] -= 1;
		else
			break;
	}
	r[0] += 1;
	r[1] += 1;
	return r;
}

int main()
{
	ToOut(twoSum({2, 7, 11, 15}, 9));
}

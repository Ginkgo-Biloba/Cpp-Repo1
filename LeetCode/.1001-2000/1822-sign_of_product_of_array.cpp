﻿#include "leetcode.hpp"

/* 1822. 数组元素积的符号

已知函数 signFunc(x) 将会根据 x 的正负返回特定值：
  如果 x 是正数，返回 1 。
  如果 x 是负数，返回 -1 。
  如果 x 是等于 0 ，返回 0 。

给你一个整数数组 nums 。
令 product 为数组 nums 中所有元素值的乘积。

返回 signFunc(product) 。

示例 1：
输入：nums = [-1,-2,-3,-4,3,2,1]
输出：1
解释：数组中所有值的乘积是 144 ，且 signFunc(144) = 1

示例 2：
输入：nums = [1,5,0,2,-3]
输出：0
解释：数组中所有值的乘积是 0 ，且 signFunc(0) = 0

示例 3：
输入：nums = [-1,1,-1,1,-1]
输出：-1
解释：数组中所有值的乘积是 -1 ，且 signFunc(-1) = -1

提示：
  1 <= nums.length <= 1000
  -100 <= nums[i] <= 100
*/

int arraySign(vector<int>& A)
{
	int p = 1;
	for (int i : A)
		p *= (i < 0 ? -1 : i > 0 ? 1
														 : 0);
	return p;
}

int main()
{
}

﻿#include "leetcode.hpp"

/* 922. 按奇偶排序数组 II

给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。

示例：
输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。

提示：
  2 <= A.length <= 20000
  A.length % 2 == 0
  0 <= A[i] <= 1000
*/

vector<int> sortArrayByParityII(vector<int>& A)
{
	int len = static_cast<int>(A.size());
	int e = 0, o = 1;
	while (true) {
		while ((e < len) && !(A[e] & 1))
			e += 2;
		while ((o < len) && (A[o] & 1))
			o += 2;
		if (e < len && o < len)
			std::swap(A[e], A[o]);
		else
			break;
	}
	return A;
}

int main()
{
	vector<int>
		a = {4, 2, 5, 7},
		b = {2, 3, 1, 1, 4, 0, 0, 4, 3, 3};
	ToOut(sortArrayByParityII(a));
	ToOut(sortArrayByParityII(b));
}

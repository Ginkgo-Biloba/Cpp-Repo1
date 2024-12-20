﻿#include "leetcode.hpp"

/* 2170. 使数组变成交替数组的最少操作数

给你一个下标从 0 开始的数组 nums ，该数组由 n 个正整数组成。

如果满足下述条件，则数组 nums 是一个 交替数组 ：

    nums[i - 2] == nums[i] ，其中 2 <= i <= n - 1 。
    nums[i - 1] != nums[i] ，其中 1 <= i <= n - 1 。

在一步 操作 中，你可以选择下标 i 并将 nums[i] 更改 为 任一 正整数。

返回使数组变成交替数组的 最少操作数 。


示例 1：
输入：nums = [3,1,3,2,4,3]
输出：3
解释：
使数组变成交替数组的方法之一是将该数组转换为 [3,1,3,1,3,1] 。
在这种情况下，操作数为 3 。
可以证明，操作数少于 3 的情况下，无法使数组变成交替数组。

示例 2：
输入：nums = [1,2,2,2,2]
输出：2
解释：
使数组变成交替数组的方法之一是将该数组转换为 [1,2,1,2,1].
在这种情况下，操作数为 2 。
注意，数组不能转换成 [2,2,2,2,2] 。因为在这种情况下，nums[0] == nums[1]，不满足交替数组的条件。

提示：
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^5
*/

auto frequent(vector<int> const& A, int start)
{
	typedef pair<int, int> elem;
	int n = static_cast<int>(A.size());
	map<int, int> M;
	for (int i = start; i < n; i += 2)
		M[A[i]] += 1;
	vector<elem> ret = {{-1, 0}, {-2, 0}};
	for (auto& it : M)
		ret.emplace_back(it);
	std::sort(ret.begin(), ret.end(), [](elem& a, elem& b) { return a.second > b.second; });
	return ret;
}

int minimumOperations(vector<int> const& A)
{
	int n = static_cast<int>(A.size());
	auto even = frequent(A, 0), odd = frequent(A, 1);
	if (even[0].first != odd[0].first)
		return n - even[0].second - odd[0].second;
	else
		return n - max(even[0].second + odd[1].second, even[1].second + odd[0].second);
}

int main()
{
	ToOut(minimumOperations({3, 1, 3, 2, 4, 3}));
	ToOut(minimumOperations({1, 2, 2, 2, 2}));
}

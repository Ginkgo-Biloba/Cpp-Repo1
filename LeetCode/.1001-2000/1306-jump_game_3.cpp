﻿#include "leetcode.hpp"

/* 1306. 跳跃游戏 III

这里有一个非负整数数组 arr，你最开始位于该数组的起始下标 start 处。
当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i - arr[i]。

请你判断自己是否能够跳到对应元素值为 0 的 任意 下标处。

注意，不管是什么情况下，你都无法跳到数组之外。

示例 1：
输入：arr = [4,2,3,0,3,1,2], start = 5
输出：true
解释：
到达值为 0 的下标 3 有以下可能方案：
下标 5 -> 下标 4 -> 下标 1 -> 下标 3
下标 5 -> 下标 6 -> 下标 4 -> 下标 1 -> 下标 3

示例 2：
输入：arr = [4,2,3,0,3,1,2], start = 0
输出：true
解释：
到达值为 0 的下标 3 有以下可能方案：
下标 0 -> 下标 4 -> 下标 1 -> 下标 3

示例 3：
输入：arr = [3,0,2,1,2], start = 2
输出：false
解释：无法到达值为 0 的下标 1 处。

提示：
  1 <= arr.length <= 5 * 10^4
  0 <= arr[i] < arr.length
  0 <= start < arr.length
*/

bool canReach(vector<int>& A, int start)
{
	if (A[start] == 0)
		return true;
	unsigned len = static_cast<unsigned>(A.size());
	vector<char> reached(len);
	vector<int> current, nextpos;
	current.push_back(start);
	reached[start] = 1;
	while (!current.empty()) {
		nextpos.clear();
		for (int cur : current) {
			int i0 = cur + A[cur];
			int i1 = cur - A[cur];
			if ((static_cast<unsigned>(i0) < len)
				&& !reached[i0]) {
				if (A[i0] == 0)
					return true;
				nextpos.push_back(i0);
				reached[i0] = 1;
			}
			if ((static_cast<unsigned>(i1) < len)
				&& !reached[i1]) {
				if (A[i1] == 0)
					return true;
				nextpos.push_back(i1);
				reached[i1] = 1;
			}
		}
		nextpos.swap(current);
	}
	return false;
}

int main()
{
	vector<int>
		a = {4, 2, 3, 0, 3, 1, 2},
		b = {4, 2, 3, 0, 3, 1, 2},
		c = {3, 0, 2, 1, 2};
	ToOut(canReach(a, 5));
	ToOut(canReach(b, 0));
	ToOut(canReach(c, 2));
}

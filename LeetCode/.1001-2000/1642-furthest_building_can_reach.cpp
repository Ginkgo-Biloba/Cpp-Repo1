﻿#include "leetcode.hpp"

/* 1642. 可以到达的最远建筑

给你一个整数数组 heights ，表示建筑物的高度。
另有一些砖块 bricks 和梯子 ladders 。

你从建筑物 0 开始旅程，不断向后面的建筑物移动，期间可能会用到砖块或梯子。

当从建筑物 i 移动到建筑物 i+1（下标 从 0 开始 ）时：
  如果当前建筑物的高度 大于或等于 下一建筑物的高度，则不需要梯子或砖块
  如果当前建筑的高度 小于 下一个建筑的高度，您可以使用 一架梯子 或 (h[i+1] - h[i]) 个砖块

如果以最佳方式使用给定的梯子和砖块，返回你可以到达的最远建筑物的下标（下标 从 0 开始 ）。

示例 1：
https://assets.leetcode.com/uploads/2020/10/27/q4.gif
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/31/q4.gif
输入：heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
输出：4
解释：从建筑物 0 出发，你可以按此方案完成旅程：
- 不使用砖块或梯子到达建筑物 1 ，因为 4 >= 2
- 使用 5 个砖块到达建筑物 2 。你必须使用砖块或梯子，因为 2 < 7
- 不使用砖块或梯子到达建筑物 3 ，因为 7 >= 6
- 使用唯一的梯子到达建筑物 4 。你必须使用砖块或梯子，因为 6 < 9
无法越过建筑物 4 ，因为没有更多砖块或梯子。

示例 2：
输入：heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
输出：7

示例 3：
输入：heights = [14,3,19,3], bricks = 17, ladders = 0
输出：3

提示：
  1 <= heights.length <= 10^5
  1 <= heights[i] <= 10^6
  0 <= bricks <= 10^9
  0 <= ladders <= heights.length
*/

int furthestBuilding(vector<int>& heights, int bricks, int ladders)
{
	int len = static_cast<int>(heights.size());
	priority_queue<int> Q;
	for (int i = 1; i < len; ++i) {
		int d = heights[i - 1] - heights[i];
		if (d >= 0)
			continue;
		if (ladders > 0) {
			--ladders;
			Q.push(d);
			continue;
		}
		if (Q.size() && d < Q.top()) {
			Q.push(d);
			d = Q.top();
			Q.pop();
		}
		bricks += d;
		if (bricks < 0)
			return i - 1;
	}
	return len - 1;
}

int main()
{
	vector<int>
		a = {4, 2, 7, 6, 9, 14, 12},
		b = {4, 12, 2, 7, 3, 18, 20, 3, 19},
		c = {14, 3, 19, 3};
	ToOut(furthestBuilding(a, 5, 1));
	ToOut(furthestBuilding(b, 10, 2));
	ToOut(furthestBuilding(c, 17, 0));
}

﻿#include "leetcode.hpp"

/* 1155. 掷骰子的N种方法

这里有 d 个一样的骰子，每个骰子上都有 f 个面，分别标号为 1, 2, ..., f。

我们约定：掷骰子的得到总点数为各骰子面朝上的数字的总和。

如果需要掷出的总点数为 target，请你计算出有多少种不同的组合情况（所有的组合情况总共有 f^d 种），模 10^9 + 7 后返回。

示例 1：
输入：d = 1, f = 6, target = 3
输出：1

示例 2：
输入：d = 2, f = 6, target = 7
输出：6

示例 3：
输入：d = 2, f = 5, target = 10
输出：1

示例 4：
输入：d = 1, f = 2, target = 3
输出：0

示例 5：
输入：d = 30, f = 30, target = 500
输出：222616187

提示：
  1 <= d, f <= 30
  1 <= target <= 1000
*/

int numRollsToTarget(int d, int f, int target)
{
	int const Mod = static_cast<int>(1e9 + 7);
	vector<int> dp(target + 1), buf(target + 1);
	size_t szdp = sizeof(int) * (target + 1);
	dp[0] = 1;

	for (; d > 0; --d) {
		memset(buf.data(), 0, szdp);
		for (int i = 1; i <= f; ++i)
			for (int k = i; k <= target; ++k)
				buf[k] = (buf[k] + dp[k - i]) % Mod;
		buf.swap(dp);
	}

	return dp[target];
}

int main()
{
	ToOut(numRollsToTarget(1, 6, 3));
	ToOut(numRollsToTarget(2, 6, 7));
	ToOut(numRollsToTarget(2, 5, 10));
	ToOut(numRollsToTarget(1, 2, 3));
	ToOut(numRollsToTarget(30, 30, 500));
}

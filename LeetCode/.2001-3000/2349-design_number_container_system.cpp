﻿#include "leetcode.hpp"

/* 2349. 设计数字容器系统

设计一个数字容器系统，可以实现以下功能：

  在系统中给定下标处 插入 或者 替换 一个数字。
  返回 系统中给定数字的最小下标。

请你实现一个 NumberContainers 类：

  NumberContainers() 初始化数字容器系统。
  void change(int index, int number) 在下标 index 处填入 number 。如果该下标 index 处已经有数字了，那么用 number 替换该数字。
  int find(int number) 返回给定数字 number 在系统中的最小下标。如果系统中没有 number ，那么返回 -1 。

示例：
输入：
["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
[[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
输出：
[null, -1, null, null, null, null, 1, null, 2]

解释：
NumberContainers nc = new NumberContainers();
nc.find(10); // 没有数字 10 ，所以返回 -1 。
nc.change(2, 10); // 容器中下标为 2 处填入数字 10 。
nc.change(1, 10); // 容器中下标为 1 处填入数字 10 。
nc.change(3, 10); // 容器中下标为 3 处填入数字 10 。
nc.change(5, 10); // 容器中下标为 5 处填入数字 10 。
nc.find(10); // 数字 10 所在的下标为 1 ，2 ，3 和 5 。因为最小下标为 1 ，所以返回 1 。
nc.change(1, 20); // 容器中下标为 1 处填入数字 20 。注意，下标 1 处之前为 10 ，现在被替换为 20 。
nc.find(10); // 数字 10 所在下标为 2 ，3 和 5 。最小下标为 2 ，所以返回 2 。

提示：
  1 <= index, number <= 10^9
  调用 change 和 find 的 总次数 不超过 10^5 次。
*/

class NumberContainers {
	unordered_map<int, int> i2v;
	unordered_map<int, set<int>> v2i;

public:
	NumberContainers() { }

	void change(int index, int number)
	{
		int val = i2v[index];
		if (val == number) return;
		i2v[index] = number;
		v2i[number].insert(index);
		if (val > 0) {
			v2i[val].erase(index);
			if (v2i[val].empty())
				v2i.erase(val);
		}
	}

	int find(int number)
	{
		auto it = v2i.find(number);
		if (it == v2i.end() || it->second.empty())
			return -1;
		return *it->second.begin();
	}
};

int main()
{
	NumberContainers c;
	ToOut(c.find(10));
	c.change(2, 10);
	c.change(1, 10);
	c.change(3, 10);
	c.change(5, 10);
	ToOut(c.find(10));
	c.change(1, 20);
	ToOut(c.find(10));
}

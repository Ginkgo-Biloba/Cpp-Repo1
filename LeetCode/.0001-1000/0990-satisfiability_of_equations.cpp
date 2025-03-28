﻿#include "leetcode.hpp"

/* 990. 等式方程的可满足性

给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。

示例 1：
输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。

示例 2：
输出：["b==a","a==b"]
输入：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。

示例 3：
输入：["a==b","b==c","a==c"]
输出：true

示例 4：
输入：["a==b","b!=c","c==a"]
输出：false

示例 5：
输入：["c==c","b==d","x!=z"]
输出：true

提示：
  1 <= equations.length <= 500
  equations[i].length == 4
  equations[i][0] 和 equations[i][3] 是小写字母
  equations[i][1] 要么是 '='，要么是 '!'
  equations[i][2] 是 '='
*/

class Solution {
	int p[26];
	vector<int> buf;

	int findpar(int i)
	{
		if (p[i] != i) {
			buf.clear();
			while (p[i] != i) {
				buf.push_back(i);
				i = p[i];
			}
			for (int x : buf)
				p[x] = i;
		}
		return i;
	}

	void unipar(int x, int y)
	{
		x = findpar(x);
		y = findpar(y);
		if (x < y)
			p[y] = x;
		else
			p[x] = y;
	}

public:
	bool equationsPossible(vector<string>& equations)
	{
		buf.reserve(26);
		for (int i = 0; i < 26; ++i)
			p[i] = i;
		for (string const& s : equations) {
			if (s[1] == '=')
				unipar(s[0] - 'a', s[3] - 'a');
		}
		for (string const& s : equations)
			if (s[1] == '!') {
				int x = findpar(s[0] - 'a');
				int y = findpar(s[3] - 'a');
				if (x == y)
					return false;
			}
		return true;
	}
};

int main()
{
	vector<string>
		a = {"a==b", "b!=a"},
		b = {"b==a", "a==b"},
		c = {"a==b", "b==c", "a==c"},
		d = {"a==b", "b!=c", "c==a"},
		e = {"c==c", "b==d", "x!=z"};
	Solution s;
	ToOut(s.equationsPossible(a));
	ToOut(s.equationsPossible(b));
	ToOut(s.equationsPossible(c));
	ToOut(s.equationsPossible(d));
	ToOut(s.equationsPossible(e));
}

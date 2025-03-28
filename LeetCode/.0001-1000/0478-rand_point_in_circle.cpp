﻿#include "leetcode.hpp"

/* 478. 在圆内随机生成点

给定圆的半径和圆心的 x、y 坐标，写一个在圆中产生均匀随机点的函数 randPoint 。

说明:
    输入值和输出值都将是浮点数。
    圆的半径和圆心的 x、y 坐标将作为参数传递给类的构造函数。
    圆周上的点也认为是在圆中。
    randPoint 返回一个包含随机点的x坐标和y坐标的大小为2的数组。

示例 1：
输入:
["Solution","randPoint","randPoint","randPoint"]
[[1,0,0],[],[],[]]
输出: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]

示例 2：
输入:
["Solution","randPoint","randPoint","randPoint"]
[[10,5,-7.5],[],[],[]]
输出: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]

输入语法说明：

输入是两个列表：调用成员函数名和调用的参数。Solution 的构造函数有三个参数，圆的半径、圆心的 x 坐标、圆心的 y 坐标。randPoint 没有参数。输入参数是一个列表，即使参数为空，也会输入一个 [] 空列表。
*/

static double const U2D = 1.0 / UINT_MAX;
static double const PI2 = 2.0 * 3.1415926535897932384626433;
class Solution {
	std::mt19937 mt;
	double R, X, Y;

public:
	Solution(double radius, double x_center, double y_center)
	{
		R = radius;
		X = x_center;
		Y = y_center;
	}

	vector<double> randPoint()
	{
		vector<double> p(2U);
		double rho = std::sqrt(mt() * U2D) * R;
		double alpha = mt() * U2D * PI2;
		p[0] = X + rho * std::cos(alpha);
		p[1] = Y + rho * std::sin(alpha);
		return p;
	}
};

int main()
{
	Solution s(10, 5, -7.5);
	vector<double> p;
	p = s.randPoint();
	printf("(%.5f, %.5f)\n", p[0], p[1]);
	p = s.randPoint();
	printf("(%.5f, %.5f)\n", p[0], p[1]);
	p = s.randPoint();
	printf("(%.5f, %.5f)\n", p[0], p[1]);
	p = s.randPoint();
	printf("(%.5f, %.5f)\n", p[0], p[1]);
}

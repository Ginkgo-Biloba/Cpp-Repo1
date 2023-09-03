
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::array;
using std::deque;
using std::list;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::priority_queue;
using std::set;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

template <typename T>
T const& toString(T const& x) { return x; }

template <typename T>
string toString(vector<T> const& A)
{
	static std::ostringstream oss;
	size_t len = A.size();
	oss.str("");
	oss << std::boolalpha << "[";
	// oss << "(" << len << ")[";
	for (size_t i = 0; i != len; ++i)
	{
		oss << toString(A[i]);
		if (i + 1 != len)
			oss << ",";
	}
	oss << "]";
	return oss.str();
}

#define ToOut(x) \
	std::cout << std::boolalpha << #x " = " << toString(x) << std::endl;

#if defined _MSC_VER
inline unsigned __builtin_popcount(unsigned n)
{
	return __popcnt(n);
	// n = n - ((n >> 1) & 0x55555555);
	// n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	// n = (n + (n >> 4)) & 0x0f0f0f0f;
	// n = (n * 0x1010101) >> 24;
	// return n;
}
#endif

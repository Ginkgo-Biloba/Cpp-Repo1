
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
#include <ctime>
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
std::ostream& operator<<(std::ostream& os, vector<T> const& A)
{
	size_t len = A.size();
	os << "[";
	// oss << "(" << len << ")[";
	for (size_t i = 0; i != len; ++i) {
		os << A[i];
		if (i + 1 != len)
			os << ",";
	}
	os << "]";
	return os;
}

#define ToOut(x) \
	std::cout << std::boolalpha << #x " = " << x << std::endl

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode()
		: val(0), left(nullptr), right(nullptr) { }
	TreeNode(int x)
		: val(x), left(nullptr), right(nullptr) { }
	TreeNode(int x, TreeNode* l, TreeNode* r)
		: val(x), left(l), right(r) { }
};

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
};

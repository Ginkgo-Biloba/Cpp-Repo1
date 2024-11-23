#include "leetcode.hpp"

int adds(int a, int b)
{
	if (a > 0)
		return (b > INT_MAX - a) ? INT_MAX : (a + b);
	else
		return (b < INT_MIN - a) ? INT_MIN : (a + b);
}

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
};

class SegTree {
	vector<int> sum;
	int len;

	int lowbit(int i)
	{
		return i & (-i);
	}

public:
	SegTree(int size)
	{
		len = size + 1;
		sum.resize(len);
	}

	void update(int i, int x)
	{
		++i;
		assert(i < len);
		for (; i < len; i += lowbit(i))
			sum[i] += x;
	}

	int get(int i)
	{
		// 需要 +1 要不 0 那里退不出去循环
		++i;
		assert(i < len);
		int r = 0;
		for (; i > 0; i -= lowbit(i))
			r += sum[i];
		return r;
	}
};

template <typename Tp,
	size_t fixed_size = (4096 + sizeof(Tp) - 1) / sizeof(Tp)>
class AutoBuffer {
	Tp buf[fixed_size];

public:
	Tp* ptr;
	size_t size;

	void allocate(size_t _size)
	{
		if (_size <= size)
			return;
		deallocate();
		size = _size;
		if (_size > fixed_size)
			ptr = new Tp[_size];
	}
	void deallocate()
	{
		if (ptr == buf)
			return;
		delete[] ptr;
		ptr = buf;
		size = fixed_size;
	}
	AutoBuffer()
	{
		ptr = buf;
		size = fixed_size;
	};
	AutoBuffer(size_t _size)
	{
		ptr = buf;
		size = fixed_size;
		allocate(_size);
	}
	~AutoBuffer()
	{
		deallocate();
	};
};

int main() { }

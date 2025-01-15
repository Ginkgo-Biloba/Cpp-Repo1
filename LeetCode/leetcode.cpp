#include "leetcode.hpp"

int adds(int a, int b)
{
	if (a > 0)
		return (b > INT_MAX - a) ? INT_MAX : (a + b);
	else
		return (b < INT_MIN - a) ? INT_MIN : (a + b);
}

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

int popcount(unsigned n)
{
	n = n - ((n >> 1) & 0x55555555u);
	n = (n & 0x33333333u) + ((n >> 2) & 0x33333333u);
	n = (n + (n >> 4)) & 0x0f0f0f0fu;
	n = (n * 0x1010101u) >> 24;
	return static_cast<int>(n);
}

// \[([^\[\]]+?)\]
// {$1}
int main() { }

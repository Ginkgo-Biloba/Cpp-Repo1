﻿#include "leetcode.hpp"

/* 843. 猜猜这个单词

这个问题是 LeetCode 平台新增的交互式问题 。

我们给出了一个由一些独特的单词组成的单词列表，每个单词都是 6 个字母长，并且这个列表中的一个单词将被选作秘密。

你可以调用 master.guess(word) 来猜单词。
你所猜的单词应当是存在于原列表并且由 6 个小写字母组成的类型字符串。

此函数将会返回一个整型数字，表示你的猜测与秘密单词的准确匹配（值和位置同时匹配）的数目。
此外，如果你的猜测不在给定的单词列表中，它将返回 -1。

对于每个测试用例，你有 10 次机会来猜出这个单词。
当所有调用都结束时，如果您对 master.guess 的调用不超过 10 次，并且至少有一次猜到秘密，那么您将通过该测试用例。

除了下面示例给出的测试用例外，还会有 5 个额外的测试用例，每个单词列表中将会有 100 个单词。这些测试用例中的每个单词的字母都是从 'a' 到 'z' 中随机选取的，并且保证给定单词列表中的每个单词都是唯一的。

示例 1:
输入: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]

解释:
master.guess("aaaaaa") 返回 -1, 因为 "aaaaaa" 不在 wordlist 中.
master.guess("acckzz") 返回 6, 因为 "acckzz" 就是秘密，6个字母完全匹配。
master.guess("ccbazz") 返回 3, 因为 "ccbazz" 有 3 个匹配项。
master.guess("eiowzz") 返回 2, 因为 "eiowzz" 有 2 个匹配项。
master.guess("abcczz") 返回 4, 因为 "abcczz" 有 4 个匹配项。

我们调用了 5 次master.guess，其中一次猜到了秘密，所以我们通过了这个测试用例。

提示：任何试图绕过评判的解决方案都将导致比赛资格被取消。
*/

static int sameCount(string const& x, string const& y)
{
	int d = 0;
	for (int i = 0; i < 6; ++i)
		d += (x[i] == y[i]);
	return d;
}

// This is the Master's API interface.
// You should not implement it, or speculate about its implementation
class Master {
	bool check;
	string s;

public:
	Master(string _s)
	{
		check = false;
		s = _s;
	}

	void output()
	{
		printf("%s | ", s.c_str());
		if (check)
			puts("found");
		else
			puts("not found");
	}

	int guess(string word)
	{
		int d = sameCount(s, word);
		if (d == 6)
			check = true;
		return d;
	}
};

// https://leetcode.com/problems/guess-the-word/discuss/134251/Optimal-MinMax-Solution-(%2B-extra-challenging-test-cases)
// 抄的
class Solution {
public:
	void findSecretWord(vector<string>& wordlist, Master& master)
	{
		int len = static_cast<int>(wordlist.size());
		vector<int> cand, next;
		int hist[7];
		cand.reserve(len);
		for (int i = 0; i < len; ++i)
			cand.push_back(i);

		for (int guess = 0; (guess < 10) && (cand.size() > 1); ++guess) {
			int part = -1, minMaxDiff = INT_MAX;
			for (int i = 0; i < len; ++i) {
				memset(hist, 0, sizeof(hist));
				for (int x : cand)
					++hist[sameCount(wordlist[i], wordlist[x])];
				int curMax = *std::max_element(hist, hist + 7);
				if (curMax < minMaxDiff) {
					part = i;
					minMaxDiff = curMax;
				}
			}

			int dc = master.guess(wordlist[part]);
			if (dc == 6)
				return;

			next.clear();
			for (int x : cand) {
				if ((x != part)
					&& (sameCount(wordlist[part], wordlist[x]) == dc))
					next.push_back(x);
			}
			next.swap(cand);
		}

		master.guess(wordlist[cand[0]]);
	}
};

int main()
{
	vector<string> w = {
		"gaxckt", "trlccr", "jxwhkz", "ycbfps", "peayuf", "yiejjw", "ldzccp", "nqsjoa", "qrjasy", "pcldos", "acrtag", "buyeia", "ubmtpj", "drtclz", "zqderp", "snywek", "caoztp", "ibpghw", "evtkhl", "bhpfla", "ymqhxk", "qkvipb", "tvmued", "rvbass", "axeasm", "qolsjg", "roswcb", "vdjgxx", "bugbyv", "zipjpc", "tamszl", "osdifo", "dvxlxm", "iwmyfb", "wmnwhe", "hslnop", "nkrfwn", "puvgve", "rqsqpq", "jwoswl", "tittgf", "evqsqe", "aishiv", "pmwovj", "sorbte", "hbaczn", "coifed", "hrctvp", "vkytbw", "dizcxz", "arabol", "uywurk", "ppywdo", "resfls", "tmoliy", "etriev", "oanvlx", "wcsnzy", "loufkw", "onnwcy", "novblw", "mtxgwe", "rgrdbt", "ckolob", "kxnflb", "phonmg", "egcdab", "cykndr", "lkzobv", "ifwmwp", "jqmbib", "mypnvf", "lnrgnj", "clijwa", "kiioqr", "syzebr", "rqsmhg", "sczjmz", "hsdjfp", "mjcgvm", "ajotcx", "olgnfv", "mjyjxj", "wzgbmg", "lpcnbj", "yjjlwn", "blrogv", "bdplzs", "oxblph", "twejel", "rupapy", "euwrrz", "apiqzu", "ydcroj", "ldvzgq", "zailgu", "xgqpsr", "wxdyho", "alrplq", "brklfk"};
	Master m("hbaczn");
	Solution s;
	s.findSecretWord(w, m);
	m.output();
}

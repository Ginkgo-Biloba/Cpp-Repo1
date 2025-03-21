﻿#include "leetcode.hpp"

/* 206. 反转链表

反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

进阶:
你可以迭代或递归地反转链表。
你能否用两种方法解决这道题？
*/

ListNode* reverseList(ListNode* head)
{
	ListNode *pre = NULL, *cur;
	while (head) {
		cur = head;
		head = head->next;
		cur->next = pre;
		pre = cur;
	}
	return pre;
}

int main()
{
}

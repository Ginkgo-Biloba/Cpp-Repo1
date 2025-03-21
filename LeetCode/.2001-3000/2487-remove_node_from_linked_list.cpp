﻿#include "leetcode.hpp"

/* 2487. 从链表中移除节点

给你一个链表的头节点 head 。

移除每个右侧有一个更大数值的节点。

返回修改后链表的头节点 head 。

示例 1：
https://assets.leetcode.com/uploads/2022/10/02/drawio.png
输入：head = [5,2,13,3,8]
输出：[13,8]
解释：需要移除的节点是 5 ，2 和 3 。
- 节点 13 在节点 5 右侧。
- 节点 13 在节点 2 右侧。
- 节点 8 在节点 3 右侧。

示例 2：
输入：head = [1,1,1,1]
输出：[1,1,1,1]
解释：每个节点的值都是 1 ，所以没有需要移除的节点。

提示：
  给定列表中的节点数目在范围 [1, 10^5] 内
  1 <= Node.val <= 10^5
*/

ListNode* reverse(ListNode* head)
{
	ListNode *a = nullptr, *b = head;
	while (b) {
		ListNode* c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	return a;
}

ListNode* removeNodes(ListNode* head)
{
	head = reverse(head);
	ListNode* a = head;
	while (a->next) {
		if (a->val > a->next->val) {
			a->next = a->next->next;
		} else {
			a = a->next;
		}
	}
	return reverse(head);
}

int main()
{
	ToOut(removeNodes(buildList({5, 2, 13, 3, 8})));
	ToOut(removeNodes(buildList({1, 1, 1, 1})));
}

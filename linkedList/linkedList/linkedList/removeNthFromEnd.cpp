#include "removeNthFromEnd.h"

int removeNthFromEnd::getLength(ListNode2* p)
{
	int count = 0;
	while (p != nullptr)
	{
		count++;
		p = p->next;
	}
	return count;
}

ListNode2* removeNthFromEnd::solutionLength(ListNode2* head, int n)
{
	//方法1：计算链表长度再定位删除
	// Dummy Node: 在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），
	// 它的next指针指向链表的头节点。这样一来，我们就不需要对头节点进行特殊的判断了。

	ListNode2 *dummy = new ListNode2(0, head);
	int length = getLength(head);
	ListNode2* cur = dummy;
	for (int i = 1; i < length - n + 1; i++)
	{
		cur = cur->next;
	}
	cur->next = cur->next->next;
	ListNode2* result = dummy->next;
	delete dummy;
	return result;
}

ListNode2* removeNthFromEnd::solutionStack(ListNode2* head, int n)
{
	//方法2：用栈来求解逆序问题
	ListNode2* dummy = new ListNode2(0,head);
	stack<ListNode2*> stk;
	ListNode2* cur = dummy;

	while (cur)
	{
		stk.push(cur);
		cur = cur->next;
	}

	for (int i = 0; i < n; i++)
	{
		stk.pop();
	}
	ListNode2* prev = stk.top();
	prev->next = prev->next->next;
	ListNode2* result = dummy->next;
	return result;
}



void removeNthFromEnd::verification()
{
	ListNode2* head = nullptr;
	ListNode2* tail = nullptr;

	head = tail = new ListNode2(0);
	head->next = tail;
	tail->next = new ListNode2(1);
	tail = tail->next;
	tail->next = new ListNode2(2);
	tail = tail->next;
	tail->next = new ListNode2(3);
	tail = tail->next;
	tail->next = new ListNode2(4);
	tail = tail->next;

	//ListNode2* x = solutionLength(head, 2);
	ListNode2* x = solutionStack(head, 2);

	while (x != nullptr)
	{
		cout << x->val;
		x = x->next;
	}
}



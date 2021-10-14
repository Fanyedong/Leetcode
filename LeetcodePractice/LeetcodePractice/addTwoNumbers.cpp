#include "addTwoNumbers.h"

addTwoNumbers::addTwoNumbers()
{
}

addTwoNumbers::~addTwoNumbers()
{
}

ListNode* addTwoNumbers::addTwoNumbersSolution(ListNode* l1, ListNode* l2)
{
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	int carry = 0;
	while (l1 || l2)
	{
		int n1 = l1 ? l1->val : 0;
		int n2 = l2 ? l2->val : 0;
		int sum = n1 + n2 + carry;

		if (!head)
		{
			head = tail = new ListNode(sum % 10);
		}
		else
		{
			tail->next = new ListNode(sum % 10);
			tail = tail->next;
		}
		carry = sum / 10;

		if (l1)
		{
			l1 = l1->next;
		}
		if (l2)
		{
			l2 = l2->next;
		}
	}
	if (carry > 0)
	{
		tail->next = new ListNode(carry);
	}
	return head;
}

void addTwoNumbers::verification()
{
	/* List1: 1,2,3 */
	ListNode* head = nullptr;
	ListNode* tail = nullptr;

	head = tail = new ListNode(1);
	head->next = tail;
	tail->next = new ListNode(2);
	tail = tail->next;
	tail->next = new ListNode(3);
	tail = tail->next;

	/* List2: 4,5,6 */
	ListNode* head2 = nullptr;
	ListNode* tail2 = nullptr;

	head2 = tail2 = new ListNode(4);
	head2->next = tail;
	tail2->next = new ListNode(5);
	tail2 = tail2->next;
	tail2->next = new ListNode(6);
	tail2 = tail2->next;

	/* Result should be 5,7,9 */
	ListNode* q = nullptr;
	//q = addTwoNumbersSolution(head, head2);
	q = practice(head, head2);
	while (q)
	{
		cout << q->val;
		q = q->next;
	}
}

ListNode* addTwoNumbers::practice(ListNode* l1, ListNode* l2)
{
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	int carry = 0;

	while (l1 || l2)
	{
		int n1 = l1 ? l1->val : 0;
		int n2 = l2 ? l2->val : 0;
		int sum = n1 + n2 + carry;

		if (!head)
		{
			head = tail = new ListNode(sum % 10);
		}
		else
		{
			tail->next = new ListNode(sum % 10);
			tail = tail->next;
		}
		carry = sum / 10;
		if (l1)
		{
			l1 = l1->next;
		}
		if (l2)
		{
			l2 = l2->next;
		}
	}
	if (carry > 0)
	{
		tail->next = new ListNode(carry);
	}
	return head;
}


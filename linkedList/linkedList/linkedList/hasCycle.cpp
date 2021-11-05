#include "hasCycle.h"

bool hasCycle::solutionHash(ListNode* head)
{
	unordered_set<ListNode*> seen;
	while (head != nullptr) {
		if (seen.count(head)) {
			return true;
		}
		seen.insert(head);
		head = head->next;
	}
	return false;
}

void hasCycle::verification()
{
	/* List1: 1,2,3 */
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	ListNode* repeat = nullptr;

	head = tail = new ListNode(1);
	head->next = tail;
	tail->next = new ListNode(2);
	tail = tail->next;
	repeat = tail;
	tail->next = new ListNode(3);
	tail = tail->next;
	tail->next = repeat;
	tail = tail->next;

	 for(int i=0;i<10;i++)
	{
		cout << head->val;
		head = head->next;
	}

	//cout<<"Result:" << solutionHash(head);
	 cout << "Result:" << solutionFastAndSlowPointer(head);
}

bool hasCycle::solutionFastAndSlowPointer(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return false;
	
	ListNode* fast = head->next;
	ListNode* slow = head;
	while (slow != fast)
	{
		if (fast == nullptr || fast->next == nullptr)
			return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}


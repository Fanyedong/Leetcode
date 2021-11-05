#pragma once
#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) { }
};

class hasCycle
{
public:
	bool solutionHash(ListNode* head);
	void verification();
	bool solutionFastAndSlowPointer(ListNode* head);
};


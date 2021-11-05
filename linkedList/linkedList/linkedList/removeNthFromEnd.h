#pragma once
#include <iostream>
#include <stack>
using namespace std;

struct ListNode2 {
	int val;
	ListNode2* next;
	ListNode2() : val(0), next(nullptr) {}
	ListNode2(int x) : val(x), next(nullptr) {}
	ListNode2(int x, ListNode2* next) : val(x), next(next) {}
};

class removeNthFromEnd
{
public:
	ListNode2* solutionLength(ListNode2* head, int n);
	ListNode2* solutionStack(ListNode2* head, int n);
	int getLength(ListNode2* p);
	void verification();
};


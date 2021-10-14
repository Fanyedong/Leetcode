﻿#pragma once
#include <iostream>
using namespace std;

	/*
	给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
	请你将两个数相加，并以相同形式返回一个表示和的链表。
	你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/add-two-numbers
	*/

	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	class addTwoNumbers
	{
	public:
		addTwoNumbers();
		~addTwoNumbers();

		ListNode* addTwoNumbersSolution(ListNode* l1, ListNode* l2);

		ListNode* practice(ListNode* l1, ListNode* l2);

		void verification();
	};



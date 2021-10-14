#pragma once
#include <iostream>
#include <vector>
using namespace std;

class mergeTwoArrays
{
public:
    mergeTwoArrays();
    ~mergeTwoArrays();

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
    void showResult(vector<int>& a);
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n);
};

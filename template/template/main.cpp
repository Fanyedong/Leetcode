#include <iostream>
using namespace std;
#include "List.h"
#include "List.cpp"


int main() {
    List<int> arr;
    int a[] = { 36,24,31,27,80,98,44,66,27,91,20,62 };
    int i, n = sizeof(a) / sizeof(a[0]);
    for (i = 0; i < n; ++i)
        arr.add(a[i]);
    arr.visit();
    cin.get();
    return 0;
}
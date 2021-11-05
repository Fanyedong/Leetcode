#include <iostream>
#include <string>
#include <array>
#include <unordered_set>
#include "hasCycle.h"
#include "removeNthFromEnd.h"

int main()
{
	//std::unordered_set<std::string> myset = { "yellow","green","blue" };
	//std::array<std::string, 2> myarray = { "black","white" };
	//std::string mystring = "red";
	//std::cout << "0: ";
	//for (const std::string& x : myset) std::cout << " " << x;

	//myset.insert(mystring);  // copy insertion
	//std::cout << " 1: ";
	//for (const std::string& x : myset) std::cout << " " << x;

	//myset.insert(mystring + "dish");                 // move insertion
	//std::cout << " 2: ";
	//for (const std::string& x : myset) std::cout << " " << x;
	//
	//myset.insert(myarray.begin(), myarray.end());  // range insertion
	//std::cout << " 3: ";
	//for (const std::string& x : myset) std::cout << " " << x;
	//
	//myset.insert({ "purple","orange" });           // initializer list insertion
	//std::cout << "myset contains:";
	//for (const std::string& x : myset) std::cout << " " << x;
	//std::cout << std::endl;

	//return 0;

	removeNthFromEnd tmp;
	tmp.verification();

}
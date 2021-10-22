#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>    // string stream
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class inorderTraversal
{
public:
	vector<int> solution(TreeNode* root);
	void inorder(TreeNode* root, vector<int>& res);

	void verification();

	void output_impl(TreeNode* n, bool left, string const& indent);
	void output(TreeNode* root);
	TreeNode* initTree(vector<string>& vec);
};


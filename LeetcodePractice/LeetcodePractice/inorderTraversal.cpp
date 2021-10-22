#include "inorderTraversal.h"

vector<int> inorderTraversal::solution(TreeNode* root)
{
    vector<int> res;
    inorder(root, res);
    return res;
}

void inorderTraversal::inorder(TreeNode* root, vector<int>& res) {
    if (!root) {
        return;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

void inorderTraversal::verification()
{
	//vector<string> v;
	//string str = "1,2,3,null,null,4,5";   //示例，leetcode上测试用例粘贴此处，删去[]
	//stringstream sstr(str);
	//string buf;
	//while (getline(sstr, buf, ','))
	//{
	//	cout << buf << endl;
	//	v.push_back(buf);
	//}

	//TreeNode* root = initTree(v);
	//output(root);
}

void inorderTraversal::output_impl(TreeNode* n, bool left, string const& indent)
{
	if (n->right)
	{
		output_impl(n->right, false, indent + (left ? "|     " : "      "));
	}
	cout << indent;
	cout << (left ? '\\' : '/');
	cout << "-----";
	cout << n->val << endl;
	if (n->left)
	{
		output_impl(n->left, true, indent + (left ? "      " : "|     "));
	}
}

void inorderTraversal::output(TreeNode* root)
{
	if (root->right)
	{
		output_impl(root->right, false, "");
	}
	cout << root->val << endl;
	if (root->left)
	{
		output_impl(root->left, true, "");
	}
}

TreeNode* inorderTraversal::initTree(vector<string>& vec)
{
	queue<TreeNode*> qu;
	TreeNode* root = new TreeNode(atoi(vec[0].c_str()));
	int i = 1;
	qu.push(root);
	while (!qu.empty())
	{
		int len = qu.size();
		while (len--)
		{
			TreeNode* node = qu.front();
			qu.pop();
			if (vec[i] != "null")
			{
				node->left = new TreeNode(atoi(vec[i].c_str()));
				qu.push(node->left);
			}
			i++;
			if (i == vec.size())
				return root;
			if (vec[i] != "null")
			{
				node->right = new TreeNode(atoi(vec[i].c_str()));
				qu.push(node->right);
			}
			i++;
			if (i == vec.size())
				return root;
		}
	}
	return root;
}
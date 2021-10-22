#include "BinNode.h"
#include "BinTree.h"
#include <stdio.h>

//更新节点x高度
template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
	return x->height = 1 + max(stature(x->lc), stature(x->rc));
}

//更新高度
template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
	while (x)
	{
		updateHeight(x);
	}
}

//三种节点插入：
//（1）e当作根节点插入
template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{
	_size = 1;
	return _root = new BinNode<T>(e);
}

//（2）e作为x的左孩子插入
template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e)
{
	_size++;
	x->insertAsLC(e);
	updateHeightAbove(x);
	return x->lc;
}

//（3）e作为x的右孩子插入
template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e)
{
	_size++;
	x->insertAsRC(e);
	updateHeightAbove(x);
	return x->rc;
}

//子树接入
//将S当作节点x的左子树接入，S本身置空
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>*& S)
{
	if (x->lc = S->root)  x->lc->parent = x;
	_size += S->size;
	updateHeightAbove(x);
	S->root = NULL;
	S->size() = 0;
	release(S);
	S = NULL;
	return x;
}

//将S当作节点x的右子树接入，S本身置空
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>*& S)
{
	if (x->rc = S->root)  x->rc->parent = x;
	_size += S->size;
	updateHeightAbove(x);
	S->root = NULL;
	S->size() = 0;
	release(S);
	S = NULL;
	return x;
}

//删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x)
{
	FromParentTo(*x) = NULL;
	updateHeightAbove(x->parent);
	int n = removeAt(x);
	_size -= n;
	return n;
}
template <typename T>
static int removeAt(BinNodePosi(T) x)
{
	if (!x) return 0;
	int n = 1 + removeAt(x->lc) + removeAt(x->rc);
	release(x->data);
	release(x);
	return n;
}

template <typename T>
BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x)
{
	FromParentTo(*x) = NULL;
	updateHeightAbove(x->parent);
	BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL;
	S->_size = x->size(); _size -= S->_size; return S;
}



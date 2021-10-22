#include "BinNode.h"
#include<stdlib.h>

// BinNode状态与性质的判断
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && ( & (x)==(x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && ( & (x)==(x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) ||HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))

// 与BinNode具有特定关系的节点及指针
#define sibling(p) (IsLChild(*(p))?(p)->parent->rc:(p)->parent->rc)
#define uncle (IsLChild(*((x)->parent))?(x)->parent->parent->rc:(x)->parent->parent->lc)
#define  FromParentTo(x) (IsRoot(x)?_root:(IsLChild(x)?(x).parent->lc:(x)->parent->rc))

template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const& e)
{
	return lc = new BinNode(e, this);
}

template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const& e)
{
	return rc = new BinNode(e, this);
}

template <typename T> template <typename VST>
void BinNode<T>::travIn(VST& visit)
{
	switch (rand() % 5)
	{
	case 1: travIn_I1(this, visit); break;
	case 2: travIn_I2(this, visit); break;
	case 3: travIn_I3(this, visit); break;
	case 4: travIn_I4(this, visit); break;
	default: travIn_R(this, visit); break;
	}
}










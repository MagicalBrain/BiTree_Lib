// BiTree.cpp : 定义静态库的函数。
//

#include "pch.h"
#include "MyBiTree.h"

// TODO: 这是一个库函数示例
/*
void fnBiTree()
{
	
}
*/

//初始化二叉树函数
void InitBiTree(BiTree& T)
{
	//BiTree p;
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = NULL;
	T->lchild = NULL;
	T->rchild = NULL;
}

//构建二叉树函数
BiTree MakeBiTree(TElemType e, BiTree L, BiTree R)
{
	BiTree p = (BiTree)malloc(sizeof(BiTNode));
	if (NULL == p)
		return NULL;
	p->data = e;
	p->lchild = L;
	p->rchild = R;
	return p;
}


BiTree CreatBiTree(char* defBT, int& i)
//用先序遍历来构造二叉树，defBT为描述序列,i为defBT的位标
{
	BiTree T;
	TElemType ch;
	ch = defBT[i++];
	if ('#' == ch)
		//InitBiTree(T);  
		T = NULL;//空树
	else
	{
		T = MakeBiTree(ch, NULL, NULL);
		T->lchild = CreatBiTree(defBT, i);
		T->rchild = CreatBiTree(defBT, i);

	}
	return T;
}

BiTree CreatBiTree(int* defBT, int& i, int num)
//用先序遍历来构造二叉树，defBT为描述序列,i为defBT的位标
//先序遍历序列为int数组时调用该函数
{
	BiTree T;
	TElemType ch;
	if (i >= num)
		return NULL;
	ch = defBT[i++];
	if (0 == ch)
		//InitBiTree(T);  
		T = NULL;//空树
	else
	{
		T = MakeBiTree(ch, NULL, NULL);
		T->lchild = CreatBiTree(defBT, i, num);
		T->rchild = CreatBiTree(defBT, i, num);

	}
	return T;
}

/*------------三叉树的构造函数------------*/

TriTree MakeBiTree_3(TElemType e, TriTree L, TriTree R, TriTree P)
//TriTNode, *TriTree;
//Bi3TNode, *Bi3Tree;
{
	TriTree p = (TriTree)malloc(sizeof(TriTNode));
	if (NULL == p)
		return NULL;
	p->data = e;
	p->lchild = L;
	p->rchild = R;
	p->parent = P;
	return p;
}

TriTree CreatBiTree_3(char* defBT, int& i)
//用先序遍历来构造二叉树，defBT为描述序列,i为defBT的位标
{
	TriTree T;
	TElemType ch;
	ch = defBT[i++];
	if ('#' == ch)
		//InitBiTree(T);  
		T = NULL;//空树
	else
	{
		T = MakeBiTree_3(ch, NULL, NULL, NULL);
		T->lchild = CreatBiTree_3(defBT, i);
		if (T->lchild)
			T->lchild->parent = T;
		T->rchild = CreatBiTree_3(defBT, i);
		if (T->rchild)
			T->rchild->parent = T;
	}
	return T;
}


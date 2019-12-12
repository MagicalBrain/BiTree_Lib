#pragma once

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0

typedef int Status;

#define TElemType char
//树的结点数据域的数据类型

/*--------二叉树的链式存储的定义--------*/

typedef struct BiTNode
{
	TElemType data;
	int count;
	struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

/*--------三叉树的链式存储的定义--------*/

typedef struct TriTNode
{
	TElemType data;
	struct TriTNode* lchild, * rchild, * parent;
	int mark;
} TriTNode, * TriTree;

//初始化二叉树函数
void InitBiTree(BiTree& T);

//构建二叉树函数
BiTree MakeBiTree(TElemType e, BiTree L, BiTree R);

BiTree CreatBiTree(char* defBT, int& i);
//用先序遍历来构造二叉树，defBT为描述序列,i为defBT的位标

BiTree CreatBiTree(int* defBT, int& i, int num);
//用先序遍历来构造二叉树，defBT为描述序列,i为defBT的位标
//先序遍历序列为int数组时调用该函数

TriTree MakeBiTree_3(TElemType e, TriTree L, TriTree R, TriTree P);

TriTree CreatBiTree_3(char* defBT, int& i);
//用先序遍历来构造二叉树，defBT为描述序列,i为defBT的位标

//遍历输出函数
Status Visit(TElemType e);

Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
//visit是对结点操作的应用函数，
//先序遍历，对每个节点调用一次应用函数
//调用失败就整个函数失败

//三叉树的先序递归遍历
Status PreOrderTraverse(TriTree T, Status(*Visit)(TElemType e));
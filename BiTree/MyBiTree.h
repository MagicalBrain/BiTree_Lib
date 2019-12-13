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

Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
//中序遍历

//三叉树的中序递归遍历
Status InOrderTraverse(TriTree T, Status(*Visit)(TElemType e));

//三叉树的中序非递归遍历
void InOrder_0(TriTree PT, void(*visit)(TElemType));
/* 不使用栈，非递归中序遍历二叉树PT，  */
/* 对每个结点的元素域data调用函数visit */

Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
//后序遍历

//三叉树的后序递归遍历
Status PostOrderTraverse(TriTree T, Status(*Visit)(TElemType e));
//后序遍历

void PostOrder(TriTree T, void(*visit)(TElemType));
/* 不使用栈，非递归后序遍历二叉树T，   */
/* 对每个结点的元素域data调用函数visit */

//判断两二叉树是否相似
Status like(BiTree B1, BiTree B2);

void ExchangeSubTree(BiTree& T);
/* 将二叉树中所有结点的左、右子树相互交换 */

int Depthx(BiTree T, TElemType x);
/* 求二叉树中以值为x的结点为根的子树深度 */

/*
* 销毁二叉树函数，
* 貌似 有问题
*/
void DestroyBiTree(BiTree& T);
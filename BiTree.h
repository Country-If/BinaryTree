#pragma once
#ifndef BiTree_H_INCLUDED
#define BiTree_H_INCLUDED

/* 函数结果状态 */
typedef enum Status
{
	error,
	success
} Status;

typedef char ElemType; 

/* 二叉树结点定义 */
typedef  struct BiTNode
{
	ElemType data; //数据域
	struct BiTNode* lchild, * rchild; //指针域，二叉链表
}BiTNode, * BiTree;

/* 队列结点定义 */
typedef struct LQueueNode {
	BiTree data; //数据域
	struct LQueueNode* next; //指针域
}LQueueNode;

/* 队列定义 */
typedef struct LQueue {
	LQueueNode* front; //队头指针
	LQueueNode* rear; //队尾指针
}LQueue, * pLQueue;

/* 销毁二叉树 */
void DestroyBiTree(BiTree* T);

/* 构造二叉树 */
Status CreateBiTree(BiTree* T, char* definition);

/* 先序遍历 */
void PreOrderTraverse(BiTree T, void(*visit)(ElemType e));

/* 中序遍历 */
void InOrderTraverse(BiTree T, void(*visit)(ElemType e));

/* 后序遍历 */
void PostOrderTraverse(BiTree T, void(*visit)(ElemType e));

/* 层次遍历 */
void LevelOrderTraverse(BiTree T, void(*visit)(ElemType e));

/* 初始化空队列 */
pLQueue InitLQueue(pLQueue Q);

/* 入队 */
Status EnLQueue(pLQueue Q, BiTree node);

/* 出队 */
BiTree DeLQueue(pLQueue Q);

/* 访问结点 */
void visit(ElemType e);

/* 求二叉树的深度 */
int BiTreeDepth(BiTree T);

/* 计算叶子结点数 */
void CountLeaf(BiTree T, int* count);

/* 显示界面 */
void show(void);

/* 规范用户输入整数 */
int judge_int(void);

#endif 

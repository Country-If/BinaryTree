#include "BiTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DestroyBiTree(BiTree* T)
{
	if (*T != NULL)
	{
		DestroyBiTree(&((*T)->lchild));
		DestroyBiTree(&((*T)->rchild));
		free(*T);
	}
}

Status CreateBiTree(BiTree* T, char* definition)
{
    definition = (char*)malloc(sizeof(char));
    if (definition == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }
    *definition = getchar();
    if (*definition == '#')
    {
        *T = NULL;
        return error;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (*T == NULL)
        {
            printf("内存分配失败\n");
            system("pause");
            exit(0);
        }
        (*T)->data = *definition;
        CreateBiTree(&(*T)->lchild, definition);
        CreateBiTree(&(*T)->rchild, definition);
        return success;
    }
}

void PreOrderTraverse(BiTree T, void(*visit)(ElemType e))
{
    if (T != NULL)
    {
        visit(T->data);
        PreOrderTraverse(T->lchild, visit);
        PreOrderTraverse(T->rchild, visit);
    }
}

void InOrderTraverse(BiTree T, void(*visit)(ElemType e))
{
    if (T != NULL)
    {
        InOrderTraverse(T->lchild, visit);
        visit(T->data);
        InOrderTraverse(T->rchild, visit);
    }
}

void PostOrderTraverse(BiTree T, void(*visit)(ElemType e))
{
    if (T != NULL)
    {
        PostOrderTraverse(T->lchild, visit);
        PostOrderTraverse(T->rchild, visit);
        visit(T->data);
    }
}

pLQueue InitLQueue(pLQueue Q)
{
    Q = (pLQueue)malloc(sizeof(LQueue));
    if (Q == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }
    Q->front = Q->rear = NULL;
    return Q;
}

Status EnLQueue(pLQueue Q, BiTree node)
{
    LQueueNode* QNode = (LQueueNode*)malloc(sizeof(LQueueNode));
    if (QNode == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }
    QNode->data = (BiTree)malloc(sizeof(BiTNode));
    if (QNode->data == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }
    memcpy(QNode->data, node, sizeof(BiTNode));
    QNode->next = NULL;
    if (Q->front == NULL)
    {
        Q->front = QNode;
        Q->rear = QNode;
    }
    else
    {
        Q->rear->next = QNode;
        Q->rear = QNode;
    }
    return success;
}

BiTree DeLQueue(pLQueue Q)
{
    BiTree BNode = (BiTree)malloc(sizeof(BiTNode));
    if (BNode == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }
    LQueueNode* temp = Q->front;
    BNode = temp->data;
    if (Q->front == Q->rear)
    {
        Q->front = Q->rear = NULL;
    }
    else
    {
        Q->front = temp->next;
    }
    free(temp);
    return BNode;
}

void LevelOrderTraverse(BiTree T, void(*visit)(ElemType e))
{
    pLQueue Q = NULL;
    Q = InitLQueue(Q);
    EnLQueue(Q, T);
    while (Q->front != NULL)
    {
        BiTree BNode = (BiTree)malloc(sizeof(BiTNode));
        if (BNode == NULL)
        {
            printf("内存分配失败\n");
            system("pause");
            exit(0);
        }
        BNode = DeLQueue(Q);
        visit(BNode->data);
        if (BNode->lchild != NULL)
        {
            EnLQueue(Q, BNode->lchild);
        }
        if (BNode->rchild != NULL)
        {
            EnLQueue(Q, BNode->rchild);
        }
        free(BNode);
    }
    free(Q);
}

void visit(ElemType e)
{
    printf("%c\t", e);
}

int BiTreeDepth(BiTree T)
{
    int depthLeft, depthRight;
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        depthLeft = BiTreeDepth(T->lchild);
        depthRight = BiTreeDepth(T->rchild);
        if (depthLeft > depthRight)
        {
            return depthLeft + 1;
        }
        else
        {
            return depthRight + 1;
        }
    }
}

void CountLeaf(BiTree T, int* count)
{
    if (T != NULL)
    {
        if (T->lchild == NULL && T->rchild == NULL)
        {
            (*count)++;
        }
        CountLeaf(T->lchild, count);
        CountLeaf(T->rchild, count);
    }
}

void show(void)
{
    printf("\n\n\n");
    printf("************************************\n");
    printf("*           二叉树                 *\n");
    printf("*----------------------------------*\n");
    printf("*  1  |    构造二叉树              *\n");
    printf("*----------------------------------*\n");
    printf("*  2  |    销毁二叉树              *\n");
    printf("*----------------------------------*\n");
    printf("*  3  |    先序遍历                *\n");
    printf("*----------------------------------*\n");
    printf("*  4  |    中序遍历                *\n");
    printf("*----------------------------------*\n");
    printf("*  5  |    后序遍历                *\n");
    printf("*----------------------------------*\n");
    printf("*  6  |    层次遍历                *\n");
    printf("*----------------------------------*\n");
    printf("*  7  |    求二叉树的深度          *\n");
    printf("*----------------------------------*\n");
    printf("*  8  |    计算叶子结点数          *\n");
    printf("*----------------------------------*\n");
    printf("*  0  |    退出                    *\n");
    printf("************************************");
    printf("\n请输入对应的数字(0-8)：");
}

int judge_int(void)  //防止用户乱输入其他的字符，规范用户输入整数
{
    int len, num = 0, arg = 1;
    char word[10] = {0};
    int m, j = 1, k;
    while (j)
    {
        scanf("%s", word);
        len = strlen(word);
        for (m = 0;m < len;m++)
        {
            if (word[m] < '0' || word[m]>'9')  //检验是否有乱输入其他字符
            {
                printf("请输入整数：");
                break;
            }
            else
            {
                if (m == len - 1)
                    j = 0;
            }
        }
    }
    j = len - 1;
    for (m = 0;m < len;m++)  // 将字符重新转换为数字
    {
        for (k = 0;k < j;k++)
            arg *= 10;
        num += (word[m] - '0') * arg;
        arg = 1;
        j--;
    }
    return num;
}

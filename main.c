#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "BiTree.h"

int main(void)
{
	int choice = 0;
	BiTree T = NULL;
	char* definition = NULL;
	int isEmpty = 1;
	do
	{
		show();
		choice = judge_int();
		system("cls");
		switch (choice)
		{
		case 0: break; //跳出循环结束程序
		case 1: //构造二叉树
		{
			if (isEmpty)
			{
				getchar();
				printf("请按照前序遍历方式构建树(#表示空结点)：\n");
				if (CreateBiTree(&T, definition))
				{
					isEmpty = 0;
					printf("二叉树构造完成\n");
				}
				else
				{
					printf("二叉树构造失败\n");
				}
			}
			else
			{
				printf("二叉树非空，请先销毁二叉树\n");
			}
			break;
		}
		case 2: //销毁二叉树
		{
			if (!isEmpty)
			{
				DestroyBiTree(&T);
				isEmpty = 1;
				printf("二叉树销毁完成");
			}
			else
			{
				printf("二叉树为空，无需销毁\n");
			}
			break;
		}
		case 3: //先序遍历
		{
			if (isEmpty)
			{
				printf("二叉树为空\n");
			}
			else
			{
				PreOrderTraverse(T, visit);
			}
			break;
		}
		case 4: //中序遍历
		{
			if (isEmpty)
			{
				printf("二叉树为空\n");
			}
			else
			{
				InOrderTraverse(T, visit);
			}
			break;
		}
		case 5: //后序遍历
		{
			if (isEmpty)
			{
				printf("二叉树为空\n");
			}
			else
			{
				PostOrderTraverse(T, visit);
			}
			break;
		}
		case 6: //层次遍历
		{
			if (isEmpty)
			{
				printf("二叉树为空\n");
			}
			else
			{
				LevelOrderTraverse(T, visit);
			}
			break;
		}
		case 7: //二叉树深度
		{
			if (isEmpty)
			{
				printf("二叉树为空，深度为0\n");
			}
			else
			{
				int depth = BiTreeDepth(T);
				printf("二叉树深度为%d", depth);
			}
			break;
		}
		case 8: //叶子结点数
		{
			if (isEmpty)
			{
				printf("二叉树为空，叶子结点数为0\n");
			}
			else
			{
				int count = 0;
				CountLeaf(T, &count);
				printf("叶子结点数为%d", count);
			}
			break;
		}
		default: {
			printf("输入有误，请重新输入\n");
			break;
		}
		}
	}while (choice != 0);

	printf("\n\n\n\n\t\t班级：19级信安1班\n\n\t\t姓名：徐国涛\n\n\t\t学号：3119005436\n\n\n\n\n\n\n\n\n");
	system("pause");

	return 0;
}

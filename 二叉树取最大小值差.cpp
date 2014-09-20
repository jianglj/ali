	
/*
写一个函数，输入一个二叉树，树中每个节点存放了一个整型值，
函数返回这颗二叉树中相差最大的两个节点间的差值绝对值。注意程序效率
*/
#define NULL 0
#include "stdio.h"
#include "stdlib.h"

int max,min;

//二叉链表结点定义
typedef struct BiTNode    //二叉树的二叉链存储表示
{
int data;
struct BiTNode *lchild,*rchild; //左右孩子指针
}BiTNode,*BiTree;

// 先序建立二叉树
void CreateBiTree(BiTree &T)
{
	int a=0,i=0;
	char c[10] = "";
	scanf("%s",c);
	printf("createBitTree\n");
	if(c[0] == '#')
	{
		T = NULL;
	}
	else
	{
		if(!(T = (BiTree)malloc(sizeof(BiTNode))))
			exit(0);
		a = 0;
		while(c[i] != '\0')
		{
			a =a*10 + (c[i]-'0');
			i++;
		}
		T->data = a;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

// 先序遍历
int visit(BiTree BT)
{
  if(BT!=NULL)
	{
	  printf("%d ",BT->data);
	  if(BT->data > max)
		  max = BT->data;
	  if(BT->data < min)
		  min = BT->data;
	  visit(BT->lchild);
	  visit(BT->rchild);
	}
  return 0;
}


int main()
{
	BiTree T = NULL;
	CreateBiTree(T);
	max = T->data;
	min = T->data;

	visit(T);
	printf("\n%d",max-min);

	return 0;
}

	
/*
дһ������������һ��������������ÿ���ڵ�����һ������ֵ��
����������Ŷ�������������������ڵ��Ĳ�ֵ����ֵ��ע�����Ч��
*/
#define NULL 0
#include "stdio.h"
#include "stdlib.h"

int max,min;

//���������㶨��
typedef struct BiTNode    //�������Ķ������洢��ʾ
{
int data;
struct BiTNode *lchild,*rchild; //���Һ���ָ��
}BiTNode,*BiTree;

// ������������
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

// �������
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

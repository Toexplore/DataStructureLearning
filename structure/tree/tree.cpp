/*
**	Purpose:
**		二叉树的实现文件
**
**	Details:
**		
**
**	Author:
**		王方（ToExplore）
**
**  E-mail:
**      wangf_solar@163.com
**
**	History:
**		2013-3-12
*/

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

Status CreateBTree(BiTree btree)
{
	int data;
	scanf("%d",&data);
	if (data == -1)
	{
		btree = NULL;
	}
	else
	{
		btree = (BiTree)malloc(sizeof(BiTNode));
		btree->data = data;

		CreateBTree(btree->lchild);//构造左子树
		CreateBTree(btree->rchild);//构造右子树
	}
	
	return OK;
}

Status DestroyBTree(BiTree btree)
{
	if (btree)
	{
		DestroyBTree(btree->lchild);
		DestroyBTree(btree->rchild);
		free(btree);
		btree = NULL;
	}
	return OK;
}
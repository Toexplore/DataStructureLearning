#ifndef DATASTRUCTURE_TREE
#define DATASTRUCTURE_TREE
/*
**	Purpose:
**		树结构的数据结构声明，相关函数原型声明。
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

#include "common.h"

typedef struct BiTNode
{
	int data;  //数据域
	struct BiTNode *parent,*lchild,*rchild;  //指向双亲，左子树和由子树
}BiTNode,*BiTree;



//构造一个空的树
Status CreateBTree(BiTree btree);

//销毁一棵树
Status DestroyBTree(BiTree btree);

//添加一个孩子


//删除某个结点（子树）


//为某个结点赋值


//获得某个结点的值


//查看其双亲


//获得右堂兄结点 


//获得树的高


//获得树的根









#endif
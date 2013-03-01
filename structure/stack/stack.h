#ifndef DATASTRUCTURE_STACK

/*
**	Purpose:
**		栈数据结构的头文件。定义了栈结构以及相应的函数原型。
**
**	Details:
**		可以通过链表或数组的形式来实现栈结构。栈的内容
**		可以是任何数据结构，但在这里我们只用栈存储int型数据。
**
**	Author:
**		王方（ToExplore）
**
**  E-mail:
**      wangf_solar@163.com
**
**	History:
**		2013-3-1
*/

#include "common.h"

/*---------------------下面是用链表来实现栈结构------------------------*/

typedef struct INT_NODE
{
	int data;//这里只用来存储int型数据
	struct INT_NODE *Next; //指向下一个结点
}Int_Node,*pInt_Node;  //Int_Node等价于Struc INT_NODE，
					   //*pInt_Node等价于struct INT_NODE*


typedef struct STACK_BY_LINK
{
	pInt_Node pTop; //栈的头
	pInt_Node pBottom; //栈的底
	int length; //记录栈的长度
}StackByLink, *pStackByLink;

Status initStack(pStackByLink pStack);  //初始化
Status pushStack(pStackByLink pStack,int data);  //将data压入到栈中
Status popStack(pStackByLink pStack,int *pData);  //将栈顶结点弹出，并返回该结点的值
bool isEmpty(pStackByLink pStack);  //栈是否为空
Status clearStack(pStackByLink pStack); //清空栈，清除所有内容
Status traveserStack(pStackByLink pStack); //遍历栈
/*---------------------------------------------------------------------*/

#endif


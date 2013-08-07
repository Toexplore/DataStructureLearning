#ifndef DATASTRUCTURE_STACK

/*
**	Purpose:
**		栈数据结构的头文件。定义了栈结构以及相应的函数原型。
**
**	Details:
**		可以通过链表或数组的形式来实现栈结构。栈的内容
**		可以是任何数据结构。
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
#include "Item.h"
/*---------------------下面是用链表来实现栈结构------------------------*/

typedef struct _NODE
{
	void *data;//这里只用来存储int型数据
	struct _NODE *Next; //指向下一个结点
}Node;  
					  


typedef struct STACK_BY_LINK
{
	Node *pTop; //栈的头
	int length; //记录栈的长度
	size_t elem_size; //每个节点数据的长度，初始化时使用
}StackByLink, *pStackByLink;

Status initStack(pStackByLink pStack,size_t elem_size);  //初始化
Status pushStack(pStackByLink pStack,void *data);  //将data压入到栈中
Status popStack(pStackByLink pStack,void *pData);  //将栈顶结点弹出，并返回该结点的值
bool isEmpty(pStackByLink pStack);  //栈是否为空
Status clearStack(pStackByLink pStack); //清空栈，清除所有内容
Status traveserStack(pStackByLink pStack); //遍历栈
/*---------------------------------------------------------------------*/

#endif


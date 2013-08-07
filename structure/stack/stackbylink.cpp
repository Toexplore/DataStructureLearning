/*
**	Purpose:
**		栈的实现文件
**
**	Details:
**		使用了链表来实现通用数据类型的栈
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "stack.h"

/*
** 初始化stack，只构造一个元素，该元素大小由elem_size（字节）决定
*/
Status initStack(pStackByLink pStack,size_t elem_size)
{
	pStack->pTop = (Node*)malloc(sizeof(Node));
	if (NULL == pStack->pTop)
		return Error;	

	pStack->pTop->Next = NULL;
	pStack->length = 0;
	pStack->elem_size = elem_size;
	return OK;
}

Status pushStack(pStackByLink pStack,void *element)
{
	Node *pNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNode)
		return Error;
	
	pNode->data = (void*)malloc(pStack->elem_size);
	if (NULL == pNode->data)
		return Error;

	memcpy(pNode->data,element,pStack->elem_size);

	pNode->Next =pStack->pTop;
	pStack->pTop = pNode;	
	pStack->length++;
	return OK;
}

Status popStack(pStackByLink pStack,void *element)
{
	if (isEmpty(pStack))
		return Error;
	
	Node* pNode = pStack->pTop;
	memcpy(element,pNode->data,pStack->elem_size);
	pStack->pTop = pNode->Next;
	if (pNode->data)
		free(pNode->data);
	if (pNode)
		free(pNode);
	
	
	pStack->length--;
	return True;
}

bool isEmpty(pStackByLink pStack)
{
	if (pStack->length == 0)
		return True;

	return False;
}

Status clearStack(pStackByLink pStack)
{	
	Node* pNode = pStack->pTop;
	pStack->pTop = pNode->Next;
	while(pNode != NULL)
	{
		free(pNode->data);
		free(pNode);
		pNode = pStack->pTop;
		pStack->pTop = pNode->Next;
	}
	pStack->pTop = NULL;
	pStack->length = 0;
	return OK;
}

Status traveserStack(pStackByLink pStack)
{
	if (isEmpty(pStack))
	{
		printf("the stack is empty!!");
		return OK;
	}
	Node* pNode = pStack->pTop;	

	while(pNode != NULL)
	{
		printf("data:%d\n",pNode->data);		
		pNode = pNode->Next;
	}
	return OK;
}
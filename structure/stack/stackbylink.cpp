/*
**	Purpose:
**		栈的实现文件
**
**	Details:
**		使用了链表来实现栈
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
#include "common.h"
#include "stack.h"

Status initStack(pStackByLink pStack)
{
	pStack->pTop = (pInt_Node)malloc(sizeof(Int_Node));
	if (NULL == pStack->pTop)
	{
		return Error;
	}

	pStack->pBottom = pStack->pTop;
	pStack->pTop->Next = NULL;
	pStack->length = 0;
	return OK;
}

Status pushStack(pStackByLink pStack,int data)
{
	pInt_Node pNode = (pInt_Node)malloc(sizeof(Int_Node));
	if (NULL == pNode)
	{
		return Error;
	}
	pNode->data = data;
	pNode->Next = pStack->pTop;
	pStack->pTop = pNode;
	pStack->length++;
	return OK;
}

Status popStack(pStackByLink pStack,int *pData)
{
	if (isEmpty(pStack))
	{
		return Error;
	}
	pInt_Node pNode = pStack->pTop;
	*pData = pNode->data;
	pStack->pTop = pNode->Next;
	free(pNode);
	pStack->length--;
	return True;
}

bool isEmpty(pStackByLink pStack)
{
	if (pStack->length == 0)
	{
		return True;
	}
	return False;
}

Status clearStack(pStackByLink pStack)
{	
	pInt_Node pNode = pStack->pTop;
	pStack->pTop = pNode->Next;
	while(pNode != pStack->pBottom)
	{
		free(pNode);
		pNode = pStack->pTop;
		pStack->pTop = pNode->Next;
	}
	pStack->pTop = pStack->pBottom;
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
	pInt_Node pNode = pStack->pTop;	

	while(pNode != pStack->pBottom)
	{
		printf("data:%d\n",pNode->data);		
		pNode = pNode->Next;
	}
	return OK;
}
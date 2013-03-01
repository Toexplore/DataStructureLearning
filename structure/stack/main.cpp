/*
**	Purpose:
**		测试文件
**
**	Details:
**		对栈的数据结构进行了测试，并实现了十进制对二进制、八进制、十六进制的转换
**
**	Author:
**		王方（ToExplore）
**
**	History:
**		2013-3-1
*/

#include "stack.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

void testStack(); //测试函数
void conversion(int format);  //十进制转为其他进制,参数format表示要转换的目标进制




void main()
{
	testStack();
	conversion(2);  //将输入的数转换为2进制
	conversion(8);  //将输入的数转换为8进制
	conversion(16); //将输入的数转换为16进制
}


void testStack()
{
	pStackByLink pStack = (pStackByLink)malloc(sizeof(StackByLink));
	initStack(pStack);
	printf("length of stack: %d\n",pStack->length);
	traveserStack(pStack);

	pushStack(pStack,1);
	pushStack(pStack,2);
	pushStack(pStack,3);
	printf("length of stack: %d \n",pStack->length);
	traveserStack(pStack);

	int popNode;
	popStack(pStack,&popNode);
	printf("the pop node is: %d\n",popNode);
	traveserStack(pStack);
	printf("length of stack: %d \n",pStack->length);

	clearStack(pStack);
	traveserStack(pStack);
	printf("length of stack: %d \n",pStack->length);

	free(pStack);
}

/*
**  利用栈实现进制的转化
*/
void conversion(int format)
{
	if (format != 2 || format != 8 || format != 16)
	{
		printf("only convert to 2,8,16 fromat");
		return;
	}

	int  decimal_num;
	pStackByLink pStack = (pStackByLink)malloc(sizeof(StackByLink));
	initStack(pStack);

	printf("please enter decimal format number: ");
	
	scanf("%d",&decimal_num);
	while(decimal_num != 0)
	{
		pushStack(pStack,decimal_num%format);
		decimal_num /=format;
	}
	
	int result_num;
	if (format == 2 || format == 8)
	{
		printf("the result(%d format) is :",format);		
		while(isEmpty(pStack) == False)
		{
			popStack(pStack,&result_num);
			printf("%d",result_num);
		}
	}
	else if (format == 16)
	{
		printf("the result(%d format) is :",format);	
		while(isEmpty(pStack) == False)
		{
			popStack(pStack,&result_num);
			if (result_num == 10)
			{
				printf("A");
				continue;
			}
			else if (result_num == 11)
			{
				printf("B");
				continue;
			}
			else if (result_num == 12)
			{
				printf("C");
				continue;
			}
			else if (result_num == 13)
			{
				printf("D");
				continue;
			}
			else if (result_num == 14)
			{
				printf("E");
				continue;
			}
			else if (result_num == 15)
			{
				printf("F");
				continue;
			}
			printf("%d",result_num);
		}
	}
}
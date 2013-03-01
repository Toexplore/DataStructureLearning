/*
**	Purpose:
**		�����ļ�
**
**	Details:
**		��ջ�����ݽṹ�����˲��ԣ���ʵ����ʮ���ƶԶ����ơ��˽��ơ�ʮ�����Ƶ�ת��
**
**	Author:
**		������ToExplore��
**
**	History:
**		2013-3-1
*/

#include "stack.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

void testStack(); //���Ժ���
void conversion(int format);  //ʮ����תΪ��������,����format��ʾҪת����Ŀ�����




void main()
{
	testStack();
	conversion(2);  //���������ת��Ϊ2����
	conversion(8);  //���������ת��Ϊ8����
	conversion(16); //���������ת��Ϊ16����
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
**  ����ջʵ�ֽ��Ƶ�ת��
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
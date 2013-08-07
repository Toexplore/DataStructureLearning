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
**  E-mail:
**      wangf_solar@163.com
**
**	History:
**		2013-3-1
*/

#include "stack.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testStack(); //���Ժ���
void conversion(int format);  //ʮ����תΪ��������,����format��ʾҪת����Ŀ�����
int suffix_cal(char *expression);
char* infix2suffix(char *infix_char);


void main()
{
	char *suffix_char = infix2suffix("((2+5)*(3+7))");

	suffix_cal(suffix_char);
	if(suffix_char)
		free(suffix_char);
	testStack();
	conversion(2);  //���������ת��Ϊ2����
	conversion(8);  //���������ת��Ϊ8����
	conversion(16); //���������ת��Ϊ16����
}


/*
**����stack
*/
void testStack()
{
	int a = 0;
	pStackByLink pStack = (pStackByLink)malloc(sizeof(StackByLink));
	initStack(pStack,sizeof(int));
	printf("length of stack: %d\n",pStack->length);
	traveserStack(pStack);
	
	a = 1;
	pushStack(pStack,&a);
	a = 2;
	pushStack(pStack,&a);
	a = 3;
	pushStack(pStack,&a);
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
	initStack(pStack,sizeof(int));

	printf("please enter decimal format number: ");
	
	scanf("%d",&decimal_num);
	while(decimal_num != 0)
	{
		pushStack(pStack,(void*)(decimal_num%format));
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


/*
** �����׺���ʽ��ֵ(����)
** ��׺���ʽ��Ԫ��֮����ո񣬱�����������׺���ʽ�ĺϷ���
*/
int suffix_cal(char *expression)
{
	int length = strlen(expression);
	int i = 0,data = 0 ,data1 = 0,data2 = 0,temp_data = 0;
	pStackByLink stack = (pStackByLink)malloc(sizeof(StackByLink));
	initStack(stack,sizeof(int));
	char *expr = expression;
	for (i = 0; i < length; i++)
	{
		if (expr[i] == '+')
		{
			popStack(stack,&data1);
			popStack(stack,&data2);
			temp_data = data1 + data2;
			pushStack(stack,&temp_data);
		}
		if(expr[i] == '-')
		{
			popStack(stack,&data1);
			popStack(stack,&data2);
			temp_data = data1 - data2;
			pushStack(stack,&temp_data);
		}
		if (expr[i] == '*')
		{
			popStack(stack,&data1);
			popStack(stack,&data2);
			temp_data = data1*data2;
			pushStack(stack,&temp_data);
		}
		if (expr[i] >= '0' && expr[i] <= '9')
		{
			temp_data = expr[i]-'0';
			pushStack(stack,&temp_data);
			while (expr[++i] >= '0' && expr[i] <= '9')
			{
				popStack(stack,&data);
				data = data * 10 + expr[i] - '0';
				pushStack(stack,&data);
			}
		}
		
	}
	popStack(stack,&data);
	return data;
	
}

/*
**infix2suffix
** ��׺���ʽת��Ϊ��׺���ʽ,��Ҫ�������ͷŸú������ڴ�
**���룺
**	infix������׺���ʽ��ÿ�����������Ҫ�����ţ�
**			 ��(2+3)*(3+7)��д��((2+3)*(3+7))��
**�����
**  ��׺���ʽ��ÿ����λ֮����Ҫ�пո��������
*/
char* infix2suffix(char *infix)
{
	int length = strlen(infix); 
	char operator_char;   //���ڼ�¼������
	pStackByLink stack = (pStackByLink)malloc(sizeof(StackByLink));
	initStack(stack,sizeof(char));
	char *suffix_char = (char *)malloc(2*length);
	suffix_char[0] = '\0';  //��Ҫ���ý�β��strcat�����β��Ȼ���ڽ�β��׷��
	for (int i = 0; i < length; i++)
	{
		int j = i;
		if (infix[i] == ')')
		{
			popStack(stack,&operator_char);
			strncat(suffix_char,&operator_char,1);
		}
		if (infix[i] == '+' || infix[i] == '*')
		{
			pushStack(stack,&infix[i]);
		}
					
		while (infix[j] >= '0' && infix[j] <= '9' )
		{
			strncat(suffix_char,&infix[j],1);
			j++;
		}
		strcat(suffix_char," ");//ÿ����λ������һ���ո񣬹������������ĺ�׺
		
	}
	strncat(suffix_char,"\0",1);
	return suffix_char;
}
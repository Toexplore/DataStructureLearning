#ifndef DATASTRUCTURE_STACK

/*
**	Purpose:
**		ջ���ݽṹ��ͷ�ļ���������ջ�ṹ�Լ���Ӧ�ĺ���ԭ�͡�
**
**	Details:
**		����ͨ��������������ʽ��ʵ��ջ�ṹ��ջ������
**		�������κ����ݽṹ��������������ֻ��ջ�洢int�����ݡ�
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

#include "common.h"

/*---------------------��������������ʵ��ջ�ṹ------------------------*/

typedef struct INT_NODE
{
	int data;//����ֻ�����洢int������
	struct INT_NODE *Next; //ָ����һ�����
}Int_Node,*pInt_Node;  //Int_Node�ȼ���Struc INT_NODE��
					   //*pInt_Node�ȼ���struct INT_NODE*


typedef struct STACK_BY_LINK
{
	pInt_Node pTop; //ջ��ͷ
	pInt_Node pBottom; //ջ�ĵ�
	int length; //��¼ջ�ĳ���
}StackByLink, *pStackByLink;

Status initStack(pStackByLink pStack);  //��ʼ��
Status pushStack(pStackByLink pStack,int data);  //��dataѹ�뵽ջ��
Status popStack(pStackByLink pStack,int *pData);  //��ջ����㵯���������ظý���ֵ
bool isEmpty(pStackByLink pStack);  //ջ�Ƿ�Ϊ��
Status clearStack(pStackByLink pStack); //���ջ�������������
Status traveserStack(pStackByLink pStack); //����ջ
/*---------------------------------------------------------------------*/

#endif


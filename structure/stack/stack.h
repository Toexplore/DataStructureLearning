#ifndef DATASTRUCTURE_STACK

/*
**	Purpose:
**		ջ���ݽṹ��ͷ�ļ���������ջ�ṹ�Լ���Ӧ�ĺ���ԭ�͡�
**
**	Details:
**		����ͨ��������������ʽ��ʵ��ջ�ṹ��ջ������
**		�������κ����ݽṹ��
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
#include "Item.h"
/*---------------------��������������ʵ��ջ�ṹ------------------------*/

typedef struct _NODE
{
	void *data;//����ֻ�����洢int������
	struct _NODE *Next; //ָ����һ�����
}Node;  
					  


typedef struct STACK_BY_LINK
{
	Node *pTop; //ջ��ͷ
	int length; //��¼ջ�ĳ���
	size_t elem_size; //ÿ���ڵ����ݵĳ��ȣ���ʼ��ʱʹ��
}StackByLink, *pStackByLink;

Status initStack(pStackByLink pStack,size_t elem_size);  //��ʼ��
Status pushStack(pStackByLink pStack,void *data);  //��dataѹ�뵽ջ��
Status popStack(pStackByLink pStack,void *pData);  //��ջ����㵯���������ظý���ֵ
bool isEmpty(pStackByLink pStack);  //ջ�Ƿ�Ϊ��
Status clearStack(pStackByLink pStack); //���ջ�������������
Status traveserStack(pStackByLink pStack); //����ջ
/*---------------------------------------------------------------------*/

#endif


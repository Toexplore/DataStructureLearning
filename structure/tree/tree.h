#ifndef DATASTRUCTURE_TREE
#define DATASTRUCTURE_TREE
/*
**	Purpose:
**		���ṹ�����ݽṹ��������غ���ԭ��������
**
**	Details:
**		
**
**	Author:
**		������ToExplore��
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
	int data;  //������
	struct BiTNode *parent,*lchild,*rchild;  //ָ��˫�ף���������������
}BiTNode,*BiTree;



//����һ���յ���
Status CreateBTree(BiTree btree);

//����һ����
Status DestroyBTree(BiTree btree);

//���һ������


//ɾ��ĳ����㣨������


//Ϊĳ����㸳ֵ


//���ĳ������ֵ


//�鿴��˫��


//��������ֽ�� 


//������ĸ�


//������ĸ�









#endif
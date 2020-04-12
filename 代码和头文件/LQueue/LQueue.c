#include<stdio.h>
#include <stdlib.h>
#include<D:\�����ϰ\��ʽ����\LQueue1.h>
#include<malloc.h>
#include<string.h>


// ��ʼ������
void InitLQueue(LQueue* Q)
{
	
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)//�����ڴ�ʧ�ܣ���ֹ
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;

}

//���ٶ���
void DestoryLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))//�ж϶����Ƿ�Ϊ��
		return;
	ClearLQueue(Q);//��ն���
	free(Q->front);
	free(Q->rear);

}


//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q->front == Q->rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue* Q, void* e)
{
	//���ӿ����޷��鿴��ͷԪ�� 
	if (IsEmptyLQueue(Q) == TRUE)
		return FALSE;
	else
		memcpy(e, Q->front->next->data, type);
	if (type == sizeof(double))
		printf("%lf", *(double*)e);
	if (type == sizeof(char))
		printf("%c", *(char*)e);
	if (type == sizeof(int))
		printf("%d", *(int*)e);
	return TRUE;
}

//ȷ�����г���
int LengthLQueue(LQueue* Q)
{
	int a ;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front;
	for (a = 0; p != Q->rear; a++)
		p = p->next;
	return a;

}

//���
Status EnLQueue(LQueue* Q, void* data)
{
	Node* p = (Node*)malloc(sizeof(Node));//��p����ռ�
	if (NULL == p)//����ʧ��
		return FALSE;
	p->data = (void*)malloc(type);
	if(NULL == p->data)
		return FALSE;
	
	memcpy(p->data, data, type);//��p->data��ֵ
	free(data);
	p->next = NULL;//p��һ��Ϊ��
	//if (NULL != p->next)
	//	return FALSE;
	Q->rear->next = p;//��p��������
	Q->rear = p;//βָ��ָ��p
	(Q->length)++;//���ȼ�һ
	
	printf("��ӳɹ�!\n");
	
	return TRUE;
	
}

//����
Status DeLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))//�ж϶����Ƿ�Ϊ��
		return FALSE;
	Node* p = (Node*)malloc(sizeof(Node));//����p
	p = Q->front->next;//����һ��Ԫ�ص�ַ����p
	Q->front->next = p->next;//Q��nextָ���һ��Ԫ��
	if (NULL == Q->front->next)//�ж�Q�ĺ�һ��Ԫ���Ƿ�Ϊ��
		Q->rear = Q->front;//��Ϊ����ͷָ�����βָ��
	free(p);//�ͷ�p
	(Q->length)--;
	printf("���ӳɹ�!\n");
	return TRUE;

}

//��ն���
void ClearLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))//�ж϶����Ƿ�Ϊ��
		return;
	Node* p, * q;//��������ָ��
	Q->rear = Q->front;//��պ�Ľ����ͷָ�����βָ��
	p = Q->front->next;//p��ֵΪ��һ��Ԫ��
	while (NULL != p)//���p���ǿ� ����ִ��ѭ��
	{
		q = p;//p��ֵ��q
		p = p->next;//p����p����һ��Ԫ��
		free(q);//�ͷŵ�ԭ��p���ڴ�
	}
	free(p);//����ͷŵ�p���ڴ�
	

}

//������������
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q))
{
	if (IsEmptyLQueue(Q))//�ж϶����Ƿ�Ϊ��
		return FALSE;
	Node* p = (Node*)malloc(sizeof(Node));//��p�����ڴ�
	p = Q->front->next;//pָ���һ��Ԫ��

	while (p != NULL)//�ж�p�Ƿ�Ϊ��
	{
		(*foo)(p->data);//��ӡp
		p = p->next;//pָ����һ��
		printf("\n");
	}

	return TRUE;
}
	

//��������
void LPrint(void* q)
{
	if (type == sizeof(double))
		printf("%lf", *(double*)q);
	if (type == sizeof(char))
		printf("%c", *(char*)q);
	if (type == sizeof(int))
		printf("%d", *(int*)q);
}
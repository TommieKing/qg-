#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<D:\�����ϰ\˳�����\AQueue1.h>
#include<malloc.h>

// ��ʼ������
void InitAQueue(AQueue* Q)
{
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		Q->data[i] = (void*)malloc(sizeof(type));

	Q->rear = Q->front = 0;
	Q->length = 0;
}

//���ٶ���
void DestoryAQueue(AQueue* Q)
{
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);
	

}

//�������Ƿ�����
Status IsFullAQueue(const AQueue* Q)
{
	if ((Q->rear + 1) % MAXQUEUE == Q->front)
		return TRUE;
	else
		return FALSE;
}

//�������Ƿ�Ϊ��
Status IsEmptyAQueue(const AQueue* Q)
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
Status GetHeadAQueue(AQueue* Q, void* e)
{
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i = Q->front;
	i = (i + 1) % MAXQUEUE;
	memcpy(e, Q->data[i], type);
	return TRUE;

}

//ȷ�����г���
int LengthAQueue(AQueue* Q)
{
	
	int a = Q->length;
	return a;
	
}

//���
Status EnAQueue(AQueue* Q, void* data)
{
	//�ж϶����Ƿ��������������޷����
	
	if (IsFullAQueue(Q) == TRUE)
		return FALSE;
	//����û�����������ƶ�ָ�룬�ڲ���Ԫ��
	else
	Q->rear = (Q->rear+ 1) % MAXQUEUE;
	memcpy(Q->data[Q->rear], data, type);//��data�������
	free(data);
	(Q->length)++;
	return TRUE;

}

//����
Status DeAQueue(AQueue* Q)
{
	//���ӿ����޷����� 
	if (IsEmptyAQueue(Q) == TRUE)
		return FALSE;
	//������Ҳ�޷�����
	else if (IsFullAQueue(Q) == TRUE)
		return FALSE;
	else
	Q->front = (Q->front + 1) %MAXQUEUE;

	Q->data[Q->front] = NULL;
	(Q->length)--;
	return TRUE;

}

//��ն���
void ClearAQueue(AQueue* Q)
{	//���Ӳ�Ϊ����ͷָ��ָ����һλ������ֵΪ��
	while (IsEmptyAQueue(Q) == TRUE)
	{
		Q->front = (Q->front + 1) % MAXQUEUE;//����ָ���һλ
		Q->data[Q->front] = NULL;//���׸�ֵΪ��
		(Q->length)--;//���ȼ�һ
	}
}

//������������
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q))
{
	if (Q->front == Q->rear)//�ж��Ƿ�Ϊ��
		return FALSE;
	int i = Q->front + 1;
	while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) 
	{
		foo(Q->data[i]);
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;
	
}

//��������
void APrint(void* q)
{
	if (type == sizeof(double))
		printf("%lf", *(double*)q);
	if (type == sizeof(char))
		printf("%c", *(char*)q);
	if (type == sizeof(int))
		printf("%d", *(int*)q);
}

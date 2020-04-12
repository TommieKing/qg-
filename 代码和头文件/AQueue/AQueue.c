#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<D:\编程练习\顺序队列\AQueue1.h>
#include<malloc.h>

// 初始化队列
void InitAQueue(AQueue* Q)
{
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		Q->data[i] = (void*)malloc(sizeof(type));

	Q->rear = Q->front = 0;
	Q->length = 0;
}

//销毁队列
void DestoryAQueue(AQueue* Q)
{
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);
	

}

//检查队列是否已满
Status IsFullAQueue(const AQueue* Q)
{
	if ((Q->rear + 1) % MAXQUEUE == Q->front)
		return TRUE;
	else
		return FALSE;
}

//检查队列是否为空
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

//查看队头元素
Status GetHeadAQueue(AQueue* Q, void* e)
{
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i = Q->front;
	i = (i + 1) % MAXQUEUE;
	memcpy(e, Q->data[i], type);
	return TRUE;

}

//确定队列长度
int LengthAQueue(AQueue* Q)
{
	
	int a = Q->length;
	return a;
	
}

//入队
Status EnAQueue(AQueue* Q, void* data)
{
	//判断队列是否已满，若满则无法入队
	
	if (IsFullAQueue(Q) == TRUE)
		return FALSE;
	//队列没有满，则先移动指针，在插入元素
	else
	Q->rear = (Q->rear+ 1) % MAXQUEUE;
	memcpy(Q->data[Q->rear], data, type);//将data存入队列
	free(data);
	(Q->length)++;
	return TRUE;

}

//出队
Status DeAQueue(AQueue* Q)
{
	//若队空则无法出队 
	if (IsEmptyAQueue(Q) == TRUE)
		return FALSE;
	//若队满也无法进队
	else if (IsFullAQueue(Q) == TRUE)
		return FALSE;
	else
	Q->front = (Q->front + 1) %MAXQUEUE;

	Q->data[Q->front] = NULL;
	(Q->length)--;
	return TRUE;

}

//清空队列
void ClearAQueue(AQueue* Q)
{	//若队不为空则头指针指向下一位，并赋值为空
	while (IsEmptyAQueue(Q) == TRUE)
	{
		Q->front = (Q->front + 1) % MAXQUEUE;//队首指向后一位
		Q->data[Q->front] = NULL;//队首赋值为空
		(Q->length)--;//长度减一
	}
}

//遍历函数操作
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q))
{
	if (Q->front == Q->rear)//判断是否为空
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

//操作函数
void APrint(void* q)
{
	if (type == sizeof(double))
		printf("%lf", *(double*)q);
	if (type == sizeof(char))
		printf("%c", *(char*)q);
	if (type == sizeof(int))
		printf("%d", *(int*)q);
}

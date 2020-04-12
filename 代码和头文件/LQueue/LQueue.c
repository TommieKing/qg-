#include<stdio.h>
#include <stdlib.h>
#include<D:\编程练习\链式队列\LQueue1.h>
#include<malloc.h>
#include<string.h>


// 初始化队列
void InitLQueue(LQueue* Q)
{
	
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)//申请内存失败，终止
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;

}

//销毁队列
void DestoryLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))//判断队列是否为空
		return;
	ClearLQueue(Q);//清空队列
	free(Q->front);
	free(Q->rear);

}


//检查队列是否为空
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

//查看队头元素
Status GetHeadLQueue(LQueue* Q, void* e)
{
	//若队空则无法查看队头元素 
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

//确定队列长度
int LengthLQueue(LQueue* Q)
{
	int a ;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front;
	for (a = 0; p != Q->rear; a++)
		p = p->next;
	return a;

}

//入队
Status EnLQueue(LQueue* Q, void* data)
{
	Node* p = (Node*)malloc(sizeof(Node));//给p分配空间
	if (NULL == p)//分配失败
		return FALSE;
	p->data = (void*)malloc(type);
	if(NULL == p->data)
		return FALSE;
	
	memcpy(p->data, data, type);//给p->data赋值
	free(data);
	p->next = NULL;//p下一个为空
	//if (NULL != p->next)
	//	return FALSE;
	Q->rear->next = p;//将p链接起来
	Q->rear = p;//尾指针指向p
	(Q->length)++;//长度加一
	
	printf("入队成功!\n");
	
	return TRUE;
	
}

//出队
Status DeLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))//判断队列是否为空
		return FALSE;
	Node* p = (Node*)malloc(sizeof(Node));//定义p
	p = Q->front->next;//将第一个元素地址赋给p
	Q->front->next = p->next;//Q的next指向后一个元素
	if (NULL == Q->front->next)//判断Q的后一个元素是否为空
		Q->rear = Q->front;//若为空则头指针等于尾指针
	free(p);//释放p
	(Q->length)--;
	printf("出队成功!\n");
	return TRUE;

}

//清空队列
void ClearLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))//判断队列是否为空
		return;
	Node* p, * q;//定义两个指针
	Q->rear = Q->front;//清空后的结果，头指针等于尾指针
	p = Q->front->next;//p赋值为第一个元素
	while (NULL != p)//如果p不是空 ，则执行循环
	{
		q = p;//p赋值给q
		p = p->next;//p等于p的下一个元素
		free(q);//释放掉原先p的内存
	}
	free(p);//最后释放掉p的内存
	

}

//遍历函数操作
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q))
{
	if (IsEmptyLQueue(Q))//判断队列是否为空
		return FALSE;
	Node* p = (Node*)malloc(sizeof(Node));//给p分配内存
	p = Q->front->next;//p指向第一个元素

	while (p != NULL)//判断p是否为空
	{
		(*foo)(p->data);//打印p
		p = p->next;//p指向下一个
		printf("\n");
	}

	return TRUE;
}
	

//操作函数
void LPrint(void* q)
{
	if (type == sizeof(double))
		printf("%lf", *(double*)q);
	if (type == sizeof(char))
		printf("%c", *(char*)q);
	if (type == sizeof(int))
		printf("%d", *(int*)q);
}
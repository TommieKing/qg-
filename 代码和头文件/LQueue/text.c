#include<stdio.h>
#include <stdlib.h>
#include<D:\编程练习\链式队列\LQueue1.h>

int main()
{
	int s, n;
	int a;
	void* e ;
	void* data ;
	
	
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	printf("请输入你想入队的类型？:\n");
	printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位)\n");
	scanf_s("%d", &n);
	while (n < 1 || n>4)
	{
		printf("应输入在[1,4]之间的整数！\n请重输：");
		scanf("%d", &n);
	}
	switch (n)
	{
	case 1:
		type = sizeof(int);
		break;
	case 2:
		type = sizeof(char);
		break;
	case 3:
		type = sizeof(double);
		break;

	}
	data = (void*)malloc(sizeof(type));
	e = (void*)malloc(sizeof(type));
	while (1)
	{
		printf("******请输入您的选择******\n");
		printf("******1.初始化队列******\n");
		printf("******2.销毁队列******\n");
		printf("******4.检查队列是否为空******\n");
		printf("******5.查看队头元素******\n");
		printf("******6.确定队列长度******\n");
		printf("******7.入队******\n");
		printf("******8.出队******\n");
		printf("******9.清空队列******\n");
		printf("******10.遍历函数操作******\n");
		scanf_s("%d", &s);
		switch (s)
		{
		case 1:
			InitLQueue(Q);//调用初始化队列的函数
			break;
		case 2:
			DestoryLQueue(Q);   //调用销毁队列的函数
			break;

		case 4:
			IsEmptyLQueue(Q);//检查队列是否为空
			break;
		case 5:
			GetHeadLQueue(Q, e);//查看队头元素
			break;
		case 6:
			a = LengthLQueue(Q);//确定队列长度
			printf("长度为%d", a);
			break;
		case 7:
			printf("请输入想入队的元素：");
			if (type == sizeof(double))
			{
				data = (void*)malloc(sizeof(type));
				scanf("%lf",(double*)data);
			}
			if (type == sizeof(char))
			{
				data = (void*)malloc(sizeof(type));
				scanf("%c", (char*)data);
			}
			if (type == sizeof(int))
			{
				data = (void*)malloc(sizeof(type));
				scanf_s("%d", (int*)data);
			}
			EnLQueue(Q, data);// 入队
			
			break;
		case 8:
			DeLQueue(Q);//出队
			break;
		case 9:
			ClearLQueue(Q);//清空队列
			break;
		case 10:

			TraverseLQueue(Q, &LPrint);//遍历函数操作
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
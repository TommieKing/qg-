#include<stdio.h>
#include <stdlib.h>
#include<D:\�����ϰ\��ʽ����\LQueue1.h>

int main()
{
	int s, n;
	int a;
	void* e ;
	void* data ;
	
	
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	printf("������������ӵ����ͣ�:\n");
	printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ)\n");
	scanf_s("%d", &n);
	while (n < 1 || n>4)
	{
		printf("Ӧ������[1,4]֮���������\n�����䣺");
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
		printf("******����������ѡ��******\n");
		printf("******1.��ʼ������******\n");
		printf("******2.���ٶ���******\n");
		printf("******4.�������Ƿ�Ϊ��******\n");
		printf("******5.�鿴��ͷԪ��******\n");
		printf("******6.ȷ�����г���******\n");
		printf("******7.���******\n");
		printf("******8.����******\n");
		printf("******9.��ն���******\n");
		printf("******10.������������******\n");
		scanf_s("%d", &s);
		switch (s)
		{
		case 1:
			InitLQueue(Q);//���ó�ʼ�����еĺ���
			break;
		case 2:
			DestoryLQueue(Q);   //�������ٶ��еĺ���
			break;

		case 4:
			IsEmptyLQueue(Q);//�������Ƿ�Ϊ��
			break;
		case 5:
			GetHeadLQueue(Q, e);//�鿴��ͷԪ��
			break;
		case 6:
			a = LengthLQueue(Q);//ȷ�����г���
			printf("����Ϊ%d", a);
			break;
		case 7:
			printf("����������ӵ�Ԫ�أ�");
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
			EnLQueue(Q, data);// ���
			
			break;
		case 8:
			DeLQueue(Q);//����
			break;
		case 9:
			ClearLQueue(Q);//��ն���
			break;
		case 10:

			TraverseLQueue(Q, &LPrint);//������������
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
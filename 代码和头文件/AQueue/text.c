#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<C:\Users\king\Desktop\QGѵ��Ӫ��������ѵ\�����ͷ�ļ�\AQueue\AQueue.h>
int main()
{
	int s, a,n;
	void* e ;
	AQueue* Q ;
	void* data ;
	Q = (AQueue*)malloc(sizeof(AQueue));
	printf("������������ӵ����ͣ�:\n");
	printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ)\n");
	scanf("%d", &n);
	while (n < 1 || n>4)
	{
		printf("Ӧ������[1,4]֮���������\n�����䣺");
		scanf("%d", &n);
	}
	switch (n)
	{
	case 1:
		type = sizeof(int);
	case 2:
		type = sizeof(char);
	case 3:
		type = sizeof(double);

	}
	data = (void*)malloc(sizeof(type));
	e = (void*)malloc(sizeof(type));
	while (1)
	{
		printf("******����������ѡ��******\n");
		printf("******1.��ʼ������******\n");
		printf("******2.���ٶ���******\n");
		printf("******3.�������Ƿ�����******\n");
		printf("******4.�������Ƿ�Ϊ��******\n");
		printf("******5.�鿴��ͷԪ��******\n");
		printf("******6.ȷ�����г���******\n");
		printf("******7.���******\n");
		printf("******8.����******\n");
		printf("******9.��ն���******\n");
		printf("******10.������������******\n");
		scanf("%d", &s);
		switch (s)
		{
		case 1:
			InitAQueue(Q);//���ó�ʼ�����еĺ���
			break;
		case 2:
			DestoryAQueue(Q);   //�������ٶ��еĺ���
			break;
		case 3:
			IsFullAQueue(Q);//�������Ƿ�����
			break;
		case 4:
			IsEmptyAQueue(Q);//�������Ƿ�Ϊ��
			break;
		case 5:
			GetHeadAQueue(Q, e);//�鿴��ͷԪ��
			break;
		case 6:
			a = LengthAQueue(Q);//ȷ�����г���
			printf("����Ϊ%d", a);
			break;
		case 7:
			printf("����������ӵ�Ԫ�أ�");
			if (type == sizeof(double))
			{
				data = (void*)malloc(sizeof(type));
				scanf("%lf", (double*)data);
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
			EnAQueue(Q, data);// ���
			break;
		case 8:
			DeAQueue(Q);//����
			break;
		case 9:
			ClearAQueue(Q);//��ն���
			break;
		case 10:

			TraverseAQueue(Q, &APrint);//������������
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
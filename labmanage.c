#include "labmanage.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

int  menu(void)
{
	printf("����Աϵͳv1.0\n");
	printf("���ã�����Ա��\n");
	printf("* * * * * * * * * *\n");
	printf("ѡ���ܣ�\n");
	printf("0.��   ��   ��   ��\n");
	printf("1.�� �� �� Ϣ �� ��\n");
	printf("2.�� Ϣ �� �� �� ��\n");
	printf("3.��   Ϣ   ��   ѯ\n");
	printf("4.��   Ϣ   ��   ��\n");
	printf("5.��   Ϣ   ͳ   ��\n");
	printf("6.ϵ   ͳ   ά   ��\n");
	printf("* * * * * * * * * *\n");
	printf("���룺");

	int option = 0;
	scanf_s("%d", &option);

	return option;
}

void fun1(List1*list1, List2*list2, List3*list3)
{
	printf("* * * * * * * * * *\n");
	printf("������Ϣ�������\n");
	printf("1.��  Ϣ  ¼  ��\n");
	printf("2.��  Ϣ  ɾ  ��\n");
	printf("�����룺");
	
	int op = 0;
	scanf_s("%d", &op);

	switch (op)
	{
	case 1:
	{
		printf("* * * * * * * * * *\n");
		printf("���ͣ�\n1.ʵ���豸\t2.ʵ��Ա\t3.ʵ����");
		int a = 0;
		printf("\n�����룺");
		scanf_s("%d", &a);
		if (a == 1)
		{
			system("cls");
			
			fentry_ep(&list1);
		}

		else if (a == 2)
		{
			system("cls");
			
			fentry_te(&list2);
		}

		else if (a == 3)
		{
			system("cls");
			
			fentry_ro(&list3);
		}break;
	}
	case 2:
	{
		printf("* * * * * * * * * *\n");
		printf("���ͣ�\n1.ʵ���豸\t2.ʵ��Ա\t3.ʵ����");
		printf("\n���룺");
		int b = 0;
		scanf("%d", &b);

		switch (b)
		{
		case 1:
		{
			system("cls");
		
			fremove_ep(&list1);
		}break;
		case 2:
		{
			system("cls");
		
			fremove_te(&list2);
		}break;
		case 3:
		{
			system("cls");
			
			fremove_ro(&list3);
		}break;
		}
	}
	}
}

void fentry_ep(List1* list)
{
	//�����ڵ�
	Node1* node1 = malloc(sizeof(Node1));
	if (!node1)
	{
		printf("malloc failed!\n");
		return;
	}
	node1->next = NULL;

	printf("* * * * * * * * * *\n");
	printf("�밴Ҫ�����룺\n");

	//����ʵ���豸��Ϣ
	printf("��ţ�\n");
	scanf_s("%d", &node1->ep.id);
	printf("���ࣺ\n");
	scanf("%s",node1->ep.ca);
	printf("���ƣ�\n");
	scanf("%s",node1->ep.name);
	printf("����ʵ���ң�\n");
	scanf_s("%d",&node1->ep.room);
	printf("�۸�\n");
	scanf_s("%d",&node1->ep.price);
	printf("״̬��1.���� / 0.�𻵣�\n");
	scanf_s("%d",&node1->ep.state);
	printf("����ʱ�䣺\n");
	scanf_s("%d",&node1->ep.pdate);
	printf("ʹ�����ޣ�\n");
	scanf_s("%d",&node1->ep.limit);
    
	//���뵽������
	node1->next = list->front;
	list->front = node1;
	list->size++;

	//���ļ�
	FILE* fp = fopen("equipments.data", "ab");
	if (!fp)
	{
		perror("file open failed");
		return;
	}

	//д���豸��Ϣ
	Node1* curnode = list->front;
	while (curnode != NULL)
	{
		fwrite(&curnode->ep, sizeof(equipment), 1, fp);
		curnode = curnode->next;
	}

	//�ر��ļ�
	fclose(fp);
}

void fentry_te(List2* list)
{
	//�����ڵ�
	Node2* node2 = malloc(sizeof(Node2));
	if (!node2)
	{
		printf("malloc failed!\n");
		return;
	}
	node2->next = NULL;

	printf("* * * * * * * * * *\n");
	printf("�밴Ҫ�����룺\n");

	//����ʵ��Ա��Ϣ
	printf("ʵ��Աid��\n");
	scanf_s("%d", &node2->te.id);
	printf("��ʵ��Ա����ʵ����������\n");
	int i = 0;
	scanf_s("%d", &i);
	for (int j = 0; j <i; j++)
	{
		printf("ʵ����%d��",j+1);
		scanf_s("%d", node2->te.room + j);
	}

	//���뵽������
	node2->next = list->front;
	list->front = node2;
	list->size++;

	//���ļ�
	FILE* fp = fopen("testers.data", "ab");
	if (!fp)
	{
		perror("file open failed");
		return;
	}

	//д���豸��Ϣ
	Node2* curnode = list->front;
	while (curnode != NULL)
	{
		fwrite(&curnode->te, sizeof(tester), 1, fp);
		curnode = curnode->next;
	}

	//�ر��ļ�
	fclose(fp);
}

void fentry_ro(List3* list)
{
	//�����ڵ�
	Node3* node3 = malloc(sizeof(Node3));
	if (!node3)
	{
		printf("malloc failed!\n");
		return;
	}
	node3->next = NULL;

	printf("* * * * * * * * * *\n");
	printf("�밴Ҫ�����룺\n");

	//����ʵ������Ϣ
	printf("ʵ���ң�\n");
	scanf_s("%d", &node3->ro);

	//���뵽������
	node3->next = list->front;
	list->front = node3;
	list->size++;

	//���ļ�
	FILE* fp = fopen("rooms.data", "ab");
	if (!fp)
	{
		perror("file open failed");
		return;
	}

	//д���豸��Ϣ
	Node3* curnode = list->front;
	fwrite(&curnode->ro, sizeof(room), 1, fp);

	 
	//�ر��ļ�
	fclose(fp);
}

void fremove_ep(List1* list)
{
	//��ȡ�豸��Ϣ
	//���ļ�
	FILE* fp = fopen("equipments.data", "wb");
	if (!fp)
	{
		perror("file open failed");
		return;
	}
	//��ȡ
	while (!feof(fp))
	{
		//�����ڵ�
		Node1* node = malloc(sizeof(Node1));
		if (!node)
		{
			printf("malloc failed!\n");
			return;
		}
		node->next = NULL;

		fread(&node->ep, sizeof(equipment), 1, fp);

		//���뵽������
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	fclose(fp); 
	remove("equipments.data"); 
	
	//����ɾ�����豸
	int buffer;
	printf("������Ҫɾ�����豸��ţ�\n");
	scanf("%d", &buffer);

	Node1* curnode = list->front;
	Node1* prenode = NULL;
	while (curnode != NULL)
	{
		if (curnode->ep.id== buffer)
			break;

		prenode = curnode;
		curnode = curnode->next;
	}

	//�Ƿ��ҵ�
	if (curnode)
	{
		//���Ҫɾ����һ���ڵ�
		if (prenode == NULL)
		{
			list->front = curnode->next;
			free(curnode);
		}
		else
		{
			prenode->next = curnode->next; 
			free(curnode); 
		}
	}

	curnode=NULL;

	//д���豸��Ϣ
	FILE* nfp = fopen("equipments.data", "ab");
	curnode = list->front;
	fwrite(&curnode->ep ,sizeof(equipment), 1, nfp);
	//�ر��ļ�
	fclose(nfp);
}

void fremove_te(List2*list)
{
	//��ȡ�豸��Ϣ
	//���ļ�
	FILE* fp = fopen("testers.data", "rb");
	if (!fp)
	{
		perror("file open failed");
		return;
	}
	//��ȡ
	while (!feof(fp))
	{
		//�����ڵ�
		Node2* node = malloc(sizeof(Node2));
		if (!node)
		{
			printf("malloc failed!\n");
			return;
		}
		node->next = NULL;

		fread(&node->te, sizeof(tester), 1, fp);

		//���뵽������
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	fclose(fp);
	remove("testers.data");

	//����ɾ�����豸
	int buffer;
	printf("������Ҫɾ����ʵ��Ա��ţ�\n");
	scanf("%d", &buffer);

	Node2* curnode = list->front;
	Node2* prenode = NULL;
	while (curnode != NULL)
	{
		if (curnode->te.id == buffer)
			break;

		prenode = curnode;
		curnode = curnode->next;
	}

	//�Ƿ��ҵ�
	if (curnode)
	{
		//���Ҫɾ����һ���ڵ�
		if (prenode == NULL)
		{
			list->front = curnode->next;
			free(curnode);
		}
		else
		{
			prenode->next = curnode->next;
			free(curnode);
		}
	}

	curnode = NULL;

	//д���豸��Ϣ
	FILE* nfp = fopen("testers.data", "wb");
	curnode = list->front;
	fwrite(&curnode->te, sizeof(room), 1, nfp);
	//�ر��ļ�
	fclose(nfp);
}

void fremove_ro(List3*list)
{
	//��ȡ�豸��Ϣ
	//���ļ�
	FILE* fp = fopen("rooms.data", "rb");
	if (!fp)
	{
		perror("file open failed");
		return;
	}
	//��ȡ
	while (!feof(fp))
	{
		//�����ڵ�
		Node3* node = malloc(sizeof(Node3));
		if (!node)
		{
			printf("malloc failed!\n");
			return;
		}
		node->next = NULL;

		fread(&node->ro, sizeof(room), 1, fp);

		//���뵽������
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	fclose(fp);
	remove("rooms.data");

	//����ɾ�����豸
	int buffer;
	printf("������Ҫɾ����ʵ���ұ�ţ�\n");
	scanf("%d", &buffer);
	Node3* curnode = list->front;
	Node3* prenode = NULL;
	while (curnode != NULL)
	{
		if (curnode->ro == buffer)
			break;

		prenode = curnode;
		curnode = curnode->next;
	}

	//�Ƿ��ҵ�
	if (curnode)
	{
		//���Ҫɾ����һ���ڵ�
		if (prenode == NULL)
		{
			list->front = curnode->next;
			free(curnode);
		}
		else
		{
			prenode->next = curnode->next;
			free(curnode);
		}
	}

	curnode = NULL;

	//д���豸��Ϣ
	FILE* nfp = fopen("rooms.data", " wb");
     curnode = list->front;
	fwrite(&curnode->ro, sizeof(room), 1, nfp);

	//�ر��ļ�
	fclose(nfp);
}

void fun2(List1* list1, List2* list2, List3* list3)
{
	printf("* * * * * * * * * *\n");
	printf("��������Ҫ�޸ĵ�����\n1.ʵ���豸    2.ʵ��Ա\n");
	printf("���룺");
	int op = 0;
	scanf("%d", &op);
	switch(op)
	{
	case 1:
	{
		system("cls");
		alter_ep(list1);
	}
	case 2:
	{
		system("cls");
		alter_te(list2);
	}
	}
}

void alter_ep(List1* list)
{
	//��ȡ�豸��Ϣ
	//���ļ�
	FILE* fp = fopen("equipments.data", "wb");
	if (!fp)
	{
		perror("file open failed");
		return;
	}
	//��ȡ
	while (!feof(fp))
	{
		//�����ڵ�
		Node1* node = malloc(sizeof(Node1));
		if (!node)
		{
			printf("malloc failed!\n");
			return;
		}
		node->next = NULL;

		fread(&node->ep, sizeof(equipment), 1, fp);

		//���뵽������
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	fclose(fp); 
	remove("equipments.data");

	//�����޸ĵ��豸
	int buffer;
	printf("������Ҫ�޸ĵ��豸��ţ�\n");
	scanf("%d", &buffer);

	Node1* curnode = list->front;
	while (curnode != NULL)
	{
		if (curnode->ep.id == buffer)
		{
			printf("������Ҫ�޸ĵ��豸���� ���� ����ʵ���� �۸� ״̬ �������� ʹ������");
			scanf("%s %s %d %d %d %d %d", &curnode->ep.ca, &curnode->ep.name, &curnode->ep.room, &curnode->ep.price, &curnode->ep.state, &curnode->ep.pdate, &curnode->ep.limit);
			printf("�޸ĳɹ�����");
			break;
		}
		curnode = curnode->next;
	}

	//д���豸��Ϣ
	FILE* nfp = fopen("equipments.data", "ab"); 
	curnode = list->front; 
	fwrite(&curnode->ep, sizeof(equipment), 1, nfp); 
	//�ر��ļ� 
	fclose(nfp); 
}

void alter_te(List2* list)
{
	//��ȡ�豸��Ϣ
	//���ļ�
	FILE* fp = fopen("testers.data", "rb");
	if (!fp)
	{
		perror("file open failed");
		return;
	}
	//��ȡ
	while (!feof(fp))
	{
		//�����ڵ�
		Node2* node = malloc(sizeof(Node2));
		if (!node)
		{
			printf("malloc failed!\n");
			return;
		}
		node->next = NULL;

		fread(&node->te, sizeof(tester), 1, fp);

		//���뵽������
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	fclose(fp);
	remove("testers.data");

	//�����޸ĵ��豸
	int buffer;
	printf("������Ҫ�޸ĵ�ʵ��Ա��ţ�\n");
	scanf("%d", &buffer);

	Node2* curnode = list->front;
	while (curnode != NULL)
	{
		if (curnode->te.id == buffer)
		{
			printf("������Ҫ�޸ĵ�ʵ��Ա��Ϣ������ʵ��������");
			scanf("%d", &curnode->te.room);
			printf("�޸ĳɹ�����");
			break;
		}
		curnode = curnode->next;
	}

	//д���豸��Ϣ
	FILE* nfp = fopen("testers.data", "ab");
	curnode = list->front; 
	fwrite(&curnode->te, sizeof(tester), 1, nfp); 
	//�ر��ļ�
	fclose(nfp);
} 

#include "labmanage.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

int  menu(void)
{
	printf("管理员系统v1.0\n");
	printf("您好，管理员！\n");
	printf("* * * * * * * * * *\n");
	printf("选择功能：\n");
	printf("0.退   出   程   序\n");
	printf("1.基 本 信 息 管 理\n");
	printf("2.信 息 调 整 管 理\n");
	printf("3.信   息   查   询\n");
	printf("4.信   息   排   序\n");
	printf("5.信   息   统   计\n");
	printf("6.系   统   维   护\n");
	printf("* * * * * * * * * *\n");
	printf("输入：");

	int option = 0;
	scanf_s("%d", &option);

	return option;
}

void fun1(List1*list1, List2*list2, List3*list3)
{
	printf("* * * * * * * * * *\n");
	printf("基本信息管理界面\n");
	printf("1.信  息  录  入\n");
	printf("2.信  息  删  除\n");
	printf("请输入：");
	
	int op = 0;
	scanf_s("%d", &op);

	switch (op)
	{
	case 1:
	{
		printf("* * * * * * * * * *\n");
		printf("类型：\n1.实验设备\t2.实验员\t3.实验室");
		int a = 0;
		printf("\n请输入：");
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
		printf("类型：\n1.实验设备\t2.实验员\t3.实验室");
		printf("\n输入：");
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
	//创建节点
	Node1* node1 = malloc(sizeof(Node1));
	if (!node1)
	{
		printf("malloc failed!\n");
		return;
	}
	node1->next = NULL;

	printf("* * * * * * * * * *\n");
	printf("请按要求输入：\n");

	//输入实验设备信息
	printf("编号：\n");
	scanf_s("%d", &node1->ep.id);
	printf("种类：\n");
	scanf("%s",node1->ep.ca);
	printf("名称：\n");
	scanf("%s",node1->ep.name);
	printf("所在实验室：\n");
	scanf_s("%d",&node1->ep.room);
	printf("价格：\n");
	scanf_s("%d",&node1->ep.price);
	printf("状态（1.良好 / 0.损坏）\n");
	scanf_s("%d",&node1->ep.state);
	printf("购进时间：\n");
	scanf_s("%d",&node1->ep.pdate);
	printf("使用年限：\n");
	scanf_s("%d",&node1->ep.limit);
    
	//插入到链表中
	node1->next = list->front;
	list->front = node1;
	list->size++;

	//打开文件
	FILE* fp = fopen("equipments.data", "ab");
	if (!fp)
	{
		perror("file open failed");
		return;
	}

	//写入设备信息
	Node1* curnode = list->front;
	while (curnode != NULL)
	{
		fwrite(&curnode->ep, sizeof(equipment), 1, fp);
		curnode = curnode->next;
	}

	//关闭文件
	fclose(fp);
}

void fentry_te(List2* list)
{
	//创建节点
	Node2* node2 = malloc(sizeof(Node2));
	if (!node2)
	{
		printf("malloc failed!\n");
		return;
	}
	node2->next = NULL;

	printf("* * * * * * * * * *\n");
	printf("请按要求输入：\n");

	//输入实验员信息
	printf("实验员id：\n");
	scanf_s("%d", &node2->te.id);
	printf("该实验员管理实验室数量：\n");
	int i = 0;
	scanf_s("%d", &i);
	for (int j = 0; j <i; j++)
	{
		printf("实验室%d：",j+1);
		scanf_s("%d", node2->te.room + j);
	}

	//插入到链表中
	node2->next = list->front;
	list->front = node2;
	list->size++;

	//打开文件
	FILE* fp = fopen("testers.data", "ab");
	if (!fp)
	{
		perror("file open failed");
		return;
	}

	//写入设备信息
	Node2* curnode = list->front;
	while (curnode != NULL)
	{
		fwrite(&curnode->te, sizeof(tester), 1, fp);
		curnode = curnode->next;
	}

	//关闭文件
	fclose(fp);
}

void fentry_ro(List3* list)
{
	//创建节点
	Node3* node3 = malloc(sizeof(Node3));
	if (!node3)
	{
		printf("malloc failed!\n");
		return;
	}
	node3->next = NULL;

	printf("* * * * * * * * * *\n");
	printf("请按要求输入：\n");

	//输入实验室信息
	printf("实验室：\n");
	scanf_s("%d", &node3->ro);

	//插入到链表中
	node3->next = list->front;
	list->front = node3;
	list->size++;

	//打开文件
	FILE* fp = fopen("rooms.data", "ab");
	if (!fp)
	{
		perror("file open failed");
		return;
	}

	//写入设备信息
	Node3* curnode = list->front;
	fwrite(&curnode->ro, sizeof(room), 1, fp);

	 
	//关闭文件
	fclose(fp);
}

void fremove_ep(List1* list)
{
	//读取设备信息
	//打开文件
	FILE* fp = fopen("equipments.data", "wb");
	if (!fp)
	{
		perror("file open failed");
		return;
	}
	//读取
	while (!feof(fp))
	{
		//创建节点
		Node1* node = malloc(sizeof(Node1));
		if (!node)
		{
			printf("malloc failed!\n");
			return;
		}
		node->next = NULL;

		fread(&node->ep, sizeof(equipment), 1, fp);

		//插入到链表中
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	fclose(fp); 
	remove("equipments.data"); 
	
	//查找删除的设备
	int buffer;
	printf("请输入要删除的设备编号：\n");
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

	//是否找到
	if (curnode)
	{
		//如果要删除第一个节点
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

	//写入设备信息
	FILE* nfp = fopen("equipments.data", "ab");
	curnode = list->front;
	fwrite(&curnode->ep ,sizeof(equipment), 1, nfp);
	//关闭文件
	fclose(nfp);
}

void fremove_te(List2*list)
{
	//读取设备信息
	//打开文件
	FILE* fp = fopen("testers.data", "rb");
	if (!fp)
	{
		perror("file open failed");
		return;
	}
	//读取
	while (!feof(fp))
	{
		//创建节点
		Node2* node = malloc(sizeof(Node2));
		if (!node)
		{
			printf("malloc failed!\n");
			return;
		}
		node->next = NULL;

		fread(&node->te, sizeof(tester), 1, fp);

		//插入到链表中
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	fclose(fp);
	remove("testers.data");

	//查找删除的设备
	int buffer;
	printf("请输入要删除的实验员编号：\n");
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

	//是否找到
	if (curnode)
	{
		//如果要删除第一个节点
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

	//写入设备信息
	FILE* nfp = fopen("testers.data", "wb");
	curnode = list->front;
	fwrite(&curnode->te, sizeof(room), 1, nfp);
	//关闭文件
	fclose(nfp);
}

void fremove_ro(List3*list)
{
	//读取设备信息
	//打开文件
	FILE* fp = fopen("rooms.data", "rb");
	if (!fp)
	{
		perror("file open failed");
		return;
	}
	//读取
	while (!feof(fp))
	{
		//创建节点
		Node3* node = malloc(sizeof(Node3));
		if (!node)
		{
			printf("malloc failed!\n");
			return;
		}
		node->next = NULL;

		fread(&node->ro, sizeof(room), 1, fp);

		//插入到链表中
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	fclose(fp);
	remove("rooms.data");

	//查找删除的设备
	int buffer;
	printf("请输入要删除的实验室编号：\n");
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

	//是否找到
	if (curnode)
	{
		//如果要删除第一个节点
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

	//写入设备信息
	FILE* nfp = fopen("rooms.data", " wb");
     curnode = list->front;
	fwrite(&curnode->ro, sizeof(room), 1, nfp);

	//关闭文件
	fclose(nfp);
}

void fun2(List1* list1, List2* list2, List3* list3)
{
	printf("* * * * * * * * * *\n");
	printf("请输入想要修改的类型\n1.实验设备    2.实验员\n");
	printf("输入：");
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
	//读取设备信息
	//打开文件
	FILE* fp = fopen("equipments.data", "wb");
	if (!fp)
	{
		perror("file open failed");
		return;
	}
	//读取
	while (!feof(fp))
	{
		//创建节点
		Node1* node = malloc(sizeof(Node1));
		if (!node)
		{
			printf("malloc failed!\n");
			return;
		}
		node->next = NULL;

		fread(&node->ep, sizeof(equipment), 1, fp);

		//插入到链表中
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	fclose(fp); 
	remove("equipments.data");

	//查找修改的设备
	int buffer;
	printf("请输入要修改的设备编号：\n");
	scanf("%d", &buffer);

	Node1* curnode = list->front;
	while (curnode != NULL)
	{
		if (curnode->ep.id == buffer)
		{
			printf("请输入要修改的设备种类 名称 所在实验室 价格 状态 购进日期 使用年限");
			scanf("%s %s %d %d %d %d %d", &curnode->ep.ca, &curnode->ep.name, &curnode->ep.room, &curnode->ep.price, &curnode->ep.state, &curnode->ep.pdate, &curnode->ep.limit);
			printf("修改成功：）");
			break;
		}
		curnode = curnode->next;
	}

	//写入设备信息
	FILE* nfp = fopen("equipments.data", "ab"); 
	curnode = list->front; 
	fwrite(&curnode->ep, sizeof(equipment), 1, nfp); 
	//关闭文件 
	fclose(nfp); 
}

void alter_te(List2* list)
{
	//读取设备信息
	//打开文件
	FILE* fp = fopen("testers.data", "rb");
	if (!fp)
	{
		perror("file open failed");
		return;
	}
	//读取
	while (!feof(fp))
	{
		//创建节点
		Node2* node = malloc(sizeof(Node2));
		if (!node)
		{
			printf("malloc failed!\n");
			return;
		}
		node->next = NULL;

		fread(&node->te, sizeof(tester), 1, fp);

		//插入到链表中
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	fclose(fp);
	remove("testers.data");

	//查找修改的设备
	int buffer;
	printf("请输入要修改的实验员编号：\n");
	scanf("%d", &buffer);

	Node2* curnode = list->front;
	while (curnode != NULL)
	{
		if (curnode->te.id == buffer)
		{
			printf("请输入要修改的实验员信息：管理实验室数量");
			scanf("%d", &curnode->te.room);
			printf("修改成功：）");
			break;
		}
		curnode = curnode->next;
	}

	//写入设备信息
	FILE* nfp = fopen("testers.data", "ab");
	curnode = list->front; 
	fwrite(&curnode->te, sizeof(tester), 1, nfp); 
	//关闭文件
	fclose(nfp);
} 

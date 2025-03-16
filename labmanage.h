#pragma once

//定义实验设备、实验员、实验室数据类型
typedef struct
{
	int id;
	char ca[50];
	char name[50];
	int room;
	int price;
	int state;
	int pdate;
	int limit;
}equipment;

typedef struct
{
	int id;
	int room[5];
}tester;

typedef int room;

//链表的节点
typedef struct Node1
{
	equipment ep;          //实验设备
	struct Node1* next;    //指向下一个节点的指针
}Node1;

typedef struct Node2
{
	tester te;             //实验员
	struct Node2* next;    //指向下一个节点的指针
}Node2;

typedef struct Node3
{
	room ro;               //实验室
	struct Node3* next;    //指向下一个节点的指针
}Node3;

//链表
typedef struct List1
{
	Node1* front;         //指向第一个节点（头指针）
	int size;             //当前节点数量
}List1;

typedef struct List2
{
	Node2* front;         //指向第一个节点（头指针）
	int size;             //当前节点数量
}List2;

typedef struct List3
{
	Node3* front;         //指向第一个节点（头指针）
	int size;             //当前节点数量
}List3;

//打印管理员界面菜单并提示用户操作
int menu();

//1.基本信息管理界面
void fun1(List1*,List2*,List3*);
//输入函数
void fentry_ep(List1*);
void fentry_te(List2*);
void fentry_ro(List3*);
//删除函数
void fremove_ep(List1*);
void fremove_te(List2*);
void fremove_ro(List3*);

//2.信息调整管理界面
void fun2(List1*, List2*, List3*);
//修改信息函数
void alter_ep(List1*);
void alter_te(List2*);
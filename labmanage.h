#pragma once

//����ʵ���豸��ʵ��Ա��ʵ������������
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

//����Ľڵ�
typedef struct Node1
{
	equipment ep;          //ʵ���豸
	struct Node1* next;    //ָ����һ���ڵ��ָ��
}Node1;

typedef struct Node2
{
	tester te;             //ʵ��Ա
	struct Node2* next;    //ָ����һ���ڵ��ָ��
}Node2;

typedef struct Node3
{
	room ro;               //ʵ����
	struct Node3* next;    //ָ����һ���ڵ��ָ��
}Node3;

//����
typedef struct List1
{
	Node1* front;         //ָ���һ���ڵ㣨ͷָ�룩
	int size;             //��ǰ�ڵ�����
}List1;

typedef struct List2
{
	Node2* front;         //ָ���һ���ڵ㣨ͷָ�룩
	int size;             //��ǰ�ڵ�����
}List2;

typedef struct List3
{
	Node3* front;         //ָ���һ���ڵ㣨ͷָ�룩
	int size;             //��ǰ�ڵ�����
}List3;

//��ӡ����Ա����˵�����ʾ�û�����
int menu();

//1.������Ϣ�������
void fun1(List1*,List2*,List3*);
//���뺯��
void fentry_ep(List1*);
void fentry_te(List2*);
void fentry_ro(List3*);
//ɾ������
void fremove_ep(List1*);
void fremove_te(List2*);
void fremove_ro(List3*);

//2.��Ϣ�����������
void fun2(List1*, List2*, List3*);
//�޸���Ϣ����
void alter_ep(List1*);
void alter_te(List2*);
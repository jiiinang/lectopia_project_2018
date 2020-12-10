#pragma once
#define FALSE 0
#define TRUE 1
typedef struct _node Node;				/* ����ü ��� ���������� */
struct  _node {							/* ��� ����ü (�ڱ����� ����ü ���) */
	Node *next;	/* ������ ���� */
};
typedef  struct  _list { 				/* ���� ����Ʈ ���� ����ü */
	Node *head;							/* head pointer (head node ����Ŵ) */
	Node *tail; 						/* tail pointer (tail node ����Ŵ) */
	int size;							/* ���� ����Ʈ�� ũ�� - ���� data node�� ���� */
}List;

int createList(List *lp);					/* ���� ����Ʈ �ʱ�ȭ */
int addFirst(List *lp, void *data, size_t size, void(*memCpy)(void *, void *));					/* head node �ڿ� node �߰�(���� ����) */
int addLast(List *lp, void *data, size_t size, void(*memCpy)(void *, void *));						/* tail node �տ� node �߰�(���� ����) */
void displayList(List *lp, void(*print)(void *));													/* ����Ʈ ���� ��� ������ ��� */
int removeNode(List *lp, void *data, int(*compare)(void *, void *), void(*clear)(void *));			/* data ��� ���� */
Node * searchNode(List *lp, void *data, int(*compare)(void*, void *));								/* data�� ��ġ�ϴ� node �˻� */
void sortList(List *lp, size_t size, void *data, int(*compare)(void*, void *), void(*memCpy)(void *, void *), void(*clear)(void *));				/* ��� ���� - �������� */
void destroyList(List *lp, void(*clear)(void *, void *));											/* ����Ʈ ���� ��� ��带 ���� */
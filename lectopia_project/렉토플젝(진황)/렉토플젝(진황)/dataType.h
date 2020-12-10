#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <time.h> //_strtime()�� ���ؼ� ��Ŭ��� �� 
#include<windows.h> // strtok(), atoi()�� ���ؼ� ��Ŭ��� �� 

typedef struct _time Time;
typedef struct _parking Parking;
typedef struct _member Member;

// �ð� ���� ����ü
typedef struct _time
{
	int hour;
	int min;
	int sec;
}Time;

// ���� ���� ����ü
typedef struct _parking
{
	char car_Num[20];		// ���� ��ȣ
	char car_position[20];	// ������ ������ ��ġ
	Time park_in_time;		// ���� ���� �ð�
}Parking;

// ȸ�� ���� ����ü
typedef struct _member
{
	char ID[20];			// ȸ���� ID
	char PW[20];			// ȸ���� ��к�ȣ
	int point;				// ȸ�� ����� ����Ʈ
	char car_Num[20];		// ȸ���� ������ȣ	
	char name[20];			// ȸ���� �̸�
}Member;
//�ǽð� �ð� ����ü


// Parking ����ü���� �Լ�
void carMemcpy(void*p1, void*p2);
void carClear(void*p);
void carPrint(void*p);
int carNumberCompare(void*p1, void*p2);
int carPositionCompare(void*p1, void*p2);

// Member ����ü���� �Լ�
void memberMemcpy(void*p1, void*p2);
void memberClear(void*p);
void memberPrint(void*p);
int memberIDCompare(void*p1, void*p2);
int memberPWCompare(void*p1, void*p2);
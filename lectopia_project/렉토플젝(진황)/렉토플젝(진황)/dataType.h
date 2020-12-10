#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <time.h> //_strtime()를 위해서 인클루드 함 
#include<windows.h> // strtok(), atoi()를 위해서 인클루드 함 

typedef struct _time Time;
typedef struct _parking Parking;
typedef struct _member Member;

// 시간 관리 구조체
typedef struct _time
{
	int hour;
	int min;
	int sec;
}Time;

// 차의 정보 구조체
typedef struct _parking
{
	char car_Num[20];		// 차량 번호
	char car_position[20];	// 차량이 주차된 위치
	Time park_in_time;		// 차량 들어온 시각
}Parking;

// 회원 정보 구조체
typedef struct _member
{
	char ID[20];			// 회원의 ID
	char PW[20];			// 회원의 비밀빈호
	int point;				// 회원 멤버십 포인트
	char car_Num[20];		// 회원의 차량번호	
	char name[20];			// 회원의 이름
}Member;
//실시간 시간 구조체


// Parking 구조체관련 함수
void carMemcpy(void*p1, void*p2);
void carClear(void*p);
void carPrint(void*p);
int carNumberCompare(void*p1, void*p2);
int carPositionCompare(void*p1, void*p2);

// Member 구조체관련 함수
void memberMemcpy(void*p1, void*p2);
void memberClear(void*p);
void memberPrint(void*p);
int memberIDCompare(void*p1, void*p2);
int memberPWCompare(void*p1, void*p2);
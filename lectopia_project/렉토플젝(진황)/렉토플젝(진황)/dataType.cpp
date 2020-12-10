#include "dataType.h"
#include"customer.h"

// 1. Parking

/*
# 함수명 : carMemcpy
# 기능 : parking 구조체의 멤버간 복사
*/
void carMemcpy(void*p1, void*p2)
{
	strcpy(((Parking*)p1)->car_Num, ((Parking*)p2)->car_Num);
	strcpy(((Parking*)p1)->car_position, ((Parking*)p2)->car_position);
	((Parking*)p1)->park_in_time = ((Parking*)p2)->park_in_time;
	
}
/*
# 함수명 : carClear
# 기능 : parking 구조체의 멤버값 초기화
*/
void carClear(void*p)
{
	((Parking*)p)->car_Num[0] = '\0';
	((Parking*)p)->car_position[0] = '\0';
	((Parking*)p)->park_in_time.hour = 0;
	((Parking*)p)->park_in_time.min = 0;
	((Parking*)p)->park_in_time.sec = 0;
}
/*
# 함수명 : carPrint
# 기능 : parking 구조체의 멤버 출력
*/
void carPrint(void*p)
{
	gotoxy(15,10);
	printf("             <고객 모드>");
	gotoxy(20,14);
	printf("차량 번호:%s ", ((Parking*)p)->car_Num);
	gotoxy(20,16);
	printf("차량 위치:%s ", ((Parking*)p)->car_position);
	gotoxy(20,18);
	printf("입차 시각:%d시 %d분 %d초 \n\n", ((Parking*)p)->park_in_time.hour, ((Parking*)p)->park_in_time.min, ((Parking*)p)->park_in_time.sec);
}
/*
# 함수명 : carNumberCompare
# 기능 : parking 구조체의 차량번호 비교
*/
int carNumberCompare(void*p1, void*p2)
{
	if (0<strcmp(((Parking*)p1)->car_Num, ((Parking*)p2)->car_Num)) return 1;
	else if (0>strcmp(((Parking*)p1)->car_Num, ((Parking*)p2)->car_Num)) return -1;
	else return 0;
}
/*
# 함수명 : carPositionCompare
# 기능 : parking 구조체의 차량 위치 비교
*/
int carPositionCompare(void*p1, void*p2)                                          
{
	if (strcmp(((Parking*)p1)->car_position, ((Parking*)p2)->car_position)) return 1;
	else if (strcmp(((Parking*)p1)->car_position, ((Parking*)p2)->car_position)) return -1;
	else return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// 2. Member


/*
# 함수명 : memberMemcpy
# 기능 : member 구조체의 멤버간 복사
*/
void memberMemcpy(void*p1, void*p2)
{
	strcpy(((Member*)p1)->ID, ((Member*)p2)->ID);
	strcpy(((Member*)p1)->PW, ((Member*)p2)->PW);
	strcpy(((Member*)p1)->car_Num, ((Member*)p2)->car_Num);
	strcpy(((Member*)p1)->name, ((Member*)p2)->name);
	((Member*)p1)->point = ((Member*)p2)->point;
}
/*
# 함수명 : memberClear
# 기능 : member 구조체 멤버의 값 초기화
*/
void memberClear(void*p)
{
	memset(((Member *)p)->ID, 0, sizeof(((Member *)p)->ID));
	memset(((Member *)p)->PW, 0, sizeof(((Member *)p)->PW));
	memset(((Member *)p)->car_Num, 0, sizeof(((Member *)p)->car_Num));
	memset(((Member *)p)->name, 0, sizeof(((Member *)p)->name));
	((Member*)p)->point = 0;
}
/*
# 함수명 : memberPrint
# 기능 : member 구조체의 멤버 출력
*/
void memberPrint(void*p)
{
	printf("회원 ID :%s \n ", ((Member*)p)->ID);
	printf("회원 PW :%s \n ", ((Member*)p)->PW);
	printf("회원 차량번호 :%s \n ", ((Member*)p)->car_Num);
	printf("회원 이름 :%s \n ", ((Member*)p)->name);
	printf("잔여 멤버십 포인트 :%d \n ", ((Member*)p)->point);
}
/*
# 함수명 : memberIDCompare
# 기능 : member 구조체의 ID 비교
*/
int memberIDCompare(void*p1, void*p2)
{
	return strcmp(((Member *)p1)->ID, (((Member *)p2)->ID));
}
/*
# 함수명 : memberPWCompare
# 기능 : member 구조체의 PW 비교
*/
int memberPWCompare(void*p1, void*p2)
{
	return strcmp(((Member *)p1)->PW, (((Member *)p2)->PW));
}




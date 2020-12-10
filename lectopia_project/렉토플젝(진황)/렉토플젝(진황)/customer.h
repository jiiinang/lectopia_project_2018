#pragma once
#include "dataType.h"
#include "LinkedList.h"

#include<conio.h>
#pragma warning(disable:4996)


// 재홍
//void inputList(List*, FILE*);
//int member_check(List*,Member*);
//void out_member_carNumber(List *member_list, Member *temp,char*);

// 진황님 부분
void parking_select_mode(List *member_list, List* current_park_list, Parking*p);
int check_parking(List *current_park_list, Parking*p, int menu);

void car_position_check_print(List*current_park_list, Parking*p);  //3.자리확인
void Input_CarNumber(List*current_park_list, Parking*p); //비회원 차량번호 입력
void out_parking_print(List *member_list, List* current_park_list, Parking*p);  //출차
void memberPay(Node *m_np, Node *np, Parking *p);              //회원 출차 결제창
void noMemberPay( Node *np, Parking *p);                       //비회원 출차 결제창
void gotoxy(int x,int y);
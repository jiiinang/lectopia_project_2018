#pragma once
#include "dataType.h"
#include "LinkedList.h"

#include<conio.h>
#pragma warning(disable:4996)


// ��ȫ
//void inputList(List*, FILE*);
//int member_check(List*,Member*);
//void out_member_carNumber(List *member_list, Member *temp,char*);

// ��Ȳ�� �κ�
void parking_select_mode(List *member_list, List* current_park_list, Parking*p);
int check_parking(List *current_park_list, Parking*p, int menu);

void car_position_check_print(List*current_park_list, Parking*p);  //3.�ڸ�Ȯ��
void Input_CarNumber(List*current_park_list, Parking*p); //��ȸ�� ������ȣ �Է�
void out_parking_print(List *member_list, List* current_park_list, Parking*p);  //����
void memberPay(Node *m_np, Node *np, Parking *p);              //ȸ�� ���� ����â
void noMemberPay( Node *np, Parking *p);                       //��ȸ�� ���� ����â
void gotoxy(int x,int y);
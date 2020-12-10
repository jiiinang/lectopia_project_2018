#include "dataType.h"
#include"customer.h"

// 1. Parking

/*
# �Լ��� : carMemcpy
# ��� : parking ����ü�� ����� ����
*/
void carMemcpy(void*p1, void*p2)
{
	strcpy(((Parking*)p1)->car_Num, ((Parking*)p2)->car_Num);
	strcpy(((Parking*)p1)->car_position, ((Parking*)p2)->car_position);
	((Parking*)p1)->park_in_time = ((Parking*)p2)->park_in_time;
	
}
/*
# �Լ��� : carClear
# ��� : parking ����ü�� ����� �ʱ�ȭ
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
# �Լ��� : carPrint
# ��� : parking ����ü�� ��� ���
*/
void carPrint(void*p)
{
	gotoxy(15,10);
	printf("             <�� ���>");
	gotoxy(20,14);
	printf("���� ��ȣ:%s ", ((Parking*)p)->car_Num);
	gotoxy(20,16);
	printf("���� ��ġ:%s ", ((Parking*)p)->car_position);
	gotoxy(20,18);
	printf("���� �ð�:%d�� %d�� %d�� \n\n", ((Parking*)p)->park_in_time.hour, ((Parking*)p)->park_in_time.min, ((Parking*)p)->park_in_time.sec);
}
/*
# �Լ��� : carNumberCompare
# ��� : parking ����ü�� ������ȣ ��
*/
int carNumberCompare(void*p1, void*p2)
{
	if (0<strcmp(((Parking*)p1)->car_Num, ((Parking*)p2)->car_Num)) return 1;
	else if (0>strcmp(((Parking*)p1)->car_Num, ((Parking*)p2)->car_Num)) return -1;
	else return 0;
}
/*
# �Լ��� : carPositionCompare
# ��� : parking ����ü�� ���� ��ġ ��
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
# �Լ��� : memberMemcpy
# ��� : member ����ü�� ����� ����
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
# �Լ��� : memberClear
# ��� : member ����ü ����� �� �ʱ�ȭ
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
# �Լ��� : memberPrint
# ��� : member ����ü�� ��� ���
*/
void memberPrint(void*p)
{
	printf("ȸ�� ID :%s \n ", ((Member*)p)->ID);
	printf("ȸ�� PW :%s \n ", ((Member*)p)->PW);
	printf("ȸ�� ������ȣ :%s \n ", ((Member*)p)->car_Num);
	printf("ȸ�� �̸� :%s \n ", ((Member*)p)->name);
	printf("�ܿ� ����� ����Ʈ :%d \n ", ((Member*)p)->point);
}
/*
# �Լ��� : memberIDCompare
# ��� : member ����ü�� ID ��
*/
int memberIDCompare(void*p1, void*p2)
{
	return strcmp(((Member *)p1)->ID, (((Member *)p2)->ID));
}
/*
# �Լ��� : memberPWCompare
# ��� : member ����ü�� PW ��
*/
int memberPWCompare(void*p1, void*p2)
{
	return strcmp(((Member *)p1)->PW, (((Member *)p2)->PW));
}




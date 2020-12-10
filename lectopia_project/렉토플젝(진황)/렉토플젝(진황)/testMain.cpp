#include"dataType.h"
#include"LinkedList.h"
#include"customer.h"
#include<string.h>
#include<conio.h>
#pragma warning(disable:4996)
// 캐릭터 배열말고 파킹 구조체를 정적할당하여 돌리기
																																																																		
int main()
{
	 List current_park_list,member_list;
	 Parking p={"","",{0,0,0}};

	 createList(&member_list);
	 createList(&current_park_list);
	 Input_CarNumber(&current_park_list,&p);
	 displayList(&current_park_list,carPrint);
	 parking_select_mode(&member_list,&current_park_list,&p);

	 return 0;

}



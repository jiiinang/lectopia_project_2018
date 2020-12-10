#include "customer.h"
#include"dataType.h"

void parking_select_mode(List *member_list, List* current_park_list, Parking*p)    //1.입차시에 차량번호와 현재주차된 리스트
{								
    int menu,res=0;			
	
	while(res==FALSE)
	{                                  
    getch();
	system("cls");

	gotoxy(15,10);
	printf("             <고객 모드>");

	gotoxy(15,14);
	
	printf("  1.입차  2.출차  3.자리 확인\n");
	gotoxy(15,16);
	printf("  ※메뉴 선택:");
	scanf("%d",&menu);                                   

	switch(menu)
	{
		case 1:if(TRUE==check_parking(current_park_list,p,menu)); break;                            //**리턴값이 TRUE이면 입차,자리선택함수 불러주기!!인호님 파트 집어넣기!!
		
		case 2:if(TRUE==check_parking(current_park_list,p,menu)) out_parking_print(member_list,current_park_list,p); break;      //**리턴값이 TRUE이면  출차 함수 불러주기!!
	    
		case 3:if(TRUE==check_parking(current_park_list,p,menu)) car_position_check_print(current_park_list,p);break;            //**리턴값이 TRUE이면  자리출력 함수 불러주기!!

		default: break;
	}
	
	}                                                                                                  // 리턴값이 FALSE 인경우에 다시 메뉴선택 물어보기


	return;
}
// 입차 시 주차 여부 검사
int check_parking(List *current_park_list, Parking*p, int menu)                                          //입차와 출차,자리검사 나눠서 구현
{
	Node *np;
	char ch;

	system("cls");  

	gotoxy(15,10);
	printf("             <고객 모드>");

	if(menu==1)
	{								// 1.입차인경우 선택만 요구받는다

		    np=searchNode(current_park_list,p,carNumberCompare);
			if(np==NULL)
			{
	   	      gotoxy(10,14);

			  printf("  주차를 하시겠습니까? (y/n) :");
		      scanf(" %c",&ch);

			  if(ch=='y')      return TRUE;
			  else if(ch=='n') return FALSE;
			  else { gotoxy(10,16); printf("  잘못입력하셨습니다.");return FALSE; }

			}
			else 
			{gotoxy(10,14);printf("현재 입차된 차량입니다.메뉴를 다시 선택해 주십시오.");return;}
	}

	else {                                                                                          //2,3번 메뉴인경우 주차장내에 주차된 차량인지 검색 한다
	
		    np=searchNode(current_park_list,p,carNumberCompare);

			gotoxy(10,14);
			
			printf("  현재 주차장 내에 고객님 차량을 조회중입니다...\n\n");
			getch();																				// 2,3 출차 자리확인 인 경우

			if(np==NULL)
			{	
				gotoxy(10,16);																         //NULL 인경우에 현재 주차된차량이 아님
			    printf("  ※현재 주차되어 있는 차량이 아닙니다!※\n\n");
				return FALSE;
			}
			else return TRUE;
	        }
	return 0;
}

void car_position_check_print(List*current_park_list,Parking*p)        //3번 차량 위치 출력해주기
{
	
	Node *np;
	
	gotoxy(10,14);

	printf("  3.차량위치확인\n\n");
	np=searchNode(current_park_list,&p,carNumberCompare);
	carPrint(np+1);

	return;

}
 
void Input_CarNumber(List*current_park_list,Parking*p)   //비회원 차량번호 입력
{	
	fflush(stdin);

	gotoxy(15,10);
	printf("             <고객 모드>");

	gotoxy(10,14);
	printf("  고객님의 차량번호를 입력하여주십시요:");                       
	fgets(p->car_Num,sizeof(p->car_Num),stdin);
	p->car_Num[strlen(p->car_Num)-1]='\0';
	
	system("cls");
	carPrint(p);
	return ;
}
void out_parking_print(List *member_list, List* current_park_list, Parking*p) //   아직 미완성
{
	Node *np,*m_np;                                                                //회원인경우 두가지 리스트정보 , 비회원인경우 한가지 리스트정보
	int point=0;

	strcpy(((Member*)(m_np+1))->car_Num,p->car_Num);
	gotoxy(15,10);
	printf("             <고객 모드>");

	gotoxy(10,14);
	printf("  현재 출차 처리가 진행중입니다....\n");
	getch();
	system("cls");
	if(member_list==NULL)
	{
		  np=searchNode(current_park_list,p,carNumberCompare);						//비회원인 경우
	      noMemberPay(np,p);
	}                                                                     
	else 
	{
		  np=searchNode(current_park_list,p,carNumberCompare);						//회원인 경우 
	      m_np=searchNode(member_list,p,carNumberCompare);
		  memberPay(m_np,np,p);
	}

	removeNode(current_park_list,p,carNumberCompare,carClear);                   //출차한 차량 노드 제거 

	system("cls");

	gotoxy(15,10);
	printf("             <고객 모드>");
	
	gotoxy(10,14);
    printf("         ☆결제가 완료되었습니다!☆");
    gotoxy(10,16);
	printf("  ★감사합니다! 다음에 또 이용해주세요.★");

}

void memberPay(Node *m_np, Node *np, Parking *p)               //회원 결제 창
{
	char ch;
	int usePoint=0,price=0;

	gotoxy(15,10);
	printf("             <고객 모드>");
	
	carPrint(np+1);                                                   //입차된 차량 정보 출력
	gotoxy(10,20);
	printf(" 포인트 :%d",((Member*)(m_np+1))->point);                       //포인트 출력
	/////////////////////////////////////////////////////////////////////////////////////////요금계산,출차시간22,요금출력24
	//price=calculatePrice(p);         출차 시간 받아와서 요금 계산
	
	gotoxy(10,22); //출차시간출력
	gotoxy(10,24); //요금 출력
	
	gotoxy(10,26);
	printf("  멤버십 포인트를 사용하시겠습니까? (y/n) : ");
	scanf(" %c",&ch);

	if(ch=='y')
	{
		gotoxy(10,27);
		printf("  %d Point 중 얼마를 사용하시겠습니까?",((Member*)(m_np+1))->point);
	    scanf("%d",&usePoint);
	    ((Member*)(m_np+1))->point -= usePoint;                                                //사용한 포인트 reset해주기
	}
	else if(ch=='n'){;}
	else{;}
	gotoxy(10,29);
    printf("※ 결제하실 최종 주차 요금은 %d원 입니다.※",price-usePoint);
	
	return;
}
void noMemberPay(Node *np, Parking *p)               //비회원 결제 창
{
	int price=0;

	gotoxy(15,10);
	printf("             <고객 모드>");


	//price=calculatePrice(p);         출차 시간 받아와서 요금 계산
	gotoxy(10,20); //출차시간출력
	gotoxy(10,22); //요금 출력

	carPrint(p);             //입차된 차량 정보 출력
	gotoxy(10,26);
	////////////////////////////////////////////////////////////////////////////////////요금 계산

	printf("※ 결제하실 최종 주차 요금은 %d원 입니다.※",price);

	return;
}

void gotoxy(int x,int y)
{
	COORD Pos={x-1,y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}



//int calculatePrice()   //요금 계산 분당 1000원으로 계산한다
//{
//	//return 출차시간(분)-입차시간(분);
//
//}

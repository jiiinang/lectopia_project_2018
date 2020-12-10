#include "customer.h"
#include"dataType.h"

void parking_select_mode(List *member_list, List* current_park_list, Parking*p)    //1.�����ÿ� ������ȣ�� ���������� ����Ʈ
{								
    int menu,res=0;			
	
	while(res==FALSE)
	{                                  
    getch();
	system("cls");

	gotoxy(15,10);
	printf("             <�� ���>");

	gotoxy(15,14);
	
	printf("  1.����  2.����  3.�ڸ� Ȯ��\n");
	gotoxy(15,16);
	printf("  �ظ޴� ����:");
	scanf("%d",&menu);                                   

	switch(menu)
	{
		case 1:if(TRUE==check_parking(current_park_list,p,menu)); break;                            //**���ϰ��� TRUE�̸� ����,�ڸ������Լ� �ҷ��ֱ�!!��ȣ�� ��Ʈ ����ֱ�!!
		
		case 2:if(TRUE==check_parking(current_park_list,p,menu)) out_parking_print(member_list,current_park_list,p); break;      //**���ϰ��� TRUE�̸�  ���� �Լ� �ҷ��ֱ�!!
	    
		case 3:if(TRUE==check_parking(current_park_list,p,menu)) car_position_check_print(current_park_list,p);break;            //**���ϰ��� TRUE�̸�  �ڸ���� �Լ� �ҷ��ֱ�!!

		default: break;
	}
	
	}                                                                                                  // ���ϰ��� FALSE �ΰ�쿡 �ٽ� �޴����� �����


	return;
}
// ���� �� ���� ���� �˻�
int check_parking(List *current_park_list, Parking*p, int menu)                                          //������ ����,�ڸ��˻� ������ ����
{
	Node *np;
	char ch;

	system("cls");  

	gotoxy(15,10);
	printf("             <�� ���>");

	if(menu==1)
	{								// 1.�����ΰ�� ���ø� �䱸�޴´�

		    np=searchNode(current_park_list,p,carNumberCompare);
			if(np==NULL)
			{
	   	      gotoxy(10,14);

			  printf("  ������ �Ͻðڽ��ϱ�? (y/n) :");
		      scanf(" %c",&ch);

			  if(ch=='y')      return TRUE;
			  else if(ch=='n') return FALSE;
			  else { gotoxy(10,16); printf("  �߸��Է��ϼ̽��ϴ�.");return FALSE; }

			}
			else 
			{gotoxy(10,14);printf("���� ������ �����Դϴ�.�޴��� �ٽ� ������ �ֽʽÿ�.");return;}
	}

	else {                                                                                          //2,3�� �޴��ΰ�� �����峻�� ������ �������� �˻� �Ѵ�
	
		    np=searchNode(current_park_list,p,carNumberCompare);

			gotoxy(10,14);
			
			printf("  ���� ������ ���� ���� ������ ��ȸ���Դϴ�...\n\n");
			getch();																				// 2,3 ���� �ڸ�Ȯ�� �� ���

			if(np==NULL)
			{	
				gotoxy(10,16);																         //NULL �ΰ�쿡 ���� ������������ �ƴ�
			    printf("  ������ �����Ǿ� �ִ� ������ �ƴմϴ�!��\n\n");
				return FALSE;
			}
			else return TRUE;
	        }
	return 0;
}

void car_position_check_print(List*current_park_list,Parking*p)        //3�� ���� ��ġ ������ֱ�
{
	
	Node *np;
	
	gotoxy(10,14);

	printf("  3.������ġȮ��\n\n");
	np=searchNode(current_park_list,&p,carNumberCompare);
	carPrint(np+1);

	return;

}
 
void Input_CarNumber(List*current_park_list,Parking*p)   //��ȸ�� ������ȣ �Է�
{	
	fflush(stdin);

	gotoxy(15,10);
	printf("             <�� ���>");

	gotoxy(10,14);
	printf("  ������ ������ȣ�� �Է��Ͽ��ֽʽÿ�:");                       
	fgets(p->car_Num,sizeof(p->car_Num),stdin);
	p->car_Num[strlen(p->car_Num)-1]='\0';
	
	system("cls");
	carPrint(p);
	return ;
}
void out_parking_print(List *member_list, List* current_park_list, Parking*p) //   ���� �̿ϼ�
{
	Node *np,*m_np;                                                                //ȸ���ΰ�� �ΰ��� ����Ʈ���� , ��ȸ���ΰ�� �Ѱ��� ����Ʈ����
	int point=0;

	strcpy(((Member*)(m_np+1))->car_Num,p->car_Num);
	gotoxy(15,10);
	printf("             <�� ���>");

	gotoxy(10,14);
	printf("  ���� ���� ó���� �������Դϴ�....\n");
	getch();
	system("cls");
	if(member_list==NULL)
	{
		  np=searchNode(current_park_list,p,carNumberCompare);						//��ȸ���� ���
	      noMemberPay(np,p);
	}                                                                     
	else 
	{
		  np=searchNode(current_park_list,p,carNumberCompare);						//ȸ���� ��� 
	      m_np=searchNode(member_list,p,carNumberCompare);
		  memberPay(m_np,np,p);
	}

	removeNode(current_park_list,p,carNumberCompare,carClear);                   //������ ���� ��� ���� 

	system("cls");

	gotoxy(15,10);
	printf("             <�� ���>");
	
	gotoxy(10,14);
    printf("         �ٰ����� �Ϸ�Ǿ����ϴ�!��");
    gotoxy(10,16);
	printf("  �ڰ����մϴ�! ������ �� �̿����ּ���.��");

}

void memberPay(Node *m_np, Node *np, Parking *p)               //ȸ�� ���� â
{
	char ch;
	int usePoint=0,price=0;

	gotoxy(15,10);
	printf("             <�� ���>");
	
	carPrint(np+1);                                                   //������ ���� ���� ���
	gotoxy(10,20);
	printf(" ����Ʈ :%d",((Member*)(m_np+1))->point);                       //����Ʈ ���
	/////////////////////////////////////////////////////////////////////////////////////////��ݰ��,�����ð�22,������24
	//price=calculatePrice(p);         ���� �ð� �޾ƿͼ� ��� ���
	
	gotoxy(10,22); //�����ð����
	gotoxy(10,24); //��� ���
	
	gotoxy(10,26);
	printf("  ����� ����Ʈ�� ����Ͻðڽ��ϱ�? (y/n) : ");
	scanf(" %c",&ch);

	if(ch=='y')
	{
		gotoxy(10,27);
		printf("  %d Point �� �󸶸� ����Ͻðڽ��ϱ�?",((Member*)(m_np+1))->point);
	    scanf("%d",&usePoint);
	    ((Member*)(m_np+1))->point -= usePoint;                                                //����� ����Ʈ reset���ֱ�
	}
	else if(ch=='n'){;}
	else{;}
	gotoxy(10,29);
    printf("�� �����Ͻ� ���� ���� ����� %d�� �Դϴ�.��",price-usePoint);
	
	return;
}
void noMemberPay(Node *np, Parking *p)               //��ȸ�� ���� â
{
	int price=0;

	gotoxy(15,10);
	printf("             <�� ���>");


	//price=calculatePrice(p);         ���� �ð� �޾ƿͼ� ��� ���
	gotoxy(10,20); //�����ð����
	gotoxy(10,22); //��� ���

	carPrint(p);             //������ ���� ���� ���
	gotoxy(10,26);
	////////////////////////////////////////////////////////////////////////////////////��� ���

	printf("�� �����Ͻ� ���� ���� ����� %d�� �Դϴ�.��",price);

	return;
}

void gotoxy(int x,int y)
{
	COORD Pos={x-1,y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}



//int calculatePrice()   //��� ��� �д� 1000������ ����Ѵ�
//{
//	//return �����ð�(��)-�����ð�(��);
//
//}

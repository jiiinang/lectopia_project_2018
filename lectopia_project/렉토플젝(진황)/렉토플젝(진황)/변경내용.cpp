gotoxy(15,14);
	printf("���� ��ȣ:%s ", ((Parking*)p)->car_Num);
	gotoxy(15,16);
	printf("���� ��ġ:%s ", ((Parking*)p)->car_position);
	gotoxy(15,18);
	printf("���� �ð�:%d�� %d�� %d�� \n\n", ((Parking*)p)->park_in_time.hour, ((Parking*)p)->park_in_time.min, ((Parking*)p)->park_in_time.sec);
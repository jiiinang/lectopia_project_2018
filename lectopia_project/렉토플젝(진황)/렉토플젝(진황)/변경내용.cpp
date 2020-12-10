gotoxy(15,14);
	printf("차량 번호:%s ", ((Parking*)p)->car_Num);
	gotoxy(15,16);
	printf("차량 위치:%s ", ((Parking*)p)->car_position);
	gotoxy(15,18);
	printf("입차 시각:%d시 %d분 %d초 \n\n", ((Parking*)p)->park_in_time.hour, ((Parking*)p)->park_in_time.min, ((Parking*)p)->park_in_time.sec);
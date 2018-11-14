#include "header.h"



void Join_person(){
	Person_Info Join_Info;
	cout <<"질문에 성실히 응답해 주세요 "<< endl;
	cout <<"이름 : ";
	cin >> Join_Info.person_name; 
	cout <<"\n성별 : ";
	cin >> Join_Info.person_gender;
	cout <<"\n나이 : ";
	cin >> Join_Info.person_age;
	cout <<"\n전화번호 : ";
	cin >> Join_Info.person_phone;
	cout <<"\n생일 : ";
	cin >> Join_Info.person_brith;
	int find = 0;
	do{
		cout <<"\n아이디 : ";
		cin >> Join_Info.person_ID;
		for(int i = 0; i < sizeof(People)/sizeof(People[0]); i++){
			if(Join_Info.person_ID == People[i].ID){
				break;
			}else find = 1;
		}
	}while(find == 0);
	cout <<"\n비밀번호 : ";
	cin >> Join_Info.person_pwd;
	do{
		cout <<"비밀번호 확인 : ";
		cin >> Join_Info.person_pwd_hak;
	}while(Join_Info.person_pwd != Join_Info.person_pwd_hak);
	
	People[count].ID = Join_Info.person_ID;
	People[count].PWD = Join_Info.person_pwd;
	People[count].person_info = Join_Info;
	count++;
	
}
void Login_person(){
	string Input_ID, Input_pwd;
	int a = 0,b = 0;
	cout << "ID 입력 : ";
	cin >> Input_ID;
	cout << "비밀번호 입력 : ";
	cin >> Input_pwd;
	for(int i = 0; i < sizeof(People)/sizeof(People[0]); i++){
		if(Input_ID == People[i].ID){
			if(Input_pwd == People[i].PWD){
				cout <<"로그인에 성공하셨습니다."<< endl; break;
				b = 1;
				Useing_ID = People[i].ID;
				Useing_PWD = People[i].PWD;
				Useing_index = i;
			}
			a = 1;
		}
	}
	if(a == 1 && b != 1)cout <<"비밀번호를 확인해 주세요"<<endl;
	if(a != 1)cout <<"아이디를 확인해 주세요"<<endl; 
};

void store_input(){
	while(1){ 
		cout<<"가게 추가를 시작합니다."<<endl;
		cout<<"가게 이름 : ";
		cin>> People[store_count].person_info.store[store_count].store_name;
		cout<<"기본 적립금 : ";
		cin>> People[store_count].person_info.store[store_count].pointer;
		cout<<"가게 특이사항 : ";
		cin>> People[store_count].person_info.store[store_count].store_info;
		store_count++;
		cout<<"가게를 더 추가하시겠습니까?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;
	}
	
}
void point_add(){
	while(1){
		int answer_add;
		int pointer_var, pointer_add; 
		cout<<"적립금을 추가할 가게를 선택해 주세요"<<endl;
		for(int i = 0; i < store_count; i++){
			cout << (i+1) << "." << People[i].person_info.store[i].store_name<<"	";
		}cout<<endl;
		cin>> answer_int;
		cout<<"적립금 적립 방법을 선택해 주세요"<<endl;
		cout<<"1. 기존 방식		2. 사용자 입력 방식";
		cin>> answer_add;
		if(answer_add == 2){
			cout <<"적립할 적립금를 적어주세요"<<endl;
			cin>>pointer_var;
			cout<<"적용되셨습니다.";
		} 
		cout<<"사용 금액 : ";
		cin >>pointer_add;
		People[0].person_info.store[answer_int-1].pointer * 10;
		
		cout<<"적립금을 더 적립하시겠습니까?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;
	}
}
void point_del(){
	while(1){
		int answer_del;
		int pointer_del; 
		cout<<"적립금을 사용할 가게를 선택해 주세요"<<endl;
		for(int i = 0; i < store_count; i++){
			cout << (i+1) << "." << People[i].person_info.store[i].store_name<<"	";
		}cout<<endl;
		cin>> answer_int;
		cout <<"사용한 적립금을 적어주세요"<<endl;
		cin>>pointer_del;
		if(People[Useing_index].person_info.store[answer_int-1].pointer - pointer_del < 0){
			cout<<"적립금을 사용하실 수 없습니다."<<endl;
			cout<<"적립금을 확인해 주시길 바랍니다."<<endl; 
		}else{
			cout<<"적용되셨습니다.";
			People[Useing_index].person_info.store[answer_int-1].pointer -= pointer_del;
		}
		cout<<"적립금을 더 적립하시겠습니까?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;
	}
}
void point_hak(){
	while(1){
		cout<<"적립금을 확인할 가게를 선택해 주세요"<<endl;
		for(int i = 0; i < store_count; i++){
			cout << (i+1) << "." << People[i].person_info.store[i].store_name<<"	";
		}cout<<endl;
		cin>> answer_int;
		cout << People[answer_int-1].person_info.store[answer_int-1].store_name<< "의 적립금은";
		cout << People[answer_int-1].person_info.store[answer_int-1].pointer<< "이고,"<<endl;
		cout << "가게 정보는" << People[answer_int-1].person_info.store[answer_int-1].store_info<< "입니다"<<endl;	
		
		cout<<"적립금을 더 확인하시겠습니까?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;	
	}
	
}
void point_change(){
	int answer_int_sub, change_pointer;
	string change_name,change_info;
	
	while(1){
		cout<<"정보를 변경할 가게를 선택해 주세요"<<endl;
		for(int i = 0; i < store_count; i++){
			cout << (i+1) << "." << People[i].person_info.store[i].store_name<<"	";
		}cout<<endl;
		cin>> answer_int;
		cout<<"수정할 부분을 선택해 주세요"<<endl;
		cout << "1. " << People[Useing_index].person_info.store[answer_int].store_name<<
				"2. " << People[Useing_index].person_info.store[answer_int].pointer<<
				"3. " << People[Useing_index].person_info.store[answer_int].store_info<<endl;
		cin >> answer_int_sub;
		switch(answer_int_sub){
			case 1:
				cout << "변경 이름 : ";
				cin >> change_name;
				cout << People[Useing_index].person_info.store[answer_int].store_name<< "을" << change_name <<"으로 변경 하시겠습니까?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.store[answer_int].store_name = change_name;
				break; 
			case 2:
				cout << "변경 포인트 : ";
				cin >> change_pointer;
				cout << People[Useing_index].person_info.store[answer_int].pointer<< "을" << change_pointer <<"으로 변경 하시겠습니까?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.store[answer_int].pointer = change_pointer;
				break; 
			case 3:
				cout << "변경 정보 : ";
				cin >> change_info;
				cout << People[Useing_index].person_info.store[answer_int].store_info<< "을" << change_info <<"으로 변경 하시겠습니까?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.store[answer_int].store_info = change_info;
				break; 
			default: break;
		}
		
		cout<<"가게정볼ㄹ 더 수정하시겠습니까?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;
	}
}
void People_change_info(){
	string change_name, change_pwd, change_pwd_hak; ;
	char change_gender[10];
	int  change_age, change_phone, change_brith;
	while(1){
		cout<<"수정할 회원정보를 선택해 주세요 "<<endl;
		cout<< "이름 : " << People[Useing_index].person_info.person_name<<endl;
		cout<< "성별 : " << People[Useing_index].person_info.person_gender<<endl;
		cout<< "나이 : " << People[Useing_index].person_info.person_age<<endl;		
		cout<< "전화번호 : " << People[Useing_index].person_info.person_phone<<endl;
		cout<< "생일 : " << People[Useing_index].person_info.person_brith<<endl;		
		cout<< "비밀번호 : " << People[Useing_index].person_info.person_pwd<<endl;
		cin>> answer_int;
		
		switch(answer_int){
			case 1:
				cout << "변경 이름 : ";
				cin >> change_name; 
				cout <<People[Useing_index].person_info.person_name<<"을"<<change_name<<"로 변경하시겠습니까?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.person_name = change_name;
				break;
			case 2:
				cout << "변경 성별 : ";
				cin >> *change_gender; 
				cout <<People[Useing_index].person_info.person_name<<"을"<<change_name<<"로 변경하시겠습니까?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.person_name = change_name;
				break;
			case 3:
				cout << "변경 나이 : ";
				cin >> change_age; 
				cout <<People[Useing_index].person_info.person_age<<"을"<<change_age<<"로 변경하시겠습니까?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.person_age = change_age;
				break;
			
			case 4:
				cout << "변경 번호 : ";
				cin >> change_phone; 
				cout <<People[Useing_index].person_info.person_phone<<"을"<<change_phone<<"로 변경하시겠습니까?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.person_phone = change_phone;
				break;
				
			case 5:
				cout << "변경 생일 : ";
				cin >> change_brith; 
				cout <<People[Useing_index].person_info.person_brith<<"을"<<change_brith<<"로 변경하시겠습니까?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.person_brith = change_brith;
				break;
				
			case 6:
				cout << "원래 비밀번호 : ";
				cin >> change_pwd_hak;
				if(change_pwd_hak != Useing_PWD)break;
				cout << "변경 비밀번호 : ";
				cin >> change_pwd; 
				cout <<People[0].person_info.person_pwd<<"을"<<change_pwd<<"로 변경하시겠습니까?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[0].person_info.person_pwd = change_pwd;
				break;
				
			default: cout<<"존재하는 숫자를 선택해 주세요"<<endl; break;
		}	
		cout<<"회원정보를 더 수정하시겠습니까?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;	
	}
	
}
void People_change(){
		cout << "1. 로그아웃 하기	2. 사용자 변경하기"<<endl;
		cin >> answer_int;
		switch(answer_int){
			case 1: cout << "로그아웃을 하시겠습니까?"<<endl;
					cin >> *answer_char;
					if(*answer_char == 'N' || *answer_char == 'n') break;
			case 2: 
				break;
			default: break;
		}
		cout<<"기본 화면으로 나가시겠습니까?";
		system("cls");
}

#include "header.h"

int main(){

	int answer; 
	cout << "○●○●○●○●환영합니다○●○●○●○●"<<endl;
	cout << "○여기는 포인트 관리를 도와주는 곳 입니다●"<<endl; 
	cout << "회원가입을 진행 하겠습니다."<<endl;	
	Join_person();
	system("CLS");
	
	cout <<"이제부터 사용하실 수 있습니다."<<endl;
	
	cout << "1. 로그인하기 2. 회원가입하기(추가)"<<endl;
		 
	cin >> answer;
	if(answer == 1){
		Login_person();
		
	}else if(answer == 2){
		cout <<"회원가입을 진행합니다"<<endl;
		Join_person();
		system("CLS");	 
	}
	while(1){
		int menu_input;
		cout<<"메뉴"<<endl;
		cout<<"1. 적립 가게 추가"<<endl;			//store_input()
		cout<<"2. 적립금 적립"<<endl;				//point_add()
		cout<<"3. 적립금 사용"<<endl;				//point_del()
		cout<<"4. 적립금 확인"<<endl;				//point_hak()
		cout<<"4. 적립금 수정"<<endl;				//point_change()
		cout<<"5. 회원정보 수정"<<endl;				//People_change_info()
		cout<<"6. 로그아웃 및 사용자 변경"<<endl; 	//People_change()
		cout<<"7. 프로그램 종료"<<endl;				//Exit;
		cin >>  menu_input;
		switch(menu_input){
			case 1:store_input();		break;
			case 2:point_add();			break;
			case 3:point_del();			break;
			case 4:point_hak();			break;
			case 5:point_change(); 		break;
			case 6:People_change_info();break;
			case 7:People_change(); 	break;
			case 8: cout<<"프로그램을 종료하시겠습니까?(Y/N)";
					cin >> answer;
					//answer == 'N' ? break : exit(0);
			default: cout <<"메뉴에 존재하는 번호를 골라 주세요"<<endl; continue;
		}
	}
	
	
	
}

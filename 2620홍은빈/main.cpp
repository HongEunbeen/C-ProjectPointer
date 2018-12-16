#include "header.h"
// header 파일에 클래스와 함수선언 , 네임 스페이스 공간 선언등을 넣어 한번에 모든 파일이 사용할 수 있도록 함
// 사용자로부터 가게별 적립금을 확인하고 관리할 수 있도록 도와주는 프로그램
 
int main(){
		char answer_char[10];
	
		cout << "○●○●○●○●환영합니다○●○●○●○●"<<endl;
		cout << "○여기는 포인트 관리를 도와주는 곳 입니다●"<<endl; 
		cout << "회원가입을 진행 하겠습니다."<<endl;//회원가입을 먼저 진행하여 회원을 만들고 시작함	
		Join_person();
		cout <<"ddd";
		system("CLS");
		cout <<"이제부터 사용하실 수 있습니다."<<endl;
	Opening();
	
	while(1){
		system("CLS");
		info_name();
		int menu_input;
		cout<<"메뉴"<<endl;
		cout<<"1. 적립 가게 추가"<<endl;			//store_input()
		cout<<"2. 적립금 적립"<<endl;				//point_add()
		cout<<"3. 적립금 사용"<<endl;				//point_del()
		cout<<"4. 적립금 확인"<<endl;				//point_hak()
		cout<<"5. 적립금 수정"<<endl;				//point_change()
		cout<<"6. 회원정보 수정"<<endl;				//People_change_info()
		cout<<"7. 로그아웃 및 사용자 변경"<<endl; 	//People_change()
		cout<<"8. 프로그램 종료"<<endl;				//Exit;
		cin >>  menu_input;
		switch(menu_input){//switch-case문을 사용하여 각자에 맞는 함수를 호출함 
			case 1: store_input();			break;
			case 2: point_add();			break;
			case 3: point_del();			break;
			case 4: point_hak();			break;
			case 5: point_change(); 		break;
			case 6: People_change_info();  	break;
			case 7: People_change(); 		break;
			case 8: 
				cout<<"프로그램을 종료하시겠습니까?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'y' || *answer_char == 'Y'){
					return 0;//프로그램을 종료 시킴					
				}
			default: cout <<"메뉴에 존재하는 번호를 골라 주세요"<<endl; continue;
		}
	}
	
	
	
}

#include "header.h"
char answer_char[10];//전역 변수로 모든 함수가 사용 가능케 함 
int answer_int;

static string Useing_PWD;
static string Useing_ID;
static int Useing_index;
static int count;
static People People[10];

void Opening(){
	int answer;
	char answer_char[10];
	while(1){
		cout << "1. 로그인하기 2. 회원가입하기(추가)"<<endl;			 
		cin >> answer;
		if(answer == 1){
			bool login_hak = Login_person();//login성공시 ture 실패시 false를 반환해줌 
			if(login_hak == true){
				break;
			}else{
				cout << "로그인에 실패하셨습니다"<<endl;
				cout << "4초 후 로그인이 가능합니다"<<endl;
				Sleep(4000);//4초 멈춤 
				system("CLS");//화면을 비워줌 
			}
		}else if(answer == 2){
			cout <<"회원가입을 진행합니다"<<endl;
			Join_person();
			system("CLS");	 
		}
	}
} 
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
		fflush(stdin);
		getline(cin,Join_Info.person_ID,'\n');
		for(int i = 0; i < count; i++){
			if(Join_Info.person_ID == People[i].ID){
				cout << "이미 있는 아이디 입니다. 확인해 주세요" << endl;//아이디 중복 확인을 해줌으로써 혼란 방지 
				Join_Info.person_ID.clear();
				find = 1; break;
			}else find = 0;
		}
	}while(find == 1);
	cout <<"\n비밀번호 : ";
	cin >> Join_Info.person_pwd;
	do{
		cout <<"비밀번호 확인 : ";
		cin >> Join_Info.person_pwd_hak;
	}while(Join_Info.person_pwd != Join_Info.person_pwd_hak);//비밀번호 확인과 비밀번호가 같을때 까지 do while로 반복 

	People[count].ID = Join_Info.person_ID;// People객체배열에 삽입하여 회원을 등록시켜줌 
	People[count].PWD = Join_Info.person_pwd;
	People[count].person_info = Join_Info;
	People[count].person_info.store_count = 0;
	count++;
}
bool Login_person(){
	string Input_ID, Input_pwd;
	int a = 0,b = 0;
	cout << "ID 입력 : ";
	cin >> Input_ID;
	cout << "비밀번호 입력 : ";
	cin >> Input_pwd;
	for(int i = 0; i < sizeof(People)/sizeof(People[0]); i++){
		if(Input_ID == People[i].ID){
			if(Input_pwd == People[i].PWD){
				cout <<"로그인에 성공하셨습니다."<< endl;
				b = 1;
				Useing_ID = People[i].ID;//로그인 성공시 현재의 비밀번호를 useing에 저장해서 다른 함수들도 공유 할 수 있도록 함 
				Useing_PWD = People[i].PWD;
				Useing_index = i;
			}
			a = 1;
		}
	}
	if(b == 1 && a ==1){
		return true;
	}
	if(a == 1 && b != 1){
		cout <<"비밀번호를 확인해 주세요"<<endl;
		return false;
	}
	if(a != 1){
		cout <<"아이디를 확인해 주세요"<<endl; 
		return false;
	}
	//비밀번호를 틀렸을 떄 아이디를 틀렸을 때 를 구분해서 알려줌 
	
}
void info_name(){
	cout << People[Useing_index].person_info.person_name <<"님 어서오세요 "<<endl;
} 
void store_input(){
	system("CLS");
	while(1){ 
		int store_count = People[Useing_index].person_info.store_count++;
		cout<<"가게 추가를 시작합니다."<<endl;
		fflush(stdin);
		cout<<"가게 이름 : ";
		getline(cin, People[Useing_index].person_info.store[store_count].store_name, '\n');//공백 처리를 도와줌 
		cout<<"기본 적립금 : ";
		cin>> People[Useing_index].person_info.store[store_count].percent;
		cout<<"가게 특이사항 : ";
		fflush(stdin);//버퍼를 비워줌 
		getline(cin,People[Useing_index].person_info.store[store_count].store_info, '\n');
		fflush(stdin);
		
		People[Useing_index].person_info.store[store_count].pointer = 0;//가게를 생성할때 pointer를 0으로 설정해줌으로써 쓰레기값 생성 방지 
		
		cout<<"가게를 더 추가하시겠습니까?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;//char형인 answer_char을 *를 통해서 값 비교  
	}
	
}
void point_add(){
	system("CLS");
	if(People[Useing_index].person_info.store[0].store_name != ""){//만약 하나의 가게라도 없으면 실행 되지 않게 함 
		while(1){
			int store_count = People[Useing_index].person_info.store_count;
			int answer_add;
			double pointer_var, pointer_add; 
			cout<<"적립금을 추가할 가게를 선택해 주세요"<<endl;
			for(int i = 0; i < store_count; i++){
				cout << (i+1) << "." << People[Useing_index].person_info.store[i].store_name<<"\t";
			}cout<<endl;
			cin>> answer_int;
			if(store_count < answer_int){
				continue;
			}
			cout<<"적립금 적립 방법을 선택해 주세요"<<endl;
			cout<<"1. 기존 방식		2. 사용자 입력 방식"<<endl;//기존방식(percent)으로 적립금이 쌓일 것인지 사용자 입력방식으로 쌓일 것인지 결정함 
			cin>> answer_add;
			if(answer_add == 2){
				cout <<"적립할 적립금를 적어주세요"<<endl;
				cin >> pointer_var;
				cout<<"적용되셨습니다.";
			} 
			cout<<"사용 금액 : ";
			cin >>pointer_add;
		
			if(answer_add == 2){
				People[Useing_index].person_info.store[answer_int-1].pointer  =+ (pointer_add * pointer_var / 100);//포인트 계산 식 
			}else{
				People[Useing_index].person_info.store[answer_int-1].pointer  =+ (pointer_add * People[Useing_index].person_info.store[answer_int-1].percent / 100);
			}
			fflush(stdin);
			cout<<"적립금을 더 적립하시겠습니까?(Y/N)"<<endl;
			cin >> answer_char;
			if(*answer_char == 'N' || *answer_char == 'n') break;
		}
	}else{
		cout << "가게를 먼저 추가해 주세요"<< endl;
		cout << "3초 후 다시 메뉴로 돌아갑니다"<<endl; //한개의 가게라도 없을시 다시 메뉴로 돌아가기 위한 안내서와 3초의 대기시간 
		Sleep(3000);
	}
}
void point_del(){
	system("CLS");
	if(People[Useing_index].person_info.store[0].store_name != ""){
		while(1){
			int store_count = People[Useing_index].person_info.store_count;
			int answer_del;
			int pointer_del; 
			cout<<"적립금을 사용할 가게를 선택해 주세요"<<endl;
			for(int i = 0; i < store_count; i++){
				cout << (i+1) << "." << People[Useing_index].person_info.store[i].store_name<<"\t";
			}cout<<endl;
			cin>> answer_int;
			cout <<"사용한 적립금을 적어주세요"<<endl;
			cin>>pointer_del;
			if(People[Useing_index].person_info.store[answer_int-1].pointer - pointer_del < 0){//answer_int에 -1은 배열에 맞게 사용하기 위해서  
				cout<<"적립금을 사용하실 수 없습니다."<<endl;
				cout<<"적립금을 확인해 주시길 바랍니다."<<endl; //만약에 적립금이 사용한 적립금보다 적으면 처리불가되게 만듦 
			}else{
				cout<<"적용되셨습니다.";
				People[Useing_index].person_info.store[answer_int-1].pointer -= pointer_del;
			}
			cout<<"적립금을 더 적립하시겠습니까?(Y/N)"<<endl;
			cin >> answer_char;
			if(*answer_char == 'N' || *answer_char == 'n') break;
		}		
	}else{
		cout << "가게를 먼저 추가해 주세요"<< endl;
		cout << "3초 후 다시 메뉴로 돌아갑니다"<<endl;
		Sleep(3000); 
	}

}
void point_hak(){
	system("CLS");
	if(People[Useing_index].person_info.store[0].store_name != ""){
		while(1){
			int store_count = People[Useing_index].person_info.store_count;
			cout<<"적립금을 확인할 가게를 선택해 주세요"<<endl;
			for(int i = 0; i < store_count; i++){
				cout << (i+1) << "." << People[Useing_index].person_info.store[i].store_name<<"	";
			}cout<<endl;
			cin>> answer_int;
			cout << People[Useing_index].person_info.store[answer_int-1].store_name<< "의 적립금은";
			cout << People[Useing_index].person_info.store[answer_int-1].pointer<< "이고,"<<endl;
			cout << "가게 정보는" << People[Useing_index].person_info.store[answer_int-1].store_info<< "입니다"<<endl;	
			cout << "적립은 "<< People[Useing_index].person_info.store[answer_int-1].percent <<"씩 됩니다"<<endl;
			//한 문자으로써 적립금을 확인 할 수 있음 
			cout<<"적립금을 더 확인하시겠습니까?(Y/N)"<<endl;
			cin >> answer_char;
			if(*answer_char == 'N' || *answer_char == 'n') break;	
		}
	}else{
		cout << "가게를 먼저 추가해 주세요"<< endl;
		cout << "3초 후 다시 메뉴로 돌아갑니다"<<endl;
		Sleep(3000); 
	}		
}
void point_change(){//가게 정보를 수정함 
	system("CLS");
	int answer_int_sub;
	double change_percent;
	string change_name,change_info;
	if(People[Useing_index].person_info.store[0].store_name != ""){
		while(1){
			int store_count = People[Useing_index].person_info.store_count;
			cout<<"정보를 변경할 가게를 선택해 주세요"<<endl;
			for(int i = 0; i < store_count; i++){
				cout << (i+1) << "." << People[Useing_index].person_info.store[i].store_name<<"	";
			}cout<<endl;
			cin>> answer_int;
			cout<<"수정할 부분을 선택해 주세요"<<endl;
			cout << "1. 가게 이름	2. 포인트(%)	3. 가게 정보 "<<endl; 
			cin >> answer_int_sub;
			switch(answer_int_sub){
				case 1:
					cout << "변경 이름 : ";
					cin >> change_name;
					cout << People[Useing_index].person_info.store[answer_int-1].store_name<< "을" << change_name <<"으로 변경 하시겠습니까?(Y/N)";
					cin >> answer_char;
					if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.store[answer_int-1].store_name = change_name;
					break; 
				case 2:
					cout << "변경 포인트 : ";
					cin >> change_percent;
					fflush(stdin);
					cout << People[Useing_index].person_info.store[answer_int-1].percent<< "을" << change_percent <<"으로 변경 하시겠습니까?(Y/N)";
					cin >> answer_char;
					if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.store[answer_int-1].percent = change_percent;
					break; 
				case 3:
					cout << "변경 정보 : ";
					cin >> change_info;
					cout << People[Useing_index].person_info.store[answer_int-1].store_info<< "을" << change_info <<"으로 변경 하시겠습니까?(Y/N)";
					cin >> answer_char;
					if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.store[answer_int-1].store_info = change_info;
					break; 
				default: break;
			}
			fflush(stdin);
			cout<<"가게정보를 더 수정하시겠습니까?(Y/N)"<<endl;
			cin >> answer_char;
			if(*answer_char == 'N' || *answer_char == 'n') break;
		}
	}else{
		cout << "가게를 먼저 추가해 주세요"<< endl;
		cout << "3초 후 다시 메뉴로 돌아갑니다"<<endl; 
		Sleep(3000);
	}
}
void People_change_info(){
	system("CLS");
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
				cout << "(한 자리수만 가능)변경 성별 : ";
				cin >> change_gender; 
				cout <<People[Useing_index].person_info.person_name<<"을"<<change_name<<"로 변경하시겠습니까?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') *People[Useing_index].person_info.person_gender = *change_gender;
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
				if(change_pwd_hak != Useing_PWD)break;//원래 비밀번호와 맞지 않으면 변경 불가 
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
	system("CLS");
	cout << "로그아웃 하기" << endl;
	cout << "로그아웃을 하시겠습니까?(Y/N)"<<endl;
	cin >> answer_char;
	if(*answer_char == 'Y' || *answer_char == 'y'){
		system("cls");
		Opening();//로그아웃을 누르면 처음 실행화면으로 돌아감 
	}	

}

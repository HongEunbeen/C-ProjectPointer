#include "header.h"



void Join_person(){
	Person_Info Join_Info;
	cout <<"������ ������ ������ �ּ��� "<< endl;
	cout <<"�̸� : ";
	cin >> Join_Info.person_name; 
	cout <<"\n���� : ";
	cin >> Join_Info.person_gender;
	cout <<"\n���� : ";
	cin >> Join_Info.person_age;
	cout <<"\n��ȭ��ȣ : ";
	cin >> Join_Info.person_phone;
	cout <<"\n���� : ";
	cin >> Join_Info.person_brith;
	int find = 0;
	do{
		cout <<"\n���̵� : ";
		cin >> Join_Info.person_ID;
		for(int i = 0; i < sizeof(People)/sizeof(People[0]); i++){
			if(Join_Info.person_ID == People[i].ID){
				break;
			}else find = 1;
		}
	}while(find == 0);
	cout <<"\n��й�ȣ : ";
	cin >> Join_Info.person_pwd;
	do{
		cout <<"��й�ȣ Ȯ�� : ";
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
	cout << "ID �Է� : ";
	cin >> Input_ID;
	cout << "��й�ȣ �Է� : ";
	cin >> Input_pwd;
	for(int i = 0; i < sizeof(People)/sizeof(People[0]); i++){
		if(Input_ID == People[i].ID){
			if(Input_pwd == People[i].PWD){
				cout <<"�α��ο� �����ϼ̽��ϴ�."<< endl; break;
				b = 1;
				Useing_ID = People[i].ID;
				Useing_PWD = People[i].PWD;
				Useing_index = i;
			}
			a = 1;
		}
	}
	if(a == 1 && b != 1)cout <<"��й�ȣ�� Ȯ���� �ּ���"<<endl;
	if(a != 1)cout <<"���̵� Ȯ���� �ּ���"<<endl; 
};

void store_input(){
	while(1){ 
		cout<<"���� �߰��� �����մϴ�."<<endl;
		cout<<"���� �̸� : ";
		cin>> People[store_count].person_info.store[store_count].store_name;
		cout<<"�⺻ ������ : ";
		cin>> People[store_count].person_info.store[store_count].pointer;
		cout<<"���� Ư�̻��� : ";
		cin>> People[store_count].person_info.store[store_count].store_info;
		store_count++;
		cout<<"���Ը� �� �߰��Ͻðڽ��ϱ�?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;
	}
	
}
void point_add(){
	while(1){
		int answer_add;
		int pointer_var, pointer_add; 
		cout<<"�������� �߰��� ���Ը� ������ �ּ���"<<endl;
		for(int i = 0; i < store_count; i++){
			cout << (i+1) << "." << People[i].person_info.store[i].store_name<<"	";
		}cout<<endl;
		cin>> answer_int;
		cout<<"������ ���� ����� ������ �ּ���"<<endl;
		cout<<"1. ���� ���		2. ����� �Է� ���";
		cin>> answer_add;
		if(answer_add == 2){
			cout <<"������ �����ݸ� �����ּ���"<<endl;
			cin>>pointer_var;
			cout<<"����Ǽ̽��ϴ�.";
		} 
		cout<<"��� �ݾ� : ";
		cin >>pointer_add;
		People[0].person_info.store[answer_int-1].pointer * 10;
		
		cout<<"�������� �� �����Ͻðڽ��ϱ�?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;
	}
}
void point_del(){
	while(1){
		int answer_del;
		int pointer_del; 
		cout<<"�������� ����� ���Ը� ������ �ּ���"<<endl;
		for(int i = 0; i < store_count; i++){
			cout << (i+1) << "." << People[i].person_info.store[i].store_name<<"	";
		}cout<<endl;
		cin>> answer_int;
		cout <<"����� �������� �����ּ���"<<endl;
		cin>>pointer_del;
		if(People[Useing_index].person_info.store[answer_int-1].pointer - pointer_del < 0){
			cout<<"�������� ����Ͻ� �� �����ϴ�."<<endl;
			cout<<"�������� Ȯ���� �ֽñ� �ٶ��ϴ�."<<endl; 
		}else{
			cout<<"����Ǽ̽��ϴ�.";
			People[Useing_index].person_info.store[answer_int-1].pointer -= pointer_del;
		}
		cout<<"�������� �� �����Ͻðڽ��ϱ�?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;
	}
}
void point_hak(){
	while(1){
		cout<<"�������� Ȯ���� ���Ը� ������ �ּ���"<<endl;
		for(int i = 0; i < store_count; i++){
			cout << (i+1) << "." << People[i].person_info.store[i].store_name<<"	";
		}cout<<endl;
		cin>> answer_int;
		cout << People[answer_int-1].person_info.store[answer_int-1].store_name<< "�� ��������";
		cout << People[answer_int-1].person_info.store[answer_int-1].pointer<< "�̰�,"<<endl;
		cout << "���� ������" << People[answer_int-1].person_info.store[answer_int-1].store_info<< "�Դϴ�"<<endl;	
		
		cout<<"�������� �� Ȯ���Ͻðڽ��ϱ�?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;	
	}
	
}
void point_change(){
	int answer_int_sub, change_pointer;
	string change_name,change_info;
	
	while(1){
		cout<<"������ ������ ���Ը� ������ �ּ���"<<endl;
		for(int i = 0; i < store_count; i++){
			cout << (i+1) << "." << People[i].person_info.store[i].store_name<<"	";
		}cout<<endl;
		cin>> answer_int;
		cout<<"������ �κ��� ������ �ּ���"<<endl;
		cout << "1. " << People[Useing_index].person_info.store[answer_int].store_name<<
				"2. " << People[Useing_index].person_info.store[answer_int].pointer<<
				"3. " << People[Useing_index].person_info.store[answer_int].store_info<<endl;
		cin >> answer_int_sub;
		switch(answer_int_sub){
			case 1:
				cout << "���� �̸� : ";
				cin >> change_name;
				cout << People[Useing_index].person_info.store[answer_int].store_name<< "��" << change_name <<"���� ���� �Ͻðڽ��ϱ�?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.store[answer_int].store_name = change_name;
				break; 
			case 2:
				cout << "���� ����Ʈ : ";
				cin >> change_pointer;
				cout << People[Useing_index].person_info.store[answer_int].pointer<< "��" << change_pointer <<"���� ���� �Ͻðڽ��ϱ�?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.store[answer_int].pointer = change_pointer;
				break; 
			case 3:
				cout << "���� ���� : ";
				cin >> change_info;
				cout << People[Useing_index].person_info.store[answer_int].store_info<< "��" << change_info <<"���� ���� �Ͻðڽ��ϱ�?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.store[answer_int].store_info = change_info;
				break; 
			default: break;
		}
		
		cout<<"���������� �� �����Ͻðڽ��ϱ�?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;
	}
}
void People_change_info(){
	string change_name, change_pwd, change_pwd_hak; ;
	char change_gender[10];
	int  change_age, change_phone, change_brith;
	while(1){
		cout<<"������ ȸ�������� ������ �ּ��� "<<endl;
		cout<< "�̸� : " << People[Useing_index].person_info.person_name<<endl;
		cout<< "���� : " << People[Useing_index].person_info.person_gender<<endl;
		cout<< "���� : " << People[Useing_index].person_info.person_age<<endl;		
		cout<< "��ȭ��ȣ : " << People[Useing_index].person_info.person_phone<<endl;
		cout<< "���� : " << People[Useing_index].person_info.person_brith<<endl;		
		cout<< "��й�ȣ : " << People[Useing_index].person_info.person_pwd<<endl;
		cin>> answer_int;
		
		switch(answer_int){
			case 1:
				cout << "���� �̸� : ";
				cin >> change_name; 
				cout <<People[Useing_index].person_info.person_name<<"��"<<change_name<<"�� �����Ͻðڽ��ϱ�?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.person_name = change_name;
				break;
			case 2:
				cout << "���� ���� : ";
				cin >> *change_gender; 
				cout <<People[Useing_index].person_info.person_name<<"��"<<change_name<<"�� �����Ͻðڽ��ϱ�?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.person_name = change_name;
				break;
			case 3:
				cout << "���� ���� : ";
				cin >> change_age; 
				cout <<People[Useing_index].person_info.person_age<<"��"<<change_age<<"�� �����Ͻðڽ��ϱ�?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.person_age = change_age;
				break;
			
			case 4:
				cout << "���� ��ȣ : ";
				cin >> change_phone; 
				cout <<People[Useing_index].person_info.person_phone<<"��"<<change_phone<<"�� �����Ͻðڽ��ϱ�?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.person_phone = change_phone;
				break;
				
			case 5:
				cout << "���� ���� : ";
				cin >> change_brith; 
				cout <<People[Useing_index].person_info.person_brith<<"��"<<change_brith<<"�� �����Ͻðڽ��ϱ�?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.person_brith = change_brith;
				break;
				
			case 6:
				cout << "���� ��й�ȣ : ";
				cin >> change_pwd_hak;
				if(change_pwd_hak != Useing_PWD)break;
				cout << "���� ��й�ȣ : ";
				cin >> change_pwd; 
				cout <<People[0].person_info.person_pwd<<"��"<<change_pwd<<"�� �����Ͻðڽ��ϱ�?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') People[0].person_info.person_pwd = change_pwd;
				break;
				
			default: cout<<"�����ϴ� ���ڸ� ������ �ּ���"<<endl; break;
		}	
		cout<<"ȸ�������� �� �����Ͻðڽ��ϱ�?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;	
	}
	
}
void People_change(){
		cout << "1. �α׾ƿ� �ϱ�	2. ����� �����ϱ�"<<endl;
		cin >> answer_int;
		switch(answer_int){
			case 1: cout << "�α׾ƿ��� �Ͻðڽ��ϱ�?"<<endl;
					cin >> *answer_char;
					if(*answer_char == 'N' || *answer_char == 'n') break;
			case 2: 
				break;
			default: break;
		}
		cout<<"�⺻ ȭ������ �����ðڽ��ϱ�?";
		system("cls");
}

#include "header.h"
char answer_char[10];//���� ������ ��� �Լ��� ��� ������ �� 
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
		cout << "1. �α����ϱ� 2. ȸ�������ϱ�(�߰�)"<<endl;			 
		cin >> answer;
		if(answer == 1){
			bool login_hak = Login_person();//login������ ture ���н� false�� ��ȯ���� 
			if(login_hak == true){
				break;
			}else{
				cout << "�α��ο� �����ϼ̽��ϴ�"<<endl;
				cout << "4�� �� �α����� �����մϴ�"<<endl;
				Sleep(4000);//4�� ���� 
				system("CLS");//ȭ���� ����� 
			}
		}else if(answer == 2){
			cout <<"ȸ�������� �����մϴ�"<<endl;
			Join_person();
			system("CLS");	 
		}
	}
} 
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
		fflush(stdin);
		getline(cin,Join_Info.person_ID,'\n');
		for(int i = 0; i < count; i++){
			if(Join_Info.person_ID == People[i].ID){
				cout << "�̹� �ִ� ���̵� �Դϴ�. Ȯ���� �ּ���" << endl;//���̵� �ߺ� Ȯ���� �������ν� ȥ�� ���� 
				Join_Info.person_ID.clear();
				find = 1; break;
			}else find = 0;
		}
	}while(find == 1);
	cout <<"\n��й�ȣ : ";
	cin >> Join_Info.person_pwd;
	do{
		cout <<"��й�ȣ Ȯ�� : ";
		cin >> Join_Info.person_pwd_hak;
	}while(Join_Info.person_pwd != Join_Info.person_pwd_hak);//��й�ȣ Ȯ�ΰ� ��й�ȣ�� ������ ���� do while�� �ݺ� 

	People[count].ID = Join_Info.person_ID;// People��ü�迭�� �����Ͽ� ȸ���� ��Ͻ����� 
	People[count].PWD = Join_Info.person_pwd;
	People[count].person_info = Join_Info;
	People[count].person_info.store_count = 0;
	count++;
}
bool Login_person(){
	string Input_ID, Input_pwd;
	int a = 0,b = 0;
	cout << "ID �Է� : ";
	cin >> Input_ID;
	cout << "��й�ȣ �Է� : ";
	cin >> Input_pwd;
	for(int i = 0; i < sizeof(People)/sizeof(People[0]); i++){
		if(Input_ID == People[i].ID){
			if(Input_pwd == People[i].PWD){
				cout <<"�α��ο� �����ϼ̽��ϴ�."<< endl;
				b = 1;
				Useing_ID = People[i].ID;//�α��� ������ ������ ��й�ȣ�� useing�� �����ؼ� �ٸ� �Լ��鵵 ���� �� �� �ֵ��� �� 
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
		cout <<"��й�ȣ�� Ȯ���� �ּ���"<<endl;
		return false;
	}
	if(a != 1){
		cout <<"���̵� Ȯ���� �ּ���"<<endl; 
		return false;
	}
	//��й�ȣ�� Ʋ���� �� ���̵� Ʋ���� �� �� �����ؼ� �˷��� 
	
}
void info_name(){
	cout << People[Useing_index].person_info.person_name <<"�� ������� "<<endl;
} 
void store_input(){
	system("CLS");
	while(1){ 
		int store_count = People[Useing_index].person_info.store_count++;
		cout<<"���� �߰��� �����մϴ�."<<endl;
		fflush(stdin);
		cout<<"���� �̸� : ";
		getline(cin, People[Useing_index].person_info.store[store_count].store_name, '\n');//���� ó���� ������ 
		cout<<"�⺻ ������ : ";
		cin>> People[Useing_index].person_info.store[store_count].percent;
		cout<<"���� Ư�̻��� : ";
		fflush(stdin);//���۸� ����� 
		getline(cin,People[Useing_index].person_info.store[store_count].store_info, '\n');
		fflush(stdin);
		
		People[Useing_index].person_info.store[store_count].pointer = 0;//���Ը� �����Ҷ� pointer�� 0���� �����������ν� �����Ⱚ ���� ���� 
		
		cout<<"���Ը� �� �߰��Ͻðڽ��ϱ�?(Y/N)"<<endl;
		cin >> answer_char;
		if(*answer_char == 'N' || *answer_char == 'n') break;//char���� answer_char�� *�� ���ؼ� �� ��  
	}
	
}
void point_add(){
	system("CLS");
	if(People[Useing_index].person_info.store[0].store_name != ""){//���� �ϳ��� ���Զ� ������ ���� ���� �ʰ� �� 
		while(1){
			int store_count = People[Useing_index].person_info.store_count;
			int answer_add;
			double pointer_var, pointer_add; 
			cout<<"�������� �߰��� ���Ը� ������ �ּ���"<<endl;
			for(int i = 0; i < store_count; i++){
				cout << (i+1) << "." << People[Useing_index].person_info.store[i].store_name<<"\t";
			}cout<<endl;
			cin>> answer_int;
			if(store_count < answer_int){
				continue;
			}
			cout<<"������ ���� ����� ������ �ּ���"<<endl;
			cout<<"1. ���� ���		2. ����� �Է� ���"<<endl;//�������(percent)���� �������� ���� ������ ����� �Է¹������ ���� ������ ������ 
			cin>> answer_add;
			if(answer_add == 2){
				cout <<"������ �����ݸ� �����ּ���"<<endl;
				cin >> pointer_var;
				cout<<"����Ǽ̽��ϴ�.";
			} 
			cout<<"��� �ݾ� : ";
			cin >>pointer_add;
		
			if(answer_add == 2){
				People[Useing_index].person_info.store[answer_int-1].pointer  =+ (pointer_add * pointer_var / 100);//����Ʈ ��� �� 
			}else{
				People[Useing_index].person_info.store[answer_int-1].pointer  =+ (pointer_add * People[Useing_index].person_info.store[answer_int-1].percent / 100);
			}
			fflush(stdin);
			cout<<"�������� �� �����Ͻðڽ��ϱ�?(Y/N)"<<endl;
			cin >> answer_char;
			if(*answer_char == 'N' || *answer_char == 'n') break;
		}
	}else{
		cout << "���Ը� ���� �߰��� �ּ���"<< endl;
		cout << "3�� �� �ٽ� �޴��� ���ư��ϴ�"<<endl; //�Ѱ��� ���Զ� ������ �ٽ� �޴��� ���ư��� ���� �ȳ����� 3���� ���ð� 
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
			cout<<"�������� ����� ���Ը� ������ �ּ���"<<endl;
			for(int i = 0; i < store_count; i++){
				cout << (i+1) << "." << People[Useing_index].person_info.store[i].store_name<<"\t";
			}cout<<endl;
			cin>> answer_int;
			cout <<"����� �������� �����ּ���"<<endl;
			cin>>pointer_del;
			if(People[Useing_index].person_info.store[answer_int-1].pointer - pointer_del < 0){//answer_int�� -1�� �迭�� �°� ����ϱ� ���ؼ�  
				cout<<"�������� ����Ͻ� �� �����ϴ�."<<endl;
				cout<<"�������� Ȯ���� �ֽñ� �ٶ��ϴ�."<<endl; //���࿡ �������� ����� �����ݺ��� ������ ó���Ұ��ǰ� ���� 
			}else{
				cout<<"����Ǽ̽��ϴ�.";
				People[Useing_index].person_info.store[answer_int-1].pointer -= pointer_del;
			}
			cout<<"�������� �� �����Ͻðڽ��ϱ�?(Y/N)"<<endl;
			cin >> answer_char;
			if(*answer_char == 'N' || *answer_char == 'n') break;
		}		
	}else{
		cout << "���Ը� ���� �߰��� �ּ���"<< endl;
		cout << "3�� �� �ٽ� �޴��� ���ư��ϴ�"<<endl;
		Sleep(3000); 
	}

}
void point_hak(){
	system("CLS");
	if(People[Useing_index].person_info.store[0].store_name != ""){
		while(1){
			int store_count = People[Useing_index].person_info.store_count;
			cout<<"�������� Ȯ���� ���Ը� ������ �ּ���"<<endl;
			for(int i = 0; i < store_count; i++){
				cout << (i+1) << "." << People[Useing_index].person_info.store[i].store_name<<"	";
			}cout<<endl;
			cin>> answer_int;
			cout << People[Useing_index].person_info.store[answer_int-1].store_name<< "�� ��������";
			cout << People[Useing_index].person_info.store[answer_int-1].pointer<< "�̰�,"<<endl;
			cout << "���� ������" << People[Useing_index].person_info.store[answer_int-1].store_info<< "�Դϴ�"<<endl;	
			cout << "������ "<< People[Useing_index].person_info.store[answer_int-1].percent <<"�� �˴ϴ�"<<endl;
			//�� �������ν� �������� Ȯ�� �� �� ���� 
			cout<<"�������� �� Ȯ���Ͻðڽ��ϱ�?(Y/N)"<<endl;
			cin >> answer_char;
			if(*answer_char == 'N' || *answer_char == 'n') break;	
		}
	}else{
		cout << "���Ը� ���� �߰��� �ּ���"<< endl;
		cout << "3�� �� �ٽ� �޴��� ���ư��ϴ�"<<endl;
		Sleep(3000); 
	}		
}
void point_change(){//���� ������ ������ 
	system("CLS");
	int answer_int_sub;
	double change_percent;
	string change_name,change_info;
	if(People[Useing_index].person_info.store[0].store_name != ""){
		while(1){
			int store_count = People[Useing_index].person_info.store_count;
			cout<<"������ ������ ���Ը� ������ �ּ���"<<endl;
			for(int i = 0; i < store_count; i++){
				cout << (i+1) << "." << People[Useing_index].person_info.store[i].store_name<<"	";
			}cout<<endl;
			cin>> answer_int;
			cout<<"������ �κ��� ������ �ּ���"<<endl;
			cout << "1. ���� �̸�	2. ����Ʈ(%)	3. ���� ���� "<<endl; 
			cin >> answer_int_sub;
			switch(answer_int_sub){
				case 1:
					cout << "���� �̸� : ";
					cin >> change_name;
					cout << People[Useing_index].person_info.store[answer_int-1].store_name<< "��" << change_name <<"���� ���� �Ͻðڽ��ϱ�?(Y/N)";
					cin >> answer_char;
					if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.store[answer_int-1].store_name = change_name;
					break; 
				case 2:
					cout << "���� ����Ʈ : ";
					cin >> change_percent;
					fflush(stdin);
					cout << People[Useing_index].person_info.store[answer_int-1].percent<< "��" << change_percent <<"���� ���� �Ͻðڽ��ϱ�?(Y/N)";
					cin >> answer_char;
					if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.store[answer_int-1].percent = change_percent;
					break; 
				case 3:
					cout << "���� ���� : ";
					cin >> change_info;
					cout << People[Useing_index].person_info.store[answer_int-1].store_info<< "��" << change_info <<"���� ���� �Ͻðڽ��ϱ�?(Y/N)";
					cin >> answer_char;
					if(*answer_char == 'Y' || *answer_char == 'y') People[Useing_index].person_info.store[answer_int-1].store_info = change_info;
					break; 
				default: break;
			}
			fflush(stdin);
			cout<<"���������� �� �����Ͻðڽ��ϱ�?(Y/N)"<<endl;
			cin >> answer_char;
			if(*answer_char == 'N' || *answer_char == 'n') break;
		}
	}else{
		cout << "���Ը� ���� �߰��� �ּ���"<< endl;
		cout << "3�� �� �ٽ� �޴��� ���ư��ϴ�"<<endl; 
		Sleep(3000);
	}
}
void People_change_info(){
	system("CLS");
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
				cout << "(�� �ڸ����� ����)���� ���� : ";
				cin >> change_gender; 
				cout <<People[Useing_index].person_info.person_name<<"��"<<change_name<<"�� �����Ͻðڽ��ϱ�?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'Y' || *answer_char == 'y') *People[Useing_index].person_info.person_gender = *change_gender;
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
				if(change_pwd_hak != Useing_PWD)break;//���� ��й�ȣ�� ���� ������ ���� �Ұ� 
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
	system("CLS");
	cout << "�α׾ƿ� �ϱ�" << endl;
	cout << "�α׾ƿ��� �Ͻðڽ��ϱ�?(Y/N)"<<endl;
	cin >> answer_char;
	if(*answer_char == 'Y' || *answer_char == 'y'){
		system("cls");
		Opening();//�α׾ƿ��� ������ ó�� ����ȭ������ ���ư� 
	}	

}

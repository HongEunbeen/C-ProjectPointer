#include "header.h"

int main(){

	int answer; 
	cout << "�ۡܡۡܡۡܡۡ�ȯ���մϴ١ۡܡۡܡۡܡۡ�"<<endl;
	cout << "�ۿ���� ����Ʈ ������ �����ִ� �� �Դϴ١�"<<endl; 
	cout << "ȸ�������� ���� �ϰڽ��ϴ�."<<endl;	
	Join_person();
	system("CLS");
	
	cout <<"�������� ����Ͻ� �� �ֽ��ϴ�."<<endl;
	
	cout << "1. �α����ϱ� 2. ȸ�������ϱ�(�߰�)"<<endl;
		 
	cin >> answer;
	if(answer == 1){
		Login_person();
		
	}else if(answer == 2){
		cout <<"ȸ�������� �����մϴ�"<<endl;
		Join_person();
		system("CLS");	 
	}
	while(1){
		int menu_input;
		cout<<"�޴�"<<endl;
		cout<<"1. ���� ���� �߰�"<<endl;			//store_input()
		cout<<"2. ������ ����"<<endl;				//point_add()
		cout<<"3. ������ ���"<<endl;				//point_del()
		cout<<"4. ������ Ȯ��"<<endl;				//point_hak()
		cout<<"4. ������ ����"<<endl;				//point_change()
		cout<<"5. ȸ������ ����"<<endl;				//People_change_info()
		cout<<"6. �α׾ƿ� �� ����� ����"<<endl; 	//People_change()
		cout<<"7. ���α׷� ����"<<endl;				//Exit;
		cin >>  menu_input;
		switch(menu_input){
			case 1:store_input();		break;
			case 2:point_add();			break;
			case 3:point_del();			break;
			case 4:point_hak();			break;
			case 5:point_change(); 		break;
			case 6:People_change_info();break;
			case 7:People_change(); 	break;
			case 8: cout<<"���α׷��� �����Ͻðڽ��ϱ�?(Y/N)";
					cin >> answer;
					//answer == 'N' ? break : exit(0);
			default: cout <<"�޴��� �����ϴ� ��ȣ�� ��� �ּ���"<<endl; continue;
		}
	}
	
	
	
}

#include "header.h"
// header ���Ͽ� Ŭ������ �Լ����� , ���� �����̽� ���� ������� �־� �ѹ��� ��� ������ ����� �� �ֵ��� ��
// ����ڷκ��� ���Ժ� �������� Ȯ���ϰ� ������ �� �ֵ��� �����ִ� ���α׷�
 
int main(){
		char answer_char[10];
	
		cout << "�ۡܡۡܡۡܡۡ�ȯ���մϴ١ۡܡۡܡۡܡۡ�"<<endl;
		cout << "�ۿ���� ����Ʈ ������ �����ִ� �� �Դϴ١�"<<endl; 
		cout << "ȸ�������� ���� �ϰڽ��ϴ�."<<endl;//ȸ�������� ���� �����Ͽ� ȸ���� ����� ������	
		Join_person();
		cout <<"ddd";
		system("CLS");
		cout <<"�������� ����Ͻ� �� �ֽ��ϴ�."<<endl;
	Opening();
	
	while(1){
		system("CLS");
		info_name();
		int menu_input;
		cout<<"�޴�"<<endl;
		cout<<"1. ���� ���� �߰�"<<endl;			//store_input()
		cout<<"2. ������ ����"<<endl;				//point_add()
		cout<<"3. ������ ���"<<endl;				//point_del()
		cout<<"4. ������ Ȯ��"<<endl;				//point_hak()
		cout<<"5. ������ ����"<<endl;				//point_change()
		cout<<"6. ȸ������ ����"<<endl;				//People_change_info()
		cout<<"7. �α׾ƿ� �� ����� ����"<<endl; 	//People_change()
		cout<<"8. ���α׷� ����"<<endl;				//Exit;
		cin >>  menu_input;
		switch(menu_input){//switch-case���� ����Ͽ� ���ڿ� �´� �Լ��� ȣ���� 
			case 1: store_input();			break;
			case 2: point_add();			break;
			case 3: point_del();			break;
			case 4: point_hak();			break;
			case 5: point_change(); 		break;
			case 6: People_change_info();  	break;
			case 7: People_change(); 		break;
			case 8: 
				cout<<"���α׷��� �����Ͻðڽ��ϱ�?(Y/N)";
				cin >> answer_char;
				if(*answer_char == 'y' || *answer_char == 'Y'){
					return 0;//���α׷��� ���� ��Ŵ					
				}
			default: cout <<"�޴��� �����ϴ� ��ȣ�� ��� �ּ���"<<endl; continue;
		}
	}
	
	
	
}

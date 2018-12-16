#ifndef HEADER_H
#define HEADER_H

#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>


using namespace std;
class Store_Point {
public:
	string store_name;
	string store_info; 
	double percent;
	double pointer;
};

class Person_Info{
public:
	string person_name;
	char person_gender[10];
	int person_age;
	int person_phone;
	int person_brith;
	string person_ID;
	string person_pwd;
	string person_pwd_hak;
	Store_Point store[20];//store ��ü�� ������ 
	int store_count;
};


struct People{
	Person_Info person_info;//class ��ü�� ������ 
	string ID;
	string PWD; 
};
//�Լ��� ��ܿ� ������ �����ν� ����� �� �ֵ��� �� 
void Opening();
bool Login_person();
void info_name();
void Join_person();	
void store_input();
void point_add();
void point_del();
void point_hak();

void point_change();
void People_change_info();
void People_change();


#else
#endif

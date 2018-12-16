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
	Store_Point store[20];//store 객체를 생성함 
	int store_count;
};


struct People{
	Person_Info person_info;//class 객체를 생성함 
	string ID;
	string PWD; 
};
//함수를 상단에 정의해 줌으로써 사용할 수 있도록 함 
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

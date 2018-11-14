#ifndef HEADER_H
#define HEADER_H

#include <cstdlib>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <process.h>


using namespace std;
char answer_char[10];
int answer_int;
int store_count = 0;
static string Useing_PWD;
static string Useing_ID;
static int Useing_index;
static int count;
class Store_Point {
public:
	string store_name;
	string store_info; 
	int pointer;
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
	Store_Point store[20];
};


struct People{
	Person_Info person_info;
	string ID;
	string PWD; 
};

static People People[10];
void Login_person();
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

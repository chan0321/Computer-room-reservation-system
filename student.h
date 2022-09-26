#pragma once
#include<iostream>
#include"identity.h"
#include<string>
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
using namespace std;

class Student:public Identity
{
public:
	Student();
	Student(int id, string name, string pwd);
	virtual void operMenu();
	void applyOrder();
	void showOrder();
	void showAllOrder();
	void cancelOrder();

	int m_Id;
	vector<ComputerRoom>vCom;	//»ú·¿ÈÝÆ÷
};

#pragma once
#include<iostream>
#include<string>
#include"identity.h"
#include"orderFile.h"
#include<vector>
using namespace std;

class Teacher :public Identity
{
public:
	Teacher();
	Teacher(int empId, string name, string pwd);	//有参构造
	virtual void operMenu();
	void showAllOrder();
	void validOrder();	//审核预约
	int m_EmpId;	//职工号
};

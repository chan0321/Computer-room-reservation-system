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
	Teacher(int empId, string name, string pwd);	//�вι���
	virtual void operMenu();
	void showAllOrder();
	void validOrder();	//���ԤԼ
	int m_EmpId;	//ְ����
};

#pragma once
#include<iostream>
using namespace std;

//身份抽象类
class Identity
{
public:
	virtual void operMenu()=0;	//纯虚函数，用于子类菜单的重写
	string m_Name;	//用户名
	string m_Pwd;	//密码
};

#pragma once
#include<iostream>
#include"globalFile.h"
#include<fstream>
#include<map>
#include<string>
using namespace std;

class OrderFile
{
public:
	OrderFile();
	void updataOrder();	//更新预约记录
	template <class T1,class T2>
	void getOrder(T1& t,T2 &m);
	int m_Size;	//记录预约条数
	map<int, map<string, string>>m_orderData;	//记录所有预约信息容器
};


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
	void updataOrder();	//����ԤԼ��¼
	template <class T1,class T2>
	void getOrder(T1& t,T2 &m);
	int m_Size;	//��¼ԤԼ����
	map<int, map<string, string>>m_orderData;	//��¼����ԤԼ��Ϣ����
};


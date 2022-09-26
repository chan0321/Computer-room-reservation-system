#pragma once
#include<iostream>
#include"identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
using namespace std;

class Manager :public Identity
{
public:
	Manager();
	Manager(string name,string pwd);
	virtual void operMenu();
	void addPerson();	//����˺�
	void showPerson();	//�鿴�˺�
	void showComputer();//�鿴������Ϣ
	void cleanFile();	//���ԤԼ��¼
	void initVector();//��ʼ������
	bool checkRepeat(int id, int type);	//����ظ�
	vector<Student>vStu;	//ѧ������
	vector<Teacher>vTea;	//��ʦ����
	vector<ComputerRoom>vCom;//��������
};
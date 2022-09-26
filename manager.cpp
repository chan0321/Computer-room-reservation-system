#include"manager.h"

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();	//��ʼ������

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "��������Ϊ:" << vCom.size() << endl;
}

void Manager::operMenu()
{
	cout << "��ӭ����Ա " << this->m_Name << " ��¼" << endl;
	cout << "1.����˺�" << endl;
	cout << "2.�鿴�˺�" << endl;
	cout << "3.�鿴����" << endl;
	cout << "4.���ԤԼ" << endl;
	cout << "0.ע����¼" << endl;
	cout << "��ѡ�����Ĳ���" << endl;
}

void Manager::addPerson()	//����˺�
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ���˺�" << endl;
	cout << "2.��ӽ�ʦ�˺�" << endl;
	string fileName;	//�����ļ���
	string tip;	//��ʾid��
	string errorTip;	//�ظ�������ʾ

	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)	//���ѧ���˺�
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ��:";
		errorTip = "ѧ���ظ�������������";
	}
	else if(select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����";
		errorTip = "ְ�����ظ�������������";
	}
	else
	{
	cout << "��������,�˳�" << endl;
	return;
	}


	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true)
	{	
		cin >> id;	
		bool ret=checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;

		}
		else
		{
			break;
		}
	}
	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;

	//��ӵ��ļ�
	ofs <<endl<< id << "	" << name << "	" << pwd << "	";
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
}

void printStudent(Student& s)
{
	cout << "ѧ��:" << s.m_Id << " ����:" << s.m_Name << " ����:" << s.m_Pwd << endl;
}

void printTeacher(Teacher &t)
{
	cout << "ְ����:" << t.m_EmpId << " ����:" << t.m_Name << " ����:" << t.m_Pwd << endl;
}

void Manager::showPerson()	//�鿴�˺�
{
	cout << "��ѡ��鿴������" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ����" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "������ʦ��Ϣ����" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()//�鿴������Ϣ
{
	cout << "������Ϣ����" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "�������" << it->m_ComId << " ��������:" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()	//���ԤԼ��¼
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()//��ʼ������
{
	vStu.clear();
	vTea.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);	//��ȡѧ����Ϣ
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);	//��ȡ��ʦ��Ϣ
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	ifs.close();
}
bool Manager::checkRepeat(int id, int type)	//����ظ�
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
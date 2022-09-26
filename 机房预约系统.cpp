#include<iostream>
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"manager.h"
#include"teacher.h"
using namespace std;

//ѧ���Ӳ˵�
void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;

		//����ԤԼ
		if (select == 1)
		{
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}

		//�鿴�Լ���ԤԼ
		else if (select == 2)
		{
			cout << "�鿴ԤԼ���" << endl;
			stu->showOrder();
		}

		//�鿴����ԤԼ
		else if (select == 3)
		{
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
		}

		//ȡ��ԤԼ
		else if (select == 4)
		{
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
		}

		//ע��
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��ʦ�Ӳ˵�
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		
		//�鿴����ԤԼ
		if (select == 1)
		{
			cout << "����ԤԼ��¼" << endl;
			tea->showAllOrder();
		}

		//���ԤԼ
		else if (select == 2)
		{
			tea->validOrder();
		}

		//ע����¼
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����Ա�Ӳ˵�
void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;

		//����˺�
		if (select == 1)
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}

		//�鿴�˺���Ϣ
		else if (select == 2)
		{
			cout << "�鿴�˺���Ϣ" << endl;
			man->showPerson();
		}

		//�鿴������Ϣ
		else if (select == 3)
		{
			cout << "�鿴������Ϣ" << endl;			
			man->showComputer();
		}

		//���ԤԼ��¼
		else if (select == 4)
		{
			cout << "���ԤԼ��¼" << endl;
			man->cleanFile();
		}

		//ע��
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼���ܣ��������ļ����ƣ�����������ͣ�
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	 
	if (type == 1)
	{
		cout << "����������ѧ��:" << endl;
		cin >> id;
	}

	else if (type == 2)
	{
		cout<<"����������ְ����:" << endl;
		cin >> id;
	}

		cout << "�������û���:" << endl;
		cin >> name;
		cout << "����������:" << endl;
		cin >> pwd;

		if (type == 1)	//ѧ�������֤
		{
			int fId;
			string fName;
			string fPwd;
			while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			{
				if (fId == id && fName == name && fPwd == pwd)
				{
					cout << "ѧ����֤��¼�ɹ���" << endl;
					system("pause");
					system("cls");
					person = new Student(id, name, pwd);
					studentMenu(person);
					return;
				}
			}
		}

		else if (type == 2)	//��ʦ�����֤
		{
			int fId;
			string fName;
			string fPwd;
			while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			{
				if (fId == id && fName == name && fPwd == pwd)
				{
					cout << "��ʦ��֤��¼�ɹ���" << endl;
					system("pause");
					system("cls");
					person = new Teacher(id, name, pwd);
					teacherMenu(person);
					return;
				}
			}
		}

		else if (type == 3)	//����Ա�����֤
		{
			string fName;
			string fPwd;
			while (ifs >> fName && ifs >> fPwd)
			{
				if (fName == name && fPwd == pwd)
				{
					cout << "����Ա��֤��¼�ɹ���" << endl;
					system("pause");
					system("cls");
					person = new Manager(name, pwd);
					managerMenu(person);	//�������Ա�Ӳ˵�
					return;
				}
			}
		}

		cout << "��֤��¼ʧ��!" << endl;
		system("pause");
		system("cls");

		return;
}
int main()
{
	int select = 0;
	while (true)
	{
		cout << "*******************��ӭ��������ԤԼϵͳ*******************" << endl;
		cout << "����������������������������"<<endl;
		cout << "|      ��ѡ���������      |" << endl;
		cout << "|        1.ѧ������        |" << endl;
		cout << "|        2.��ʦ            |" << endl;
		cout << "|        3.����Ա          |" << endl;
		cout << "|        0.�˳�            |" << endl;
		cout << "����������������������������" << endl;
		cout << "����������ѡ��" << endl;

		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);//ѧ�����
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);//��ʦ���
			break;
		case 3:
			LoginIn(ADM_FILE, 3);//����Ա���
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
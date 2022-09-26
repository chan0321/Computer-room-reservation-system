#include<iostream>
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"manager.h"
#include"teacher.h"
using namespace std;

//学生子菜单
void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;

		//申请预约
		if (select == 1)
		{
			cout << "申请预约" << endl;
			stu->applyOrder();
		}

		//查看自己的预约
		else if (select == 2)
		{
			cout << "查看预约情况" << endl;
			stu->showOrder();
		}

		//查看所有预约
		else if (select == 3)
		{
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
		}

		//取消预约
		else if (select == 4)
		{
			cout << "取消预约" << endl;
			stu->cancelOrder();
		}

		//注销
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//教师子菜单
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		
		//查看所有预约
		if (select == 1)
		{
			cout << "所有预约记录" << endl;
			tea->showAllOrder();
		}

		//审核预约
		else if (select == 2)
		{
			tea->validOrder();
		}

		//注销登录
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//管理员子菜单
void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;

		//添加账号
		if (select == 1)
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}

		//查看账号信息
		else if (select == 2)
		{
			cout << "查看账号信息" << endl;
			man->showPerson();
		}

		//查看机房信息
		else if (select == 3)
		{
			cout << "查看机房信息" << endl;			
			man->showComputer();
		}

		//清空预约记录
		else if (select == 4)
		{
			cout << "清空预约记录" << endl;
			man->cleanFile();
		}

		//注销
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能（操作的文件名称，操作身份类型）
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	 
	if (type == 1)
	{
		cout << "请输入您的学号:" << endl;
		cin >> id;
	}

	else if (type == 2)
	{
		cout<<"请输入您的职工号:" << endl;
		cin >> id;
	}

		cout << "请输入用户名:" << endl;
		cin >> name;
		cout << "请输入密码:" << endl;
		cin >> pwd;

		if (type == 1)	//学生身份验证
		{
			int fId;
			string fName;
			string fPwd;
			while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			{
				if (fId == id && fName == name && fPwd == pwd)
				{
					cout << "学生验证登录成功！" << endl;
					system("pause");
					system("cls");
					person = new Student(id, name, pwd);
					studentMenu(person);
					return;
				}
			}
		}

		else if (type == 2)	//教师身份验证
		{
			int fId;
			string fName;
			string fPwd;
			while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			{
				if (fId == id && fName == name && fPwd == pwd)
				{
					cout << "教师验证登录成功！" << endl;
					system("pause");
					system("cls");
					person = new Teacher(id, name, pwd);
					teacherMenu(person);
					return;
				}
			}
		}

		else if (type == 3)	//管理员身份验证
		{
			string fName;
			string fPwd;
			while (ifs >> fName && ifs >> fPwd)
			{
				if (fName == name && fPwd == pwd)
				{
					cout << "管理员验证登录成功！" << endl;
					system("pause");
					system("cls");
					person = new Manager(name, pwd);
					managerMenu(person);	//进入管理员子菜单
					return;
				}
			}
		}

		cout << "验证登录失败!" << endl;
		system("pause");
		system("cls");

		return;
}
int main()
{
	int select = 0;
	while (true)
	{
		cout << "*******************欢迎来到机房预约系统*******************" << endl;
		cout << "——————————————"<<endl;
		cout << "|      请选择您的身份      |" << endl;
		cout << "|        1.学生代表        |" << endl;
		cout << "|        2.老师            |" << endl;
		cout << "|        3.管理员          |" << endl;
		cout << "|        0.退出            |" << endl;
		cout << "——————————————" << endl;
		cout << "请输入您的选择" << endl;

		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);//学生身份
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);//老师身份
			break;
		case 3:
			LoginIn(ADM_FILE, 3);//管理员身份
			break;
		case 0://退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
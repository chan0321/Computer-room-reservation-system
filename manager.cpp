#include"manager.h"

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();	//初始化容器

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房数量为:" << vCom.size() << endl;
}

void Manager::operMenu()
{
	cout << "欢迎管理员 " << this->m_Name << " 登录" << endl;
	cout << "1.添加账号" << endl;
	cout << "2.查看账号" << endl;
	cout << "3.查看机房" << endl;
	cout << "4.清空预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "请选择您的操作" << endl;
}

void Manager::addPerson()	//添加账号
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生账号" << endl;
	cout << "2.添加教师账号" << endl;
	string fileName;	//操作文件名
	string tip;	//提示id号
	string errorTip;	//重复错误提示

	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)	//添加学生账号
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号:";
		errorTip = "学号重复，请重新输入";
	}
	else if(select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工号";
		errorTip = "职工号重复，请重新输入";
	}
	else
	{
	cout << "输入有误,退出" << endl;
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
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	//添加到文件
	ofs <<endl<< id << "	" << name << "	" << pwd << "	";
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
}

void printStudent(Student& s)
{
	cout << "学号:" << s.m_Id << " 姓名:" << s.m_Name << " 密码:" << s.m_Pwd << endl;
}

void printTeacher(Teacher &t)
{
	cout << "职工号:" << t.m_EmpId << " 姓名:" << t.m_Name << " 密码:" << t.m_Pwd << endl;
}

void Manager::showPerson()	//查看账号
{
	cout << "请选择查看的内容" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()//查看机房信息
{
	cout << "机房信息如下" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号" << it->m_ComId << " 机房容量:" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()	//清空预约记录
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()//初始化容器
{
	vStu.clear();
	vTea.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);	//读取学生信息
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);	//读取教师信息
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	ifs.close();
}
bool Manager::checkRepeat(int id, int type)	//检测重复
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
#include"teacher.h"

Teacher::Teacher()
{
}
Teacher::Teacher(int empId, string name, string pwd)	//有参构造
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
void Teacher::operMenu()	//教师菜单
{
	cout << "欢迎教师 " << this->m_Name << " 登录" << endl;
	cout << "1.查看所有预约" << endl;
	cout << "2.审核预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "请选择您的操作" << endl;
}
void Teacher::showAllOrder()	//显示预约信息
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "预约日期:周" << of.m_orderData[i]["data"];
		cout << "  时间段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "  学生学号:" << of.m_orderData[i]["stuId"];
		cout << "  学生姓名:" << of.m_orderData[i]["stuName"];
		cout << "  机房编号:" << of.m_orderData[i]["roomId"];
		string status = "状态:";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败,审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << "  " << status << endl;
	}
	system("pause");
	system("cls");
}
void Teacher::validOrder()	//审核预约
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的预约如下" << endl;
	int index = 0;
	vector<int>v;	//存放最大容器中的下标编号
	for (int i = 0; i < of.m_Size; i++)
	{

		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << ".";
			cout << "预约日期:周" << of.m_orderData[i]["data"];
			cout << "  时间段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "  学生学号:" << of.m_orderData[i]["stuId"];
			cout << "  学生姓名:" << of.m_orderData[i]["stuName"];
			cout << "  机房编号:" << of.m_orderData[i]["roomId"];
			string status = "状态:待审核";
			cout << "  " << status << endl;
		}
	}
	cout << "请输入要审核的预约记录，0代表返回" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1.通过" << endl;
				cout << "2.通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderData[v[select-1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updataOrder();
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入错误,请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
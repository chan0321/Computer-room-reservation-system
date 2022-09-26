#include"teacher.h"

Teacher::Teacher()
{
}
Teacher::Teacher(int empId, string name, string pwd)	//�вι���
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
void Teacher::operMenu()	//��ʦ�˵�
{
	cout << "��ӭ��ʦ " << this->m_Name << " ��¼" << endl;
	cout << "1.�鿴����ԤԼ" << endl;
	cout << "2.���ԤԼ" << endl;
	cout << "0.ע����¼" << endl;
	cout << "��ѡ�����Ĳ���" << endl;
}
void Teacher::showAllOrder()	//��ʾԤԼ��Ϣ
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "ԤԼ����:��" << of.m_orderData[i]["data"];
		cout << "  ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "  ѧ��ѧ��:" << of.m_orderData[i]["stuId"];
		cout << "  ѧ������:" << of.m_orderData[i]["stuName"];
		cout << "  �������:" << of.m_orderData[i]["roomId"];
		string status = "״̬:";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��,���δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << "  " << status << endl;
	}
	system("pause");
	system("cls");
}
void Teacher::validOrder()	//���ԤԼ
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵�ԤԼ����" << endl;
	int index = 0;
	vector<int>v;	//�����������е��±���
	for (int i = 0; i < of.m_Size; i++)
	{

		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << ".";
			cout << "ԤԼ����:��" << of.m_orderData[i]["data"];
			cout << "  ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "  ѧ��ѧ��:" << of.m_orderData[i]["stuId"];
			cout << "  ѧ������:" << of.m_orderData[i]["stuName"];
			cout << "  �������:" << of.m_orderData[i]["roomId"];
			string status = "״̬:�����";
			cout << "  " << status << endl;
		}
	}
	cout << "������Ҫ��˵�ԤԼ��¼��0������" << endl;
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
				cout << "��������˽��" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.ͨ��" << endl;
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
				cout << "������" << endl;
				break;
			}
		}
		cout << "�������,����������" << endl;
	}
	system("pause");
	system("cls");
}
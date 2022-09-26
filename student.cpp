#include"student.h"

Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

void Student::operMenu()
{
	cout << "��ӭѧ�� " << this->m_Name << " ��¼" << endl;
	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴ԤԼ" << endl;
	cout << "3.�鿴����ԤԼ" << endl;
	cout << "4.ȡ��ԤԼ" << endl;
	cout << "0.ע����¼" << endl;
	cout << "��ѡ�����Ĳ���" << endl;
}
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ������1" << endl;
	cout << "����������ԤԼ��ʱ��" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	
	int data = 0;
	int interval = 0;
	int room = 0;
	
	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "������ԤԼʱ���" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "��ѡ�����" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "�Ż���������Ϊ:" << vCom[i].m_MaxNum  << endl;
	}
	
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "��������,����������" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;

	//ԤԼ��¼д�뵽�ļ�
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "data:" << data << " ";
	ofs << "interval:" << interval<< " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}
void Student::showOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	

	for (int i = 0;i<of.m_Size;i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			cout << "ԤԼ����:��" << of.m_orderData[i]["data"];
			cout << "  ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
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
	}
	system("pause");
	system("cls");
}
void Student::showAllOrder()
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
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼������ȡ������ѡ��Ҫȡ���ļ�¼" << endl;
	int index = 1;
	vector<int>v;	//�����������е��±���
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ".";
				cout << "ԤԼ����:��" << of.m_orderData[i]["data"];
				cout << "  ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
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
				cout << "  " << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0��������" << endl;
	int select = 0;
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
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updataOrder();
				cout << "ȡ��ԤԼ�ɹ�" << endl;
				break;
			}
		}
		cout << "�������,����������" << endl;
	}
	system("pause");
	system("cls");
}
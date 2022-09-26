#include"orderFile.h"

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	this->m_Size = 0;
	string data;	//周一到周五
	string interval;	//上午或下午
	string stuId;	//学号
	string stuName;	//姓名	
	string roomId;	//机房号
	string status;	//预约状态

	while(ifs >> data && ifs >> interval && ifs >> stuId&& ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		map<string, string>m;
		//使用函数模板将数据装入map容器m中
		getOrder(data,m);
		getOrder(interval,m);
		getOrder(stuId,m);
		getOrder(stuName,m);
		getOrder(roomId,m);
		getOrder(status,m);

		//将map容器m中的数据放入map容器m_orderData
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;		

	}


	//	int pos=data.find(":");
	//	if (pos != -1)
	//	{
	//		key = data.substr(0, pos);
	//		value = data.substr(pos + 1,data.size()-pos-1 );
	//		m.insert(make_pair(key, value));
	//	}

	//	pos = interval.find(":");
	//	if (pos != -1)
	//	{
	//		key = interval.substr(0, pos);
	//		value = interval.substr(pos + 1, interval.size() - pos - 1);
	//		m.insert(make_pair(key, value));
	//	}

	//	pos = stuId.find(":");
	//	if (pos != -1)
	//	{
	//		key = stuId.substr(0, pos);
	//		value = stuId.substr(pos + 1, stuId.size() - pos - 1);
	//		m.insert(make_pair(key, value));
	//	}

	//	pos = stuName.find(":");
	//	if (pos != -1)
	//	{
	//		key = stuName.substr(0, pos);
	//		value = stuName.substr(pos + 1, stuName.size() - pos - 1);
	//		m.insert(make_pair(key, value));
	//	}

	//	pos = roomId.find(":");
	//	if (pos != -1)
	//	{
	//		key = roomId.substr(0, pos);
	//		value = roomId.substr(pos + 1, roomId.size() - pos - 1);
	//		m.insert(make_pair(key, value));
	//	}

	//	pos = status.find(":");
	//	if (pos != -1)
	//	{
	//		key = status.substr(0, pos);
	//		value = status.substr(pos + 1, status.size() - pos - 1);
	//		m.insert(make_pair(key, value));
	//	}
	

	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	//{
	//	cout <<"第"<< it->first<<"条记录" << endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << mit->first << ":" << mit->second << "  ";
	//	}
	//	cout << endl;
	//}	
	ifs.close();
}

void OrderFile::updataOrder()	//更新预约记录
{
	if (this->m_Size == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "data:" << this->m_orderData[i]["data"] << "	"
			<< "interval:" << this->m_orderData[i]["interval"] << "	"
			<< "stuId:" << this->m_orderData[i]["stuId"] << "	"
			<< "stuName:" << this->m_orderData[i]["stuName"] << "	"
			<< "roomId:" << this->m_orderData[i]["roomId"] << "	"
			<< "status:" << this->m_orderData[i]["status"] << endl;
	}

	ofs.close();
}

template <class T1,class T2>
void OrderFile::getOrder(T1& t,T2 &m)
{
	string key;
	string value;
	int pos = t.find(":");
	if (pos != -1)
	{
		key = t.substr(0, pos);
		value = t.substr(pos + 1, t.size() - pos - 1);
		m.insert(make_pair(key,value));
	}
}
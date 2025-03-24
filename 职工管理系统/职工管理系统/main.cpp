#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

//写文件
void static Write(ofstream& ofs)
{
	ofs.open("information.txt", ios::out | ios::trunc);
}


//读文件
void static Read(ifstream &ifs)
{
	ifs.open("information.txt", ios::in);
	
}

//打印文件
void Output(ifstream &ifs)
{
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}
}

//写入文件
void Write_to_File(string (&info)[100],int& total)
{
	ofstream ofs;
	Write(ofs);
	for (int i = 0; i <= total;i++)
	{
		ofs << info[i] << endl;
	}
	ofs.close();
}

////读取编号(不能传数组的引用）
//int* ReadNum(const int& total, const string (&info)[100])
//{
//	int* num = new int[total+1];
//	for (int i = 0; i <= total;i++)
//	{
//		istringstream iss(info[i]);
//		string temp;
//		iss >> temp;
//		iss >> num[i];
//		/*cout << num[i] << "ReadNum" << endl;*/
//	}
//	return num;
//	
//}

//判断员工是否存在
int Judge(string (&Save)[100], string(&info)[100], string& attribute, const int& total,int kind)
{
	/*int num = stoi(m_num);*/
	int flag = 0;
	int count = 0;
	for (int i = 1;i <= total; i++)
	{
		/*cout << Save[i] << "Judge" << endl;*/
		if (attribute == Save[i])
		{
			flag = i;
			count++;
		}

	}
	if (count > 1)
	{
		if (kind == 1)
		{
			cout << "编号为" << attribute << "的有" << count << "个" << endl;
		}

		if (kind == 2)
		{
			cout << "姓名为" << attribute << "的有" << count << "个" << endl;
		}

		for (int j = 1;j <= total;j++)
		{
			if (attribute == Save[j])
			{
				cout << info[j] << endl;
			}
		}
		cout << "当前访问的是最后一个" << endl;
	}

	return flag;
}

//判断部门是否存在
void Judge(string &institution, string &duty)
{
	while (true)
	{
		if (institution == "1")
		{
			duty = "管理公司所有事务";
			break;
		}
		else if (institution == "2")
		{
			duty = "完成老板交代的任务，并下发给员工";
			break;
		}
		else if (institution == "3")
		{
			duty = "完成经理交代的任务";
			break;
		}
		//判断部门编号是否合理
		else
		{
			cout << "不存在这个部门，请重新输入或按0退出" << endl;
			cout << "请输入部门编号：";
			cin >> institution;
			if (institution == "0")
			{
				break;
			}
		}

	}
}

//按编号删除
void Del(string& num, string(&info)[100],int &total,string(&numSave)[100])
{
	/*int *numArray = ReadNum(total, info);*/
	int flag = 0;
	while(true)
	{
		for (int j = 1;j <= total;j++)
		{
			if (numSave[j] == num)
			{
				cout << "已找到，你要删除的员工编号是" << num << endl;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			cout << "不存在这个编号，请重新输入或按0退出" << endl;
			cout << "请输入要删除的编号:";
			cin >> num;

		}
		else
		{
			break;
		}

		if (num == "0")
		{
			break;
		}
		else
		{
			continue;
		}
		
	}

	if (num != "0")
	{
		for (int i = stoi(num);i <= total;i++)
		{
			info[i] = info[i + 1];
		}

		cout << "删除成功" << endl;
		total--;
		string string_total = to_string(total);
		info[0] = "总人数: " + string_total;
	}

	/*delete[]numArray;*/
	/*numArray = NULL;*/
}

//冒泡排序
//升序
void BubbleAscending(int(&num)[100], string(&info)[100], int& total)
{
	for (int i = total; i > 1;i--)
	{
		for (int j = 1; j < i;j++)
		{
			string temp1;
			int temp2;
			if (num[j] > num[j + 1])
			{
				temp1 = info[j];
				info[j] = info[j + 1];
				info[j + 1] = temp1;
				temp2 = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp2;
			}
		}
	}
	//for (int i = 0;i <= total;i++)
	//{
	//	cout << info[i] << endl;
	//}
	Write_to_File(info, total);

}

//降序
void BubbleDescending(int(&num)[100], string(&info)[100], int& total)
{
	for (int i = total; i > 1;i--)
	{
		for (int j = 1; j < i;j++)
		{
			string temp1;
			int temp2;
			if (num[j] < num[j + 1])
			{
				temp1 = info[j];
				info[j] = info[j + 1];
				info[j + 1] = temp1;
				temp2 = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp2;
			}
		}
	}
	Write_to_File(info, total);

}

//虚拟类
class Person
{
public:
	//功能虚函数
	virtual void Function(int &total) = 0;

	//析构函数
	virtual ~Person() = 0;

	static string m_total;
	static string m_info[100];
	static string m_nameSave[100];
	static string m_numSave[100];
	static string m_institutionSave[100];
	string m_num;
	string m_name;
	string m_institution;
	string m_duty;
	int* m_numArray;

};
//类外初始化
string Person::m_total = "";
string Person::m_info[100] = {"0"};
string Person::m_numSave[100] = {"0"};
string Person::m_nameSave[100] = {"0"};
string Person::m_institutionSave[100] = {"0"};
Person::~Person()
{ }

//初始化类
class Initialization :public Person
{
public:
	void Function(int& total)
	{
		ifstream ifs;
		Read(ifs);

		//判断是否有文件
		if (!ifs.is_open())
		{
			char ex;
			cout << "文件不存在，是否初始化(y/n)" << endl;
			cin >> ex;
			if (ex == 'y')
			{
				ofstream ofs;
				ofs.open("Information.txt", ios::out);
				ofs << "总人数" << " " << total << endl;
				ofs.close();
			}
			else
			{
				ifs.close();
			}

		}
		//读取总人数
		string firstline;
		//读取第一行
		if (getline(ifs, firstline));
		m_info[0] = firstline;
		//将第一行以流的方式处理
		istringstream iss(firstline);

		//读取总人数
		string temp;
		iss >> temp;
		iss >> total;
	
		//获取总名单
		string buf;
		//文件指针位置已到第二行
		int i = 1;
		while (getline(ifs, buf))
		{
			istringstream iss(buf);
			iss >> temp;
			iss >> m_numSave[i];
			/*cout << m_numSave[i] << "num" << endl;*/
			iss >> temp;
			iss >> m_nameSave[i];
			/*cout << m_nameSave[i] << "name" << endl;*/
			iss >> temp;
			iss >> m_institutionSave[i];
			/*cout << m_institutionSave[i] << "institution" << endl;*/
			m_info[i] = buf;
			i++;
		}

		//for (int i = 0;i <= total;i++)
		//{
		//	cout << m_info[i] << endl;
		//}
		ifs.close();
	}
};

//退出类
class End :public Person
{
public:
	void Function(int &total)
	{
	   
		cout << "欢迎下次使用" << endl;
		
	}
};

//增加员工信息
class Add :public Person
{
public:
	void Function(int &total)
	{
		cout << total;
		for (int i = 1;i < 100;i++)
		{
			/*m_numArray = ReadNum(total, m_numSave);*/
			while (true)
			{  
				int flag;
				cout << "请输入职工编号：";
				cin >> m_num;
				cout << endl;

				flag = Judge(m_numSave, m_info, m_num, total, 1);
				if (flag)
				{
					cout << "此编号已存在，请重新输入" << endl;
				}
				else
				{
					break;
				}
			}
			

			cout << "请输入职工姓名：";
			cin >> m_name;
			cout << endl;

			cout << "请输入部门编号：" << endl;
			cout << "1.普通员工\n" << "2.经理\n" << "3.老板\n" << endl;
			cin >> m_institution;
			cout << endl;
			Judge(m_institution, m_duty);

			//保存数据
			total++;
			m_info[total] = "编号: " + m_num+"  " + "姓名: " + m_name + "  " + "部门编号: " + m_institution + "  " + "部门职责: " + m_duty;
			m_numSave[total] = m_num;
			m_nameSave[total] = m_name;
			m_institutionSave[total] = m_institution;

			//将整型转为字符串
			m_total = to_string(total);
			m_info[0] = "总人数: " + m_total;
			

			//是否继续输入
			cout << "按0退出,按1输入" << endl;
			cin >> dec;
			if (dec == 0)
			{
				break;
			}
			else if(dec == 1)
			{
				continue;
			}
			else
			{
				cout << "输入不正确,已退出" << endl;
				break;
			}
		}
		//写入文件
		Write_to_File(m_info, total);

	}
	int dec;

	~Add()
	{
		if (m_numArray != NULL)
		{
			delete[]m_numArray;
			m_numArray = nullptr;
		}
	}
};

//展示信息
class Show :public Person
{
public:
	void Function(int &total)
	{
		ifstream ifs;
		Read(ifs);
		Output(ifs);
	}
};

//删除信息
class Delete :public Person
{
public:
	void Function(int &total)
	{
		cout << "请输入你要删除的员工编号：";
		cin >> m_del;
		Del(m_del, m_info, total,m_numSave);
		Write_to_File(m_info, total);

	}
	string m_del;
};

//修改信息
class Correct :public Person
{
public:
	void Function(int& total)
	{
		int flag;
		while (true)
		{
			cout << "请输入你要修改的员工编号:";
			cin >> m_num;
			if (m_num == "0")
			{
				break;
			}
			flag = Judge(m_numSave, m_info, m_num, total, 1);

			if (flag)
			{
				cor = flag;
				cout << "该员工的信息为 :" << m_info[cor]<< endl;
				while (true)
				{
					cout << "请输入修改后的员工编号:";
					cin >> m_num;
					cout << endl;
					flag = Judge(m_numSave, m_info, m_num, total, 1);
					if(flag)
					{
						cout << "此编号已存在，请重新输入或按0退出" << endl;
					}
			        else
			        {
				        break;
			        }
				}

				cout << "请输入修改后的员工名字:";
				cin >> m_name;
				cout << endl;

				cout << "请输入修改后的部门编号:";
				cin >> m_institution;
				cout << endl;
				Judge(m_institution, m_duty);

				m_info[cor] = "编号: " + m_num + "  " + "姓名: " + m_name + "  " + "部门编号: " + m_institution + "  " + "部门职责: " + m_duty;
				
				Write_to_File(m_info, total);

				cout << "修改成功,继续修改按4，退出按0" << endl;

			}
			else
			{
				cout << "该员工编号不存在,重新选择按4,按0退出" << endl;
			}
			cin >> cor;

			if (cor == 0)
			{
				break;
			}

			else if (cor == 4)
			{
				continue;
			}

			else
			{
				cout << "无效操作，退出" << endl;
				break;
			}
		}
		
	}
	int cor;

};

//查找信息
class Find :public Person
{
public:
	void Function(int& total)
	{
		int flag = 0;
		while (true)
		{
			cout << "按员工编号查找请按1,按姓名查找请按2,退出请按0" << endl;
			cin >> f;
			if (f != 0)
			{
				if (f == 1)
				{
					cout << "请输入员工编号：";
					cin >> m_num;
					flag = Judge(m_numSave, m_info, m_num, total, 1);
					if (!flag)
					{
						cout << "员工编号不存在" << endl;
						continue;
					}
					cout << "以下是该员工的信息：" << endl;
					cout << m_info[flag] << endl;
				}

				else if (f == 2)
				{
					cout << "请输入员工姓名：";
					cin >> m_name;
					flag = Judge(m_nameSave, m_info, m_name, total, 2);
					if (!flag)
					{
						cout << "员工姓名不存在" << endl;
						continue;
					}
					cout << "以下是该员工的信息：" << endl;
					cout << m_info[flag] << endl;
				}

				cout << "继续查询请按5,退出请按0" << endl;
				cin >> f;
			}
			else if (f == 0)
			{
				break;
			}

			else
			{
				cout << "无效操作,退出" << endl;
				break;
			}
		}

	}
	 
	int f;
};

//按编号排序
class Sort :public Person
{
public:
	void Function(int& total)
	{
		/*for (int i = 1; i <= total;i++)
		{
			Num[i] = stoi(m_numSave[i]);
			cout << Num[i] << endl;;
		}*/
		cout << "按1进行降序排列,按2进行升序排列" << endl;
		cin >> s;
		if (s == 1)
		{
			cout << "进行降序排列" << endl;
			BubbleDescending(Num, m_info, total);
			cout << "排序成功" << endl;
		}
		else if (s == 2)
		{
			cout << "进行升序排列" << endl;
			BubbleAscending(Num, m_info, total);
			cout << "排序成功" << endl;
		}
		else
		{
			cout << "无效操作，退出" << endl;
		}
		
	}

	int s;
	int Num[100] = { 0 };
};

//清空
class Clean :public Person
{
public:
	void Function(int& total)
	{
		cout << "确认要清空? (y/n)" << endl;
		cin >> c;
		if (c = 'y')
		{
			ofstream ofs;
			Write(ofs);
		}

	}
	
	char c;

};




int main()
{
	int func;
	int total = 0;
	Person* p = nullptr;
	delete p;
	
	while (true)
	{
		cout << "按任意键进入功能区" << endl;
		system("pause");
		system("cls");
		cout << "欢迎打开员工管理系统" << "\n" << endl;
		cout << "***0 退出管理系统***" << endl;
		cout << "***1 增加职工信息***" << endl;
		cout << "***2 显示职工信息***" << endl;
		cout << "***3 删除离职信息***" << endl;
		cout << "***4 修改职工信息***" << endl;
		cout << "***5 查找职工信息***" << endl;
		cout << "***6 按照编号排序***" << endl;
		cout << "***7 删除所有文档***" << "\n" << endl;
		cout << "请输入功能编号:";
		cin >> func;

		p = new Initialization;
		p->Function(total);

		switch (func)
		{
		case 0:
			
			p = new End;
			delete p;
			return 0;
			break;

		case 1:
		    p = new Add;
			p->Function(total);
			delete p;
			break;
			
		case 2:
			p = new Show;
			p->Function(total);
			delete p;
			break;

		case 3:
			p = new Delete;
			p->Function(total);
			delete p;
			break;

		case 4:
			p = new Correct;
			p->Function(total);
			delete p;
			break;

		case 5:
			p = new Find;
			p->Function(total);
			delete p;
			break;

		case 6:
			p = new Sort;
			p->Function(total);
			delete p;
			break;

		case 7:
			p = new Clean;
			p->Function(total);
			delete p;
			break;

		default:
			cout << "无效操作" << endl;

		}
		
	}

	system("pause");
	return 0;

}
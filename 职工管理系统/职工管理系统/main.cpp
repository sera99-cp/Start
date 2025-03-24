#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

//д�ļ�
void static Write(ofstream& ofs)
{
	ofs.open("information.txt", ios::out | ios::trunc);
}


//���ļ�
void static Read(ifstream &ifs)
{
	ifs.open("information.txt", ios::in);
	
}

//��ӡ�ļ�
void Output(ifstream &ifs)
{
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}
}

//д���ļ�
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

////��ȡ���(���ܴ���������ã�
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

//�ж�Ա���Ƿ����
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
			cout << "���Ϊ" << attribute << "����" << count << "��" << endl;
		}

		if (kind == 2)
		{
			cout << "����Ϊ" << attribute << "����" << count << "��" << endl;
		}

		for (int j = 1;j <= total;j++)
		{
			if (attribute == Save[j])
			{
				cout << info[j] << endl;
			}
		}
		cout << "��ǰ���ʵ������һ��" << endl;
	}

	return flag;
}

//�жϲ����Ƿ����
void Judge(string &institution, string &duty)
{
	while (true)
	{
		if (institution == "1")
		{
			duty = "����˾��������";
			break;
		}
		else if (institution == "2")
		{
			duty = "����ϰ彻�������񣬲��·���Ա��";
			break;
		}
		else if (institution == "3")
		{
			duty = "��ɾ�����������";
			break;
		}
		//�жϲ��ű���Ƿ����
		else
		{
			cout << "������������ţ������������0�˳�" << endl;
			cout << "�����벿�ű�ţ�";
			cin >> institution;
			if (institution == "0")
			{
				break;
			}
		}

	}
}

//�����ɾ��
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
				cout << "���ҵ�����Ҫɾ����Ա�������" << num << endl;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			cout << "�����������ţ������������0�˳�" << endl;
			cout << "������Ҫɾ���ı��:";
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

		cout << "ɾ���ɹ�" << endl;
		total--;
		string string_total = to_string(total);
		info[0] = "������: " + string_total;
	}

	/*delete[]numArray;*/
	/*numArray = NULL;*/
}

//ð������
//����
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

//����
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

//������
class Person
{
public:
	//�����麯��
	virtual void Function(int &total) = 0;

	//��������
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
//�����ʼ��
string Person::m_total = "";
string Person::m_info[100] = {"0"};
string Person::m_numSave[100] = {"0"};
string Person::m_nameSave[100] = {"0"};
string Person::m_institutionSave[100] = {"0"};
Person::~Person()
{ }

//��ʼ����
class Initialization :public Person
{
public:
	void Function(int& total)
	{
		ifstream ifs;
		Read(ifs);

		//�ж��Ƿ����ļ�
		if (!ifs.is_open())
		{
			char ex;
			cout << "�ļ������ڣ��Ƿ��ʼ��(y/n)" << endl;
			cin >> ex;
			if (ex == 'y')
			{
				ofstream ofs;
				ofs.open("Information.txt", ios::out);
				ofs << "������" << " " << total << endl;
				ofs.close();
			}
			else
			{
				ifs.close();
			}

		}
		//��ȡ������
		string firstline;
		//��ȡ��һ��
		if (getline(ifs, firstline));
		m_info[0] = firstline;
		//����һ�������ķ�ʽ����
		istringstream iss(firstline);

		//��ȡ������
		string temp;
		iss >> temp;
		iss >> total;
	
		//��ȡ������
		string buf;
		//�ļ�ָ��λ���ѵ��ڶ���
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

//�˳���
class End :public Person
{
public:
	void Function(int &total)
	{
	   
		cout << "��ӭ�´�ʹ��" << endl;
		
	}
};

//����Ա����Ϣ
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
				cout << "������ְ����ţ�";
				cin >> m_num;
				cout << endl;

				flag = Judge(m_numSave, m_info, m_num, total, 1);
				if (flag)
				{
					cout << "�˱���Ѵ��ڣ�����������" << endl;
				}
				else
				{
					break;
				}
			}
			

			cout << "������ְ��������";
			cin >> m_name;
			cout << endl;

			cout << "�����벿�ű�ţ�" << endl;
			cout << "1.��ͨԱ��\n" << "2.����\n" << "3.�ϰ�\n" << endl;
			cin >> m_institution;
			cout << endl;
			Judge(m_institution, m_duty);

			//��������
			total++;
			m_info[total] = "���: " + m_num+"  " + "����: " + m_name + "  " + "���ű��: " + m_institution + "  " + "����ְ��: " + m_duty;
			m_numSave[total] = m_num;
			m_nameSave[total] = m_name;
			m_institutionSave[total] = m_institution;

			//������תΪ�ַ���
			m_total = to_string(total);
			m_info[0] = "������: " + m_total;
			

			//�Ƿ��������
			cout << "��0�˳�,��1����" << endl;
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
				cout << "���벻��ȷ,���˳�" << endl;
				break;
			}
		}
		//д���ļ�
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

//չʾ��Ϣ
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

//ɾ����Ϣ
class Delete :public Person
{
public:
	void Function(int &total)
	{
		cout << "��������Ҫɾ����Ա����ţ�";
		cin >> m_del;
		Del(m_del, m_info, total,m_numSave);
		Write_to_File(m_info, total);

	}
	string m_del;
};

//�޸���Ϣ
class Correct :public Person
{
public:
	void Function(int& total)
	{
		int flag;
		while (true)
		{
			cout << "��������Ҫ�޸ĵ�Ա�����:";
			cin >> m_num;
			if (m_num == "0")
			{
				break;
			}
			flag = Judge(m_numSave, m_info, m_num, total, 1);

			if (flag)
			{
				cor = flag;
				cout << "��Ա������ϢΪ :" << m_info[cor]<< endl;
				while (true)
				{
					cout << "�������޸ĺ��Ա�����:";
					cin >> m_num;
					cout << endl;
					flag = Judge(m_numSave, m_info, m_num, total, 1);
					if(flag)
					{
						cout << "�˱���Ѵ��ڣ������������0�˳�" << endl;
					}
			        else
			        {
				        break;
			        }
				}

				cout << "�������޸ĺ��Ա������:";
				cin >> m_name;
				cout << endl;

				cout << "�������޸ĺ�Ĳ��ű��:";
				cin >> m_institution;
				cout << endl;
				Judge(m_institution, m_duty);

				m_info[cor] = "���: " + m_num + "  " + "����: " + m_name + "  " + "���ű��: " + m_institution + "  " + "����ְ��: " + m_duty;
				
				Write_to_File(m_info, total);

				cout << "�޸ĳɹ�,�����޸İ�4���˳���0" << endl;

			}
			else
			{
				cout << "��Ա����Ų�����,����ѡ��4,��0�˳�" << endl;
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
				cout << "��Ч�������˳�" << endl;
				break;
			}
		}
		
	}
	int cor;

};

//������Ϣ
class Find :public Person
{
public:
	void Function(int& total)
	{
		int flag = 0;
		while (true)
		{
			cout << "��Ա����Ų����밴1,�����������밴2,�˳��밴0" << endl;
			cin >> f;
			if (f != 0)
			{
				if (f == 1)
				{
					cout << "������Ա����ţ�";
					cin >> m_num;
					flag = Judge(m_numSave, m_info, m_num, total, 1);
					if (!flag)
					{
						cout << "Ա����Ų�����" << endl;
						continue;
					}
					cout << "�����Ǹ�Ա������Ϣ��" << endl;
					cout << m_info[flag] << endl;
				}

				else if (f == 2)
				{
					cout << "������Ա��������";
					cin >> m_name;
					flag = Judge(m_nameSave, m_info, m_name, total, 2);
					if (!flag)
					{
						cout << "Ա������������" << endl;
						continue;
					}
					cout << "�����Ǹ�Ա������Ϣ��" << endl;
					cout << m_info[flag] << endl;
				}

				cout << "������ѯ�밴5,�˳��밴0" << endl;
				cin >> f;
			}
			else if (f == 0)
			{
				break;
			}

			else
			{
				cout << "��Ч����,�˳�" << endl;
				break;
			}
		}

	}
	 
	int f;
};

//���������
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
		cout << "��1���н�������,��2������������" << endl;
		cin >> s;
		if (s == 1)
		{
			cout << "���н�������" << endl;
			BubbleDescending(Num, m_info, total);
			cout << "����ɹ�" << endl;
		}
		else if (s == 2)
		{
			cout << "������������" << endl;
			BubbleAscending(Num, m_info, total);
			cout << "����ɹ�" << endl;
		}
		else
		{
			cout << "��Ч�������˳�" << endl;
		}
		
	}

	int s;
	int Num[100] = { 0 };
};

//���
class Clean :public Person
{
public:
	void Function(int& total)
	{
		cout << "ȷ��Ҫ���? (y/n)" << endl;
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
		cout << "����������빦����" << endl;
		system("pause");
		system("cls");
		cout << "��ӭ��Ա������ϵͳ" << "\n" << endl;
		cout << "***0 �˳�����ϵͳ***" << endl;
		cout << "***1 ����ְ����Ϣ***" << endl;
		cout << "***2 ��ʾְ����Ϣ***" << endl;
		cout << "***3 ɾ����ְ��Ϣ***" << endl;
		cout << "***4 �޸�ְ����Ϣ***" << endl;
		cout << "***5 ����ְ����Ϣ***" << endl;
		cout << "***6 ���ձ������***" << endl;
		cout << "***7 ɾ�������ĵ�***" << "\n" << endl;
		cout << "�����빦�ܱ��:";
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
			cout << "��Ч����" << endl;

		}
		
	}

	system("pause");
	return 0;

}
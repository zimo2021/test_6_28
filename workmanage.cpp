
#include"workmanage.h"//����������Ϳ�������ʹ��cout��cin��
workmamage::workmamage()
{
	ifstream ifs;
	//�ļ������ڵ����
	ifs.open("date.txt", ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->m_Empnum = 0;
		this->m_Emparr = NULL;
		this->m_fileisnull = true;
		ifs.close();
	}
	//�ļ�����Ϊ�յ����
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->m_Empnum = 0;
		this->m_Emparr = NULL;
		this->m_fileisnull = true;
		ifs.close();
	}
	//�ļ������Ҳ�Ϊ��
	int num = this->m_memnum();
	//cout << "�Ѽ���" << num << "��" << endl;
	this->m_Empnum = num;
	//�ȿ��ٿռ�
	this->m_Emparr = new worker*[this->m_Empnum];
	this->samenamesid = new int[this->m_Empnum];
	//��ʼ��
	int i;
	for (i = 0; i < this->m_Empnum; i++)
	{
		this->samenamesid[i] = 0;
	}
	//���ص��ռ���ȥ
	this->m_initarr();
	//��ӡһ���¿�һ��Ч��
	/*int i;
	for (i = 0; i < this->m_Empnum; i++)
	{
		cout << "��ţ�" << this->m_Emparr[i]->m_id << " "
			<< "������" << this->m_Emparr[i]->m_name << " "
			<< "���ű�ţ�" << this->m_Emparr[i]->m_deptid << endl;
	}*/
}
workmamage::~workmamage()
{
	int i;
	for (i = 0; i < this->m_Empnum; i++)
	{
		if (this->m_Emparr[i] != NULL)
		{
			delete this->m_Emparr[i];//�������ڶ������������
		}
	}
	this->m_Empnum = 0;
	delete[] this->m_Emparr;
	this->m_Emparr = NULL;
	delete[] this->samenamesid;
	this->m_Emparr = NULL;
}
void workmamage::showmenu()
{
	cout << "************************************" << endl;
	cout << "********��ӭ����ְ������ϵͳ********" << endl;
	cout << "************0.�˳�����ϵͳ**********" << endl;
	cout << "************1.����ְ����Ϣ**********" << endl;
	cout << "************2.��ʾְ����Ϣ**********" << endl;
	cout << "************3.ɾ��ְ��**************" << endl;
	cout << "************4.�޸�ְ����Ϣ**********" << endl;
	cout << "************5.����ְ��**************" << endl;
	cout << "************6.���ձ������**********" << endl;
	cout << "************7.���������Ϣ**********" << endl;
	cout << "************************************" << endl;
}

void workmamage::Exitsystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);//�˳�����
}
void workmamage::Add_Emp()
{
	int i;
	cout << "���������ְ������" << endl;
	int Addnum;//��¼���ְ������
	cin >> Addnum;
	if (Addnum > 0)
	{
		//������Ӻ��ְ������
		int newsize = this->m_Empnum + Addnum;
		//�����µĿռ�
		worker** newSpace = new worker*[newsize];
		//�ж�ԭ�ռ��µ����ݣ���������ݻ��ÿ�����
		if (this->m_Emparr != NULL)
		{
			for (i = 0; i < this->m_Empnum; i++)
			{
				newSpace[i] = this->m_Emparr[i];//����ȥ
			}
		}
		//�������������
		for (i = 0; i < Addnum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "��Ա�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��Ա������" << endl;
			cin >> name;
			cout << "��ѡ��ְ����λ"<< endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			worker* newAdd = NULL;
			switch (dSelect)
			{
			case 1:
				newAdd = new Employee(id, name, dSelect);
				break;
			case 2:
				newAdd = new manager(id, name, dSelect);
				break;
			case 3:
				newAdd = new Boss(id, name, dSelect);
				break;
			}
			newSpace[i + this->m_Empnum] = newAdd;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_Emparr;
		//���¿ռ�ָ��
		this->m_Emparr = newSpace;
		//����ְ������
		this->m_Empnum = newsize;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << Addnum << "��ְ��" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
	this->m_fileisnull = false;
	this->save();
	system("pause");
	system("cls");
}

void workmamage::save()
{
	int i;
	ofstream ofs;
	ofs.open("date.txt", ios::out);
	for (i = 0; i < this->m_Empnum; i++)
	{
		ofs << this->m_Emparr[i]->m_id << " "
			<< this->m_Emparr[i]->m_name << " "
			<< this->m_Emparr[i]->m_id << endl;
	}
	ofs.close();
}
int workmamage::m_memnum()
{
	ifstream ifs;
	ifs.open("date.txt", ios::in);
	int num = 0;
	int id;
	string name;
	int did;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}
void workmamage::m_initarr()
{
	ifstream ifs;
	ifs.open("date.txt",ios::in);
	int id;
	string name;
	int did;
	int i = 0;
	if (this->m_fileisnull)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
		return;
	}
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* p = NULL;
		if (did == 1)
		{
			p = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			p = new manager(id, name,did);
		}
		else
		{
			p = new Boss(id, name, did);
		}
		this->m_Emparr[i++] = p;
	}
	ifs.close();
}
void workmamage::show_emp()
{
	if (this->m_fileisnull)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		int i;
		for (i = 0; i < this->m_Empnum; i++)
		{
			this->m_Emparr[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}

//�ж�Ҫɾ����Ա���Ƿ����
int workmamage::m_isexist(int sid)
{
	int index = -1;
	int i;
	for (i = 0; i < this->m_Empnum; i++)
	{
		if (this->m_Emparr[i]->m_id == sid)
		{
			index = i;
			break;
		}
	}
	return index;
}
//ɾ��Ա��
void workmamage::del_mem()
{
	if (this->m_fileisnull)
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	int p;
	cout << "������Ҫɾ����ְ�����" << endl;
	cin >> p;
	int x = this->m_isexist(p);
	if (x == -1)
	{
		cout << "��ְ�������ڣ�" << endl;
	}
	else
	{
		int i;
		for (i = x; i < this->m_Empnum; i++)
		{
			this->m_Emparr[i] = this->m_Emparr[i + 1];
		}
		this->m_Empnum--;
		this->save();
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//�޸�ְ��
void workmamage::mod_mem()
{
	if (this->m_fileisnull)
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	int p;
	cout << "������Ҫ�޸ĵ�ְ�����" << endl;
	cin >> p;
	int x = this->m_isexist(p);
	if (x == -1)
	{
		cout << "��ְ�������ڣ�" << endl;
	}
	else
	{
		cout << "ԭְ����ϢΪ��" << endl;
		this->m_Emparr[x]->showinfo();
		int id;
		string name;
		int dSelect;
		cout << "�������޸ĵ�Ա�����" << endl;
		cin >> id;
		cout << "�������޸ĵ�Ա������" << endl;
		cin >> name;
		cout << "��ѡ��ְ����λ" << endl;
		cout << "1.��ְͨ��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
		cin >> dSelect;
		worker* newAdd = NULL;
		switch (dSelect)
		{
		case 1:
			newAdd = new Employee(id, name, dSelect);
			break;
		case 2:
			newAdd = new manager(id, name, dSelect);
			break;
		case 3:
			newAdd = new Boss(id, name, dSelect);
			break;
		}
		this->m_Emparr[x] = newAdd;
		this->save();
		cout << "�޸ĳɹ���" << endl;
	}
	system("pause");
	system("cls");
}
void workmamage::find_mem()
{
	if (this->m_fileisnull)
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
	}
	else
	{
		//������ѡ�� �����֣�������ȫ����ӡ���������ҺͰ�ְ����Ų���
		int choice;
		string name;
		int id;
		cout << "��ѡ����ҷ�ʽ" << endl;
		cout << "1.����������" << endl;
		cout << "2.��ְ����Ų���" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{//�������кܶ����ʱ ����������Ǳ�Ҫ��
			cout << "������Ҫ���ҵ�Ա������:" << endl;
			cin >> name;
			int x = this->find_byname(name);
			if (x == -1)
			{
				cout << "���޴��ˣ�" << endl;
			}
			else
			{
				cout << "���ҽ������" << endl;
				int i = 0;
				int m = this->samenamesid[i];
				if (m == 0)
				{
					this->m_Emparr[m]->showinfo();
					i++;
				}
				while (m = this->samenamesid[i])
				{
					this->m_Emparr[m]->showinfo();
					i++;
				}
			}
		}
			break;
		case 2:
		{
			cout << "������Ҫ���ҵ�ְ�����:" << endl;
			cin >> id;
			int x = this->m_isexist(id);
			if (x == -1)
			{
				cout << "���޴��ˣ�" << endl;
			}
			else
			{
				cout << "���ҽ������" << endl;
				this->m_Emparr[x]->showinfo();
			}
		}
			break;
		default:
			cout << "�������" << endl;
		}
	}
	system("pause");
	system("cls");
}
int workmamage::find_byname(string name)
{
	int i;
	int j = 0;
	int index = -1;
	for (i = 0; i < this->m_Empnum; i++)
	{
		if (this->m_Emparr[i]->m_name == name)
		{
			this->samenamesid[j] = i;
			j++;
			index = i;
		}
	}
	return index;
}
void workmamage::sort_mem()
{
	if (this->m_fileisnull)
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	int i ;
	int j;
	int choice;
	cout << "��ѡ��" << endl;
	cout << "1.��ְ�������������" << endl;
	cout << "1.��ְ����Ž�������" << endl;
	cin >> choice;
	//ѡ������
	for (i = 0; i < this->m_Empnum; i++)
	{
		int maxormin = i;
		for (j = i + 1; j < this->m_Empnum; j++)
		{
			if (choice == 1)
			{
				if (this->m_Emparr[maxormin]->m_id > this->m_Emparr[j]->m_id)
				{
					maxormin = j;
				}
			}
			else
			{
				if (this->m_Emparr[maxormin]->m_id < this->m_Emparr[j]->m_id)
				{
					maxormin = j;
				}
			}
		}
		if (maxormin != i)
		{
			//����
			worker* tmp = this->m_Emparr[i];
			this->m_Emparr[i] = this->m_Emparr[maxormin];
			this->m_Emparr[maxormin] = tmp;
		}
	}
	cout << "����ɹ���" << endl;
	cout << "�������Ա�б�Ϊ��" << endl;;
	this->save();
	this->show_emp();
}

void workmamage::clean_mem()
{
	cout << "ȷ�������" << endl;
	cout << "1.���" << endl;
	cout << "2.ȡ��" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open("date.txt", ios::trunc);
		ofs.close();
		//ɾ���ڴ� 
		//����û������ ��Щ���ǻ��������б��ͷ��� ΪʲôҪ�������ͷ� ��ʵ��ִ���������ʱ ��û��ִ����������  ֻ���˳�����Ż�  ����ֻ�������������ղ���
		if (this->m_Emparr != NULL)
		{
			int i;
			for (i = 0; i < this->m_Empnum; i++)
			{
				if (this->m_Emparr[i] != NULL)
				{
					delete this->m_Emparr[i];
				}
			}
			this->m_Empnum = 0;
			delete[] this->m_Emparr;
			this->m_Emparr = NULL;
			this->m_fileisnull = true;
			cout << "��ճɹ���" << endl;
		}
	}
	else
	{
		cout << "��ȡ����" << endl;
	}
	system("pause");
	system("cls");
}
















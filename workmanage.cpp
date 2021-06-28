
#include"workmanage.h"//引用了这个就可以正常使用cout和cin等
workmamage::workmamage()
{
	ifstream ifs;
	//文件不存在的情况
	ifs.open("date.txt", ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_Empnum = 0;
		this->m_Emparr = NULL;
		this->m_fileisnull = true;
		ifs.close();
	}
	//文件数据为空的情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;
		this->m_Empnum = 0;
		this->m_Emparr = NULL;
		this->m_fileisnull = true;
		ifs.close();
	}
	//文件存在且不为空
	int num = this->m_memnum();
	//cout << "已加载" << num << "人" << endl;
	this->m_Empnum = num;
	//先开辟空间
	this->m_Emparr = new worker*[this->m_Empnum];
	this->samenamesid = new int[this->m_Empnum];
	//初始化
	int i;
	for (i = 0; i < this->m_Empnum; i++)
	{
		this->samenamesid[i] = 0;
	}
	//加载到空间中去
	this->m_initarr();
	//打印一下下看一下效果
	/*int i;
	for (i = 0; i < this->m_Empnum; i++)
	{
		cout << "编号：" << this->m_Emparr[i]->m_id << " "
			<< "姓名：" << this->m_Emparr[i]->m_name << " "
			<< "部门编号：" << this->m_Emparr[i]->m_deptid << endl;
	}*/
}
workmamage::~workmamage()
{
	int i;
	for (i = 0; i < this->m_Empnum; i++)
	{
		if (this->m_Emparr[i] != NULL)
		{
			delete this->m_Emparr[i];//将创建在堆区的数据清空
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
	cout << "********欢迎来到职工管理系统********" << endl;
	cout << "************0.退出管理系统**********" << endl;
	cout << "************1.增加职工信息**********" << endl;
	cout << "************2.显示职工信息**********" << endl;
	cout << "************3.删除职工**************" << endl;
	cout << "************4.修改职工信息**********" << endl;
	cout << "************5.查找职工**************" << endl;
	cout << "************6.按照编号排序**********" << endl;
	cout << "************7.清空所有信息**********" << endl;
	cout << "************************************" << endl;
}

void workmamage::Exitsystem()
{
	cout << "欢迎下次使用" << endl;
	exit(0);//退出操作
}
void workmamage::Add_Emp()
{
	int i;
	cout << "请输入添加职工数量" << endl;
	int Addnum;//记录添加职工数量
	cin >> Addnum;
	if (Addnum > 0)
	{
		//计算添加后的职工数量
		int newsize = this->m_Empnum + Addnum;
		//开辟新的空间
		worker** newSpace = new worker*[newsize];
		//判断原空间下的数据，如果有数据还得拷过来
		if (this->m_Emparr != NULL)
		{
			for (i = 0; i < this->m_Empnum; i++)
			{
				newSpace[i] = this->m_Emparr[i];//拷过去
			}
		}
		//批量添加新数据
		for (i = 0; i < Addnum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个员工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个员工姓名" << endl;
			cin >> name;
			cout << "请选择职工岗位"<< endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
		//释放原有空间
		delete[] this->m_Emparr;
		//更新空间指向
		this->m_Emparr = newSpace;
		//更新职工人数
		this->m_Empnum = newsize;
		//提示添加成功
		cout << "成功添加" << Addnum << "名职工" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
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
		cout << "文件不存在或文件为空" << endl;
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
		cout << "文件不存在或文件为空" << endl;
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

//判断要删除的员工是否存在
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
//删除员工
void workmamage::del_mem()
{
	if (this->m_fileisnull)
	{
		cout << "文件不存在或数据为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	int p;
	cout << "请输入要删除的职工编号" << endl;
	cin >> p;
	int x = this->m_isexist(p);
	if (x == -1)
	{
		cout << "该职工不存在！" << endl;
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
		cout << "删除成功！" << endl;
	}
	system("pause");
	system("cls");
}

//修改职工
void workmamage::mod_mem()
{
	if (this->m_fileisnull)
	{
		cout << "文件不存在或数据为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	int p;
	cout << "请输入要修改的职工编号" << endl;
	cin >> p;
	int x = this->m_isexist(p);
	if (x == -1)
	{
		cout << "该职工不存在！" << endl;
	}
	else
	{
		cout << "原职工信息为：" << endl;
		this->m_Emparr[x]->showinfo();
		int id;
		string name;
		int dSelect;
		cout << "请输入修改的员工编号" << endl;
		cin >> id;
		cout << "请输入修改的员工姓名" << endl;
		cin >> name;
		cout << "请选择职工岗位" << endl;
		cout << "1.普通职工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
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
		cout << "修改成功！" << endl;
	}
	system("pause");
	system("cls");
}
void workmamage::find_mem()
{
	if (this->m_fileisnull)
	{
		cout << "文件不存在或数据为空" << endl;
	}
	else
	{
		//有两个选择 按名字（重名的全部打印出来）查找和按职工编号查找
		int choice;
		string name;
		int id;
		cout << "请选择查找方式" << endl;
		cout << "1.按姓名查找" << endl;
		cout << "2.按职工编号查找" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{//在下面有很多代码时 这个花括号是必要的
			cout << "请输入要查找的员工姓名:" << endl;
			cin >> name;
			int x = this->find_byname(name);
			if (x == -1)
			{
				cout << "查无此人！" << endl;
			}
			else
			{
				cout << "查找结果如下" << endl;
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
			cout << "请输入要查找的职工编号:" << endl;
			cin >> id;
			int x = this->m_isexist(id);
			if (x == -1)
			{
				cout << "查无此人！" << endl;
			}
			else
			{
				cout << "查找结果如下" << endl;
				this->m_Emparr[x]->showinfo();
			}
		}
			break;
		default:
			cout << "输入错误！" << endl;
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
		cout << "文件不存在或数据为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	int i ;
	int j;
	int choice;
	cout << "请选择：" << endl;
	cout << "1.按职工编号升序排列" << endl;
	cout << "1.按职工编号降序排列" << endl;
	cin >> choice;
	//选择排序
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
			//交换
			worker* tmp = this->m_Emparr[i];
			this->m_Emparr[i] = this->m_Emparr[maxormin];
			this->m_Emparr[maxormin] = tmp;
		}
	}
	cout << "排序成功！" << endl;
	cout << "排序后组员列表为：" << endl;;
	this->save();
	this->show_emp();
}

void workmamage::clean_mem()
{
	cout << "确认清空吗？" << endl;
	cout << "1.清空" << endl;
	cout << "2.取消" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open("date.txt", ios::trunc);
		ofs.close();
		//删除内存 
		//但有没有疑问 这些不是会在析构中被释放吗 为什么要在这里释放 其实在执行清除代码时 并没有执行析构代码  只有退出程序才会  所以只有在这里进行清空操作
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
			cout << "清空成功！" << endl;
		}
	}
	else
	{
		cout << "已取消！" << endl;
	}
	system("pause");
	system("cls");
}
















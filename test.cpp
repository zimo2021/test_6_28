#include<iostream>
using namespace std;
//����c++����һ��ְ������ϵͳ
#include"manager.h"
#include"employee.h"
#include"worker.h"
#include"Boss.h"
#include"workmanage.h"
int main()
{
	//���Դ���
	/*worker* p = new Employee(1, "����", 1);
	p->showinfo();
	delete p;
	p = new manager(2, "����", 2);
	p->showinfo();
	delete p;
	p = new Boss(3, "����", 3);
	p->showinfo();
	delete p;*/
	workmamage p;
	int choice;
	while (1)
	{
		p.showmenu();//��ӡ�˵�
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			p.Exitsystem();
			break;
		case 1://����Ա��
			p.Add_Emp();
			break;
		case 2://��ʾ
			p.show_emp();
			break;
		case 3://ɾ��
			p.del_mem();
			break;
		case 4://�޸�
			p.mod_mem();
			break;
		case 5://����
			p.find_mem();
			break;
		case 6://����
			p.sort_mem();
			break;
		case 7://���
			p.clean_mem();
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}


//class A
//{
//public:
//	virtual void func() = 0;
//	virtual void func1() = 0;
//
//};
//class B:public A
//{
//public:
//	virtual void func();
//	virtual void func1()
//	{
//		cout << "func1�����ĵ���" << endl;
//	}
//};
//void B::func()
//{
//	cout << "func�����ĵ���" << endl;
//}
//int main()
//{
//	A* p = new B;
//	p->func();
//	return 0;
//}


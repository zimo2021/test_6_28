#include<iostream>
using namespace std;
//利用c++创建一个职工管理系统
#include"manager.h"
#include"employee.h"
#include"worker.h"
#include"Boss.h"
#include"workmanage.h"
int main()
{
	//测试代码
	/*worker* p = new Employee(1, "张三", 1);
	p->showinfo();
	delete p;
	p = new manager(2, "李四", 2);
	p->showinfo();
	delete p;
	p = new Boss(3, "王五", 3);
	p->showinfo();
	delete p;*/
	workmamage p;
	int choice;
	while (1)
	{
		p.showmenu();//打印菜单
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			p.Exitsystem();
			break;
		case 1://增加员工
			p.Add_Emp();
			break;
		case 2://显示
			p.show_emp();
			break;
		case 3://删除
			p.del_mem();
			break;
		case 4://修改
			p.mod_mem();
			break;
		case 5://查找
			p.find_mem();
			break;
		case 6://排序
			p.sort_mem();
			break;
		case 7://清空
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
//		cout << "func1函数的调用" << endl;
//	}
//};
//void B::func()
//{
//	cout << "func函数的调用" << endl;
//}
//int main()
//{
//	A* p = new B;
//	p->func();
//	return 0;
//}


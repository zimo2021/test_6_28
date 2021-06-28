#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"Boss.h"
#include<fstream>
class workmamage
{
public:
	workmamage();
	//记录职工人数
	int m_Empnum;
	//职工数组指针
	worker** m_Emparr;
	//增加职工
	void Add_Emp();
	//添加判断文件是否为空的标志
	bool m_fileisnull;
	//统计原文件中人数
	int m_memnum();
	//将原文件中的数据加载到m_Emparr中
	void m_initarr();
	//显示文件中的成员
	void show_emp();
	//判断要删除的员工是否存在
	int m_isexist(int sid);
	//修改职工
	void mod_mem();
	//删除员工
	void del_mem();
	//查找员工
	void find_mem();
	//按照名字查找
	int find_byname(string name);
	//保存同名员工底号
	int* samenamesid;
	//排序
	void sort_mem();
	//清空
	void clean_mem();
	//保存
	void save();
	~workmamage();
	//打印菜单
	void showmenu();
	//退出系统
	void Exitsystem();
};





#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include<string>
class manager :public worker
{
public:
	//构造函数
	manager(int id, string name, int deptid);
	//显示个人信息
	virtual void showinfo();
	//获取岗位名称
	virtual string getdeptname();
};
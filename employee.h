#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include<string>
class Employee :public worker
{
public:
	//���캯��
	Employee(int id, string name, int deptid);
	//��ʾ������Ϣ
	virtual void showinfo();
	//��ȡ��λ����
	virtual string getdeptname();
};
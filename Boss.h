#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include<string>
class Boss :public worker
{
public:
	//���캯��
	Boss(int id, string name, int deptid);
	//��ʾ������Ϣ
	virtual void showinfo();
	//��ȡ��λ����
	virtual string getdeptname();
};
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
	//��¼ְ������
	int m_Empnum;
	//ְ������ָ��
	worker** m_Emparr;
	//����ְ��
	void Add_Emp();
	//����ж��ļ��Ƿ�Ϊ�յı�־
	bool m_fileisnull;
	//ͳ��ԭ�ļ�������
	int m_memnum();
	//��ԭ�ļ��е����ݼ��ص�m_Emparr��
	void m_initarr();
	//��ʾ�ļ��еĳ�Ա
	void show_emp();
	//�ж�Ҫɾ����Ա���Ƿ����
	int m_isexist(int sid);
	//�޸�ְ��
	void mod_mem();
	//ɾ��Ա��
	void del_mem();
	//����Ա��
	void find_mem();
	//�������ֲ���
	int find_byname(string name);
	//����ͬ��Ա���׺�
	int* samenamesid;
	//����
	void sort_mem();
	//���
	void clean_mem();
	//����
	void save();
	~workmamage();
	//��ӡ�˵�
	void showmenu();
	//�˳�ϵͳ
	void Exitsystem();
};





#include"Boss.h"
//构造函数
Boss::Boss(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}
//显示个人信息
void Boss::showinfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t姓名：" << this->m_name
		<< "\t岗位：" << this->getdeptname()
		<< "\t岗位职责：管理公司事务" << endl;
}
//获取岗位名称
string Boss::getdeptname()
{
	return string("老板");
}
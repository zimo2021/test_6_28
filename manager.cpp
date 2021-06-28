#include"manager.h"
//构造函数
manager::manager(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}
//显示个人信息
void manager::showinfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t姓名：" << this->m_name
		<< "\t岗位：" << this->getdeptname()
		<< "\t岗位职责：完成老板交给的任务" << endl;
}
//获取岗位名称
string manager::getdeptname()
{
	return string("经理");
}
#include"employee.h"
//���캯��
Employee:: Employee(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}
//��ʾ������Ϣ
void Employee::showinfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\t������" << this->m_name
		<< "\t��λ��" << this->getdeptname()
		<< "\t��λְ����ɾ�����������" << endl;
}
//��ȡ��λ����
string Employee::getdeptname()
{
	return string("Ա��");
}
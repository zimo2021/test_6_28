#include"manager.h"
//���캯��
manager::manager(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}
//��ʾ������Ϣ
void manager::showinfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\t������" << this->m_name
		<< "\t��λ��" << this->getdeptname()
		<< "\t��λְ������ϰ彻��������" << endl;
}
//��ȡ��λ����
string manager::getdeptname()
{
	return string("����");
}
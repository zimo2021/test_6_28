#include"Boss.h"
//���캯��
Boss::Boss(int id, string name, int deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}
//��ʾ������Ϣ
void Boss::showinfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\t������" << this->m_name
		<< "\t��λ��" << this->getdeptname()
		<< "\t��λְ�𣺹���˾����" << endl;
}
//��ȡ��λ����
string Boss::getdeptname()
{
	return string("�ϰ�");
}
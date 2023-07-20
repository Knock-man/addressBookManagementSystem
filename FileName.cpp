#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
struct Person {
	string m_Name; //����
	string m_Sex; //�Ա�1�� 2Ů
	string m_Age; //����
	string m_Phone; //�绰
	string m_Addr; //סַ
};
struct Addressbooks {
	Person personArray[MAX];//ͨѶ¼�е���ϵ��
	int m_Size;//ͨѶ¼��������
};

//�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}
//�����ϵ����Ϣ��
void addPerson(Addressbooks* abs) {
	if (abs->m_Size > MAX) {
		cout << "ͨѶ¼����";
		return;
	}
	string name, sex , telephon, address, age;
	cout << "������������" << endl;
	cin >> name;
	cout << "�������Ա�" << endl;
	cin >> sex;
	cout << "���������䣺" << endl;
	cin >> age;
	cout << "������绰��" << endl;
	cin >> telephon;
	cout << "������סַ��" << endl;
	cin >> address;
	abs->personArray[abs->m_Size].m_Name = name;
	abs->personArray[abs->m_Size].m_Sex = sex;
	abs->personArray[abs->m_Size].m_Age = age;
	abs->personArray[abs->m_Size].m_Phone = telephon;
	abs->personArray[abs->m_Size].m_Addr = address;
	abs->personArray[abs->m_Size].m_Name = name;
	abs->personArray[abs->m_Size].m_Name = name;
	abs->m_Size++;//ͨѶ¼������һ
	cout << "��ӳɹ�!"<<endl;
}
//��ʾ��ϵ��
void showPerson(Addressbooks* abs){
	if (abs->m_Size <= 0) {
		cout << "ͨѶ¼Ϊ��"<<endl;
		return;
	}
	for (int i = 0; i < abs->m_Size; i++) {
		cout << endl << abs->personArray[i].m_Name << " " << abs->personArray[i].m_Sex << " " << abs->personArray[i].m_Age << " " << abs->personArray[i].m_Phone << " " << abs->personArray[i].m_Addr << endl;
	}
}
//�ж���ϵ���Ƿ����
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;//���ڣ�����λ��
		}
	}
	return -1;//������
}
//ɾ����ϵ��
void deletePerson(Addressbooks* abs) {
	string name;
	cout << "������ɾ����ϵ������:";
	cin >> name;
	int i = isExist(abs, name);//�����򷵻���ϵ�˴洢λ��
	if (i==-1) {//������
		cout << endl << "ɾ����ϵ�˲�����" << endl;
		return;
	}
	//��ϵ�˴���
	for (int j = i + 1; j < abs->m_Size; j++) {
		abs->personArray[j - 1] = abs->personArray[j];//������ϵ����ǰ�ƶ�ʵ��ɾ��
	}
	abs->m_Size--;
	cout <<endl<<"ɾ���ɹ�" << endl;
}
//������ϵ��
void findPerson(Addressbooks* abs) {
	string name;
	cout << "�����������ϵ�ˣ�";
	cin >> name;
	int i = isExist(abs, name);//�����򷵻���ϵ�˴洢λ��
	if (i == -1) {
		cout << endl << "������ϵ�˲�����" << endl;
		return;
	}
	else {
		cout << endl << abs->personArray[i].m_Name << " " << abs->personArray[i].m_Sex << " " << abs->personArray[i].m_Age << " " << abs->personArray[i].m_Phone << " " << abs->personArray[i].m_Addr << endl;
	}
}
//�޸���ϵ��
void modifyPerson(Addressbooks* abs){
	string name;
	cout << "�������޸���ϵ������:";
	cin >> name;
	int i = isExist(abs, name);//�����򷵻���ϵ�˴洢λ��
	if (i == -1) {
		cout << endl << "�޸���ϵ�˲�����" << endl;
		return;
	}
	cout << "��ѡ���޸�ѡ��:1.���� 2.�Ա� 3.���� 4.�绰 5.��ַ" << endl;
	int xuan;
	cin >> xuan;
	cout << "�������µ���Ϣ:";
	string xx;
	cin >> xx;
	switch (xuan)
	{
		case 1: {
			abs->personArray[i].m_Name = xx;
			break;
		}
		case 2: {
			abs->personArray[i].m_Sex = xx;
			break;
		}
		case 3: {
			abs->personArray[i].m_Age = xx;
			break;
		}
		case 4: {
			abs->personArray[i].m_Phone = xx;
			break;
		}
		case 5: {
			abs->personArray[i].m_Addr = xx;
			break;
		}
		default: {
			cout << "�������";
			return;
		}
	}
	cout << "�޸ĳɹ�" << endl;
}
//���������ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main() {
	Addressbooks abs;//����һ��ͨѶ¼
	abs.m_Size = 0;//��ʼ��ͨѶ¼����
	while (1) {
		showMenu();
		cout << "�����������";
		int select;
		cin >> select;
		switch (select)
		{
		case 1: {
			addPerson(&abs);//�����ϵ��
			break;
		}
		case 2: {
			showPerson(&abs);//��ʾ��ϵ��
			break;
		}
		case 3: {
			deletePerson(&abs);//ɾ����ϵ��
			break;
		}
		case 4: {
			findPerson(&abs);//������ϵ��
			break;
		}
		case 5: {
			modifyPerson(&abs);//�޸���ϵ��
			break;
		}
		case 6: {
			cleanPerson(&abs); //�����ϵ��
			break;
		}
		case 0: {
			//�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
		}
		default:
			break;
		}
		cout << "�س�����";
		cin.get();//�س�������
		cin.get();//�س�������
		system("cls");
	}
	
	cin.get();
	return 0;
}
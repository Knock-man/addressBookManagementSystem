#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
struct Person {
	string m_Name; //姓名
	string m_Sex; //性别：1男 2女
	string m_Age; //年龄
	string m_Phone; //电话
	string m_Addr; //住址
};
struct Addressbooks {
	Person personArray[MAX];//通讯录中的联系人
	int m_Size;//通讯录人数个数
};

//菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
//添加联系人信息；
void addPerson(Addressbooks* abs) {
	if (abs->m_Size > MAX) {
		cout << "通讯录已满";
		return;
	}
	string name, sex , telephon, address, age;
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入性别：" << endl;
	cin >> sex;
	cout << "请输入年龄：" << endl;
	cin >> age;
	cout << "请输入电话：" << endl;
	cin >> telephon;
	cout << "请输入住址：" << endl;
	cin >> address;
	abs->personArray[abs->m_Size].m_Name = name;
	abs->personArray[abs->m_Size].m_Sex = sex;
	abs->personArray[abs->m_Size].m_Age = age;
	abs->personArray[abs->m_Size].m_Phone = telephon;
	abs->personArray[abs->m_Size].m_Addr = address;
	abs->personArray[abs->m_Size].m_Name = name;
	abs->personArray[abs->m_Size].m_Name = name;
	abs->m_Size++;//通讯录人数加一
	cout << "添加成功!"<<endl;
}
//显示联系人
void showPerson(Addressbooks* abs){
	if (abs->m_Size <= 0) {
		cout << "通讯录为空"<<endl;
		return;
	}
	for (int i = 0; i < abs->m_Size; i++) {
		cout << endl << abs->personArray[i].m_Name << " " << abs->personArray[i].m_Sex << " " << abs->personArray[i].m_Age << " " << abs->personArray[i].m_Phone << " " << abs->personArray[i].m_Addr << endl;
	}
}
//判断联系人是否存在
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;//存在，返回位置
		}
	}
	return -1;//不存在
}
//删除联系人
void deletePerson(Addressbooks* abs) {
	string name;
	cout << "请输入删除联系人姓名:";
	cin >> name;
	int i = isExist(abs, name);//存在则返回联系人存储位置
	if (i==-1) {//不存在
		cout << endl << "删除联系人不存在" << endl;
		return;
	}
	//联系人存在
	for (int j = i + 1; j < abs->m_Size; j++) {
		abs->personArray[j - 1] = abs->personArray[j];//后面联系人向前移动实现删除
	}
	abs->m_Size--;
	cout <<endl<<"删除成功" << endl;
}
//查找联系人
void findPerson(Addressbooks* abs) {
	string name;
	cout << "请输入查找联系人：";
	cin >> name;
	int i = isExist(abs, name);//存在则返回联系人存储位置
	if (i == -1) {
		cout << endl << "查找联系人不存在" << endl;
		return;
	}
	else {
		cout << endl << abs->personArray[i].m_Name << " " << abs->personArray[i].m_Sex << " " << abs->personArray[i].m_Age << " " << abs->personArray[i].m_Phone << " " << abs->personArray[i].m_Addr << endl;
	}
}
//修改联系人
void modifyPerson(Addressbooks* abs){
	string name;
	cout << "请输入修改联系人姓名:";
	cin >> name;
	int i = isExist(abs, name);//存在则返回联系人存储位置
	if (i == -1) {
		cout << endl << "修改联系人不存在" << endl;
		return;
	}
	cout << "请选择修改选项:1.姓名 2.性别 3.年龄 4.电话 5.地址" << endl;
	int xuan;
	cin >> xuan;
	cout << "请输入新的信息:";
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
			cout << "输入错误";
			return;
		}
	}
	cout << "修改成功" << endl;
}
//清空所有联系人
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main() {
	Addressbooks abs;//创建一个通讯录
	abs.m_Size = 0;//初始化通讯录人数
	while (1) {
		showMenu();
		cout << "请输入操作：";
		int select;
		cin >> select;
		switch (select)
		{
		case 1: {
			addPerson(&abs);//添加联系人
			break;
		}
		case 2: {
			showPerson(&abs);//显示联系人
			break;
		}
		case 3: {
			deletePerson(&abs);//删除联系人
			break;
		}
		case 4: {
			findPerson(&abs);//查找联系人
			break;
		}
		case 5: {
			modifyPerson(&abs);//修改联系人
			break;
		}
		case 6: {
			cleanPerson(&abs); //清空联系人
			break;
		}
		case 0: {
			//退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
		}
		default:
			break;
		}
		cout << "回车继续";
		cin.get();//回车再清屏
		cin.get();//回车再清屏
		system("cls");
	}
	
	cin.get();
	return 0;
}
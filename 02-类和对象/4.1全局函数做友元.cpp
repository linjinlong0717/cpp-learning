友元
//在程序里，有些私有属性，也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

右元的目的就是让一个函数或者类 访问另一个类中私有成员

友元的关键字为 friend

友元的三种实现
·全局函数做友元
·类做友元
·成员函数做友元

一、全局函数做友元
//代码演示：
#include<iostream>
using namespace std;
#include<string>
//建筑物类
class Building
{
	//goodGuy全局函数是 Building好朋友，可以访问Building中私有成员
	friend void goodGuy(Building* building);
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;   //卧室
};

//全局函数
void goodGuy(Building *building)
{
	cout << "好基友全局函数 正在访问：" << building->m_SittingRoom << endl;
	cout << "好基友全局函数 正在访问：" << building->m_BedRoom << endl;
}
void test01()
{
	Building building;
	goodGuy(&building);
}
int main()
{
	test01();
	system("pause");
	return 0;
}

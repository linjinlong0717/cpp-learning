默认情况下，C++编译器至少给一个类添加3个函数
1.默认构造函数(无参，函数体为空)
2.默认析构函数(无参，函数体为空)
3.默认拷贝构造函数，对属性进行值拷贝

一、构造函数调用规则如下：
·若用户定义有参构造函数，C++不会再提供默认无参构造，但是会提供默认拷贝构造
·若用户定义拷贝构造函数，C++不会再提供其他构造函数

二、代码演示：
#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int a)
	{
		m_Age = a;
		cout << "Person的有参构造函数调用" << endl;
	}
	Person(const Person& p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
	int m_Age;
};
void test01()
{
	Person p;
	p.m_Age = 18;
	Person p2(p);  //若类中没有提供拷贝构造函数，则编译器会提供拷贝构造函数
	cout << "p2的年龄为：" << p2.m_Age << endl;
}
void test02()
{
	Person p;//若我们在类中写了有参构造函数(编译器不会提供默认构造函数了)，但没写默认构造函数，此时这行代码会报错

}
int main()
{
	test01(); 
	test02();
	system("pause");
	return 0;
}
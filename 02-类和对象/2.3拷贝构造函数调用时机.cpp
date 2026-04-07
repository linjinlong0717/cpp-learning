拷贝构造函数调用时机
一、C++中拷贝构造函数调用时机通常有三种情况
·使用一个已经创建完毕的对象来初始化一个新对象
·值传递的方式给函数参数传值
·以值方式返回局部对象

二、代码演示
#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "Person默认构造函数调用" << endl;
	}
	Person(int a)
	{
		m_Age = a;
		cout << "Person有参构造函数调用" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		cout << "Person拷贝构造函数调用" << endl;
	}
	~Person ()
	{
		cout << "Person析构函数调用" << endl;
	}
	int m_Age;
};
//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20);
	Person p2(p1);
	cout << "P2的年龄为：" << p2.m_Age << endl;
}

//2.值传递的方式给函数参数传值
void dowork(Person p)  //这里的p和test02里面的p不是一个p
{ }
void test02()
{
	Person p;
	dowork(p);
}

//3.值方式返回局部对象
Person dowork2()
{
	Person p1;
	cout << (int*)&p1 << endl;  //这里的地址和下面的p地址不同 
	return p1;
}
void test03()
{
	Person p = dowork2();
	cout << (int*)&p << endl;
}

int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
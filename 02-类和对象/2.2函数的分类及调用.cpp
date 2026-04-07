构造函数的分类及调用
一、两种分类方式：
按参数分为：有参构造和无参构造
按类型分为：普通构造和拷贝构造

三种调用方式：
括号法、显示法、隐式转换法

二、代码演示：
#include<iostream>
using namespace std;
class Person
{
public:
	//构造函数
	Person()
	{
		cout << "Person的无参(默认)构造函数调用" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "Person的有参构造函数调用" << endl;
	}
	//拷贝构造函数
	Person(const Person &p)
	{
		//将插入的人身上的所有属性，拷贝到我身上
		cout << "Person的拷贝构造函数调用" << endl;
		age = p.age;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
	int age;
};
//调用
void test01()
{
	//1.括号法(常用)
	Person p1;     //默认构造函数调用
	Person p2(10); //有参构造函数
	Person p3(p2); //拷贝构造函数

	//注意事项1：调用默认构造函数时候，不要加()
	//例：Person p1();  这会被编译器认为是函数声明，不会认为在创建对象

	//2.显示法
    Person p4;
	Person p5 = Person(10); //有参构造
	Person p6 = Person(p5); //拷贝构造

	Person(10);   //匿名构造  特点：当前行执行结束后，系统会立即回收掉匿名对象
	cout << "aaa" << endl;  //打印这行之前会执行Person(10)的析构函数
	
	//注意事项2：不用利用拷贝构造函数 初始化匿名对象，编译器把Person(p3)等价于Person p3
	
	//3.隐式转换法
	Person p7 = 10; //相当于 写了 Person p7=Person(10); 有参构造
	Person p8 = p7; //拷贝构造
}
int main()
{
	test01();
	system("pause");
	return 0;
}
类模板分文件编写
//问题：
·类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
//解决：
·解决方式1：直接包含.cpp源文件
·解决方式2：将声明和实现写到同一个文件中，并更改为后缀为.hpp，hpp是约定的名称，并不是强制

代码演示：
//person.h头文件中代码
#pragma once
#include<iostream>
using namespace std;
#include<string>
template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	void showPerson();
	T1 m_Name;
	T2 m_Age;
};

//person.cpp源文件中代码
#include "person.h"
template<class T1,class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1,class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名：" << this->m_Name << " 年龄：" << this->m_Age << endl;
}

//含main函数的文件 中代码
#include<iostream>
using namespace std;
#include "person.h"

void test01()
{
	Person<string, int>p("Jerry", 18);
	p.showPerson();
}
int main()
{
	test01();
	return 0;
}
//此时会出现两个无法解析的外部命令

//解决1：#include "person.h" 改成#include "person.cpp" 直接包含 源文件

//解决2(主流)：将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件
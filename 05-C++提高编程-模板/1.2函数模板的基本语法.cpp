C++提高编程
·C++另一种编程思想称为 泛型编程，主要利用的技术就是模板
·C++提供两种模板机制：函数模板 和 类模板

一、函数模板语法
//函数模板作用：
建立一个通用函数，其函数 返回值类型 和 形参类型 可以不提前指定，
用一个虚拟的类型来代替(将类型参数化)

语法：
template<typename T>
函数声明 或 定义
//解释：
template --声明创建模板
typename --表明其后面的符号是一种数据类型，可以用class代替
T  -- 通用的数据类型，名称可以替换，通常为大写字母

二、代码演示：
#include<iostream>
using namespace std;
template<typename T> //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
void test01()
{
	int a = 10;
	int b = 20;
	//利用函数模板交换
	//两种方式使用函数模板
	//1.自动类型推导
	myswap(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	//2.显示特定类型
	myswap<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}
int main()
{
	test01();
	return 0;
}
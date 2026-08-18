一、pair对组
//要包含头文件#include<utility>

二、创建pair的三种常见写法
#include<iostream>
#include<utility>
#include<string>
using namespace std;

int main()
{
	//1.直接调用构造函数(指定类型)
	pair<int, string>p1(10, "Hello");

	//2.使用make_pair函数(自动推导类型，常用)
	auto p2 = make_pair(20, "World");
	//也可以用于容器中，eg:  v.push_back(make_pair(10,20));

	//3.C++11 列表初始化(简洁)
	pair<int, double>p3 = { 30,3.14 };

	//访问数据
	cout << p1.first << "," << p1.second << endl;
	cout << p2.first << "," << p2.second << endl;
	cout << p3.first << "," << p3.second << endl;

	return 0;
}

//set的insert插入函数返回的类型是 pair<set<元素类型>::iterator,bool>

//pair 支持直接比较：先比 first，first 相等再比 second
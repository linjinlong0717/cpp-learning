vector存放内置数据类型
代码演示：
#include<iostream>
#include<vector> //要加头文件
using namespace std;
int main()
{
	//定义存放int的vector
	vector<int>v;

	//尾插数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	//方式1：迭代器遍历
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//方式2：下标访问
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
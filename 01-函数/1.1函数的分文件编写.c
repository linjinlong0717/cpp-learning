函数的分文件编写
一、作用：让代码结构更加清晰

二、步骤
1.创建后缀名为.h的头文件
2.创建后缀名为.cpp的源文件
3.在头文件中写函数的声明
4.在源文件中写函数的定义

三、案例
1.swap.h的头文件中代码：
#include <iostream>
using namespace std;

void swap(int a, int b);

2.swap.cpp的源文件中代码：
#include "swap.h"   //这里的双引号表示是自己写的头文件
void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

3.需要调用swap函数的文件中的代码：
#include <iostream>
using namespace std;
#include "swap.h"
int main()
{
	int a = 10;
	int b = 20;
	swap(a, b);
	system("pause");
	return 0;
}
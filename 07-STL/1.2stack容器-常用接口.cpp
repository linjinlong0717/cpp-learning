stack常用接口
一、
构造函数：
·stack<T>stk;             //stack对象的默认构造形式
·stack(const stack& stk); //拷贝构造函数

赋值操作：
·stack& operator=(const stack& stk); //重载等号操作符

数据存取：
·push(elem);   //从栈顶添加元素
·pop();        //从栈顶移除一个元素
·top();        //返回栈顶元素

大小操作：
·empty();      //判断堆栈是否为空
·size();       //返回栈的大小

二、代码演示：
#include<iostream>
#include<stack>
using namespace std;

//栈stack容器
void test01()
{
	//特点：先进后出 
	stack<int>s;

	//入栈
	s.push(10);  //注意是push
	s.push(20);
	s.push(30);
	s.push(40);
	cout << "栈的大小为：" << s.size() << endl;  //输出4

	//只要栈不为空，就查看栈顶，并且执行出栈操作
	while (!s.empty())
	{
		//查看栈顶元素
		cout << "栈顶元素为：" << s.top() << endl;

		//出栈
		s.pop();
	}
	cout << "栈的大小为：" << s.size() << endl;  //输出0
}
int main()
{
	test01();
	return 0;
}
一、inline 的核心作用
消除普通函数调用的开销

//普通函数调用流程：
保存现场、参数压栈
跳转到函数地址执行
执行完返回、恢复栈
频繁调用短小函数时，跳转、栈操作的耗时占比很高。

//inline 优化逻辑：
编译阶段把函数体代码直接复制粘贴到每一处调用位置，没有跳转、没有栈操作，提升运行速度。

二、代码演示：
#include<iostream>
using namespace std;
inline int func(int a, int b)
{
	return a + b;
}
int main()
{
	int num1 = 10;
	int num2 = 20;
	int ret = func(num1, num2);
	cout << ret << endl;
	return 0;
}

三、限制：函数体不能复杂(循环、递归、大量分支不可用inline)
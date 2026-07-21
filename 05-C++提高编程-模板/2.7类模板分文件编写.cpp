类模板分文件编写
//问题(模板分离编译问题)：
·类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
//解决：
·解决方式1：main.cpp文件直接包含.cpp源文件
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

//解决2(主流)：将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件(和.h后缀的文件都在头文件这一栏，后序不会被转换为.obj后缀的目标文件)

//补充：分离编译的流程(包含a.h（头文件）、a.cpp（实现文件）和 main.cpp（主入口文件）)
第一步：预处理（.h 文件被“拷贝”）
当编译器开始干活时，它首先处理 #include 指令。
 ·在 a.cpp 中，你写了 #include "a.h" → 编译器把 a.h 的内容完整复制进 a.cpp 的顶部
 ·在 main.cpp 中，你也写了 #include "a.h" → 编译器把 a.h 的内容完整复制进 main.cpp 的顶部
此时：硬盘上依然是这三个文件，但在编译器眼里，它现在要处理的是两个独立的“翻译单元”：
  翻译单元 1：a.cpp + a.h 的拷贝（合并后的巨型文本）
  翻译单元 2：main.cpp + a.h 的拷贝（合并后的巨型文本）

第二步：编译（.cpp 变成.obj）
编译器分别对这两个“翻译单元”进行编译（互不通信）
 ·处理 a.cpp（ + a.h）：编译器把它翻译成机器码，生成 a.obj（目标文件）
注意：如果里面定义了普通函数，直接生成二进制代码。
如果是模板函数且没人调用，则生成 0 字节代码（这正是分文件编译失败的 根源 ）
 ·处理 main.cpp（ + a.h）：编译器把它翻译成机器码，生成 main.obj
硬盘产物：现在除了源码，多了两个新的中间文件：a.obj 和 main.obj（通常存放在 Debug / Release 文件夹里）

第三步：链接（.obj 变成.exe）
链接器登场，把项目中所有的.obj 文件（这里就是 a.obj 和 main.obj）全部拉进来
·链接器的工作：把 main.obj 里调用的函数（比如 myCompare），去 a.obj 里找对应的机器码
·如果找到了：把两段代码拼在一起，补全地址，最终生成 a.exe（可执行文件）
·如果没找到（模板场景）：main.obj 需要一个 myCompare<int> 的代码，但 a.obj 里因为没实例化，根本没有这个代码。链接器直接报错 LNK2019
文件操作
一、
//程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
//通过文件可以将数据持久化
//C++中对文件操作需要包含头文件<fstream>

文件类型分为两种：
1.文本文件：文件以文本的ASCII码形式存储在计算机中
2.二进制文件：文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们

操作文件的三大类：
1.ofstream:写文件
2.ifstream : 读文件
3.fstream : 读写文件

二、写文件(从 程序 到 文件)
步骤：
1.包含头文件
#include<fstream>

2.创建流对象
ofstream ofs;

3.打开文件
ofs.open("文件路径", 打开方式);

4.写数据
ofs << "写入的数据";

5.关闭文件
ofs.close();

//补充：
文件打开方式          意义
ios::in           为读文件而打开文件
ios::out          为写文件而打开文件
ios::ate          初始位置：文件尾
ios::app          追加方式写文件
ios::trunc        若文件存在 先删除，再创建
ios::binary       二进制方式
//注意：文件打开方式可以配合使用，利用|操作符
例：用二进制方式写文件 ios::binary | ios::out

//代码演示：
#include<iostream>
using namespace std;
#include<fstream>
void test01()
{
	//1.包含头文件 fstream

	//2.创建流对象
	ofstream ofs;

	//3.指定打开方式
	ofs.open("test.txt", ios::out);  //不写路径，就默认和项目的路径一致
	                                 //若文件不存在，则自动创建一个文件
									 // 打开文件的同时，清空文件之前的内容
	//4.写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	//5.关闭文件
	ofs.close();
}
int main()
{
	test01();
	return 0;
}
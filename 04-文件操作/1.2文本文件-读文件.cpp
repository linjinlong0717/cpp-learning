读文件
//读文件与写文件步骤相似，但是读取方式相对较多

一、步骤
1.包含头文件
#include<fstream>

2.创建流对象
ifstream ifs;

3.打开文件 并 判断文件是否打开成功
ifs.open("文件路径", 打开方式);

4.读数据
四种方式读取

5.关闭文件
ifs.close();

二、代码演示：
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
void test01()
{
	//1.包含头文件

	//2.创建流对象
	ifstream ifs;

	//3.打开文件 并且判断是否打开成功
	ifs.open("text.txt",ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;  //比如：路径写错的时候
		return;
	}

	//4.读数据
	  //第一种 
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}

	  //第二种
	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}

	  //第三种(推荐)
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

	  //第四种 //效率比较低
	char c;
	while ((c = ifs.get()) != EOF) //EOF end of file
	{
		cout << c;
	}
	  
	//5.关闭文件
	ifs.close();
}
int main()
{
	test01();
	return 0;
}
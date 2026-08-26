读文件(从 文件 到 程序)
//读文件与写文件步骤相似，但是读取方式相对较多

一、步骤
1.包含头文件
#include<fstream>

2.创建流对象
ifstream ifs;                          //2.和3.步可以合并为 
                                       //ifstream ifs("文件路径", ios::in); 或 ifstream ifs("文件路径");
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

//补充：读int类型数据
写法1：
int  a, b, c;
ifs >> a >> b >> c; //若文件里有“10 20 30”，三个变量分别被赋值

写法2：
int num;
while (ifs >> num)
{
	cout << num << " "; //会读完全部数字
}

//读取容器中的数据
// 先写入 vector
vector<int> v = { 1, 2, 3, 4, 5 };
ofstream ofs("vec.txt");         
ofs << v.size() << endl;
for (int x : v) ofs << x << " ";
ofs.close();

// 读取 vector
ifstream ifs("vec.txt");
int n;
ifs >> n;
vector<int> v2(n);
for (int i = 0; i < n; i++) ifs >> v2[i];
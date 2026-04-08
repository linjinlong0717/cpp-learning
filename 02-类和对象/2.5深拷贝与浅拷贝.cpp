深拷贝与浅拷贝
一、深拷贝是面试经典问题，也是常见的一个坑
浅拷贝：简单的赋值拷贝操作
深拷贝：在堆区重新申请空间，进行拷贝操作

二、代码演示
#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int a, int height)
	{
		m_Age = a;
		m_Height = new int(height);
		cout << "Person的有参构造函数调用" << endl;
	}
	~Person()
	{
		//析构代码，可以用于将堆区开辟的数据做释放操作
		if (m_Height != NULL)
		{
			delete m_Height;    //对于test01,由于栈先进后出的特性，p2会先进行析构
			m_Height = NULL;    //此时会释放堆区数据一次；然后进行p1的析构，此时又
		}                       //把堆区数据释放一次，这样是非法的。(现在运行会报错)
		cout << "Person的析构函数调用"<<endl;
	}
	int m_Age;    //年龄
	int* m_Height;//身高
};
void test01()
{
	Person p1(18, 160);
	cout << "p1的年龄为:" << p1.m_Age << "身高为：" << *p1.m_Height << endl;
	Person p2(p1);
	cout << "p2的年龄为：" << p2.m_Age << "身高为：" << *p2.m_Height << endl;
}
//若利用编译器提供的拷贝构造函数，会做浅拷贝操作
//浅拷贝带来的问题就是堆区的内存重复释放
//此时要用到深拷贝(自己实现拷贝构造函数,解决浅拷贝带来的问题)进行解决
/*Person(const Person& p)
{
	cout << "Person拷贝构造函数调用" << endl;
	m_Age=p.m_Age;
	//m_Height=p.m_Height;编译器默认实现就是这行代码
	//深拷贝操作
	m_Height=new int (*p.m_Height);  //重新在堆区申请一个空间，这样就不会出现重复释放的问题  
}
*/
int main()
{
	test01();
	system("pause");
	return 0;
}
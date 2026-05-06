继承中的构造和析构顺序
//代码演示：
class Base
{
	Base()
	{
		cout << "Base构造函数" << endl;
	}
	~Base()
	{
		cout << "Base析构函数" << endl;
	}
}
class Son :public Base
{
	Son()
	{
		cout << "Son构造函数" << endl;
	}
	~Son()
	{
		cout << "Son析构函数" << endl;
	}
};
test01()
{
	//继承中的构造和析构顺序如下：
	//先构造父类，再构造子类，析构的顺序与构造的顺序相反
	Son s;
}
int main()
{
	test01();
	return 0;
}
//输出：
Base构造函数
Son构造函数
Son析构函数
Base析构函数
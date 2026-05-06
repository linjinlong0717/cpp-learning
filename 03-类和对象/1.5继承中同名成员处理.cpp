继承同名成员处理方式
一、//问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类同名的数据呢？
·访问子类同名成员  直接访问即可
·访问父类同名成员  需要加作用域

二、代码演示：
//继承中同名成员处理
class Base
{
public:
	Base()
	{
		m_A = 100;
	}
	void func()
	{
		cout << "Base - func()调用" << endl;
	}
	void func(int a)
	{
		cout << "Base - func(int a)调用" << endl;
	}
	int m_A;
};
class Son :public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son - func()调用" << endl;
	}
	int m_A;
};
//同名成员属性
void test01()
{
	Son s;
	cout << "Son 下 m_A = " << s.m_A << endl;  //200
	//若通过子类对象 访问父类中同名成员，需要加作用域
	cout << "Son 下 m_A = " << s.Base::m_A << endl; //100
}
//同名成员函数
void test02()
{
	Son s;
	s.func();//直接调用 调用是子类中的同名成员

	s.Base::func();//加作用域 调用父类中的成员函数

	//s.func(100);报错  
	//若子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数

	//若想访问到父类中被隐藏的同名成员函数，需要加作用域
	s.Base::func(100);
}
int main()
{
	test01();
	return 0;
}
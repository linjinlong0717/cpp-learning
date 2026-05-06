同名静态成员处理

问题：继承中同名的静态成员在子类对象上如何进行访问？
一、//静态成员和非静态成员出现同名，处理方式一致(只不过有两种访问的方式，通过对象和通过类名)
·访问子类同名成员 直接访问即可
·访问父类同名成员 需要加作用域

二、代码演示：
class Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}
};
int Base::m_A = 100;
class Son :public Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
};
int Son::m_A = 200;

//同名静态成员属性
void test01()
{
	Son s;
	//1.通过对象访问
	cout << "Son 下 m_A = " << s.m_A << endl;
	cout << "Base 下 m_A = " << s.Base::m_A << endl;

	//2.通过类名访问
	cout << "Son 下 m_A = " << Son::m_A << endl;
	第一个::代表通过类名方式访问，第二个::代表访问父类作用域下
	cout << "Base 下 m_A = " << Son::Base::m_A << endl;
}

//同名静态成员函数
void test02()
{
	Son s;
	//1.通过对象访问
	s.func();
	s.Base::func();

	//2.通过类名访问
	Son::func();
	Son::Base::func();

	//子类出现和父类同名静态成员函数，也会隐藏父类中所有同名成员函数
	//若想访问父类中被隐藏同名成员，需要加作用域
	Son::Base::func(100);
}

int main()
{
	test01();
	test02();
	return 0;
}
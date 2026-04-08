初始化列表
一、1.作用：
C++提供了初始化列表语法，用来初始化属性

2.语法：构造函数():属性1(值1), 属性2(值2)...{}

//传统初始化操作
class Person
{
public:
	Person(int a, int b, int c)
	{
		m_A = a;
		m_B = b;
		m_C = c;
	}
	int m_A;
	int m_B;
	int m_C;
};
//初始化列表初始化属性(把有参构造函数改成这个即可)
Person(int a,int b,int c) :m_A(a), m_B(b), m_C(c)
{

}
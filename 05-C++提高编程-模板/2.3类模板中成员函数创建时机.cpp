类模板中成员函数创建时机
//类模板中成员函数和普通函数创建时机是有区别的：
·普通类中的成员函数一开始就可以创建
·类模板中的成员函数并不是在一开始就创建的，而是在调用时才去创建

一、代码演示：
class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};
class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};
template<class T>
class MyClass
{
public:
	T obj;
	//类模板中的成员函数
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2(); //注意：类模板中的成员函数在调用时才可以创建，所以这段代码不会报错
	}
};
void test01()
{
	MyClass<Person1>m;
	m.func1();  //输出Person1 show
	//m.func2();  类模板里面的obj是Person1类型的，所以会报错
}
int main()
{
	test01();
	return 0;
}
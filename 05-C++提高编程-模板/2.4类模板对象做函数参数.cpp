类模板对象做函数参数
一、共三种传入方式：
1.指定的类型  --直接显示对象的数据类型
2.参数模板化  --将对象中的参数变为模板进行传递
3.整个类模板化 --将这个对象类型 模板化进行传递

二、代码演示：
template<class T1,class T2>
class Person
{
	Person(T1 name,T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "姓名：" << this->m_Name << " 年龄：" << this->m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};
//1.指定传入类型(常用)
void printPerson(Person<string, int>& p)
{
	p.showPerson();
}
void test01()
{
	Person<string, int>p("孙悟空", 100);
	p.printPerson(p);
}
//2.参数模板化
template<class T1,class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
}
void test02()
{
	Person<string, int>p("猪八戒", 90);
	p.printPerson2(p);
}
//3.这个类模板化
template<class T>
void printPerson3(T& p)
{
	p.showPerson();
	//查看T1 和 T2的类型
	cout << "T1的类型为：" << typeid(T1).name() << endl;
	cout << "T2的类型为：" << typeid(T2).name() << endl;
}

void test03()
{
	Person<string, int>p("唐僧", 30);
	printPerson(p);
}
int main()
{
	test01();
	test02();
	test03();
	return 0;
}
//2.和3.相当于函数模板 配合 类模板 使用
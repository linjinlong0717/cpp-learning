类模板与友元
全局函数类内实现 - 直接在类内声明友元即可
全局函数类外实现 - 需要提前让编译器知道全局函数的存在

//建议全局函数做类内实现，用法简单，而且编译器可以直接识别
 
//代码演示：

template<class T1,class T2>
class Person;

//类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
	cout << "类外实现--姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	//全局函数 类内实现
	friend void printPerson(Person<T1,T2> p)
	{
		cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
	}
	//全局函数 类外实现
	//friend void printPerson2(Person<T1, T2> p); //这是普通函数的声明
	friend void printPerson2<>(Person<T1, T2> p); // 函数模板的类外实现：需提前声明函数模板，并加 <> 表示是模板友元

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};

//1.全局函数在类内实现
void test01()
{
	Person<string, int>p("Tom", 20);
	printPerson(p);
}  
//2.全局函数在类外实现
void test02()
{
	Person<string, int>p("Jerry", 20);
	printPerson2(p);
}

int main()
{
	test01();
	test02();
	return 0;
}
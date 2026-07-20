模板的局限性
//模板的通用性不是万能的，有些特定数据类型，需要用具体化方式做特殊实现(模板特化)

代码演示：
一、函数模板的特化 (只支持全特化)
//对比两个数据是否相等的函数
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;  //姓名
	int m_Age;      //年龄
};

template <class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//利用具体化Person的版本实现代码，具体化优先调用
template<> bool myCompare<Person>(Person& p1, Person& p2)  //<Person>可以省略
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}
void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!= b" << endl;
	}
}

int main()
{
	test01();
	test02();
	return 0;
}
//总结：
·利用具体化的模板，可以解决自定义类型的通用化
·学习模板并不是为了写模板，而是在STL能够运用系统提供的模板

二、类模板的特化(分为 全特化 和 偏特化 )
1.全特化
template<class T1,class T2>
class Box
{
public:
	T1 data1;
	T2 data2;
};

template<>
class Box<int, double> //类里面不一定要用到int和double
{
public:
	bool is_valid;
	int extra_data;
};

2.偏特化
//偏特化1：
template<class T>
class Box<T, T>
{

};

//偏特化2：
template<class T>
class Box<T, int>
{

};

//偏特化3：
template<class T>
class Box<T*, T*>
{

};
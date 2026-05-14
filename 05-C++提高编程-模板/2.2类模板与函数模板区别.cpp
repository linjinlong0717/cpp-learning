类模板与函数模板区别主要有两点：
1.类模板没有自动类型推导的使用方式,只能用显示指定类型方式
2.类模板在模板参数列表中可以有默认参数

代码演示：
template<class NameType, class AgeType = int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this -> m_Age = age;
	}
	void showPerson()
	{
		cout << "姓名：" << this -> m_Name << "年龄：" << this -> m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};
//1.类模板没有自动类型推导使用方式
void test01()
{
	//Person p("孙悟空",1000); 错误，无法使用自动类型推导
	Person<string, int>p("孙悟空", 1000);//正确，只能用显示指定类型
	p.showPerson();
}

//2.类模板在模板参数列表中可以有默认参数
void test02()
{
	Person<string>p("猪八戒", 999);
	p.showPerson();
}
int main()
{
	test01();
	test02();
	return 0;
}
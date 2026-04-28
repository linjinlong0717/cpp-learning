一、this指针指向被调用的成员函数所属的对象

二、this指针的用途：
·当形参和成员函数同名时，可用this指针来区别
·在类的非静态成员函数中返回对象本身，可使用return *this

三、代码演示：
class Person
{
public:
	Person(int age)
	{
		//this指针指向被调用的成员函数所属的对象
		this->age = age;  //这里用this指针来区别
	}
	Person& PersonAddAge(Person &p)
	{
		this->age += p.age;
		return *this;
	}
	int age;
};
//1.解决名称冲突
void test01()
{
	Person p1(18);
	cout << "p1的年龄为：" << p1.age << endl;
}
//2.返回对象本身用*this
void test02()
{
	Person p1(10);
	Person p2(10);
	//链式编程思想
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
	cout << "p2的年龄为：" << p2.age << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
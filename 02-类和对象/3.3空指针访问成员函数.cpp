代码演示：
class Person
{
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}
	void showPersonAge()
	{
		if (this == NULL) //增加代码健壮性
		{
			return;
		}
		cout << "age = " << m_Age << endl;
	}
	int m_Age;
};
void test01()
{
	Person* p = NULL;
	p->showClassName();
	// p->showPersonAge();第二个函数会访问对象的属性，但指针为空，所以报错
}
int main()
{
	test01();
	system("pause");
	return 0;
}
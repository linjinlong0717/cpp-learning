 递增运算符重载
一、作用：通过重载递增运算符，实现自己的整型数据

二、代码演示：
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载前置++运算符 返回引用为了一直对一个数据进行递增操作
	MyInteger& operator++()
	{
		//先进行++运算
		m_Num++;
		//再将自身做返回
		return *this;
	}
	//重载后置++运算符
	//这里的int代表占位参数，可以用于区分前置和后置递增
	MyInteger operator++(int)  //这里不能返回引用，否则就会出现返回局部变量的引用
	{
		//先 记录当时结果
		MyInteger temp = *this;
		//后 递增
		m_Num++;
		//最后 将记录结果做返回
		return temp;
	}
private:
	int m_Num;
};
//重载<<运算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}
void test01()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
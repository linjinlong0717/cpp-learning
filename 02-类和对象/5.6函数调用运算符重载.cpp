函数调用运算符重载
一、
·函数调用运算符(),也可以重载
·由于重载后使用的方式非常像函数的调用，因此称为仿函数
·仿函数没有固定写法，非常灵活

二、代码演示：
//打印输出类
class MyPrint
{
public:
	//重载函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}
};
//加法类
class MyAdd
{
public:
	int operator()(int num1,int num2)
	{
		return num1 + num2;
	}
};
void test01()
{
	MyPrint myPrint;
	myPrint("hello world");
}
void test02()
{
	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret = " << ret << endl;

	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}
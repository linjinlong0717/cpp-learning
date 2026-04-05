new操作符
一、C++中利用new操作符在堆区开辟数据
堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
语法：new数据类型
利用new创建的数据，会返回该数据对应的类型的指针

二、代码演示：
1.new的基本语法
int* func()
{
	int* p = new int(10);
	return p;
}
void test01()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;//都是输出10
	delete p;
	//cout<<*p<<endl;  内存已经被释放，再次访问就是非法操作，会报错
}
int test02() //在堆区利用new开辟数组
{
	int* arr = new int[10]; //10代表数组有10个元素
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	delete[] arr; //释放堆区数组
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}

一、普通函数与函数模板区别：
·普通函数调用时可以发生自动类型转换(隐式类型转换)
·函数模板调用时，若利用自动类型推导，不会发生隐式类型转换
·若利用显示指定类型的方式，可以发生隐式类型转换

二、代码演示：
//普通函数
int myAdd01(int a, int b)
{
	return a + b;
}
//函数模板
template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd01(a, b) << endl;
	cout << myAdd01(a, c) << endl;//普通函数可以发生隐式类型转换

	//模板函数的自动类型推导(不能发生隐式类型转换)
	cout << myAdd02(a, b) << endl;
	//cout << myAdd02(a, c) << endl; 报错

	//模板函数的显示指定类型(能发生隐式类型转换)
	cout << myAdd02<int>(a, c) << endl; //109
}
int main()
{
	test01();
	return 0;
}

//建议使用显示指定类型的方式，调用函数模板
//因为可以自己确定通用类型T
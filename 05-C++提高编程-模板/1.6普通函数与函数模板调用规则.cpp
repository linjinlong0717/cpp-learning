普通函数与函数模板的调用规则
一、规则：
1.若函数模板和普通函数都可以实现，优先调用普通函数
2.可以通过空模板参数列表来强制调用函数模板
3.函数模板也可以发生重载
4.若函数模板可以产生更好的匹配，优先调用函数模板

二、代码实现：
void myPrint(int a,int b)
{
	cout << "调用的普通函数" << endl;
}

template<class T>
void myPrint(T a,T b)
{
	cout << "调用的模板" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
	cout << "调用重载的模板" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;
	myPrint(a, b);  //输出调用的普通函数 //若这时候，只写普通函数的声明，则会报错

	//通过空模板参数列表，强制调用函数模板
	myPrint<>(a, b);

	//调用重载的模板
	myPrint(a, b, 100);

	//若函数模板产生更好的匹配，优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2); //调用函数模板
}

int main()
{
	test01();
	return 0;
}

//既然提供了函数模板，最好就不要提供普通函数
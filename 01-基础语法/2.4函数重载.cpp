函数重载
一、1.作用：函数名可以相同，提高复用性

2.函数重载满足条件：
(1)同一个作用域下
(2)函数名称相同
(3)函数参数类型不同 或者 个数不同 或者顺序不同

//注意：函数的返回值不可以作为函数重载的条件
//例如：int func(double a,int b)和void func(double a,int b)不行。因为在调用的时候会出现二义性。

3.代码演示：
void func()
{
	cout << "func的调用" << endl;
}
void func(int a)
{
	cout << "func(int)的调用" << endl;
}
int main()
{
	func();
	func(10);
	system("pause");
	return 0;
}

二、函数重载注意事项
1.引用作为重载条件
void func(int& a)
{
	cout << "func(int &a)调用" << endl;
}
void func(const int& a)
{
	cout << "func(const int &a)调用" << endl;
}
int main()
{
	int a = 10;
	func(a);  //调用第一个函数
	func(10); //调用第二个函数
	system("pause");
	return 0;
}

2.函数重载碰到函数默认参数
//容易出现二义性，所以尽量不要这么写
例：void func(int a,int b=10)和void func(int a)。用func(a)时会出现二义性。
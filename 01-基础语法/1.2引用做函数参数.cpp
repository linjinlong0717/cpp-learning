引用做函数参数
一、作用：函数传参时，可以利用引用的技术让形参修饰实参
//优点：可以简化指针修改实参

二、代码演示：
void mySwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a = 10;
	int b = 20;
	mySwap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	//输出a为20，b为10
	system("pause");
	return 0;
}
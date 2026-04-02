引用做函数返回值
一、作用：引用是可以作为函数返回值存在的
//注意：1.不要返回局部变量引用
        2.函数调用可以作为左值

对于1.：
int& test01()
{
    int a = 10; //局部变量存放在四区中的栈区(改成这个static int a = 10;静态变量，存放在全局区，全局区上的数据在程序结束后系统释放。结果就不会错了)
    return a;
}
int main()
{
    int& ref = test01();
    cout << "ref = " << ref << endl;//第一次结果正确，是因为编译器做了保留
    cout << "ref = " << ref << endl;//第二次结果错误，因为a的内存已经释放
}

对于2.：
int& test02()
{
    static int a = 10;
    return a;
}
int main()
{
    int& ref = test02();
    cout << "ref = " << ref << endl;//输出10
    cout << "ref = " << ref << endl;
    test02() = 1000;            //如果函数的返回值是引用，这个函数调用可以作为左值
    cout << "ref = " << ref << endl;//输出1000
    cout << "ref = " << ref << endl;
}

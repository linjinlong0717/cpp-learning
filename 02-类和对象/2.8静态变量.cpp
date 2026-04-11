静态变量
一、静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员

静态成员分为：
·静态成员变量
     所有对象共享同一份数据
     在编译阶段分配内存
     类内声明，类外初始化

·静态成员函数
     所有对象共享同一个函数
     静态成员函数只能访问静态成员变量

二、静态成员的代码演示：
class Person
{
public:
    static int m_A;

//静态成员变量也是有访问权限的(类外访问不到私有静态成员变量)
private:
    static int m_B;
};
int Person::m_A = 100;
int Person::m_B = 200;

void test01()
{
    Person p;
    cout << p.m_A << endl;  //100

    Person p2;
    p2.m_A = 200;

    cout << p.m_A << endl;  //200
}
void test02()
{
    //静态成员变量有两种访问方式
    //1.通过对象进行访问
    Person p;
    cout << p.m_A << endl;

    //2.通过类名进行访问
    cout << Person::m_A << endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}

静态函数的代码演示：
class Person
{
public:
    //静态成员函数
    static void func()
    {
        m_A = 100; //静态成员函数可以访问 静态成员变量
       // m_B = 200; 静态成员函数不可以访问 非静态成员变量(因为无法区分到底是哪个对象的m_B)
        cout << "static void func调用 " << endl;
    }
    static int m_A;//静态成员变量
    int m_B;       //非静态成员变量
private:
    static void func2()
    {
        cout << "static void func2调用" << endl;
    }
};
int Person::m_A = 0;
//有两种访问方式
void test01()
{
    //1.通过对象访问
    Person p;
    p.func();
    //2.通过类名访问
    Person::func();
    //Person::func2();类外访问不到私有静态成员函数
}
int main()
{
    test01();
    system("pause");
    return 0;
}
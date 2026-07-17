一、内置类型 -> 类对象
1.例子：
#include <iostream>
using namespace std;

class Number 
{
public:
    int val;
    Number(int x) 
    {
        val = x;
    }
};

int main() 
{
    Number obj1(20);
    cout << obj1.val << endl;

    // 神奇操作：直接给数字，自动转成Number对象
    Number obj2 = 30;
    cout << obj2.val << endl;

    return 0;
}

//原理：编译器偷偷执行了 Number(30)，把整数 30 包装成一个 Number 对象，这叫 隐式转换

//坏处：容易出 bug

//解决：explicit 关键字（禁止自动转换）
2.
class Number 
{
public:
    int val;
    explicit Number(int x) 
    {
        val = x;
    }
};

int main() 
{
    // Number obj = 50;   报错，不让隐式转换
    Number obj(50); // 正确，显式调用构造
    Number obj2 = Number(60); // 正确
    return 0;
}

二、类对象 -> 内置类型
1.例子：
#include <iostream>
using namespace std;

class Box
{
public:
    int num;
    Box(int n)
    {
        num = n;
    }

    // 转换规则：对象转int
    operator int() const
    {
        // 返回要给到int的值
        return num;
    }
};

int main()
{
    Box b(66);

    // 编译器自动调用上面的 operator int()
    int x = b;

    cout << x << endl; // 输出66
    return 0;
}

//不加explicit会发生隐式类型转换
2.
#include<iostream>
using namespace std;

class Box
{
public:
    Box(int a)
    {
        val = a;
    }

    explicit operator int() const
    {
        return val;
    }
    int val;
};

int main()
{
    Box b(20);

    int a = static_cast<int>(b);  //显式强制转换语法
    cout << a << endl;   //输出20
    return 0;
}
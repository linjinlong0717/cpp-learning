一、nullptr空指针
1.C++11新增nullptr空指针，专门代表空指针，代替C语言 NULL(NULL本质是0整数，存在类型隐患)
只能赋值给指针变量

2、代码演示：
#include <iostream>
using namespace std;

void func(int num)
{
    cout << "匹配 int 整型版本" << endl;
}

void func(char* ptr)
{
    cout << "匹配 指针 版本" << endl;
}

int main()
{
    func(NULL);
    func(nullptr);
    return 0;
}
vector容量和大小
函数原型：
·empty();            //判断容器是否为空
·capacity();         //容器的容量
·size();             //返回容量中元素的个数
·resize();           //重新制定容器的长度为num，若容器变长，则以默认值填充新位置
                       若容器变短，则末尾超出容器长度的元素被删除    
·resize(int num, elem);//同上，若容器变长，则以elem值填充新位置

代码演示：
void printVector(vector<int>& v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    if (v1.empty())  //为真 代表容器为空
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1的容量为：" << v1.capacity() << endl;
        cout << "v1的大小为：" << v1.size() << endl;
    }

    //重新制定大小
    v1.resize(15);
    printVector(v1);  //输出 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0

    v1.resize(5);
    printVector(v1);  //输出 0 1 2 3 4 
}
int main()
{
    test01();
    return 0;
}
deque排序
//利用算法实现对deque容器进行排序
算法：
·sort(iterator beg, iterator end); //对beg和end区间内元素进行排序

//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
例如：vector容器也可以利用sort进行排序

代码演示：
#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>  //标准算法头文件
void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
    
	printDeque(d);  //300 200 100 10 20 30

	//排序 默认排序规则 从小到大 升序
	sort(d.begin(), d.end());
	cout << "排序后：" << endl;
	printDeque(d);
}
int main()
{
	test01();
	return 0;
}
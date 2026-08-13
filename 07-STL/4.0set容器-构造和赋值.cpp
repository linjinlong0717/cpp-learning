set/multiset 容器   //要加头文件 #include<set>
一、set基本概念
·所有元素都会在插入时自动被 排序

本质：set/multiset属于关联式容器，底层结构是用二叉树实现

set和multiset区别：
·set不允许容器中有重复的元素
·multiset允许容器中有重复的元素

二、代码演示：
void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int>s1;

	//插入数据 只有insert方式
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);

	//遍历容器
	printSet(s1);  //输出10 20 30 40

	//拷贝构造
	set<int>s2(s1);
	printSet(s2);

	//赋值构造
	set<int>s3;
	s3 = s1;
	printSet(s3);
}
set大小和交换
·功能：
统计set容器大小以及交换set容器

函数原型：
·size();  //返回容器中元素的数目  //set容器没有resize
·empty(); //判断容器是否为空
·swap(st); //交换两个集合容器

//大小
void test01()
{
	set<int> s1;

	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为：" << s1.size() << endl;
	}
}

//交换
void test02()
{
	set<int> s1;

	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int> s2;

	//插入数据
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);

	s1.swap(s2);
}

int main()
{
	test01();
	test02();
	return 0;
}
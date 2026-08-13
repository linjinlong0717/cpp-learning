set插入和删除
一、功能描述：
·set容器进行插入数据和删除数据

函数原型：
·insert(elem);  //在容器中插入元素
·clear();       //清除所有元素
·erase(pos);    //删除pos迭代器所指的元素，返回下一个元素的迭代器
·erase(beg, end);//删除区间[beg,end)的所有元素，返回下一个元素的迭代器
·erase(elem);    //删除容器中值为elem的元素

二、代码演示：
void test01()
{
	set<int>s1;

	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	//删除  //是删除排序后的元素
	s1.erase(s1.begin());

	//删除的重载版本
	s1.erase(30);  //把元素30删除

	//清空
	s1.erase(s1.begin(), s1.end());
}

int main()
{
	test01();
	return 0;
}
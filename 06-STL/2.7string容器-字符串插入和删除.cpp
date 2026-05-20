string插入和删除
//对string字符串进行 插入 和 删除 字符操作

函数原型：
·string& insert(int pos, const char* s);    //插入字符串
·string& insert(int pos, const string& str);//插入字符串
·string& insert(int pos, int n, char c);    //在指定位置插入n个字符c
·string& erase(int pos, int n = npos);    //删除从pos开始的n个字符

//代码演示：
void test01()
{
	string str = "hello";
	//插入
	str.insert(1, "111");
	cout << "str = " << str << endl; //输出h111ello

	//输出
	str.erase(1, 3); 
	cout << "str = " << str << endl; //输出hello
}

//插入和删除的起始下标都是从0开始
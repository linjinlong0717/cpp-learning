string查找和替换
//查找：查找指定字符是否存在
替换：在指定的位置替换字符串

函数原型：
·int find(const string& str, int pos = 0) const;  //查找str第一次出现位置，从pos开始查找
·int find(const char* s, int pos = 0) const;      //查找s第一次出现位置，从pos开始查找
·int find(const char* s, int pos, int n) const;   //从pos位置查找 s的前n个字符 第一次位置
·int find(const char c, int pos = 0) const;       //查找字符c第一次出现位置
·int rfind(const string& str, int pos = npos) const;//查找str最后一次出现位置，从pos开始查找
·int rfind(const char* s, int pos = npos) const;    //查找s最后一次出现位置，从pos开始查找
·int rfind(const char* s, int pos, int n) const;   //从pos查找 s的前n个字符 最后一次位置
·int rfind(const char c, int pos = 0) const;       //查找字符c最后一次出现位置
·string& replace(int pos, int n, const string& str);//替换从pos开始 n个字符为字符串str
·string& replace(int pos, int n, const char* s);  //替换从pos开始的n个字符 为 字符串s

代码演示：
//1.查找
void test01()
{
	string str1 = "abcdefgde";
	int pos = str1.find("de");
	if (pos == -1)
	{
		cout << "未找到字符串" << endl; //没找到会返回 -1
	}
	else
	{
		cout << "找到字符串，pos = " << pos << endl;  //pos = 3
	}

	//rfind 和 find区别
	//rfind从右往左查找  find从左往右查找
	pos = str1.rfind("de");
	cout << "pos = " << pos << endl;  //pos = 7
}

//2.替换 
void test02()
{
	string str1="abcdefg";
	str1.replace(1, 3, "1111"); //从1号位置起 3个字符 替换为"1111"
	cout << "str1 = " << str1 << endl;//输出str1 = a1111efg
}

int main()
{
	test01();
	test02();
	return 0;
}
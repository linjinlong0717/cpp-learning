string子串
//功能描述：
·从字符串中获取想要的子串

函数原型：
·string substr(int pos = 0, int n = npos) const; //返回由pos开始的 n个字符 组成的字符串(注意：n的含义)

//代码演示：
void test01()
{
	string str = "abcdef";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;
}

//实用操作
void test02()
{
	string email = "zhangsan@sina.com";
	int pos = email.find("@");
	string usrName = email.substr(0, pos);
	cout << usrName << endl; 
}
//灵活的运用求子串的功能，可以在实际开发中获取有效的信息
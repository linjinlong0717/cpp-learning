string字符串比较
//比较方式：
·字符串比较是按字符的ASCII码进行对比
= 返回 0
> 返回 1
< 返回 -1

函数原型：
·int compare(const string & s) const; //与字符串s比较
·int compare(const char* s) const;    //与字符串s比较

代码演示：
void test01()
{
	string str1 = "hello";
	string str2 = "hello";
	if (str1.compare(str2) == 0)
	{
		cout << "str 等于 str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1 大于 str2" << endl;
	}
	else
	{
		cout << "str1 小于 str2" << endl;
	}
 }
//字符串对比主要是用于比较两个字符串是否相等
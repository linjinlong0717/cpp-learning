#include<iostream>
#include<cstring>
using namespace std;
//构造、析构、拷贝构造、拷贝赋值
class Mystring
{
public:
	char* str;
	int len;
	Mystring(const char* s = "")
	{
		this->len = strlen(s);
		str = new char[(this->len) + 1];  //要包含'\0'
		strcpy(str, s);
		cout << "构造函数：" << str << endl;
	}

	Mystring(const Mystring& other)
	{
		this->len = other.len;
		str = new char[(this->len) + 1];
		strcpy(str, other.str);
		cout << "拷贝构造：" << str << endl;
	}

	Mystring& operator=(const Mystring& s)
	{
		if (this == &s) return *this;
		delete[] this->str;
		this->len = s.len;
		this->str = new char[len + 1];
		strcpy(str, s.str);
		cout << "赋值运算符：" << str << endl;
		return *this;
	}

	~Mystring()
	{
		cout << "析构：" << str << endl;
		delete[] str;
		cout << "析构函数：" << endl;
	}
};
int main()
{

	return 0;
}
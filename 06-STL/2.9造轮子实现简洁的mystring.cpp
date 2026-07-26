#include<iostream>
#include<cstring>
using namespace std;
class my_string
{
private:
	char* str;
	int len;
public:
	//构造函数
	my_string(const char* s="") //包含默认构造
	{
		len = strlen(s);
		str = new char[len + 1];//+1留给'\0'
		strcpy(str, s);
	}

	//拷贝构造
	my_string(const my_string& s)
	{
		this->len = s.len;
		this->str = new char[this->len+1];
		strcpy(str, s.str);
	}

	//获取C风格字符串
	const char* mystr()const
	{
		return str;
	}

	//获取长度
	int size()const
	{
		return len;
	}

	//重载[]运算符
	char& operator[](int pos)
	{
		return str[pos];
	}

	//重载=运算符
	my_string& operator=(const my_string& other)
	{
		if (this == &other) return *this;
		delete[]str;
	    this->len = other.len;
		this->str = new char[len + 1];
		strcpy(str, other.str);
		return *this;
	}

	//析构函数
	~my_string()
	{
		delete[]str;
		str = nullptr;
		len = 0;
	}
};
//重载<<运算符   写成全局函数
ostream& operator<<(ostream& os, const my_string& s)
{
	os << s.mystr();
	return os;
}
int main()
{
	return 0;
}
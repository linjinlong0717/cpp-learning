类模板案例
//案例描述：实现一个通用数组类，要求如下：
·可以对内置数据类型以及自定义数据类型的数据存储
·将数组中的数据存储到堆区
·构造函数中可以传入数组的容器
·提供对应的拷贝构造函数以及operator = 防止浅拷贝问题
·提供尾插法和尾删法对数组中的数据进增加和删除
·可以通过下标的方式访问数组中的元素
·可以获取数组中当前元素个数和数组的容器

//代码演示：
//MyArray.hpp头文件中的代码
#pragma once
#include<iostream>
using namespace std;
template<class T>
class MyArray
{
public:
	//有参构造 参数 容量
	MyArray(int capacity)
	{
		cout << "Myarray有参构造函数调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
		cout << "Myarray拷贝构造函数调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress; 浅拷贝
		this->pAddress = new T[arr.m_Capacity];//深拷贝
	    
		//将arr中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator= 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr)
	{
		cout << "Myarray 的 operator=调用" << endl;
		//先判断原来堆区是否有数据，若有先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;//别漏了
	}

	//尾插法
	void Push_Back(const T& val)
	{
		//判断容器是否等于大小
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val; //在数组末尾插入数据
		this->m_Size++;   //更新数组大小
	}

	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//通过下标方式访问数组中的元素 arr[0]=100;
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	  
	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//返回数组大小
	int getSize()
	{
		return this->m_Size;
	}

	//析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			cout << "Myarray析构函数调用" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;   //指针指向堆区开辟的真实数组
	int m_Capacity;//数组容量
	int m_Size;    //数组大小
};

//含main函数文件中的代码：
#include<iostream>
#include<string>
using namespace std;
#include "MyArray.hpp"
void test01()
{
	MyArray<int> arr1(5);
	MyArray<int> arr2(arr1);
	MyArray<int> arr3(100);
	arr3 = arr1;
}

void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test02()
{
	MyArray<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//利用尾删法向数组中插入数据
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出为：" << endl;

	printIntArray(arr1);

	cout << "arr1的容量为：" << arr1.getCapacity() << endl;
	cout << "arr1的大小为：" << arr1.getSize() << endl;

	//尾删
	arr1.Pop_Back();
	cout << "arr1尾删后：" << endl;
	cout << "arr1的容量为：" << arr1.getCapacity() << endl;
	cout << "arr1的大小为：" << arr1.getSize() << endl;
}

class Person
{
public:
	Person() {}
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}

	string  m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名为：" << arr[i].m_Name << " 年龄为：" << arr[i].m_Age << endl;
	}
	cout << endl;
}

void test03()
{
	MyArray<Person> arr(10);
	Person p1("孙悟空", 999);
	Person p2("韩信", 30);
	Person p3("妲己", 20);
	Person p4("赵云", 25);
	Person p5("安其拉", 27);

	//将数据插入数组中
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

	//打印数组
	printPersonArray(arr);

	//输出容量
	cout << "arr容量为：" << arr.getCapacity() << endl;
	//输出大小
	cout << "arr大小为：" << arr.getSize() << endl;
}
int main()
{
	test01();
	test02();
	test03();
	return 0;
}
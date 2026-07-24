#include<iostream>
#include<string>
using namespace std;
template<class T>
class myvector
{
private:
	T* ptr;
	int size;
	int capacity;

public:
	//默认构造
	myvector()
	{
		ptr = nullptr;
		size = 0;
		capacity = 0;
	}

	//拷贝构造函数
	myvector(const myvector<T>& v)
	{
		this->ptr = new T[v.capacity];
		this->size = v.size;
		this->capacity = v.capacity;
		for (int i = 0; i < size; i++)
		{
			ptr[i] = v.ptr[i];
		}
	}

	//赋值运算符重载
	myvector<T>& operator=(const myvector<T>& v)
	{
		if (this != &v)
		{
			if (ptr != nullptr) delete[]ptr;
			this->ptr = new T[v.capacity];
			this->size = v.size;
			this->capacity = v.capacity;
			for (int i = 0; i < size; i++)
			{
				ptr[i] = v.ptr[i];
			}
			return *this;
		}
		return *this;
	}

	//[]运算符重载
	T& operator[](const int& a)
	{
		return ptr[a];
	}

	//返回首元素
	T& myfront()
	{
		return ptr[0];
	}

	//返回尾元素
	T& myback()
	{
		return ptr[size - 1];
	}

	//尾插
	void push_back(const T& a)
	{
		if (size < capacity)
		{
			ptr[size] = a;
			size++;
		}
		else
		{
			int new_capacity = (capacity == 0) ? 1 : 2 * capacity;
			reserve(new_capacity);
			ptr[size] = a;
			size++;
		}
	}

	//尾删
	void pop_back()
	{
		size--;
	}

	//预留空间
	void reserve(int a)
	{
		if (capacity < a)
		{
			if (ptr != nullptr)
			{
				T* p = new T[a];
				for (int i = 0; i < size; i++)
				{
					p[i] = ptr[i];
				}
				delete[]ptr;
				ptr = p;
				capacity = a;
			}
			else
			{
				ptr = new T[a];
				capacity = a;
			}
		}
		else
		{
			return;
		}
	}

	//获取容器大小
	int getsize()
	{
		return size;
	}

	//获取容器容量
	int getcapacity()
	{
		return capacity;
	}

	~myvector()
	{
		if (ptr != nullptr) delete[]ptr;
	}
};
int main()
{

	return 0;
}
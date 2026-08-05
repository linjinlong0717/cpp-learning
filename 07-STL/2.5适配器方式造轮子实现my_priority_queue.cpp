#include<iostream>
#include<algorithm>
#include<functional>  //包含less<T>
#include<vector>
using namespace std;

template<class T,class Container = vector<T>,class Compare = less<T>> 
class my_priority_queue
{
private:
	Container c;
	Compare comp;
public:
	void push(const T& val)
	{
		c.push_back(val);
		push_heap(c.begin(), c.end(), comp); //头文件#include<algorithm>
	}

	void pop()
	{
		pop_heap(c.begin(), c.end(), comp);
		c.pop_back();
	}

	const T& top() const
	{
		return c[0];
	}

	size_t size() const
	{
		return c.size();
	}

	bool empty() const
	{
		return c.empty();
	}
};
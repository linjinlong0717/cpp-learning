template<class T,class container = deque<T>>
class my_stack
{
private:
	container c;
public:
	void push(T val)
	{
		c.push_back(val);
	}

	void pop()
	{
		c.pop_back();
	}

	T& top()
	{
		return c.back();
	}

	int size() const
	{
		return c.size();
	}

	bool empty() const
	{
		return c.empty();
	}
};
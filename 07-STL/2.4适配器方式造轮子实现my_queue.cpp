template<class T, class container = deque<T>>
class my_queue
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
		c.pop_front();
	}

	T& front() 
	{
		return c.front();
	}

	T& back() 
	{
		return c.back();
	}

	int size() const
	{
		return c.size();
	}

	bool empty()
	{
		return c.empty();
	}
};
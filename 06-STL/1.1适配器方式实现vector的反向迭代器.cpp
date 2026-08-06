一、vector的正向迭代器实现
template<class T>
class my_vector
{
private:
	T* ptr;   //随机访问迭代器(正向)
	int m_size;
public:
	using iterator = T*;  //using 相当于起别名

	iterator begin()
	{
		return ptr;
	}

	iterator end()
	{
		return ptr+m_size;
	}

	size_t size()const
	{
		return m_size;
	}

	bool empty() const
	{
		if (m_size == 0) return true;
		else return false;
	}
};

二、适配器方式实现vector的反向迭代器
template<class Iterator>
class my_reverse_iterator
{
private:
	Iterator current;
public:
	explicit my_reverse_iterator(Iterator it) : current(it) {}

	auto operator*() const
	{
		Iterator temp = current;
		temp--;                    //要前移一位
		return *temp;
	}

	my_reverse_iterator& operator++()   //前置(要引用，才可以++(++it))
	{
		current--;
		return *this;
	}

	my_reverse_iterator& operator--()
	{
		current++;
		return *this;
	}

	my_reverse_iterator operator++(int) //后置
	{
		my_reverse_iterator tmp = *this;
		--current; 
		return tmp;
	}

	my_reverse_iterator operator--(int)
	{
		my_reverse_iterator tmp = *this;
		++current;
		return tmp;
	}

	bool operator==(const my_reverse_iterator & other) const
	{
		return current == other.current;
	}

	bool operator!=(const my_reverse_iterator& other) const
	{
		return current != other.current;
	}
};

template<class T>
class my_vector
{
private:
	T* ptr;
	int m_size;
public:
	using iterator = T*;

	iterator begin()
	{
		return ptr;
	}

	iterator end()
	{
		return ptr + m_size;
	}

	using reverse_iterator = my_reverse_iterator<iterator>;  //这里的iterator是前面的T*

	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}

	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}

	size_t size()const
	{
		return m_size;
	}

	bool empty() const
	{
		if (m_size == 0) return true;
		else return false;
	}
};

//vector的正向迭代器里面的ptr可以直接++，所以不需要额外再定义一个类
//而vector的反向迭代器里面的current++的规则是反向的，所以需要额外再定义一个类
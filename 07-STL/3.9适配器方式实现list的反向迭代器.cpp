适配器方式实现list的反向迭代器(双向非循环链表)
template<class T>
struct Node
{
	T data;
	Node* next;
	Node* pre;

	Node(const T& val):data(val),pre(nullptr),next(nullptr) {}
};

template<class Iterator>
class list_reverse_iterator
{
private:
	Iterator cur;
public:
	list_reverse_iterator(Iterator it = nullptr) :cur(it) {}
	
	auto& operator* ()
	{
		return cur->data;
	}

	list_reverse_iterator& operator++()
	{
		cur=cur->pre;
		return *this;
	}

	list_reverse_iterator& operator--()
	{
		cur = cur->next;
		return *this;
	}

	list_reverse_iterator operator++(int)
	{
		list_reverse_iterator tmp = *this;
		cur = cur->pre;
		return tmp; 
	}

	list_reverse_iterator operator--(int)
	{
		list_reverse_iterator tmp = *this;
		cur = cur->next;
		return tmp;
	}

	bool operator!=(const list_reverse_iterator& other)const
	{
		return cur != other.cur;
	}

	bool operator==(const list_reverse_iterator& other)const
	{
		return cur == other.cur;
	}
};

template<class T>
class my_list
{
private:
	Node<T>* head;
	Node<T>* tail;
	int m_size;
public:
	using iterator = Node<T>*;
	using reverse_iterator = list_reverse_iterator<iterator>;

	my_list(): head(nullptr),tail(nullptr),m_size(0){}

	void push_back(const T& val)
	{
		Node<T>* node = new Node<T>(val);
		if (!head)
		{
			head = tail = node;
		}
		else
		{
			tail->next = node;
			node->pre = tail;
			tail = node;
		}
		m_size++;
	}

	iterator begin()
	{
		return head;
	}

	iterator end()
	{
		return nullptr;
	}

	reverse_iterator rend()
	{
		return reverse_iterator(nullptr);
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(tail);
	}
};
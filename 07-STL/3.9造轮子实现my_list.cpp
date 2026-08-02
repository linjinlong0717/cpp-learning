//节点定义(Node)
struct Node
{
	int val;
	Node* pre;
	Node* next;
};

//链表类(MyList) -- 双向循环链表
class MyList
{
private:
	Node* head;
	int size;
public:
	MyList() 
	{
		head = new Node;
		head->pre = head;
		head->next = head;
		size = 0;
	}

	MyList(const MyList& l) //深拷贝
	{
		head = new Node;
		size = 0;
		head->pre = head;
		head->next = head;
		if (l.size == 0) return;
		Node* cur = l.head;
		for (int i = 0; i < l.size; i++)
		{
			push_back(cur->val);
			cur = cur->next;
		}
	}

	MyList& operator=(const MyList& other)
	{
		if (this == &other) return *this;//处理自赋值的情况
		while (size > 0)  //要清空当前链表
		{
			pop_front();  // 当 size == 1 时，只重置指针，不删除节点
		}
		Node* cur = other.head;
		for (int i = 0; i < other.size; ++i)
		{
			push_back(cur->val);
			cur = cur->next;
		}
		return *this;
	}

	void push_back(int val)
	{
		if (size == 0)
		{
			head->val = val;
			size++;
		}
		else
		{
			Node* temp = head->pre;
			temp->next = new Node;
			temp->next->val = val;
			temp->next->next = head;
			temp->next->pre = temp;
			head->pre = temp->next;
			size++;
		}
	}

	void push_front(int val)
	{
		if (size == 0)
		{
			head->val = val;
			size++;
		}
		else
		{
			Node* temp = head->pre;
			head->pre = new Node;
			head->pre->val = val;
			head->pre->next = head;
			head->pre->pre = temp;
			head = head->pre;
			temp->next = head;
			size++;
		}
	}

	void pop_front()
	{
		 if (size == 0) return;
		 if (size == 1)
		 {
			   size--;
		 }
		 else
		 {
		  Node* temp = head;
		  head = head->next;
		  temp->next->pre = temp->pre;
	      temp->pre->next = temp->next;
		  delete temp;
		  size--;
		 }
	}

	void pop_back()
	{
		if (size == 0) return;
		if (size == 1)
		{
			size--;
		}
		else
		{
			Node* t = head->pre;
			Node* temp = head->pre->pre;
			head->pre = temp;
			temp->next = head;
			delete t;
			size--;
		}
	}

	int mysize()
	{
		return size;
	}

	bool empty()
	{
		if (size == 0) return true;
		else return false;
	}

	~MyList()
	{
		while (size > 0)
		{
			pop_front();
		}
		delete head;
	}
};
#pragma once

// 带头结点的单链表
// 结点结构
// 链表结构
// 采用复合方式：将List类声明成ListNode类的友元类

template<class T>
struct ListNode
{
	T data;
	ListNode<T>* next;

	ListNode(ListNode<T>* ptr = NULL)
	{
		next = ptr;
	}

	ListNode(const T& item, ListNode<T>* ptr = NULL)
	{
		data = item;
		next = ptr;
	}
};

template<class T>
class List
{
public:
	List() // 构造函数
	{
		head = new ListNode<T>;
	}

	List(const ListNode<T>& x) // 构造函数，将头结点初始化为x
	{
		head = new ListNode<T>(x); 
	}

	List(List<T>& L); // 拷贝构造函数

	~List() // 析构函数
	{
		makeEmpty();
	}

	// 将链表置为空表
	void makeEmpty();

	// 计算链表长度
	int Length()const;

	// 返回附加头结点地址
	ListNode<T>* getHead()const
	{
		return first;
	}

	// 设置附加头结点地址
	void setHead(ListNode<T>* p)
	{
		first = p;
	}

	// 搜索含数据x的元素
	ListNode<T>* Search(T x);

	// 搜索第i个元素的地址
	ListNode<T>* Locate(int i);

	// 取出第i个元素的值
	T* getData(int i);

	// 用x修改第i个元素的值
	void setData(int i, T& x);

	// 在第i个元素后插入x
	bool Insert(int i, T& x);

	// 删除第i个元素，x返回该元素的值
	bool Remove(int i, T& x);

	// 判空
	bool IsEmpty()const
	{
		return head->next == NULL;
	}

	// 排序
	void Sort();

	// 输入
	void Input();

	// 输出
	void OutPut();

	// 赋值运算符重载
	List<T>& operator=(List<T>& L);

	// 头插
	void PushFront(T x);
	// 头删
	void PopFront();

	// 尾插
	void PushBack(T x);
	// 尾删
	void PopBack();

private:
	ListNode<T>* head;
};

template<class T>
List<T>::List(List<T>& L) // 拷贝构造函数
{
	T value; // 用来存放原链表中的data
	ListNode<T>* srcptr = L.getHead(); // srcptr用来遍历原链表
	ListNode<T>* destptr =  = new ListNode<T>; // dest是初始化的新链表 这是给附加头结点开辟的空间
	while (srcptr->next != NULL) // 如果头结点的指针域不为空，将结点一个一个复制
	{
		value = srcptr->next->data; // 先拿到结点的data
		destptr->next = new LinkNode<T>(value); // 用data初始化新结点
		descptr = destptr->next;
		srcptr = srcptr->next;
	}
	destptr->next = NULL;
}

// 将链表置为空表
template<class T>
void List<T>::makeEmpty()
{
	ListNode<T>* q; // 用来标记当前待删结点
	while (head->next != NULL) // 当链不空时，删去链中所有结点
	{
		q = head->next; // 每次标记一个
		head->next = q->next; // 让head的指针域指向待删结点的下一个节点
		delete q; // 删除此时标记的节点 循环直到删除完所有节点
	}
}

// 计算链表长度
template<class T>
int List<T>::Length()const
{
	ListNode<T>* p = head->next;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

// 搜索含数据x的元素
// 【这应该再改改，返回元素下标会好点】
template<class T>
ListNode<T>* List<T>::Search(T x)
{
	ListNode<T>* cur = head->next;
	while (cur != NULL)
	{
		if (cur->data == x)
			break;
		else
			cur = cur->next;
	}
	return cur;
}

// 搜索第i个元素的地址
template<class T>
ListNode<T>* List<T>::Locate(int i)
{
	if (i < 0) return NULL;
	ListNode<T>* cur = head->next;
	int k = 0; // 【我感觉这k没用】
	while (cur != NULL && k < i)
	{
		cur = cur->next;
		k++;
	}
	return cur;	// 如果找到，返回第i个节点地址；若i值大于链表长度，返回NULL
}

// 取出第i个元素的值
template<class T>
T* List<T>::getData(int i)
{
	if (i < 0) return NULL;
	ListNode<T>* cur = Locate(i);
	if (cur == NULL)
		return NULL;
	return &cur->data; 
}

// 用x修改第i个元素的值
template <class T>
void List<T>::setData(int i, T& x)
{
	if (i < 0) return;
	ListNode<T>* cur = Locate(i);
	if (cur == NULL)
		return;
	cur->data = x;
}

// 在第i个元素后插入x
/*
位置还是从0号下标开始！！
*/
template<class T>
bool List<T>::Insert(int i, T& x)
{
	/*
	先找位置
	位置合法：插入
	位置不合法：return false;
	*/
	ListNode<T>* cur = Locate(i);
	if (cur == NULL) return false;
	ListNode<T>* newNode = new ListNode<T>(x);
	newNode->next = cur->next;
	cur->next = newNode;
	return true;
}

// 删除第i个元素，x返回该元素的值
template <class T>
bool List<T>::Remove(int i, T& x)
{
	ListNode<T>* cur = Locate(i-1);
	if (cur == NULL) return false;
	ListNode<T>* del = cur->next;
	x = del->data;
	delete del;
	return true;
}


// 输出
template<class T>
void List<T>::OutPut()
{
	ListNode<T>* cur = head->next;
	while (cur != NULL)
	{
		cout << cur->data << " " ;
		cur = cur->next;
	}
	cout << endl;
}

// 赋值运算符重载
template<class T>
List<T>& List<T>::operator=(List<T>& L)
{
	T value;
	ListNode<T>* src = L.getHead();
	ListNode<T>* dest = first = new ListNode<T>;
	while (src->next != NULL)
	{
		value = src->next->data;
		dest->next = new ListNode<T>(value);
		src = src->next;
		dest = dest->next;
	}
	dest->next = NULL;
	return *this;
}

// 头插
template<class T>
void List<T>::PushFront(T x)
{
	ListNode<T>* newnode = new ListNode<T>(x);
	if (newnode == NULL) return;
	if (head->next == NULL) // 如果是空链表直接插入
	{
		head->next = newnode;
		newnode->next = NULL;
	}
	// 链表不空，将头结点后边的节点先连在新结点上
	// 再将head的next指针域指向新结点
	else
	{
		newnode->next = head->next;
		head->next = newnode;
	}
}

// 头删(删除第一个结点)
template<class T>
void List<T>::PopFront()
{
	ListNode<T>* del = head->next;
	head->next = del->next;
	delete del;

}

// 尾插
template<class T>
void List<T>::PushBack(T x)
{
	ListNode<T>* newnode = new ListNode<T>(x);
	if (newnode == NULL) return;

	if (head->next == NULL)
	{
		head->next = newnode;
		newnode->next = NULL;
	}
	ListNode<T>* cur = head->next;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	cur->next = newnode;
	newnode->next = NULL;

}

// 尾删
template<class T>
void List<T>::PopBack()
{
	ListNode<T>* cur = head;
	ListNode<T>* del = head->next;
	while (del->next != NULL)
	{
		cur = cur->next;
		del = del->next;
	}
	delete del;
	cur->next = NULL;
}
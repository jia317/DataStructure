#pragma once

// 带头双向链表
template<class T>
struct DListNode
{
	T data;
	DListNode* prev;
	DListNode* next;

	DListNode()
		: prev(NULL)
		, next(NULL)
	{ }

	DListNode(T x)
		: data(x)
		, prev(NULL)
		, next(NULL)
	{ }

	~DListNode()
	{ }
};

template<class T>
class DList
{
public:
	DList()
	{
		head = new DListNode<T>;
		if (head == NULL)
		{
			cerr << "存储分配出错" << endl;
			exit(1);
		}
		head->next = head->prev = head;
	}

	~DList()
	{
		destroyDList();
	}

	// 返回链表长度
	int DListLength()const
	{
		DListNode<T>* cur = head->next;
		int count = 0;
		while (cur != head)
		{
			cur = cur->next;
			count++;
		}
		return count;
	}

	// 判断双向循环链表是否为空
	bool IsEmpty()
	{
		return head->next == head;
	}

	// 取附加头结点位置
	DListNode<T>* GetHead()const
	{
		return head;
	}
	
////////////////////////////////////////////////////////////////////

	// 头插
	void PushFront(const T& x);
	// 头删
	void PopFront();

	// 尾插
	void PushBack(const T& x);
	// 尾删
	void PopBack();
	
	/*
	定位：返回结点地址
	1. 前驱定位
	2. 后驱定位
	*/
	DListNode<T>* Locate(int i, int d); // i表示第i个结点的位置；d表示查找方向

	// 在pos位置的插入，d=0前驱方向插入
	bool Insert(int pos, const T& x, int d);
	// 删除pos位置的结点,x返回其值
	bool Remove(int pos, T& x, int d);

	// 在链表中沿后继方向寻找等于给定值x的结点
	DListNode<T>* Search(const T& x);


	// 将双向循环链表置空
	void destroyDList();

	void print()
	{
		if (head->next == head) return;

		DListNode<T>* cur = head->next;
		while (cur != head)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}
private:
	DListNode<T>* head;
};

// 头插
template<class T>
void DList<T>::PushFront(const T& x)
{
	DListNode<T>* newNode = new DListNode<T>(x);
	if (newNode == NULL)
	{
		cerr << "结点申请失败" << endl;
		exit(1);
	}

	// 链表为空，直接链接
	if (head->next == head)
	{
		head->next = newNode;
		newNode->next = head;
		newNode->prev = head;
		head->prev = newNode;
	}
	else // 链表不为空
	{
		newNode->next = head->next;
		head->next = newNode;
		newNode->next->prev = newNode;
		newNode->prev = head;
	}	
}
// 头删
template<class T>
void DList<T>::PopFront()
{
	// 链表为空
	if (head->next == head) return;

	DListNode<T>* del = head->next;
	head->next = del->next;
	del->next->prev = head;

	delete del;
}

// 尾插
template<class T>
void DList<T>::PushBack(const T& x)
{
	DListNode<T>* newNode = new DListNode<T>(x);
	if (newNode == NULL)
	{
		cerr << "结点申请失败" << endl;
		exit(1);
	}

	// 链表为空，直接链接
	if (head->next == head)
	{
		head->next = newNode;
		newNode->next = head;
		newNode->prev = head;
		head->prev = newNode;
	}
	else
	{
		DListNode<T>* cur = head->next;
		while (cur->next != head)
		{
			cur = cur->next;
		}
		cur->next = newNode;
		newNode->next = head;
		head->prev = newNode;
		newNode->prev = cur;
	}
}

// 尾删
template<class T>
void DList<T>::PopBack()
{  
	if (head->next == head) return;

	DListNode<T>* cur = head->next;
	while (cur->next != head)
	{
		cur = cur->next;
	}
	cur->prev->next = head;
	head->prev = cur->prev;
	delete cur;
}

// 查找第i个结点位置
template<class T>
DListNode<T>* DList<T>::Locate(int i, int d)
{
	if (head->next == head || i <= 0) return head;

	DListNode<T>* cur;
	if (d == 0)
	{
		cur = head->prev;
	}
	else
	{
		cur = head->next;
	}

	for (int j = 1; j < i; j++)
	{
		if (cur == head) // 注意这里必须是cur==head才表示找完链表了
			break;
		else if (d == 0)
			cur = cur->prev;
		else
			cur = cur->next;
	}

	if (cur != head) 
		return cur;
	else 
		return NULL;
}

// 在pos位置的插入
template<class T>
bool DList<T>::Insert(int pos, const T& x, int d)
{
	DListNode<T>* cur = Locate(pos, d);
	if (cur == NULL) return false;

	DListNode<T>* newNode = new DListNode<T>(x);
	if (newNode == NULL)
	{
		cerr << "存储分配失败" << endl;
		exit(1);
	}

	if (d == 0)
	{
		cur->prev->next = newNode;
		newNode->next = cur;
		newNode->prev = cur->prev;
		cur->prev = newNode;	
	}
	else // 插后边
	{
		newNode->prev = cur;
		newNode->next = cur->next;
		cur->next = newNode;
		newNode->next->prev = newNode;
	}
	return true;
}

// 删除pos位置的结点
template<class T>
bool DList<T>::Remove(int pos, T& x, int d)
{
	DListNode<T>* cur = Locate(pos, d);
	if (cur == NULL) return false;

	x = cur->data;
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	delete cur;

	return true;
}

// 查找
template<class T>
DListNode<T>* DList<T>::Search(const T& x)
{
	DListNode<T>* cur = head->next;
	while (cur != head)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

// 将双向循环链表置空
template<class T>
void DList<T>::destroyDList()
{
	if (head->next == head) return;

	DListNode<T>* cur = head->next;
	DListNode<T>* del = cur;
	while (cur != head)
	{
		head->next = cur->next;
		cur->next->prev = head;
		delete del;
		cur = head->next;
		del = cur;
	}
}
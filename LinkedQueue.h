#pragma once

// 基于链表的单向队列的实现

// 链表结点类定义
template<class T>
struct QListNode
{
	T data;
	QListNode<T>* next;

	QListNode(const T& x)
		:data(x)
		, next(nullptr)
	{ }
};

// 链式队列的类定义
template<class T>
class LinkedQueue
{
public:
	LinkedQueue()
		:front(nullptr)
		, rear(nullptr)
	{ }

	~LinkedQueue()
	{
		makeEmpty();
	}

	bool IsEmpty()const
	{
		return (front == NULL) ? true : false;
	}

	void makeEmpty();

	bool EnQueue(const T& x);

	bool DeQueue(T& x);

	bool getFront(T& x);

	bool getRear(T& x);

	int getSize()const;

	void Print()
	{
		if (IsEmpty()) return;

		QListNode<T>* cur = front;
		while (cur != NULL)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}
private:
	QListNode<T>* front;
	QListNode<T>* rear; // 指向最后一个结点
};

// 将队列置空
template<class T>
void LinkedQueue<T>::makeEmpty()
{
	if (IsEmpty()) return;

	QListNode<T>* cur;
	while (front != NULL)
	{
		cur = front;
		front = front->next;
		delete cur;
	}
}

// 入队
template<class T>
bool LinkedQueue<T>::EnQueue(const T& x)
{
	if (front == NULL)
	{
		front = rear = new QListNode<T>(x);
		if (front == NULL)
		{
			cerr << "存储分配出错" << endl;
			exit(1);
		}
	}
	else
	{
		QListNode<T>* newNode = new QListNode<T>(x);
		if (newNode == NULL)
		{
			cerr << "存储分配出错" << endl;
			exit(1);
		}
		rear->next = newNode;
		rear = rear->next;
	}
	return true;
}

// 出队
template<class T>
bool LinkedQueue<T>::DeQueue(T& x)
{
	if (IsEmpty()) return false;
	
	QListNode<T>* p = front; // 暂存要出队的队头元素
	x = front->data; 
	front = front->next; // 修改队头
	delete p;
	
	return true;
}

// 获取队头结点
template<class T>
bool LinkedQueue<T>::getFront(T& x)
{
	if (IsEmpty()) return false;

	x = front->data;
	return true;
}

// 获取队尾结点
template<class T>
bool LinkedQueue<T>::getRear(T& x)
{
	if (IsEmpty()) return false;

	x = rear->data;
	return true;
}

// 统计队列中节点个数
template<class T>
int LinkedQueue<T>::getSize()const
{
	if (IsEmpty()) return 0;

	QListNode<T>* cur = front;
	int count = 0;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	
	return count;
}
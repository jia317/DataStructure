#pragma once

// ��������ĵ�����е�ʵ��

// �������ඨ��
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

// ��ʽ���е��ඨ��
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
	QListNode<T>* rear; // ָ�����һ�����
};

// �������ÿ�
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

// ���
template<class T>
bool LinkedQueue<T>::EnQueue(const T& x)
{
	if (front == NULL)
	{
		front = rear = new QListNode<T>(x);
		if (front == NULL)
		{
			cerr << "�洢�������" << endl;
			exit(1);
		}
	}
	else
	{
		QListNode<T>* newNode = new QListNode<T>(x);
		if (newNode == NULL)
		{
			cerr << "�洢�������" << endl;
			exit(1);
		}
		rear->next = newNode;
		rear = rear->next;
	}
	return true;
}

// ����
template<class T>
bool LinkedQueue<T>::DeQueue(T& x)
{
	if (IsEmpty()) return false;
	
	QListNode<T>* p = front; // �ݴ�Ҫ���ӵĶ�ͷԪ��
	x = front->data; 
	front = front->next; // �޸Ķ�ͷ
	delete p;
	
	return true;
}

// ��ȡ��ͷ���
template<class T>
bool LinkedQueue<T>::getFront(T& x)
{
	if (IsEmpty()) return false;

	x = front->data;
	return true;
}

// ��ȡ��β���
template<class T>
bool LinkedQueue<T>::getRear(T& x)
{
	if (IsEmpty()) return false;

	x = rear->data;
	return true;
}

// ͳ�ƶ����нڵ����
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
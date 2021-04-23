#pragma once

// ��ͷ˫������
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
			cerr << "�洢�������" << endl;
			exit(1);
		}
		head->next = head->prev = head;
	}

	~DList()
	{
		destroyDList();
	}

	// ����������
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

	// �ж�˫��ѭ�������Ƿ�Ϊ��
	bool IsEmpty()
	{
		return head->next == head;
	}

	// ȡ����ͷ���λ��
	DListNode<T>* GetHead()const
	{
		return head;
	}
	
////////////////////////////////////////////////////////////////////

	// ͷ��
	void PushFront(const T& x);
	// ͷɾ
	void PopFront();

	// β��
	void PushBack(const T& x);
	// βɾ
	void PopBack();
	
	/*
	��λ�����ؽ���ַ
	1. ǰ����λ
	2. ������λ
	*/
	DListNode<T>* Locate(int i, int d); // i��ʾ��i������λ�ã�d��ʾ���ҷ���

	// ��posλ�õĲ��룬d=0ǰ���������
	bool Insert(int pos, const T& x, int d);
	// ɾ��posλ�õĽ��,x������ֵ
	bool Remove(int pos, T& x, int d);

	// ���������غ�̷���Ѱ�ҵ��ڸ���ֵx�Ľ��
	DListNode<T>* Search(const T& x);


	// ��˫��ѭ�������ÿ�
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

// ͷ��
template<class T>
void DList<T>::PushFront(const T& x)
{
	DListNode<T>* newNode = new DListNode<T>(x);
	if (newNode == NULL)
	{
		cerr << "�������ʧ��" << endl;
		exit(1);
	}

	// ����Ϊ�գ�ֱ������
	if (head->next == head)
	{
		head->next = newNode;
		newNode->next = head;
		newNode->prev = head;
		head->prev = newNode;
	}
	else // ����Ϊ��
	{
		newNode->next = head->next;
		head->next = newNode;
		newNode->next->prev = newNode;
		newNode->prev = head;
	}	
}
// ͷɾ
template<class T>
void DList<T>::PopFront()
{
	// ����Ϊ��
	if (head->next == head) return;

	DListNode<T>* del = head->next;
	head->next = del->next;
	del->next->prev = head;

	delete del;
}

// β��
template<class T>
void DList<T>::PushBack(const T& x)
{
	DListNode<T>* newNode = new DListNode<T>(x);
	if (newNode == NULL)
	{
		cerr << "�������ʧ��" << endl;
		exit(1);
	}

	// ����Ϊ�գ�ֱ������
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

// βɾ
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

// ���ҵ�i�����λ��
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
		if (cur == head) // ע�����������cur==head�ű�ʾ����������
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

// ��posλ�õĲ���
template<class T>
bool DList<T>::Insert(int pos, const T& x, int d)
{
	DListNode<T>* cur = Locate(pos, d);
	if (cur == NULL) return false;

	DListNode<T>* newNode = new DListNode<T>(x);
	if (newNode == NULL)
	{
		cerr << "�洢����ʧ��" << endl;
		exit(1);
	}

	if (d == 0)
	{
		cur->prev->next = newNode;
		newNode->next = cur;
		newNode->prev = cur->prev;
		cur->prev = newNode;	
	}
	else // ����
	{
		newNode->prev = cur;
		newNode->next = cur->next;
		cur->next = newNode;
		newNode->next->prev = newNode;
	}
	return true;
}

// ɾ��posλ�õĽ��
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

// ����
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

// ��˫��ѭ�������ÿ�
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
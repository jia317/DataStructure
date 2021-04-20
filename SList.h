#pragma once

// ��ͷ���ĵ�����
// ���ṹ
// ����ṹ
// ���ø��Ϸ�ʽ����List��������ListNode�����Ԫ��

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
	List() // ���캯��
	{
		head = new ListNode<T>;
	}

	List(const ListNode<T>& x) // ���캯������ͷ����ʼ��Ϊx
	{
		head = new ListNode<T>(x); 
	}

	List(List<T>& L); // �������캯��

	~List() // ��������
	{
		makeEmpty();
	}

	// ��������Ϊ�ձ�
	void makeEmpty();

	// ����������
	int Length()const;

	// ���ظ���ͷ����ַ
	ListNode<T>* getHead()const
	{
		return first;
	}

	// ���ø���ͷ����ַ
	void setHead(ListNode<T>* p)
	{
		first = p;
	}

	// ����������x��Ԫ��
	ListNode<T>* Search(T x);

	// ������i��Ԫ�صĵ�ַ
	ListNode<T>* Locate(int i);

	// ȡ����i��Ԫ�ص�ֵ
	T* getData(int i);

	// ��x�޸ĵ�i��Ԫ�ص�ֵ
	void setData(int i, T& x);

	// �ڵ�i��Ԫ�غ����x
	bool Insert(int i, T& x);

	// ɾ����i��Ԫ�أ�x���ظ�Ԫ�ص�ֵ
	bool Remove(int i, T& x);

	// �п�
	bool IsEmpty()const
	{
		return head->next == NULL;
	}

	// ����
	void Sort();

	// ����
	void Input();

	// ���
	void OutPut();

	// ��ֵ���������
	List<T>& operator=(List<T>& L);

	// ͷ��
	void PushFront(T x);
	// ͷɾ
	void PopFront();

	// β��
	void PushBack(T x);
	// βɾ
	void PopBack();

private:
	ListNode<T>* head;
};

template<class T>
List<T>::List(List<T>& L) // �������캯��
{
	T value; // �������ԭ�����е�data
	ListNode<T>* srcptr = L.getHead(); // srcptr��������ԭ����
	ListNode<T>* destptr =  = new ListNode<T>; // dest�ǳ�ʼ���������� ���Ǹ�����ͷ��㿪�ٵĿռ�
	while (srcptr->next != NULL) // ���ͷ����ָ����Ϊ�գ������һ��һ������
	{
		value = srcptr->next->data; // ���õ�����data
		destptr->next = new LinkNode<T>(value); // ��data��ʼ���½��
		descptr = destptr->next;
		srcptr = srcptr->next;
	}
	destptr->next = NULL;
}

// ��������Ϊ�ձ�
template<class T>
void List<T>::makeEmpty()
{
	ListNode<T>* q; // ������ǵ�ǰ��ɾ���
	while (head->next != NULL) // ��������ʱ��ɾȥ�������н��
	{
		q = head->next; // ÿ�α��һ��
		head->next = q->next; // ��head��ָ����ָ���ɾ������һ���ڵ�
		delete q; // ɾ����ʱ��ǵĽڵ� ѭ��ֱ��ɾ�������нڵ�
	}
}

// ����������
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

// ����������x��Ԫ��
// ����Ӧ���ٸĸģ�����Ԫ���±��õ㡿
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

// ������i��Ԫ�صĵ�ַ
template<class T>
ListNode<T>* List<T>::Locate(int i)
{
	if (i < 0) return NULL;
	ListNode<T>* cur = head->next;
	int k = 0; // ���Ҹо���kû�á�
	while (cur != NULL && k < i)
	{
		cur = cur->next;
		k++;
	}
	return cur;	// ����ҵ������ص�i���ڵ��ַ����iֵ���������ȣ�����NULL
}

// ȡ����i��Ԫ�ص�ֵ
template<class T>
T* List<T>::getData(int i)
{
	if (i < 0) return NULL;
	ListNode<T>* cur = Locate(i);
	if (cur == NULL)
		return NULL;
	return &cur->data; 
}

// ��x�޸ĵ�i��Ԫ�ص�ֵ
template <class T>
void List<T>::setData(int i, T& x)
{
	if (i < 0) return;
	ListNode<T>* cur = Locate(i);
	if (cur == NULL)
		return;
	cur->data = x;
}

// �ڵ�i��Ԫ�غ����x
/*
λ�û��Ǵ�0���±꿪ʼ����
*/
template<class T>
bool List<T>::Insert(int i, T& x)
{
	/*
	����λ��
	λ�úϷ�������
	λ�ò��Ϸ���return false;
	*/
	ListNode<T>* cur = Locate(i);
	if (cur == NULL) return false;
	ListNode<T>* newNode = new ListNode<T>(x);
	newNode->next = cur->next;
	cur->next = newNode;
	return true;
}

// ɾ����i��Ԫ�أ�x���ظ�Ԫ�ص�ֵ
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


// ���
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

// ��ֵ���������
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

// ͷ��
template<class T>
void List<T>::PushFront(T x)
{
	ListNode<T>* newnode = new ListNode<T>(x);
	if (newnode == NULL) return;
	if (head->next == NULL) // ����ǿ�����ֱ�Ӳ���
	{
		head->next = newnode;
		newnode->next = NULL;
	}
	// �����գ���ͷ����ߵĽڵ��������½����
	// �ٽ�head��nextָ����ָ���½��
	else
	{
		newnode->next = head->next;
		head->next = newnode;
	}
}

// ͷɾ(ɾ����һ�����)
template<class T>
void List<T>::PopFront()
{
	ListNode<T>* del = head->next;
	head->next = del->next;
	delete del;

}

// β��
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

// βɾ
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
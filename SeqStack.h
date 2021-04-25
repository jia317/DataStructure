#pragma once
#include<assert.h>
#include<iostream>

// ˳��ջ��ʵ��

const int maxSize = 50;
template<class T>
class SeqStack
{
public:
	SeqStack(int ca = maxSize)
		:top(-1)
		, capacity(ca)
	{
		elements = new T[capacity];
		assert(elements != NULL);
	}

	~SeqStack() 
	{
		delete[] elements;
	}

	bool IsEmpty()const
	{
		return (top == -1) ? true:false;
	}

	bool IsFull()const
	{
		return (top == capacity - 1) ? true:false;
	}

	void makeEmpty()
	{
		top = -1;
	}

	//////////////////////////////////////////////////////////////////////

	void Push(const T& x);

	bool Pop(T& x);

	bool Top(T& x);

	int getSize()const;

	//friend ostream& operator << (ostream& os, SeqStack<T>& s);

	void Print()
	{
		if (IsEmpty()) return;

		for (int i = 0; i <= top; i++)
			cout << elements[i] << " ";
		cout << endl;
	}

private:
	T* elements;
	int top; // ջ��ָ��
	int capacity;
	void overflowProcess(); // ջ���������
};

// ����ջ�Ĵ洢�ռ�
const int stackIncrement = 20;
template<class T>
void SeqStack<T>::overflowProcess()
{
	// 1. ������һ�δ�СΪcapacity(old)+stackIncrement��С�Ŀռ�
	T* newArray = new T[capacity + stackIncrement];
	if (newArray == NULL)
	{
		cerr << "�洢����ʧ��";
		exit(1);
	}

	// 2. ���ɿռ�Ԫ�ذ��Ƶ��¿ռ�
	for (int i = 0; i <= top; i++)
	{
		newArray[i] = elements[i];
	}

	// 3. �ͷžɿռ�
	delete[] elements;

	// 4. ��elementsָ��ָ���¿ռ�
	elements = newArray;

	// 5. ����capacity(new)=capacity(old)+stackIncrement
	capacity = capacity + stackIncrement;
}

// ��ջ
template<class T>
void SeqStack<T>::Push(const T& x)
{
	if (IsFull()) overflowProcess();

	elements[++top] = x;
}

// ��ջ
template<class T>
bool SeqStack<T>::Pop(T& x)
{
	if (IsEmpty()) return false;

	x = elements[top];
	top--;
	return true;
}

// ����ջ��Ԫ��
template<class T>
bool SeqStack<T>::Top(T& x)
{
	if (IsEmpty()) return false;

	x = elements[top];
	return true;
}

// ͳ��ջ��Ԫ�ظ���
template<class T>
int SeqStack<T>::getSize()const
{
	if (IsEmpty()) return 0;

	int count = 0;
	for (int i = 0; i <= top; i++)
		count++;

	return count;
}
//int SeqStack<T>::getSize()
//{
//	return top + 1;
//}

//template<class T>
//ostream& operator << (ostream& os, SeqStack<T>& s)
//{
//	os << "top=" << s.top() << endl;
//	for (int i = 0; i <= top; i++)
//	{
//		os << i << ":" << s.elements[i] << " ";
//	}
//	os << endl;
//
//	return os;
//}
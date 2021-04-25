#pragma once
#include<assert.h>
#include<iostream>

// 顺序栈的实现

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
	int top; // 栈顶指针
	int capacity;
	void overflowProcess(); // 栈的溢出处理
};

// 扩充栈的存储空间
const int stackIncrement = 20;
template<class T>
void SeqStack<T>::overflowProcess()
{
	// 1. 新申请一段大小为capacity(old)+stackIncrement大小的空间
	T* newArray = new T[capacity + stackIncrement];
	if (newArray == NULL)
	{
		cerr << "存储分配失败";
		exit(1);
	}

	// 2. 将旧空间元素搬移到新空间
	for (int i = 0; i <= top; i++)
	{
		newArray[i] = elements[i];
	}

	// 3. 释放旧空间
	delete[] elements;

	// 4. 让elements指针指向新空间
	elements = newArray;

	// 5. 更新capacity(new)=capacity(old)+stackIncrement
	capacity = capacity + stackIncrement;
}

// 入栈
template<class T>
void SeqStack<T>::Push(const T& x)
{
	if (IsFull()) overflowProcess();

	elements[++top] = x;
}

// 出栈
template<class T>
bool SeqStack<T>::Pop(T& x)
{
	if (IsEmpty()) return false;

	x = elements[top];
	top--;
	return true;
}

// 返回栈顶元素
template<class T>
bool SeqStack<T>::Top(T& x)
{
	if (IsEmpty()) return false;

	x = elements[top];
	return true;
}

// 统计栈中元素个数
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
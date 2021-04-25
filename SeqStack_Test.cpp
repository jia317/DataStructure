#include<iostream>
#include<windows.h>
using namespace std;

#include"SeqStack.h"

int main()
{
	SeqStack<int> st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	st.Push(5);
	st.Print();

	int x;
	st.Pop(x);
	cout << x << endl;
	st.Pop(x);
	st.Pop(x);
	st.Print();

	cout << st.getSize() << endl;

	int top = st.Top(top);
	cout << top << endl;

	st.makeEmpty();
	if (!st.IsEmpty())
		cout << "Õ»²»¿Õ" << endl;
	else
		cout << "Õ»Îª¿Õ" << endl;


	system("pause");
	return 0;
}
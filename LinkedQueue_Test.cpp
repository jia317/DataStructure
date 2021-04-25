#include<iostream>
using namespace std;

#include"LinkedQueue.h"

int main()
{
	LinkedQueue<int> q;
	q.EnQueue(1);
	q.EnQueue(2);
	q.EnQueue(3);
	q.EnQueue(4);
	q.EnQueue(5);
	q.Print();

	int x;
	q.DeQueue(x);
	cout << x << endl;
	q.DeQueue(x);
	cout << x << endl;
	q.Print();

	q.getFront(x);
	cout << "��ͷԪ��Ϊ��" << x << endl;

	q.getRear(x);
	cout << "��βԪ��Ϊ��" << x << endl;

	cout << "�������У�" << q.getSize() << endl;

	if (q.IsEmpty())
		cout << "����Ϊ��" << endl;
	else
		cout << "���в�Ϊ��" << endl;

	q.makeEmpty();
	if (q.IsEmpty())
		cout << "����Ϊ��" << endl;
	else
		cout << "���в�Ϊ��" << endl;


	system("pause");
	return 0;
}
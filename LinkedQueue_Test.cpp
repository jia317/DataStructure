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
	cout << "队头元素为：" << x << endl;

	q.getRear(x);
	cout << "队尾元素为：" << x << endl;

	cout << "队列中有：" << q.getSize() << endl;

	if (q.IsEmpty())
		cout << "队列为空" << endl;
	else
		cout << "队列不为空" << endl;

	q.makeEmpty();
	if (q.IsEmpty())
		cout << "队列为空" << endl;
	else
		cout << "队列不为空" << endl;


	system("pause");
	return 0;
}
#include<iostream>
#include<Windows.h>
using namespace std;

#include"Dlist.h"

// 测试头插和头删
void test1()
{
	DList<int> dl;
	dl.PushFront(1);
	dl.PushFront(2);
	dl.PushFront(3);
	dl.PushFront(4);
	dl.PushFront(5);
	dl.print();

	dl.PopFront();
	dl.PopFront();
	dl.PopFront();
	dl.print();
}

// 测试尾插和尾删
void test2()
{
	DList<int> dl;

	dl.PushBack(1);
	dl.PushBack(2);
	dl.PushBack(3);
	dl.PushBack(4);
	dl.PushBack(5);
	dl.print();
	cout << dl.DListLength() << endl;

	dl.PopBack();
	dl.PopBack();
	dl.PopBack();
	dl.print();

}

// 测试任意位置的插入和删除
void test3()
{
	// 注意：任意位置的插入，如果是空表，那么就无法插入，因为位置i不合法
	
	DList<int> dl;
	dl.PushBack(0);

	// 后继插入
	dl.Insert(1, 1, 1);
	dl.Insert(2, 2, 1);
	dl.Insert(3, 3, 1);
	dl.print(); // 1，2，3
	
	// 前驱插入
	dl.Insert(1, 4, 0); // 0，1，2，4，3
	dl.Insert(2, 5, 0); // 0，1，2，5，4，3
	dl.Insert(3, 6, 0); // 0，1，2，6，5，4，3
	dl.print(); // 0,1,2,6,5,4,3

	// 删除pos位置的结点
	int x;
	dl.Remove(3, x, 1);
	dl.print();

	cout << dl.Search(6) << endl;
	cout << dl.Search(2) << endl;

	dl.destroyDList();
	if (dl.IsEmpty())
	{
		cout << "链表已置空" << endl;
	}
		
}

int main()
{
	//test1();
	test2();
	//test3();

	system("pause");
	return 0;
}
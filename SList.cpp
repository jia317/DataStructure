#include<iostream>
#include<Windows.h>
using namespace std;

#include"SList.h"

void test1()
{
	List<int> l;
	l.PushFront(1);
	l.PushFront(2);
	l.PushFront(3);
	l.PushFront(4);
	l.PushFront(5);
	l.Length();
	l.OutPut();

	l.PopFront();
	l.OutPut();

	l.PushBack(6);
	l.PushBack(7);
	l.OutPut();

	l.PopBack();
	l.OutPut();	
}

void test2()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	int x = 7;
	l.Insert(2, x);
	l.OutPut(); // 1,2,3,7,4

	if (l.IsEmpty())
	{
		cout << "链表为空" << endl;
	}
	cout << "链表不为空，链表长度为：" << l.Length() << endl;

	cout << *(l.getData(2)) << endl;

	/*int del;
	l.Remove(1, del);
	cout << del << endl; */// 【这运行完报错了！！】

	cout << l.Search(7) << endl;

	int num = 9;
	l.setData(4, num);
	l.OutPut();

	l.makeEmpty();
	l.OutPut();

}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}
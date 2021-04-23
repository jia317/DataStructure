#include<iostream>
#include<Windows.h>
using namespace std;

#include"Dlist.h"

// ����ͷ���ͷɾ
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

// ����β���βɾ
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

// ��������λ�õĲ����ɾ��
void test3()
{
	// ע�⣺����λ�õĲ��룬����ǿձ���ô���޷����룬��Ϊλ��i���Ϸ�
	
	DList<int> dl;
	dl.PushBack(0);

	// ��̲���
	dl.Insert(1, 1, 1);
	dl.Insert(2, 2, 1);
	dl.Insert(3, 3, 1);
	dl.print(); // 1��2��3
	
	// ǰ������
	dl.Insert(1, 4, 0); // 0��1��2��4��3
	dl.Insert(2, 5, 0); // 0��1��2��5��4��3
	dl.Insert(3, 6, 0); // 0��1��2��6��5��4��3
	dl.print(); // 0,1,2,6,5,4,3

	// ɾ��posλ�õĽ��
	int x;
	dl.Remove(3, x, 1);
	dl.print();

	cout << dl.Search(6) << endl;
	cout << dl.Search(2) << endl;

	dl.destroyDList();
	if (dl.IsEmpty())
	{
		cout << "�������ÿ�" << endl;
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
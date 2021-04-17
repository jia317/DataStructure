#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string>
#include <iostream>
using namespace std;
#include "SeqList.h"

/*
 插入前要检测空间大小
 删除前要判空
*/

// 顺序表的初始化
void SeqListInit(SeqList* ps, int capacity)
{
	if (nullptr == ps)
	{
		assert(0);
		return;
	}
		
	ps->capacity = capacity <= 0 ? 10 : capacity;
	ps->array = (DataType*)malloc(ps->capacity*sizeof(DataType));
	ps->size = 0;
}

// 顺序表的销毁
void SeqListDestroy(SeqList* ps)
{
	if (ps)
	{
		free(ps->array);
		ps->array = nullptr;
		ps->capacity = 0;
		ps->size = 0;
	}
}

// 扩容
int CheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity * 2;

		// 申请新空间
		int* pTemp = (int*)malloc(newCapacity*sizeof(DataType));
		if (nullptr == pTemp)
		{
			assert(0);
			return -1;
		}

		// 将原空间元素拷贝至新空间
		memcpy(pTemp, ps->array, ps->capacity*sizeof(DataType));

		// 释放旧空间
		free(ps->array);
		ps->array = pTemp;
		ps->capacity = newCapacity;
	}
}

// 尾插
void SeqListPushBack(SeqList* ps, DataType data)
{
	assert(ps);

	if (!CheckCapacity(ps))
		return;

	ps->array[ps->size++] = data;
}

// 尾删
void SeqListPopBack(SeqList* ps)
{
	if (SeqListEmpty(ps))
		return;

	ps->size--;
}

// 头插
void SeqListPushFront(SeqList* ps, DataType data)
{
	if (!CheckCapacity(ps))
		return;

	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->array[i + 1] = ps->array[i];
	}

	ps->array[0] = data;
	ps->size++;
}

// 头删
void SeqListPopFront(SeqList* ps)
{
	if (SeqListEmpty(ps))
		return;

	for (int i = 1; i < ps->size;++i)
		ps->array[i-1] = ps->array[i];

	ps->size--;
}

// 任意位置的插入
void SeqListInsert(SeqList* ps, int pos, DataType data)
{
	assert(ps);
	if (pos < 0 || pos > ps->size)
		return;

	if (!CheckCapacity(ps))
		return;

	for (int i = ps->size - 1; i >= pos; --i)
		ps->array[i + 1] = ps->array[i];

	ps->array[pos] = data;
	ps->size++;
}

// 任意位置的删除
void SeqListErase(SeqList* ps, int pos)
{
	if (SeqListEmpty(ps))
		return;

	for (int i = pos + 1; i < ps->size; i++)
		ps->array[i - 1] = ps->array[i];

	ps->size--;
}

// 在顺序表中查找值为data的元素，返回该元素的下标
int SeqListFind(SeqList* ps, DataType data)
{
	assert(ps);

	if (SeqListEmpty(ps))
		return -1;

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == data)
			return i;
	}

	return -1;
}

// 检测顺序表中是否为空
int SeqListEmpty(SeqList* ps)
{
	assert(ps);
	return ps->size==0;
}

// 获取顺序表中有效元素的个数
int SeqListSize(SeqList* ps)
{
	return ps->size;
}

// 获取顺序表中空间的容量
int SeqListCapacity(SeqList* ps)
{
	return ps->capacity;
}

// 将顺序表中的元素清空
void SeqListClear(SeqList* ps)
{
	assert(ps);
	ps->size = 0;
}
 
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
		printf("%d ", ps->array[i]);

	printf("\n");
}

void Test1()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListPopBack(&s);
	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListPushFront(&s, 0);
	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListPopFront(&s);
	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListInsert(&s, 3, 7);
	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListErase(&s, 5);
	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	cout << SeqListFind(&s, 7) << endl;

	SeqListClear(&s);
	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);
	
}

int main()
{
	Test1();

	system("pause");
	return 0;
}
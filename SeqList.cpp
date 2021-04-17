#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string>
#include <iostream>
using namespace std;
#include "SeqList.h"

/*
 ����ǰҪ���ռ��С
 ɾ��ǰҪ�п�
*/

// ˳���ĳ�ʼ��
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

// ˳��������
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

// ����
int CheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity * 2;

		// �����¿ռ�
		int* pTemp = (int*)malloc(newCapacity*sizeof(DataType));
		if (nullptr == pTemp)
		{
			assert(0);
			return -1;
		}

		// ��ԭ�ռ�Ԫ�ؿ������¿ռ�
		memcpy(pTemp, ps->array, ps->capacity*sizeof(DataType));

		// �ͷžɿռ�
		free(ps->array);
		ps->array = pTemp;
		ps->capacity = newCapacity;
	}
}

// β��
void SeqListPushBack(SeqList* ps, DataType data)
{
	assert(ps);

	if (!CheckCapacity(ps))
		return;

	ps->array[ps->size++] = data;
}

// βɾ
void SeqListPopBack(SeqList* ps)
{
	if (SeqListEmpty(ps))
		return;

	ps->size--;
}

// ͷ��
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

// ͷɾ
void SeqListPopFront(SeqList* ps)
{
	if (SeqListEmpty(ps))
		return;

	for (int i = 1; i < ps->size;++i)
		ps->array[i-1] = ps->array[i];

	ps->size--;
}

// ����λ�õĲ���
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

// ����λ�õ�ɾ��
void SeqListErase(SeqList* ps, int pos)
{
	if (SeqListEmpty(ps))
		return;

	for (int i = pos + 1; i < ps->size; i++)
		ps->array[i - 1] = ps->array[i];

	ps->size--;
}

// ��˳����в���ֵΪdata��Ԫ�أ����ظ�Ԫ�ص��±�
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

// ���˳������Ƿ�Ϊ��
int SeqListEmpty(SeqList* ps)
{
	assert(ps);
	return ps->size==0;
}

// ��ȡ˳�������ЧԪ�صĸ���
int SeqListSize(SeqList* ps)
{
	return ps->size;
}

// ��ȡ˳����пռ������
int SeqListCapacity(SeqList* ps)
{
	return ps->capacity;
}

// ��˳����е�Ԫ�����
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
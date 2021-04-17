#pragma once

// ��̬˳���

typedef int DataType;

typedef struct SeqList
{
	DataType* array;
	int capacity; // �ռ���ܴ�С
	int size; // ��ЧԪ�ظ���
}SeqList;

// ˳���ĳ�ʼ��
void SeqListInit(SeqList* ps, int capacity);

// ˳��������
void SeqListDestroy(SeqList* ps);

// β��
void SeqListPushBack(SeqList* ps, DataType data);

// βɾ
void SeqListPopBack(SeqList* ps);

// ͷ��
void SeqListPushFront(SeqList* ps, DataType data);

// ͷɾ
void SeqListPopFront(SeqList* ps);

// ����λ�õĲ���
void SeqListInsert(SeqList* ps, int pos, DataType data);

// ����λ�õ�ɾ��
void SeqListErase(SeqList* ps, int pos);

// ��˳����в���ֵΪdata��Ԫ�أ����ظ�Ԫ�ص��±�
int SeqListFind(SeqList* ps, DataType data);

// ���˳������Ƿ�Ϊ��
int SeqListEmpty(SeqList* ps);

// ��ȡ˳�������ЧԪ�صĸ���
int SeqListSize(SeqList* ps);

// ��ȡ˳����пռ������
int SeqListCapacity(SeqList* ps);

// ��˳����е�Ԫ�����
void SeqListClear(SeqList* ps);



#pragma once

// 动态顺序表

typedef int DataType;

typedef struct SeqList
{
	DataType* array;
	int capacity; // 空间的总大小
	int size; // 有效元素个数
}SeqList;

// 顺序表的初始化
void SeqListInit(SeqList* ps, int capacity);

// 顺序表的销毁
void SeqListDestroy(SeqList* ps);

// 尾插
void SeqListPushBack(SeqList* ps, DataType data);

// 尾删
void SeqListPopBack(SeqList* ps);

// 头插
void SeqListPushFront(SeqList* ps, DataType data);

// 头删
void SeqListPopFront(SeqList* ps);

// 任意位置的插入
void SeqListInsert(SeqList* ps, int pos, DataType data);

// 任意位置的删除
void SeqListErase(SeqList* ps, int pos);

// 在顺序表中查找值为data的元素，返回该元素的下标
int SeqListFind(SeqList* ps, DataType data);

// 检测顺序表中是否为空
int SeqListEmpty(SeqList* ps);

// 获取顺序表中有效元素的个数
int SeqListSize(SeqList* ps);

// 获取顺序表中空间的容量
int SeqListCapacity(SeqList* ps);

// 将顺序表中的元素清空
void SeqListClear(SeqList* ps);



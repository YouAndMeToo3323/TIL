#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	if (plist->head == NULL)
		return;
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
		return;
	newNode->data = data;
	
	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
		return;
	Node* pred = plist->head;	//pred는 더미 노드를 가리킴
	newNode->data = data;	//새 노드에 데이터 저장

	//새 노드가 들어갈 위치를 찾기 위한 반복문
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
		pred = pred->next;	//다음 노드로 이동

	newNode->next = newNode;
	(plist->numOfData)++;
}

void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}
int LFirst(List* plist, LData* pdata)
{
	if (plist->head->next == NULL)
		return FALSE;
	
	plist->before = plist->head;
	plist->cur = plist->head->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}
LData LRemove(List* plist)
{
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}
int LCount(List* plist)
{
	return plist->numOfData;
}
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

//main함수에 정의해야 하는 소스파일
int WhoIsPrecede(int d1, int d2)
{
	if(d1<d2)
		return 0;
	else
		return 1;
}






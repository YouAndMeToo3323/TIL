#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"


void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));	//새 노드 생성
	if (newNode == NULL)						
		return;
	newNode->data = data;			//새 노드에 데이터 저장

	if (plist->tail == NULL)		//첫 번째 노드라면,
	{
		plist->tail = newNode;		//tail이 새 노드를 가리키게 한다.
		newNode->next = newNode;	//새 노드 자신을 가리키게 한다.
	}
	else							//두 번째 이후의 노드라면
	{
		newNode->next = plist->tail->next;	//새 노드와 뒤에 연결된 노드 연결
		plist->tail->next = newNode;		//앞에 연결된 노드와 새 노드 연결
		plist->tail = newNode;				//LInsertFront 함수와 유일한 차이점
	}
	(plist->numOfData)++;
}

void LInsertFront(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));	//새 노드 생성
	if (newNode == NULL)
		return;
	newNode->data = data;			//새 노드에 데이터 저장

	if (plist->tail == NULL)		//첫 번째 노드라면,
	{
		plist->tail = newNode;		//tail이 새 노드를 가리키게 한다.
		newNode->next = newNode;	//새 노드 자신을 가리키게 한다.
	}
	else							//두 번째 이후의 노드라면
	{
		newNode->next = plist->tail->next;	//새 노드와 뒤에 연결된 노드 연결
		plist->tail->next = newNode;		//앞에 연결된 노드와 새 노드 연결
	}
	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->tail == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist)
{
	Node* rpos = plist->cur;
	Data rdata = rpos->data;

	//삭제할 대상을 tail이 가리키는 경우
	if (rpos == plist->tail)
	{
		//그리고 삭제할 대상이 마지막 남은 노드라면
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;		//핵심 연산 1
	plist->cur = plist->before;					//핵심 연산 2

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}

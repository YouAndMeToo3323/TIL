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

void FLInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
		return;
	newNode->data = data;
	
	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SLInsert(List* plist, LData data)
{

}

void LInsert(List* plist, LData data)
{

}













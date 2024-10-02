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
	Node* newNode = (Node*)malloc(sizeof(Node));	//�� ��� ����
	if (newNode == NULL)						
		return;
	newNode->data = data;			//�� ��忡 ������ ����

	if (plist->tail == NULL)		//ù ��° �����,
	{
		plist->tail = newNode;		//tail�� �� ��带 ����Ű�� �Ѵ�.
		newNode->next = newNode;	//�� ��� �ڽ��� ����Ű�� �Ѵ�.
	}
	else							//�� ��° ������ �����
	{
		newNode->next = plist->tail->next;	//�� ���� �ڿ� ����� ��� ����
		plist->tail->next = newNode;		//�տ� ����� ���� �� ��� ����
		plist->tail = newNode;				//LInsertFront �Լ��� ������ ������
	}
	(plist->numOfData)++;
}

void LInsertFront(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));	//�� ��� ����
	if (newNode == NULL)
		return;
	newNode->data = data;			//�� ��忡 ������ ����

	if (plist->tail == NULL)		//ù ��° �����,
	{
		plist->tail = newNode;		//tail�� �� ��带 ����Ű�� �Ѵ�.
		newNode->next = newNode;	//�� ��� �ڽ��� ����Ű�� �Ѵ�.
	}
	else							//�� ��° ������ �����
	{
		newNode->next = plist->tail->next;	//�� ���� �ڿ� ����� ��� ����
		plist->tail->next = newNode;		//�տ� ����� ���� �� ��� ����
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

	//������ ����� tail�� ����Ű�� ���
	if (rpos == plist->tail)
	{
		//�׸��� ������ ����� ������ ���� �����
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;		//�ٽ� ���� 1
	plist->cur = plist->before;					//�ٽ� ���� 2

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}

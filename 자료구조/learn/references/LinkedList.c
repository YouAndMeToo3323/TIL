#include <stdio.h>
#include "LinkedList.h"

void ListInit(List* plist)
{
	(plist->numOfData) = 0;		//����Ʈ�� ����� �������� ���� 0���� ����
	(plist->curPosition) = -1;	//�迭�� 0���� �����ϹǷ� ��ġ���� -1���� ����
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		printf("������ �Ұ����մϴ�.\n");
		return;
	}//����Һ��� �����ͷ��� Ŭ��� �Լ� ����

	plist->arr[plist->numOfData] = data;	//�迭�� ������ ����
	(plist->numOfData)++;					//plist�� ����� �������� �� ����
}


int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)					//plist�� �����Ͱ� ���� ���(0)
		return FALSE;

	(plist->curPosition) = 0;					//plist�� ������ġ�� 0
	*pdata = plist->arr[plist->curPosition];	//plist�� ������ġ�� �ش��ϴ� ������ ���
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= plist->numOfData - 1)	//plist�� ���� ������ġ���� ���� ����� �������� ���� ������(������ġ�� 0���� �����ϹǷ� �������Ǽ� -1)
		return FALSE;

	(plist->curPosition)++;							//plist�� ������ġ ����
	*pdata = plist->arr[plist->curPosition];		//plist�� ������ġ�� �ش��ϴ� ������ ���
	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;				//plist�� ���� ������ġ
	int num = plist->numOfData;					//plist�� ���� �������� ��
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];		//plist�� ���� �����͸� �� ĭ�� �̵�
	}
	(plist->curPosition)--;						//plist�� ���� ������ġ ����
	(plist->numOfData)--;						//plist�� ���� �������� �� ����

	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;	//���� ����� �������Ǽ� ��ȯ
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2))
{

}

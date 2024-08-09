#include <stdio.h>
#include "LinkedList.h"

void ListInit(List* plist)
{
	(plist->numOfData) = 0;		//리스트에 저장된 데이터의 수를 0으로 선언
	(plist->curPosition) = -1;	//배열은 0부터 시작하므로 위치값은 -1부터 시작
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		printf("저장이 불가능합니다.\n");
		return;
	}//저장소보다 데이터량이 클경우 함수 종료

	plist->arr[plist->numOfData] = data;	//배열에 데이터 저장
	(plist->numOfData)++;					//plist에 저장된 데이터의 수 증가
}


int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)					//plist에 데이터가 없을 경우(0)
		return FALSE;

	(plist->curPosition) = 0;					//plist의 참조위치는 0
	*pdata = plist->arr[plist->curPosition];	//plist의 참조위치에 해당하는 데이터 출력
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= plist->numOfData - 1)	//plist의 현재 참조위치보다 현재 저장된 데이터의 수가 적으면(참조위치가 0부터 시작하므로 데이터의수 -1)
		return FALSE;

	(plist->curPosition)++;							//plist의 참조위치 증가
	*pdata = plist->arr[plist->curPosition];		//plist의 참조위치에 해당하는 데이터 출력
	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;				//plist의 현재 참조위치
	int num = plist->numOfData;					//plist의 현재 데이터의 수
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];		//plist의 현재 데이터를 한 칸씩 이동
	}
	(plist->curPosition)--;						//plist의 현재 참조위치 삭제
	(plist->numOfData)--;						//plist의 현재 데이터의 수 삭제

	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;	//현재 저장된 데이터의수 반환
}

int WhoIsPrecede(LData d1, LData d2)
{
	if (d1 < d2)
		return 0;	//d1이 정렬 순서상 빠르다
	else
		return 1;	//d2가 정렬 순서상 빠르거나 같다
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2))
{

}

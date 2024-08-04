#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


#define TRUE 1		//'참'을 표현하기 위한 매크로 정의
#define FALSE 0		//'거짓'을 표현하기 위한 매크로 정의

#define LIST_LEN 100
typedef int LData;	//LData에 대한 typedef 선언

typedef struct __LinkedList	//링크드 리스트를 정의한 구조체
{
	LData arr[LIST_LEN];	//리스트의 저장소인 배열
	int numOfData;			//저장된 데이터의 수
	int curPosition;		//데이터 참조위치를 기록
} LinkedList;

typedef LinkedList List;

//초기화할 리스트의 주소 값을 인자로 전달, 제일 먼저 호출되어야 하는 함수
void ListInit(List* plist);
//리스트에 데이터 저장, 매개변수 data에 전달된 값을 저장
void LInsert(List* plist, LData data);

//첫 번째 데이터가 pdata가 가리키는 메로리에 저장, 데이터의 참조를 위한 초기화 진행
int LFirst(List* plist, LData* pdata);
//참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장, 순차적인 참조를 위해서 반복 호출
//참조를 새로 시작하려면 먼저 LFirst 함수 호줄
int LNext(List* plist, LData* pdata);

//참조된 함수의 마지막 반환 데이터를 삭제, 삭제된 데이터 반환
//마지막 반환 데이터를 삭제하므로 반복 호출 해제
LData LRemove(List* plist);
//리스트에 저장된 데이터의 수 반환
int LCount(List* plist);

//리스트에 정렬의 기준되는 함수 등록
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));

#endif
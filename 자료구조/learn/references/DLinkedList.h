#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__


#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
} Node;


typedef struct _linkedList
{
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;			//저장된 데이터의 수
	int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

//초기화할 리스트의 주소 값을 인자로 전달, 제일 먼저 호출되어야 하는 함수
void ListInit(List* plist);
//리스트에 데이터 저장, 매개변수 data에 전달된 값을 저장
void LInsert(List* plist, LData data);

//첫 번째 데이터가 pdata가 가리키는 메모리에 저장, 데이터의 참조를 위한 초기화 진행
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

//main함수에 정의되어 있는 소스파일
int WhoIsPrecede(int d1, int d2);

#endif

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
	int numOfData;			//����� �������� ��
	int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

//�ʱ�ȭ�� ����Ʈ�� �ּ� ���� ���ڷ� ����, ���� ���� ȣ��Ǿ�� �ϴ� �Լ�
void ListInit(List* plist);
//����Ʈ�� ������ ����, �Ű����� data�� ���޵� ���� ����
void LInsert(List* plist, LData data);

//ù ��° �����Ͱ� pdata�� ����Ű�� �޸𸮿� ����, �������� ������ ���� �ʱ�ȭ ����
int LFirst(List* plist, LData* pdata);
//������ �������� ���� �����Ͱ� pdata�� ����Ű�� �޸𸮿� ����, �������� ������ ���ؼ� �ݺ� ȣ��
//������ ���� �����Ϸ��� ���� LFirst �Լ� ȣ��
int LNext(List* plist, LData* pdata);

//������ �Լ��� ������ ��ȯ �����͸� ����, ������ ������ ��ȯ
//������ ��ȯ �����͸� �����ϹǷ� �ݺ� ȣ�� ����
LData LRemove(List* plist);
//����Ʈ�� ����� �������� �� ��ȯ
int LCount(List* plist);

//����Ʈ�� ������ ���صǴ� �Լ� ���
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));

#endif
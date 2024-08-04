#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


#define TRUE 1		//'��'�� ǥ���ϱ� ���� ��ũ�� ����
#define FALSE 0		//'����'�� ǥ���ϱ� ���� ��ũ�� ����

#define LIST_LEN 100
typedef int LData;	//LData�� ���� typedef ����

typedef struct __LinkedList	//��ũ�� ����Ʈ�� ������ ����ü
{
	LData arr[LIST_LEN];	//����Ʈ�� ������� �迭
	int numOfData;			//����� �������� ��
	int curPosition;		//������ ������ġ�� ���
} LinkedList;

typedef LinkedList List;

//�ʱ�ȭ�� ����Ʈ�� �ּ� ���� ���ڷ� ����, ���� ���� ȣ��Ǿ�� �ϴ� �Լ�
void ListInit(List* plist);
//����Ʈ�� ������ ����, �Ű����� data�� ���޵� ���� ����
void LInsert(List* plist, LData data);

//ù ��° �����Ͱ� pdata�� ����Ű�� �޷θ��� ����, �������� ������ ���� �ʱ�ȭ ����
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
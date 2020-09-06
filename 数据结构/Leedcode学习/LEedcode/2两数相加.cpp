#include <cstddef>
#include<malloc.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
//�Լ���
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	pHead->val = 0;
	pHead->next = NULL;

	struct ListNode* pTail = pHead;
	int carry = 0;
	int sum = 0;

	while (l1 != NULL || l2 != NULL)
	{
		int x = (l1 == NULL) ? 0 : l1->val;  //����������˭��β���˾�ȡ0��������
		int y = (l2 == NULL) ? 0 : l2->val;
		//ע���ʱsum�е�carry����һλ���ֵ��������!
		sum = x + y + carry;
		carry = sum / 10;

		struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));  //����ڵ��Ž���Ľڵ�
		p->val = sum % 10;
		p->next = NULL;
		//�ѱ�λ��ӵĸ��ӵ�������
		if (pTail->next == NULL)
		{
			pTail->next = p;
			pTail = pTail->next;
		}
		else	//���pTail����������β��˵����λ��
		{
			pTail->next->val = p->val;
			pTail = pTail->next;
		}

		if (l1 != NULL)
		{
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			l2 = l2->next;
		}
		//������,�������λ�ϵ��������Ҫ��λ
		if (carry == 1)
		{
			struct ListNode* ca = (struct ListNode*)malloc(sizeof(struct ListNode));
			ca->val = carry;
			ca->next = NULL;
			pTail->next = ca;	//��һ��pTailû��������λ
		}
	}
	return pHead->next;
}

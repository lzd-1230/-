#include <cstddef>
#include<malloc.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
//自己的
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
		int x = (l1 == NULL) ? 0 : l1->val;  //两个链表有谁到尾巴了就取0与别的数加
		int y = (l2 == NULL) ? 0 : l2->val;
		//注意此时sum中的carry是上一位相加值所决定的!
		sum = x + y + carry;
		carry = sum / 10;

		struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));  //申请节点存放结果的节点
		p->val = sum % 10;
		p->next = NULL;
		//把本位相加的给接到链表上
		if (pTail->next == NULL)
		{
			pTail->next = p;
			pTail = pTail->next;
		}
		else	//如果pTail不是在链表尾部说明进位了
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
		//作用是,两个最大位上的数相加需要进位
		if (carry == 1)
		{
			struct ListNode* ca = (struct ListNode*)malloc(sizeof(struct ListNode));
			ca->val = carry;
			ca->next = NULL;
			pTail->next = ca;	//这一步pTail没有往后移位
		}
	}
	return pHead->next;
}

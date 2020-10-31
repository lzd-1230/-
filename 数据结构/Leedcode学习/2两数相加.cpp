#include <cstddef>
#include<malloc.h>

//�Լ���
#if 0
struct ListNode
{
	int val;
	struct ListNode* next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{	//����ͷ���
	struct ListNode* pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	pHead->val = 0;
	pHead->next = NULL;
	//β�ڵ�
	struct ListNode* pTail = pHead;
	int carry = 0;
	int sum = 0;

	while (l1 != NULL || l2 != NULL)
	{
		int x = (l1 == NULL) ? 0 : l1->val;		//����������˭��β���˾�ȡ0��������
		int y = (l2 == NULL) ? 0 : l2->val;		//û��0��ȡ�Լ����ڵ�ֵ
		//ע���ʱsum�е�carry����һλ���ֵ��������!
		sum = x + y + carry;
		carry = sum / 10;	//���>10���н�λ

		struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));  //����ڵ��Ž���Ľڵ�
		p->val = sum % 10;
		p->next = NULL;
		//�ѱ�λ��ӵĸ��ӵ�������
		if (pTail->next == NULL)
		{
			pTail->next = p;
			pTail = pTail->next;
		}
		//���������if��carry==1����ͬ���ƽ�λ
		else	//���pTail����������β��˵����λ��
		{
			pTail->next->val = p->val;	//��ca��1���1+��λԭ��Ӧ���еĽ��
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
			ca->val = carry;	//�󲿷�����ᱻx+y+carry��ֵ�����������7+5=12���������Ҫ������ĸ�ֵ
			ca->next = NULL;
			pTail->next = ca;	//��һ��pTailû��������λ
		}
	}
	return pHead->next;
}
#endif
//C++�汾�ⷨһ
/*
��ȡ������������Ӧ�ĳ���
�ڽ϶̵�����ĩβ����
������ӿ��ǽ�λ
*/
#if 0
struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}    //���ι��캯��
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 1;//��¼l1�ĳ���
        int len2 = 1;//��¼l2�ĳ���
        ListNode* p = l1;
        ListNode* q = l2;
        while (p->next != NULL)//��ȡl1�ĳ���
        {
            len1++;
            p = p->next;
        }
        while (q->next != NULL)//��ȡl2�ĳ���
        {
            len2++;
            q = q->next;
        }

        if (len1 > len2)//l1�ϳ�����l2ĩβ����
        {
            for (int i = 0; i < len1 - len2; i++)
            {
                q->next = new ListNode(0);
                q = q->next;
            }
        }

        else//l2�ϳ�����l1ĩβ����
        {
            for (int i = 0; i < len2 - len1; i++)
            {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        //��pq�ٴη��س�ͷ���
        p = l1;
        q = l2;

        bool count = false;//��¼��λ
        ListNode* l3 = new ListNode(-1);//��Ž��������
        ListNode* pTail = l3;//l3���ƶ�ָ��
        int sum = 0;//��¼��ӽ��

        while (p != NULL && q != NULL)  //��Ϊ����0,��������һ��,��ʵֻ��һ������
        {
            sum = count + p->val + q->val;
            pTail->next = new ListNode(sum % 10);
            count = sum >= 10 ? true : false;   //�������»غ�
            pTail = pTail->next;
            p = p->next;
            q = q->next;
        }

        if (count)//������н�λ
        {
            pTail->next = new ListNode(1);
            pTail = pTail->next;
        }
        return l3->next;
    }
};
#endif

//C++ �汾��
#if 0
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode(-1);  //��Ž��������
        ListNode* pTail = head;             //�ƶ�ָ��
        int sum = 0;                        //ÿ��λ�ļӺͽ��
        bool carry = false;                 //��λ��־
        while (l1 != NULL || l2 != NULL)    //��һ��û��β
        {
            sum = 0;                        //����sum
            //û�ղŲ�����sum
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            if (carry)              //��һλ��carry��û�н�λ
                sum++;

            pTail->next = new ListNode(sum % 10);   //�������ù��캯��
            pTail = pTail->next;
            //����carry
            carry = sum >= 10 ? true : false;
        }
        //����ѭ��������,�����λ��Ҫ��λ,�ٴ����½�㸳ֵ1
        if (carry)
        {
            pTail->next = new ListNode(1);
        }
        return head->next;
    }
};
#endif





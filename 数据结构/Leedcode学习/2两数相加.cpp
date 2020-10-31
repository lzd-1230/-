#include <cstddef>
#include<malloc.h>

//自己的
#if 0
struct ListNode
{
	int val;
	struct ListNode* next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{	//创建头结点
	struct ListNode* pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	pHead->val = 0;
	pHead->next = NULL;
	//尾节点
	struct ListNode* pTail = pHead;
	int carry = 0;
	int sum = 0;

	while (l1 != NULL || l2 != NULL)
	{
		int x = (l1 == NULL) ? 0 : l1->val;		//两个链表有谁到尾巴了就取0与别的数加
		int y = (l2 == NULL) ? 0 : l2->val;		//没到0就取自己现在的值
		//注意此时sum中的carry是上一位相加值所决定的!
		sum = x + y + carry;
		carry = sum / 10;	//如果>10就有进位

		struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));  //申请节点存放结果的节点
		p->val = sum % 10;
		p->next = NULL;
		//把本位相加的给接到链表上
		if (pTail->next == NULL)
		{
			pTail->next = p;
			pTail = pTail->next;
		}
		//！和下面的if（carry==1）共同控制进位
		else	//如果pTail不是在链表尾部说明进位了
		{
			pTail->next->val = p->val;	//把ca的1变成1+本位原本应该有的结果
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
			ca->val = carry;	//大部分情况会被x+y+carry赋值掉，但如果是7+5=12的情况还是要靠这里的赋值
			ca->next = NULL;
			pTail->next = ca;	//这一步pTail没有往后移位
		}
	}
	return pHead->next;
}
#endif
//C++版本解法一
/*
获取两个链表所对应的长度
在较短的链表末尾补零
对齐相加考虑进位
*/
#if 0
struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}    //带参构造函数
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 1;//记录l1的长度
        int len2 = 1;//记录l2的长度
        ListNode* p = l1;
        ListNode* q = l2;
        while (p->next != NULL)//获取l1的长度
        {
            len1++;
            p = p->next;
        }
        while (q->next != NULL)//获取l2的长度
        {
            len2++;
            q = q->next;
        }

        if (len1 > len2)//l1较长，在l2末尾补零
        {
            for (int i = 0; i < len1 - len2; i++)
            {
                q->next = new ListNode(0);
                q = q->next;
            }
        }

        else//l2较长，在l1末尾补零
        {
            for (int i = 0; i < len2 - len1; i++)
            {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        //将pq再次返回成头结点
        p = l1;
        q = l2;

        bool count = false;//记录进位
        ListNode* l3 = new ListNode(-1);//存放结果的链表
        ListNode* pTail = l3;//l3的移动指针
        int sum = 0;//记录相加结果

        while (p != NULL && q != NULL)  //因为补过0,两个长度一样,其实只用一个就行
        {
            sum = count + p->val + q->val;
            pTail->next = new ListNode(sum % 10);
            count = sum >= 10 ? true : false;   //作用于下回合
            pTail = pTail->next;
            p = p->next;
            q = q->next;
        }

        if (count)//若最后还有进位
        {
            pTail->next = new ListNode(1);
            pTail = pTail->next;
        }
        return l3->next;
    }
};
#endif

//C++ 版本二
#if 0
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode(-1);  //存放结果的链表
        ListNode* pTail = head;             //移动指针
        int sum = 0;                        //每个位的加和结果
        bool carry = false;                 //进位标志
        while (l1 != NULL || l2 != NULL)    //有一个没到尾
        {
            sum = 0;                        //重置sum
            //没空才参与求sum
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

            if (carry)              //上一位的carry有没有进位
                sum++;

            pTail->next = new ListNode(sum % 10);   //巧妙利用构造函数
            pTail = pTail->next;
            //更新carry
            carry = sum >= 10 ? true : false;
        }
        //假设循环结束后,即最大位还要进位,再创建新结点赋值1
        if (carry)
        {
            pTail->next = new ListNode(1);
        }
        return head->next;
    }
};
#endif





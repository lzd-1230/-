#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cstring>


  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    ListNode *l3,*t,*pl1,*pl2;
    pl1=l1;
    pl2=l2;
    l3=(ListNode*)malloc(sizeof(ListNode));
    l3->next=0;
    t=l3;
    int jinwei=0;
    while(pl1 && pl2)           //都不为空
    {
        
        if(pl1->val+pl2->val+jinwei<=9)        //不用进位
        {
            t->val=pl1->val+pl2->val+jinwei;
            ListNode*pNew=(ListNode*)malloc(sizeof(ListNode));
            t->next=pNew;
            t=t->next;
            pl1=pl1->next;
            pl2=pl2->next;
        }
        else if(pl1->val+pl2->val+jinwei>10)
        {
            t->val=pl1->val+pl2->val-10;
            jinwei=1;
            ListNode*pNew=(ListNode*)malloc(sizeof(ListNode));
            t->next=pNew;
            t=t->next;
            pl1=pl1->next;
            pl2=pl2->next;
            continue;
        }
        jinwei=0;
    }
}


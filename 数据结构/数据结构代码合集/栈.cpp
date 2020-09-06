#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int data;
	struct Node* pNext;	
}Node,*PNode;

//栈的结构体:约束从一个口进从一个口出 
//!!注意区分栈的指针域是往前指的 

typedef struct Stack
{
	PNode ptop;
	PNode pbottom;
}stack,*pstack;

void init(pstack);				//初始化为空,使top和bottom指向同一个头结点 
void push(pstack,int);			//压栈 
void travel(pstack);			//遍历 
bool pop(pstack ,int* );		//出栈 

int main()
{
	int val;				
	stack s;
	init(&s);
	push(&s,1);				//因为只能放在栈顶的位置,相当于插入的位置固定的
	push(&s,2);
	push(&s,3);
	push(&s,4);
	push(&s,5);
	if(pop(&s,&val))
	{
		printf("出栈的元素是%d\n",val);
	}
	else	printf("出栈失败\n"); 
	travel(&s);			
	return 0;
} 
//建立一个空的栈(使ptop和pbottom都指向一个头结点) 
void init(pstack p)
{
	p->ptop=(PNode)malloc(sizeof(Node));	//新建节点 
	if(nullptr==p->ptop)						 
	{
		printf("动态内存分配失败");
		exit(-1); 
	}
	
	else
	{
		p->pbottom=p->ptop;					//让ptop和pbottom的值相等 
		p->ptop->pNext=nullptr;				//让ptop成为最上面的节点 
	}	
}
//压栈(每次压一个) 
void push(pstack p,int val)
{
	PNode pNew=(PNode)malloc(sizeof(Node));			//创建新节点 
	pNew->data=val;									//data域赋值 
	pNew->pNext=p->ptop;							//指针域赋值 
	p->ptop=pNew;									//ptop的更新 
} 
//遍历 
void travel(pstack p)
{ 
	PNode t=p->ptop;
	while(t!=p->pbottom)
	{
		printf("%4d",t->data);			//输出数据域 
		t=t->pNext;						//t++ 
	}
	printf("\n");
	return;
}
//判度是否为空
bool is_Empty(pstack p)
{
	if(p->pbottom==p->ptop)				//bottom和top是否相等 
	{
		printf("栈为空\n");
		return true; 
	}
	else return false; 
} 
//出栈
bool pop(pstack p ,int* pval )
{
	if(is_Empty(p))	return false;
	else
	{
		PNode t=p->ptop;				//记录出栈元素地址,一会释放 
		*pval=p->ptop->data; 			
		p->ptop=p->ptop->pNext; 		//让ptop从最上面往下移一个 
		free(t);						//但要记得free空间 
		t=nullptr;	
		return true;
	}
} 

//栈的应用:计算器(网上代码) 

//#include<stdio.h>
//#include<stdlib.h>
//#define OK    1
//#define ERROR 0
//
//typedef struct node 
//{
//    int data;						//数据域 
//    struct node *next;				//指针域 
//}Node;
// 
//
//typedef struct stack
//{
//    Node *top;						//栈顶 
//    int count;						//栈的有效元素 
//}Stack;
//
////初始化空栈 
//int InitStack(Stack *S)
//{
//    S->top = nullptr;
//    S->count = 0;
//    return OK;
//}
//
//int is_Empty(Stack *S)
//{
//    return (S->count == 0) ? OK : ERROR;
//}
//
////压栈 
//int Push(Stack *S, int e)
//{
//    Node *p = (Node *)malloc(sizeof(Node));
//    if (nullptr == p)						//是否成功建立新节点内存 
//    {
//        return ERROR;
//    }
//    //压栈三部曲 
//    p->data = e; 
//    p->next = S->top;
//    S->top = p;
//    S->count++;
//    return OK;
//}
////获得栈顶元素 
//int GetTop(Stack *S)
//{
//    if (nullptr == S->top)
//    {
//        return ERROR;
//    }
//
//    return (S->top->data);
//}
////四则运算的优先级 
//int Priority(char s)
//{
//    switch(s)
//    {
//        case '(':
//            return 3;			//最高级数 
//        case '*':
//        case '/':
//            return 2;			//次高级数 
//        case '+':
//        case '-':
//            return 1;			
//        default :
//            return 0;
//    }
//}
////出栈(数字输出) 
//int Pop(Stack *S)
//{
//    int e;
//    if (nullptr == S->top)
//    {
//        return ERROR;
//    }
//    Node *p = S->top;				//待会要释放内存 
//    e = p->data;					//记录出栈元素 
//    S->top = p->next;				//top往下退一个 
//    free(p);
//    S->count--;			
//    return e;						//返回出栈元素的值 
//}
//int main()
//{
//    char str[100] = {0};			//初始化存放输入的表达式 
//    int i = 0, tmp = 0, j;
//    Stack num, opt;					//两个栈,一个放数字一个放运算符 
////判断是否创建空栈成功 
//    if (InitStack(&num) != OK || InitStack(&opt) != OK)
//    {
//        printf("Init Failure!\n");
//        exit(1);
//    }
////开始输入 
//    printf("Please input operator :\n");
//    scanf_s("%s",&str);
//
//    while (str[i] != '\0' || is_Empty(&opt) != OK)		//遍历表达式 
//    {
//        if (str[i] >= '0' && str[i] <= '9')				//是数字就给tmp存放 
//        {
//            tmp = tmp * 10 + str[i] - '0';				//以整数的形式存放!!! 
//            i++;
//
//            if (str[i] < '0' || str[i] >'9')			//是符号就把刚刚存放的数字压栈 
//            {
//                Push(&num, tmp);						
//                tmp = 0;								//清空临时储存 
//            }
//        }
//
//        else											//是符号 
//        {
//            if (is_Empty(&opt) == OK || (GetTop(&opt) == '(' && str[i] != ')') || 
//                Priority(str[i]) > Priority(GetTop(&opt)))		//适合符号进栈的条件①符号栈为空②符号栈顶为(但str中不是右括号③str中符号优先级大于栈顶符号 
//            {
//                Push(&opt, str[i]);
//                i++;
//            	continue;
//            }
//
//            if (GetTop(&opt) == '(' && str[i] == ')')			//是两个括号匹配的情况 
//            {
//                Pop(&opt);										//出栈括号内的那个运算符 
//                i++;
//                continue;
//            }
//
//            if ((str[i] == '\0' && is_Empty(&opt) != OK) || str[i] == ')' && GetTop(&opt) != '(' ||
//                Priority(str[i]) <= Priority(GetTop(&opt)))			//符号出栈的规则 
//            {
//                switch(Pop(&opt))								//各个出栈的符号怎么运算 
//                {
//                    case '+':
//                        Push(&num, Pop(&num) + Pop(&num));
//                        break;
//                    case '-':
//                        j = Pop(&num);				//减数在上 
//                        Push(&num, Pop(&num) - j);	
//                        break;
//                    case '*':
//                        Push(&num, Pop(&num) * Pop(&num));
//                        break;
//                    case '/':
//                        j = Pop(&num);				//除数在上 
//                        Push(&num, Pop(&num) / j);
//                        break;
//                }
//            	continue;
//            }
//        }
//    }
//    printf("%d\n",Pop(&num));
//    return 0;
//}


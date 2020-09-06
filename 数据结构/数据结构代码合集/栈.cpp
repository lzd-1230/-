#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int data;
	struct Node* pNext;	
}Node,*PNode;

//ջ�Ľṹ��:Լ����һ���ڽ���һ���ڳ� 
//!!ע������ջ��ָ��������ǰָ�� 

typedef struct Stack
{
	PNode ptop;
	PNode pbottom;
}stack,*pstack;

void init(pstack);				//��ʼ��Ϊ��,ʹtop��bottomָ��ͬһ��ͷ��� 
void push(pstack,int);			//ѹջ 
void travel(pstack);			//���� 
bool pop(pstack ,int* );		//��ջ 

int main()
{
	int val;				
	stack s;
	init(&s);
	push(&s,1);				//��Ϊֻ�ܷ���ջ����λ��,�൱�ڲ����λ�ù̶���
	push(&s,2);
	push(&s,3);
	push(&s,4);
	push(&s,5);
	if(pop(&s,&val))
	{
		printf("��ջ��Ԫ����%d\n",val);
	}
	else	printf("��ջʧ��\n"); 
	travel(&s);			
	return 0;
} 
//����һ���յ�ջ(ʹptop��pbottom��ָ��һ��ͷ���) 
void init(pstack p)
{
	p->ptop=(PNode)malloc(sizeof(Node));	//�½��ڵ� 
	if(nullptr==p->ptop)						 
	{
		printf("��̬�ڴ����ʧ��");
		exit(-1); 
	}
	
	else
	{
		p->pbottom=p->ptop;					//��ptop��pbottom��ֵ��� 
		p->ptop->pNext=nullptr;				//��ptop��Ϊ������Ľڵ� 
	}	
}
//ѹջ(ÿ��ѹһ��) 
void push(pstack p,int val)
{
	PNode pNew=(PNode)malloc(sizeof(Node));			//�����½ڵ� 
	pNew->data=val;									//data��ֵ 
	pNew->pNext=p->ptop;							//ָ����ֵ 
	p->ptop=pNew;									//ptop�ĸ��� 
} 
//���� 
void travel(pstack p)
{ 
	PNode t=p->ptop;
	while(t!=p->pbottom)
	{
		printf("%4d",t->data);			//��������� 
		t=t->pNext;						//t++ 
	}
	printf("\n");
	return;
}
//�ж��Ƿ�Ϊ��
bool is_Empty(pstack p)
{
	if(p->pbottom==p->ptop)				//bottom��top�Ƿ���� 
	{
		printf("ջΪ��\n");
		return true; 
	}
	else return false; 
} 
//��ջ
bool pop(pstack p ,int* pval )
{
	if(is_Empty(p))	return false;
	else
	{
		PNode t=p->ptop;				//��¼��ջԪ�ص�ַ,һ���ͷ� 
		*pval=p->ptop->data; 			
		p->ptop=p->ptop->pNext; 		//��ptop��������������һ�� 
		free(t);						//��Ҫ�ǵ�free�ռ� 
		t=nullptr;	
		return true;
	}
} 

//ջ��Ӧ��:������(���ϴ���) 

//#include<stdio.h>
//#include<stdlib.h>
//#define OK    1
//#define ERROR 0
//
//typedef struct node 
//{
//    int data;						//������ 
//    struct node *next;				//ָ���� 
//}Node;
// 
//
//typedef struct stack
//{
//    Node *top;						//ջ�� 
//    int count;						//ջ����ЧԪ�� 
//}Stack;
//
////��ʼ����ջ 
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
////ѹջ 
//int Push(Stack *S, int e)
//{
//    Node *p = (Node *)malloc(sizeof(Node));
//    if (nullptr == p)						//�Ƿ�ɹ������½ڵ��ڴ� 
//    {
//        return ERROR;
//    }
//    //ѹջ������ 
//    p->data = e; 
//    p->next = S->top;
//    S->top = p;
//    S->count++;
//    return OK;
//}
////���ջ��Ԫ�� 
//int GetTop(Stack *S)
//{
//    if (nullptr == S->top)
//    {
//        return ERROR;
//    }
//
//    return (S->top->data);
//}
////������������ȼ� 
//int Priority(char s)
//{
//    switch(s)
//    {
//        case '(':
//            return 3;			//��߼��� 
//        case '*':
//        case '/':
//            return 2;			//�θ߼��� 
//        case '+':
//        case '-':
//            return 1;			
//        default :
//            return 0;
//    }
//}
////��ջ(�������) 
//int Pop(Stack *S)
//{
//    int e;
//    if (nullptr == S->top)
//    {
//        return ERROR;
//    }
//    Node *p = S->top;				//����Ҫ�ͷ��ڴ� 
//    e = p->data;					//��¼��ջԪ�� 
//    S->top = p->next;				//top������һ�� 
//    free(p);
//    S->count--;			
//    return e;						//���س�ջԪ�ص�ֵ 
//}
//int main()
//{
//    char str[100] = {0};			//��ʼ���������ı��ʽ 
//    int i = 0, tmp = 0, j;
//    Stack num, opt;					//����ջ,һ��������һ��������� 
////�ж��Ƿ񴴽���ջ�ɹ� 
//    if (InitStack(&num) != OK || InitStack(&opt) != OK)
//    {
//        printf("Init Failure!\n");
//        exit(1);
//    }
////��ʼ���� 
//    printf("Please input operator :\n");
//    scanf_s("%s",&str);
//
//    while (str[i] != '\0' || is_Empty(&opt) != OK)		//�������ʽ 
//    {
//        if (str[i] >= '0' && str[i] <= '9')				//�����־͸�tmp��� 
//        {
//            tmp = tmp * 10 + str[i] - '0';				//����������ʽ���!!! 
//            i++;
//
//            if (str[i] < '0' || str[i] >'9')			//�Ƿ��žͰѸոմ�ŵ�����ѹջ 
//            {
//                Push(&num, tmp);						
//                tmp = 0;								//�����ʱ���� 
//            }
//        }
//
//        else											//�Ƿ��� 
//        {
//            if (is_Empty(&opt) == OK || (GetTop(&opt) == '(' && str[i] != ')') || 
//                Priority(str[i]) > Priority(GetTop(&opt)))		//�ʺϷ��Ž�ջ�������ٷ���ջΪ�բڷ���ջ��Ϊ(��str�в��������Ţ�str�з������ȼ�����ջ������ 
//            {
//                Push(&opt, str[i]);
//                i++;
//            	continue;
//            }
//
//            if (GetTop(&opt) == '(' && str[i] == ')')			//����������ƥ������ 
//            {
//                Pop(&opt);										//��ջ�����ڵ��Ǹ������ 
//                i++;
//                continue;
//            }
//
//            if ((str[i] == '\0' && is_Empty(&opt) != OK) || str[i] == ')' && GetTop(&opt) != '(' ||
//                Priority(str[i]) <= Priority(GetTop(&opt)))			//���ų�ջ�Ĺ��� 
//            {
//                switch(Pop(&opt))								//������ջ�ķ�����ô���� 
//                {
//                    case '+':
//                        Push(&num, Pop(&num) + Pop(&num));
//                        break;
//                    case '-':
//                        j = Pop(&num);				//�������� 
//                        Push(&num, Pop(&num) - j);	
//                        break;
//                    case '*':
//                        Push(&num, Pop(&num) * Pop(&num));
//                        break;
//                    case '/':
//                        j = Pop(&num);				//�������� 
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


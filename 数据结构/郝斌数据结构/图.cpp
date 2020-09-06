//图
 
#include<stdio.h>
#include<string.h>
typedef struct
{
	char vertex[100];			//顶点表
	int arcs[100][100];			//邻接矩阵
	int num_v,num_a;			//目前已经使用的顶点数和边的数目
}AMG;

//根据输入的字符定位G中顶点下标
int locate(AMG G,char v)
{
	int i;
	for(i=0;i<G.num_v;i++)
	{
		if(v==G.vertex[i])
			return i;
	}
	printf("未找到该顶点\n");
	return -1;
}

//构建无向网
void creat_G(AMG &G)
{
	printf("请输入顶点的个数:");
	scanf("%d",&G.num_v);
	printf("请输入边的个数:");
	scanf("%d",&G.num_a);
	printf("请输入顶点信息\n");	int i,j;
	fflush(stdin);
	for(i=0;i<G.num_v;i++)
	{
		G.vertex[i]=getchar();					//error:getchar的时候要小心缓冲区内剩下的回车 
	}
	//初始化网的邻接矩阵	
	for(i=0;i<G.num_v;i++)
	{
		for(j=0;j<G.num_v;j++)
		{
			if(i==j)
				G.arcs[i][j]=0;
			else
				G.arcs[i][j]=666;
		}
	}
	//输入边的信息(头尾节点,权)
	int w;
	char v1,v2;
	int i_v1,i_v2;
	for(i=0;i<G.num_a;i++)
	{
	//输入边的三个信息
		fflush(stdin);
		printf("请输入第%d条边顶点v1和v2和权:\n",i+1);
		scanf("%c %c %d",&v1,&v2,&w); 			//!!只要最后输入的是整型的时候都要小心缓冲区剩下的那个回车 
		fflush(stdin);
	//找到顶点在顶点表的下标
		i_v1=locate(G,v1);
		i_v2=locate(G,v2);
	
	//给邻接矩阵赋值
		G.arcs[i_v1][i_v2]=w;
		G.arcs[i_v2][i_v1]=G.arcs[i_v1][i_v2];			//等效于matlab中的X=X+X'
	}
}
int main()
{
	AMG G;
	int i,j;
	creat_G(G);
	for(i=0;i<G.num_v;i++)
	{
		printf("%3c",G.vertex[i]);
	}
	printf("\n");
	for(i=0;i<G.num_v;i++)
	{
		for(j=0;j<G.num_v;j++)							//error:是j++看清楚 
		{
			printf("%5d",G.arcs[i][j]); 
			if(j==G.num_a)
				printf("\n");
		}
	} 
	return 0;
}

/* 
//邻接表(无向) 
#include<stdio.h>
#include<string.h>
#include<malloc.h> 
typedef struct SideNode
{
	int index;
	struct SideNode* pNext;					//指向自身(注意是头插法,指针指前面一个)
	int weight;
}SideNode;
typedef struct
{
	char data;
	SideNode* pSide;
}VNode,AVNode[100];			//AVNode就是邻接表的类型
typedef struct
{
	AVNode vNode;			//图的邻接表
	int v_num,a_num;		//当前有效结点和边
}Graph;
/*
Graph G;
给顶点赋值:G.vNode.data='a'
定义一个指针指向第i个顶点的邻结点链表:SideNode* p=G.vNode[i].pSide
给该链表赋值:p->index=n;
算法思想
	①输入总顶点数和总边数
	②建立顶点表
	  for(i=1;i<=v_num;i++)
	 {
		依次输入顶点的信息
		使pSide初始化为NULL
	 }
	③创建每个顶点自己的单链表
		1.输入边的两个顶点和权值
		2.locate两个顶点下标i,j,在顶点表的相应位置建立两个结点
		3.用头插法插到顶点表的对应位置vNode[i]和vNode[j]后面
/*
int locate(Graph& G,char v)
{
	int i;
	for(i=0;i<G.v_num;i++)
	{
		if(v==G.vNode[i].data)
			return i;
		else
			printf("未找到该结点\n");
			return -1; 
	}
}

void CreatG(Graph& G)
{
	int i;
	printf("请输入顶点个数: 边的个数:");
	scanf("%d%d",&G.v_num,&G.a_num);
	//初始化顶点表
	for(i=0;i<G.v_num;i++)
	{
		printf("请输入第%d个结点的字母",i+1);
		fflush(stdin);
		scanf("%c",&G.vNode[i].data);
		G.vNode[i].pSide=NULL;			//初始化所有的顶点还没有边
	}
	//输入边的信息
	for(i=0;i<G.a_num;i++)
	{
		char v1,v2;
		int w,i_v1,i_v2;
		printf("请输入第%d条边顶点v1和v2和权");
		fflush(stdin);
		scanf("%c %c %d",&v1,&v2,&w);
		i_v1=locate(G,v1);
		i_v2=locate(G,v2);
		//边链表的创建和插入
		SideNode* pSideNode1=(SideNode*)malloc(sizeof(SideNode));
		SideNode* pSideNode2=(SideNode*)malloc(sizeof(SideNode));
		
		pSideNode1->pNext=G.vNode[i_v1].pSide;
		G.vNode[i_v1].pSide=pSideNode1;		//这两步更新保证了pSide始终是从邻链表的头部插入 
		
		pSideNode1->index=i_v1;
		pSideNode1->weight=w;
//		pSideNode1->pNext=NULL;				//error不能直接这样写,不然后面多插一个边界点的时候就插在顶点表上了
		//有向网的话pSideNode2就省略了
		pSideNode2->pNext=G.vNode[i_v2].pSide;
		G.vNode[i_v2].pSide=pSideNode2;		//这两步更新保证了pSide始终是邻链表的末尾
		
		pSideNode2->index=i_v2;
		pSideNode2->weight=w;
	}
}
*/

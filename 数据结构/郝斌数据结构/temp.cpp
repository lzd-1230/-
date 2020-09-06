//图
 
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
int len=12;
int lowcost[100];
int adjvert[100];
int maxw=100;
typedef struct sideNode
{
	int begin;
	int end;
	int w;
}Edge,*pEdge;
typedef struct queque
{
	int * pbase;
	int front;					//front 和 rear都相当于数组下标 
	int rear;					//rear指向的是下一个元素进来的位置,该位置没有元素!! 
}que;

typedef struct
{
	char vertex[100];			//顶点表
	int arcs[100][100];			//邻接矩阵
	int num_v,num_a;			//目前已经使用的顶点数和边的数目
}AMG;

//初始化队列
void init(que* pq)
{
	pq->pbase=(int *)malloc(len*sizeof(int));
	pq->front=0;
	pq->rear=0;
}	
//判满 
bool full_que(que* pq)
{
	if((pq->rear+1)%len==pq->front)		return true ;
	else return false;
}

//入队 
bool input(que* pq,int val)
{
	if(full_que(pq))	return false;
	else
	{
		pq->pbase[pq->rear]=val;
		pq->rear=(pq->rear+1)%len;			//相当于rear++ 
		return true;
	} 
} 

//判空
bool is_empty(que* pq)
{
	if(pq->front==pq->rear)		
	return true;
	else 	
	return false;
}

//出队 
bool out_que(que* pq,int* val)
{
	if(is_empty(pq))
	{
		printf("队列为空,出队失败\n");
		exit(-1); 
	}
	else
	{
		*val=pq->pbase[pq->front];			
		pq->front=(pq->front+1)%len;		//只需把front往前挪即可 
	}
	return true;
}
int visited[100]={0};				//DBS中的标记数组

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
				G.arcs[i][j]=999;
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
//DFS(邻接矩阵版)
void DFS(AMG &G,int v)				//v是第一个访问的结点
{
	visited[v]=1;
	printf("已经访问了%c结点\n",G.vertex[v]);
	for(int w=0;w<G.num_v;w++)
	{
		if((G.arcs[v][w]!=0) && (visited[w]==0))
		{
			DFS(G,w);
		}
	}
}
void DBStravel (AMG G)
{
	int i;
	for(i=0;i<G.num_v;i++)
	{
		visited[i]=0;				//所有节点初始化为未访问
	}
	for(i=0;i<G.num_v;i++)
	{
		if(visited[i]==0)
		{
			DFS(G,i);
		}
	}
}
//广度优先
void BFSTtravel(AMG &G)
{
	int i,j,val;
	que Q;
	for(i=0;i<G.num_v;i++)
		visited[i]=0;
	init(&Q);
	for(i=0;i<G.num_v;i++)			//对行遍历
	{
		if(visited[i]==0)
		{
			visited[i]=1;
			printf("已经访问了%c结点\n",G.vertex[i]);
			input(&Q,i);
			while(!is_empty(&Q))
			{
				out_que(&Q,&i);				//将出队的值赋给i 
				for(j=0;j<G.num_v;j++)
				{
					if(G.arcs[i][j]>0 && visited[j]==0)	//对列遍历(邻接点)
					{
						visited[j]=1;
						printf("已经访问了%c结点\n",G.vertex[j]);
//(有向图应该要加,无向图省略)						printf("已经访问了%c结点\n",G.vertex[i]);
						input(&Q,j);
					}
				}
			}
		}
	}
	
}
//prim算法 
void MiniCret_prim(AMG G)
{
	int min,i,j,k;
	lowcost[0]=0;
	adjvert[0]=0;
	//初始化
	for(i=1;i<G.num_v;i++)
	{
		lowcost[i]=G.arcs[0][i];	//两集合的所有路径权
		adjvert[i]=0;				//待会printf的时候起点都是0
	}
		//选u0相邻的最小的v0
	for(i=1;i<G.num_v;i++)			
	{
		min=maxw;
		j=1;k=0;
		while(j<G.num_v)
		{
			if(lowcost[j]!=0 && lowcost[j]<min)	//已经在树中的结点不选
			{
				min=lowcost[j];
				k=j;
			}
			j++;
		}
		printf("(%d,%d)",adjvert[k],k);
		lowcost[k]=0;
		//更新两集合的最短路径以及起点数组
		for(j=1;j<G.num_v;j++)
		{
			if(lowcost[j]!=0 && G.arcs[k][j]<lowcost[j])
			{
				lowcost[j]=G.arcs[k][j];		//v1到某点的距离比v0到某点的距离更小 
				adjvert[j]=k;				//到对应下标距离最近的顶点更新为k
			}
		}
	}	
}

//Kruskal(省略了将权重邻接矩阵转化为边集数组的步骤)
Edge edge[100];
//插入排序
void sort(int len)
{
	int i,j;				
	Edge temp;
	for( i = 0 ; i < len - 1 ; i++ )
	    for( j = 0 ; j < len - i - 1 ; j++ )
	    	if(edge[j].w>edge[j+1].w)
	    	{
	    		temp = edge[ j ] ;
               	edge[ j ] = edge[ j+ 1 ] ;
                edge[ j+ 1 ] = temp ;
			}
}

//找连通分量的根节点
int Find(int *parent,int f)
{
	while(parent[f]>-1)
		f=parent[f];
	return f;				//若parent[f]==-1说明f本身就是根节点
}
//转化函数 
void convert(AMG G,pEdge E)
{
	int i,j,k;
	k=0;
	for(i=0;i<G.num_v;i++)
	{
		for(j=i+1;j<G.num_v;j++)
		{
			if(G.arcs[i][j]<666)
			{
				E[k].begin=i;
				E[k].end=j;
				E[k].w=G.arcs[i][j];
				k++;
			}
		} 
	}
} 

void MiniCret_Kruskal(AMG G)
{
	int i,n,m,j,k=0;
	int parent[100];				//一开始所有的结点都是根节点
	for(i=0;i<100;i++)
	{
		parent[i]=-1;
	}
	  
//省略了将权重邻接矩阵转化成边集数组并且排序的算法!!
	convert(G,edge) ;
	//将边集数组按照权重排序
	sort(G.num_a);
	
	for(i=0;i<G.num_a;i++)
	{
		m=Find(parent,edge[i].begin);		//连通分量1的根节点
		n=Find(parent,edge[i].end);			//连通分量2的根节点
		
		if(n!=m)
		{
			parent[n]=m;			//将两个连通分量合并,任选一个作为根节点即可,可替换成parent[m]=n;
									//合并的结果是两个根节点要少一个,因为一棵树只能有一个根节点
			printf("边:(%c,%c)权:%d\n",G.vertex[ edge[ i ].begin ] , G.vertex[ edge[ i ].end ] , edge[ i ].w);
		}
	}
}

int main()
{
	AMG G;
	int i,j;
	creat_G(G);
 	MiniCret_Kruskal(G);
	return 0;
} 

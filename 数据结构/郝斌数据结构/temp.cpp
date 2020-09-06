//ͼ
 
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
	int front;					//front �� rear���൱�������±� 
	int rear;					//rearָ�������һ��Ԫ�ؽ�����λ��,��λ��û��Ԫ��!! 
}que;

typedef struct
{
	char vertex[100];			//�����
	int arcs[100][100];			//�ڽӾ���
	int num_v,num_a;			//Ŀǰ�Ѿ�ʹ�õĶ������ͱߵ���Ŀ
}AMG;

//��ʼ������
void init(que* pq)
{
	pq->pbase=(int *)malloc(len*sizeof(int));
	pq->front=0;
	pq->rear=0;
}	
//���� 
bool full_que(que* pq)
{
	if((pq->rear+1)%len==pq->front)		return true ;
	else return false;
}

//��� 
bool input(que* pq,int val)
{
	if(full_que(pq))	return false;
	else
	{
		pq->pbase[pq->rear]=val;
		pq->rear=(pq->rear+1)%len;			//�൱��rear++ 
		return true;
	} 
} 

//�п�
bool is_empty(que* pq)
{
	if(pq->front==pq->rear)		
	return true;
	else 	
	return false;
}

//���� 
bool out_que(que* pq,int* val)
{
	if(is_empty(pq))
	{
		printf("����Ϊ��,����ʧ��\n");
		exit(-1); 
	}
	else
	{
		*val=pq->pbase[pq->front];			
		pq->front=(pq->front+1)%len;		//ֻ���front��ǰŲ���� 
	}
	return true;
}
int visited[100]={0};				//DBS�еı������

//����������ַ���λG�ж����±�
int locate(AMG G,char v)
{
	int i;
	for(i=0;i<G.num_v;i++)
	{
		if(v==G.vertex[i])
			return i;
	}
	printf("δ�ҵ��ö���\n");
	return -1;
}

//����������
void creat_G(AMG &G)
{
	printf("�����붥��ĸ���:");
	scanf("%d",&G.num_v);
	printf("������ߵĸ���:");
	scanf("%d",&G.num_a);
	printf("�����붥����Ϣ\n");	int i,j;
	fflush(stdin);
	for(i=0;i<G.num_v;i++)
	{
		G.vertex[i]=getchar();					//error:getchar��ʱ��ҪС�Ļ�������ʣ�µĻس� 
	}
	//��ʼ�������ڽӾ���	
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
	//����ߵ���Ϣ(ͷβ�ڵ�,Ȩ)
	int w;
	char v1,v2;
	int i_v1,i_v2;
	for(i=0;i<G.num_a;i++)
	{
	//����ߵ�������Ϣ
		fflush(stdin);
		printf("�������%d���߶���v1��v2��Ȩ:\n",i+1);
		scanf("%c %c %d",&v1,&v2,&w); 			//!!ֻҪ�������������͵�ʱ��ҪС�Ļ�����ʣ�µ��Ǹ��س� 
		fflush(stdin);
	//�ҵ������ڶ������±�
		i_v1=locate(G,v1);
		i_v2=locate(G,v2);
	
	//���ڽӾ���ֵ
		G.arcs[i_v1][i_v2]=w;
		G.arcs[i_v2][i_v1]=G.arcs[i_v1][i_v2];			//��Ч��matlab�е�X=X+X'
	}
}
//DFS(�ڽӾ����)
void DFS(AMG &G,int v)				//v�ǵ�һ�����ʵĽ��
{
	visited[v]=1;
	printf("�Ѿ�������%c���\n",G.vertex[v]);
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
		visited[i]=0;				//���нڵ��ʼ��Ϊδ����
	}
	for(i=0;i<G.num_v;i++)
	{
		if(visited[i]==0)
		{
			DFS(G,i);
		}
	}
}
//�������
void BFSTtravel(AMG &G)
{
	int i,j,val;
	que Q;
	for(i=0;i<G.num_v;i++)
		visited[i]=0;
	init(&Q);
	for(i=0;i<G.num_v;i++)			//���б���
	{
		if(visited[i]==0)
		{
			visited[i]=1;
			printf("�Ѿ�������%c���\n",G.vertex[i]);
			input(&Q,i);
			while(!is_empty(&Q))
			{
				out_que(&Q,&i);				//�����ӵ�ֵ����i 
				for(j=0;j<G.num_v;j++)
				{
					if(G.arcs[i][j]>0 && visited[j]==0)	//���б���(�ڽӵ�)
					{
						visited[j]=1;
						printf("�Ѿ�������%c���\n",G.vertex[j]);
//(����ͼӦ��Ҫ��,����ͼʡ��)						printf("�Ѿ�������%c���\n",G.vertex[i]);
						input(&Q,j);
					}
				}
			}
		}
	}
	
}
//prim�㷨 
void MiniCret_prim(AMG G)
{
	int min,i,j,k;
	lowcost[0]=0;
	adjvert[0]=0;
	//��ʼ��
	for(i=1;i<G.num_v;i++)
	{
		lowcost[i]=G.arcs[0][i];	//�����ϵ�����·��Ȩ
		adjvert[i]=0;				//����printf��ʱ����㶼��0
	}
		//ѡu0���ڵ���С��v0
	for(i=1;i<G.num_v;i++)			
	{
		min=maxw;
		j=1;k=0;
		while(j<G.num_v)
		{
			if(lowcost[j]!=0 && lowcost[j]<min)	//�Ѿ������еĽ�㲻ѡ
			{
				min=lowcost[j];
				k=j;
			}
			j++;
		}
		printf("(%d,%d)",adjvert[k],k);
		lowcost[k]=0;
		//���������ϵ����·���Լ��������
		for(j=1;j<G.num_v;j++)
		{
			if(lowcost[j]!=0 && G.arcs[k][j]<lowcost[j])
			{
				lowcost[j]=G.arcs[k][j];		//v1��ĳ��ľ����v0��ĳ��ľ����С 
				adjvert[j]=k;				//����Ӧ�±��������Ķ������Ϊk
			}
		}
	}	
}

//Kruskal(ʡ���˽�Ȩ���ڽӾ���ת��Ϊ�߼�����Ĳ���)
Edge edge[100];
//��������
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

//����ͨ�����ĸ��ڵ�
int Find(int *parent,int f)
{
	while(parent[f]>-1)
		f=parent[f];
	return f;				//��parent[f]==-1˵��f������Ǹ��ڵ�
}
//ת������ 
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
	int parent[100];				//һ��ʼ���еĽ�㶼�Ǹ��ڵ�
	for(i=0;i<100;i++)
	{
		parent[i]=-1;
	}
	  
//ʡ���˽�Ȩ���ڽӾ���ת���ɱ߼����鲢��������㷨!!
	convert(G,edge) ;
	//���߼����鰴��Ȩ������
	sort(G.num_a);
	
	for(i=0;i<G.num_a;i++)
	{
		m=Find(parent,edge[i].begin);		//��ͨ����1�ĸ��ڵ�
		n=Find(parent,edge[i].end);			//��ͨ����2�ĸ��ڵ�
		
		if(n!=m)
		{
			parent[n]=m;			//��������ͨ�����ϲ�,��ѡһ����Ϊ���ڵ㼴��,���滻��parent[m]=n;
									//�ϲ��Ľ�����������ڵ�Ҫ��һ��,��Ϊһ����ֻ����һ�����ڵ�
			printf("��:(%c,%c)Ȩ:%d\n",G.vertex[ edge[ i ].begin ] , G.vertex[ edge[ i ].end ] , edge[ i ].w);
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

//ͼ
 
#include<stdio.h>
#include<string.h>
typedef struct
{
	char vertex[100];			//�����
	int arcs[100][100];			//�ڽӾ���
	int num_v,num_a;			//Ŀǰ�Ѿ�ʹ�õĶ������ͱߵ���Ŀ
}AMG;

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
				G.arcs[i][j]=666;
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
		for(j=0;j<G.num_v;j++)							//error:��j++����� 
		{
			printf("%5d",G.arcs[i][j]); 
			if(j==G.num_a)
				printf("\n");
		}
	} 
	return 0;
}

/* 
//�ڽӱ�(����) 
#include<stdio.h>
#include<string.h>
#include<malloc.h> 
typedef struct SideNode
{
	int index;
	struct SideNode* pNext;					//ָ������(ע����ͷ�巨,ָ��ָǰ��һ��)
	int weight;
}SideNode;
typedef struct
{
	char data;
	SideNode* pSide;
}VNode,AVNode[100];			//AVNode�����ڽӱ������
typedef struct
{
	AVNode vNode;			//ͼ���ڽӱ�
	int v_num,a_num;		//��ǰ��Ч���ͱ�
}Graph;
/*
Graph G;
�����㸳ֵ:G.vNode.data='a'
����һ��ָ��ָ���i��������ڽ������:SideNode* p=G.vNode[i].pSide
��������ֵ:p->index=n;
�㷨˼��
	�������ܶ��������ܱ���
	�ڽ��������
	  for(i=1;i<=v_num;i++)
	 {
		�������붥�����Ϣ
		ʹpSide��ʼ��ΪNULL
	 }
	�۴���ÿ�������Լ��ĵ�����
		1.����ߵ����������Ȩֵ
		2.locate���������±�i,j,�ڶ�������Ӧλ�ý����������
		3.��ͷ�巨�嵽�����Ķ�Ӧλ��vNode[i]��vNode[j]����
/*
int locate(Graph& G,char v)
{
	int i;
	for(i=0;i<G.v_num;i++)
	{
		if(v==G.vNode[i].data)
			return i;
		else
			printf("δ�ҵ��ý��\n");
			return -1; 
	}
}

void CreatG(Graph& G)
{
	int i;
	printf("�����붥�����: �ߵĸ���:");
	scanf("%d%d",&G.v_num,&G.a_num);
	//��ʼ�������
	for(i=0;i<G.v_num;i++)
	{
		printf("�������%d��������ĸ",i+1);
		fflush(stdin);
		scanf("%c",&G.vNode[i].data);
		G.vNode[i].pSide=NULL;			//��ʼ�����еĶ��㻹û�б�
	}
	//����ߵ���Ϣ
	for(i=0;i<G.a_num;i++)
	{
		char v1,v2;
		int w,i_v1,i_v2;
		printf("�������%d���߶���v1��v2��Ȩ");
		fflush(stdin);
		scanf("%c %c %d",&v1,&v2,&w);
		i_v1=locate(G,v1);
		i_v2=locate(G,v2);
		//������Ĵ����Ͳ���
		SideNode* pSideNode1=(SideNode*)malloc(sizeof(SideNode));
		SideNode* pSideNode2=(SideNode*)malloc(sizeof(SideNode));
		
		pSideNode1->pNext=G.vNode[i_v1].pSide;
		G.vNode[i_v1].pSide=pSideNode1;		//���������±�֤��pSideʼ���Ǵ��������ͷ������ 
		
		pSideNode1->index=i_v1;
		pSideNode1->weight=w;
//		pSideNode1->pNext=NULL;				//error����ֱ������д,��Ȼ������һ���߽���ʱ��Ͳ��ڶ��������
		//�������Ļ�pSideNode2��ʡ����
		pSideNode2->pNext=G.vNode[i_v2].pSide;
		G.vNode[i_v2].pSide=pSideNode2;		//���������±�֤��pSideʼ�����������ĩβ
		
		pSideNode2->index=i_v2;
		pSideNode2->weight=w;
	}
}
*/

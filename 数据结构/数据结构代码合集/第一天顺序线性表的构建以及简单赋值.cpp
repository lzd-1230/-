#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int data[100];
	int length;
}Sqlist;
typedef Sqlist* List;
List creat(){
	List point;
	point=(List)malloc(sizeof(Sqlist));
	point->length=-1;
	return point;
}
int main(){
	List point=creat();
	point->length=10;
	int i;
	for(i=0;i<point->length-1;i++)
	{
		point->data[i]=i+1;
	}
	for(i=0;i<point->length-1;i++)
	{
		printf("第%d个数据是%d\n",i+1,point->data[i]);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stu.h" 
//���� 
struct stu{
	int age;
	float score;
	char name[100];
};
int main(int argc, char *argv[]) {
	int len;
	struct stu *p;
	int i;
	int j;
	struct stu t;										//�����ṹ�廻 
//�����ռ�	
	printf("������ѧ���ĸ���:");
	scanf("%d",&len); 
	p=(struct stu *)malloc(len*sizeof(struct stu)); 
	
	input(p,len);
	arrange(p,len);
	output(p,len);
	return 0;
}

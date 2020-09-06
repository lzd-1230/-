#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stu.h" 
//定义 
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
	struct stu t;										//整个结构体换 
//构建空间	
	printf("请输入学生的个数:");
	scanf("%d",&len); 
	p=(struct stu *)malloc(len*sizeof(struct stu)); 
	
	input(p,len);
	arrange(p,len);
	output(p,len);
	return 0;
}

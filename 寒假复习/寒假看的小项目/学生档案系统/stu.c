struct stu{
	int age;
	float score;
	char name[100];
};


void input(struct stu *p,int len){
		int i;
		for(i=0;i<len;i++){
		printf("请输入第%d个学生的信息：",i+1);
		printf("age=");
		scanf("%d",&p[i].age);
		printf("score=");
		scanf("%f",&p[i].score);
		printf("name=");
		scanf("%s",p[i].name);				//∵name本身是数组，因此数组名表示首地址 
	} 
}

void arrange(struct stu *p,int len){
	int i,j;
	struct stu t;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(p[j].score<p[j+1].score)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t; 
			}
		}
	}	
}

void output(struct stu *p,int len){
	int i;
	for(i=0;i<len;i++){
		printf("第%d个学生的信息：\n",i+1);
		printf("age=%d\t",p[i].age);
		printf("score=%.2f\t",p[i].score);
		printf("name=%s\t",p[i].name);
		printf("\n");		
	} 
}


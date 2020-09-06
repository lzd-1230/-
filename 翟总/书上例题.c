#include<Stdio.h>
int main(){
	void average(float*p,int n);    //n拿来干嘛 
	void search(float(*p)[4],int n);
	float score[3][4]={{90,90,90,90},{80,80,80,80},{70,70,70,70}};
	average(*score,12);               //求12个分数的平均       加*表示从0行0列开始 
	search(score,1);                  //求序号为2的学生成绩 ,不加*表明0行的首地址 
	void schfail(float(*p)[4],int n);
	return 0; 
}
void average(float*p,int n){
	float *p1;
	float aver,sum=0;
	p1=p+n-1;                //为了循环 
	for(;p<=p1;p++)
	sum=sum+*p;             //为什么要打括号啊 ？？？
	aver=sum/n;
	printf("平均分%f\n",aver); 
}
void search(float (*p)[4],int n){
	int i;
	printf("the score of No.%dare:\n",n);
	for(i=0;i<4;i++)
	printf("%f\n",*(*(p+n)+i));
}
void schfail(float (*p)[4],int n){
	int i,j,flag;
	for(i=0;i<n;i++){
		flag=0;
		for(j=0;j<4;j++){
			if(*(*(p+j)+i)<60)
				flag=1;
			if(flag==1){
				printf("No.%dfails,his scores are\n",i+1);
				for(j=0;j<4;j++){
					printf("%f\n",*(*(p+i)+j));
				}
			}
		}
			
			
	}
}


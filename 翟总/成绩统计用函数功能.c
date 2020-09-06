#include <stdio.h>
#include <stdlib.h>
int main(){
	float avs(int s);
	float s[10][5];               //存放成绩 
	int i,j;                    //输入成绩	 
	for(i=0;i<=9;i++){
		for(j=0;j<=4;j++){
			printf("输入第%d名同学的第%d科成绩",i+1,j+1);    
			scanf("%f\n",&s[i][j]);
		}
	}    
	int sum,av;                                        //输入完成
	for(i=0;i<=9;i++){
		for(j=0;j<=4;j++){
			 sum+=s[i][j];
			 if(j==4){
			 av=avs(sum);                              //把每个同学的总分赋值给avs 
				 printf("第%d名同学的平均分为%f\n",i+1,av); 
				 }
			}
		}
return 0;	
}float avs(int s){                                       //只用实现求平均数的功能 
        int z,i,j;
		z=s/5;
		return z; 
	                  
 }
 
 
 //递归法将整数n变成字符串 483——>字符串483 
 /*int main(){
 int a,n;
 scanf("%d,%d",&a,n);
 char s[a];
 itoa(a,s,10);
 printf("%s",s);
 return 0;}*/
  

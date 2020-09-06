/*判断2000-2100年中是否为闰年  符合下面两种条件之一的即为闰年
1：能被4整除但不能被100整除
2：能被100整除且能被400整除
注：两个条件中闰年都能被4整除，所以不能被4整除的一定不是闰年！ */
#include<stdio.h>
int main()
{   printf("请输入你想要判断闰年的起止年份(注：请在年份之间打上空格哦~)："); 
	int year,year1;
	scanf("%d %d",&year,&year1); 
	int cnt=0;
	int t=0; 
	for(;year<=year1;year++){
	
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				printf("%d  ",year);
				cnt++;
				t++;
			}
		}else{
			printf("%d  ",year);
			cnt++;
			t++;
		}
	}
	if(cnt==5){printf("\n");
	cnt=0;
	 
	}
	}
	printf("\n总计闰年数为：%d",t); 

return 0;	
}
 

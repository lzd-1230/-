#include<stdio.h>
int main()
{
int foot,inch;
printf("请输入英寸 英尺");
scanf("%d %d",&foot,&inch);
printf("您的身高%f米",((foot+inch/12.0)*0.304));
return 0;
}

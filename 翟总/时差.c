#include<stdio.h>
int main()
{int hour1,mintue1;
 int hour2,mintue2;
 scanf("%d %d",&hour1,&mintue1);
 scanf("%d %d",&hour2,&mintue2);
 int t1=hour1*60+mintue1;
 int t2=hour2*60+mintue2;
 int t=t1-t2;
 printf("ʱ�����%dСʱ%d��",t/60,t%60);
 return 0;
 }

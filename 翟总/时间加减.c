#include<stdio.h>
int main()
{int t;
    printf("��������λ��ʱ��");
 scanf("%d",&t);
 int a,b;
 a=t/100;
 b=t%100;
 int c=a*60+b;
 int change;
 printf("������ʱ���");
 scanf("%d",&change);
 int final1=c+change;
 int d=final1/60;
 int e=final1%60;
 int final2=d*100+e;
 printf("%d",final2);
 return 0;
}

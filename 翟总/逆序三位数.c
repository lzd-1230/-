#include<stdio.h>
int main()
{int a;
    scanf("%d",&a);
    int b,c,d,e;
    b=a/100;
    c=a%10;
    d=a/10;
    e=d%10;
    int f;
    f=e*10+b+c*100;

    printf("%d",f);
    return 0;
}

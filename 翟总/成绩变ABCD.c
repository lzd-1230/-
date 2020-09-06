#include<stdio.h>
int main()
{int grade;
scanf("%d",&grade);
int x=grade/10;                  //将成绩的十位数提出来分情况给评分 
switch(x){
	case 10:printf("A+\n"); 
	break;
	case 9:printf("A\n");
	break;
	case 8:printf("B\n");
	break;
	case 7:printf("C\n");
	break;
	case 6:printf("D\n");
	break;
	default:printf("E\n");
}
return 0;
	 }                        //case 与后面数字要有空格 

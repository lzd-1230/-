#include<stdio.h>
int main()
{int grade;
scanf("%d",&grade);
int x=grade/10;                  //���ɼ���ʮλ������������������ 
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
	 }                        //case ���������Ҫ�пո� 

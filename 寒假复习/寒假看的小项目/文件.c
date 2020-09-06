//文件：格式化输入输
//printf中%和d之间可以插入4个字符
/*#include<stdio.h>
void main(){
	char* num;
	/*printf("%9d\n",123);				//默认右对齐
	printf("%-9d\n",123);				//-表示左对齐 
	printf("%09d\n",123);				//因此+表示强制输出+号 
	printf("%9.2f\n",123.00);			//整个占9位小数点后占2位 
	printf("%d%n\n",12345,&num);
	printf("%d",num);
}  */ 

//scanfprintf的返回结果 
void main(){
	char a[10]="0";
	scanf("%8s",a);
	printf("%s",*a);
}

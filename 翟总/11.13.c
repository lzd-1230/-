#include <stdio.h>
#include <stdlib.h>
//数组的定义以及输入输出 
int main(){

/*{
	int i,a[10];
	for(i=0;i<=9;i++){
		a[i]=i;
	}	
	for(i=9;i>=0;i--){                //逆序输出i的值 
		printf("%d ",a[i]);
	}
	return 0;
}*/

	/*int i;
	int f[20]={1,1};                //f[0]==f[1]==1
	for(i=2;i<=19;i++){
		f[i]=f[i-2]+f[i-1];
	for(i=0;i<=19;i++){
		printf("%12d",f[i]);
		if(i%5==0)
		printf("\n");               //每五个换行 
	}
	}return 0;
}
*/ 
 
 //起泡排序法 ：两两进行比较，一趟找一个最大的数
 	int a[10];
 	int i,j,t;
 	for(i=0;i<10;i++){
 		scanf("%d",&a[i]);
	 }
	for(j=0;j<9-j;j++){          //十个数比9次 
	for(i=0;i<9-j;i++){          //每次比完把最大的那个甩了 
		if(a[i]>a[i=1]){        //比较两个数
			t=a[i];a[i]=a[i+1];a[i+1]=t;     //交换两个数
		}}  for(i=0;i<=9;i++){
			printf("%d",a[i]);
		}} 
	 
	return 0;		
	}
	
	
	//二维数组——矩阵 
	//1.3X4的矩阵，求出最大的元素值，及其行和列
	/*int i,j,r,c,max;
	int a[3][4];
	max=aa[0][0];
	*/
	
	
	
	
	
	
	
	
	
	 

#include <stdio.h>
#include <stdlib.h>
//����Ķ����Լ�������� 
int main(){

/*{
	int i,a[10];
	for(i=0;i<=9;i++){
		a[i]=i;
	}	
	for(i=9;i>=0;i--){                //�������i��ֵ 
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
		printf("\n");               //ÿ������� 
	}
	}return 0;
}
*/ 
 
 //�������� ���������бȽϣ�һ����һ��������
 	int a[10];
 	int i,j,t;
 	for(i=0;i<10;i++){
 		scanf("%d",&a[i]);
	 }
	for(j=0;j<9-j;j++){          //ʮ������9�� 
	for(i=0;i<9-j;i++){          //ÿ�α���������Ǹ�˦�� 
		if(a[i]>a[i=1]){        //�Ƚ�������
			t=a[i];a[i]=a[i+1];a[i+1]=t;     //����������
		}}  for(i=0;i<=9;i++){
			printf("%d",a[i]);
		}} 
	 
	return 0;		
	}
	
	
	//��ά���顪������ 
	//1.3X4�ľ����������Ԫ��ֵ�������к���
	/*int i,j,r,c,max;
	int a[3][4];
	max=aa[0][0];
	*/
	
	
	
	
	
	
	
	
	
	 

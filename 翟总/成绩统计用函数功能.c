#include <stdio.h>
#include <stdlib.h>
int main(){
	float avs(int s);
	float s[10][5];               //��ųɼ� 
	int i,j;                    //����ɼ�	 
	for(i=0;i<=9;i++){
		for(j=0;j<=4;j++){
			printf("�����%d��ͬѧ�ĵ�%d�Ƴɼ�",i+1,j+1);    
			scanf("%f\n",&s[i][j]);
		}
	}    
	int sum,av;                                        //�������
	for(i=0;i<=9;i++){
		for(j=0;j<=4;j++){
			 sum+=s[i][j];
			 if(j==4){
			 av=avs(sum);                              //��ÿ��ͬѧ���ָܷ�ֵ��avs 
				 printf("��%d��ͬѧ��ƽ����Ϊ%f\n",i+1,av); 
				 }
			}
		}
return 0;	
}float avs(int s){                                       //ֻ��ʵ����ƽ�����Ĺ��� 
        int z,i,j;
		z=s/5;
		return z; 
	                  
 }
 
 
 //�ݹ鷨������n����ַ��� 483����>�ַ���483 
 /*int main(){
 int a,n;
 scanf("%d,%d",&a,n);
 char s[a];
 itoa(a,s,10);
 printf("%s",s);
 return 0;}*/
  

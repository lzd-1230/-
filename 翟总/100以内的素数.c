#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
/*int main(){
	int x;
	for(x=1;x<=100;x++){
		int n;
    	int t=1;                //��Ҫ�������������Ը�ֵ1 
   	 for(n=2;n<=x-1;n++){
        if(x%n==0){
          t=0;
        }
    }	
		if(t==1){
            printf("%d ",x);
    ;
	 }} 
    return 0;
	} */                         //֪��100����
	
	
	
	//Ҫ��Ҫǰ50�������������ǵ�50ͣ
		int main(){
			int n=3,i,a;
			for(i=1;i<=50;i++){
				for(a=2;a<=i-1;a++){
					if(i%a==0)
					continue;
					printf("%d������",n);
					}
} 
		return 0;	
}
	//1000���˾��赽10wԪֹͣ ,�������ô��� ͳ�ƴﵽ10wʱ�������� 
	/*int main(){
		int sum=10000;
		int n,m,t,a,i;
		for(i=1;n<=1000&&m<sum;i++){
		                                 ���������������ʱ��������  
			scanf("%d",&a);                          
			t=t+a;
		}printf("%d",i);
	}return 0; 
	}*/
	//�����������еľ��� 
	/*int main(){
		int i,j,n;
		for(;;i++){
		for(;;j++,n++){
			
		}
	}return 0;}*/ 
	 
	

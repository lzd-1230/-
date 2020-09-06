#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
/*int main(){
	int x;
	for(x=1;x<=100;x++){
		int n;
    	int t=1;                //想要表达的是素数所以赋值1 
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
	} */                         //知道100以内
	
	
	
	//要是要前50个素数，而不是到50停
		int main(){
			int n=3,i,a;
			for(i=1;i<=50;i++){
				for(a=2;a<=i-1;a++){
					if(i%a==0)
					continue;
					printf("%d是素数",n);
					}
} 
		return 0;	
}
	//1000个人捐款，捐到10w元停止 ,条件不好处理。 统计达到10w时的人数。 
	/*int main(){
		int sum=10000;
		int n,m,t,a,i;
		for(i=1;n<=1000&&m<sum;i++){
		                                 两个条件都满足的时候继续捐款  
			scanf("%d",&a);                          
			t=t+a;
		}printf("%d",i);
	}return 0; 
	}*/
	//输入任意行列的矩阵 
	/*int main(){
		int i,j,n;
		for(;;i++){
		for(;;j++,n++){
			
		}
	}return 0;}*/ 
	 
	

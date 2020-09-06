#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>

//循环例子训练
//Π=1-1/3+1/5-1/7...直到发现某一项绝对值小于10的-6次方为止 
int main(){
	/*int sign=1;
	double pi=0.0,n=1.0,term=1.0;//pi代表多项式的值，最后代表Π，n代表分母，term代表当前分式值 
	while(fabs(term)>1e-6)        //注意绝对值和10的-6表示方法 
	{
		pi=pi+term;
		n=n+2;
		sign=-sign;                 //-1的n次方表示方法，（正负交替出现的解决方法）在循环中赋值相反数  
		term=1/n*sign;
}	pi=pi*4;
	printf("%f",pi);
	return 0;
} */ 
// 1/n的求和  
//1-1/2+1/3...多了一个-1的n次方    

/*int main(){
	int n,i,sign=1;
	double sum=0.0;                //sum已经不是一个整数了 
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		sum+=1.0/i*sign;           //两边都要是浮点数，要用1.0
		sign=-sign;				   //也可以把sign放在分子 
		}
 	printf("%d %f",n,sum);
	return 0;}*/
	//矩阵的输入4x5
	 /*int i,j,x;
	 for(i=1;i<=4;i++){
	 	for(j=1;j<=5;j++){
	 		printf("%-3d",i*j);
	 		if(j>=5)
	 		printf("\n");
		 }
	 }return 0;
	 }                                         //如何实现自由的输入矩阵中元素？？？？？？ 
	
	
	 
	//整数逆序分解       整数正序分解思路：把求逆和分解分为两个步骤。   
	/*int main(){
		int x,i,t,y;
		scanf("%d",&y);
		while(y>0){	                 //第一个循环求逆序 
			i=y%10;
			x=x*10+i;
			y/=10;
		} printf("%d\n",x);
		for(;x>0;x/=10){             //第二个循环输出 
			t=x%10;
			printf("%d",t);	//要想解决最后的空格问题，就得设置最后一次判断条件使最后一次不输出空格
			if(x>=10) 
			printf(" ");    //这样最后一次就没有空格		
			}return 0; 
	} *///发现有零就不好使了
	

		/*int mask,a,f,r;
		scanf("%d %d",&a,&mask);
	while(mask>0){
		f=a/mask;
		printf("%d",f);
		r=a%mask;
		mask/=10;
		printf("f=%d,r=%d,mask=%d\n",f,r,mask); 
	}*/
	
           //例题用for 改写 
	
/*	int a,cnt;
	scanf("%d",&a);
	int i,j,k;
	int c=0;
	for(i=a;i<=a+3;i++){
		for(j=a;j<=a+3;j++){
			for(k=a;k<=a+3;k++){
				if(k!=j&&j!=k&&i!=k){
					c++;
					printf("%d%d%d",i,j,k);
					if(c==6){
						printf("\n");
						c=0;                    //要给c这个每行都要判断的数在执行后归零 
					}else{
						printf(" ");
					}
					
					
				}
			}
		}
	}return 0;
}
	*/ 
	
	
	 
 

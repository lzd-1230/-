#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>

//ѭ������ѵ��
//��=1-1/3+1/5-1/7...ֱ������ĳһ�����ֵС��10��-6�η�Ϊֹ 
int main(){
	/*int sign=1;
	double pi=0.0,n=1.0,term=1.0;//pi�������ʽ��ֵ����������n�����ĸ��term����ǰ��ʽֵ 
	while(fabs(term)>1e-6)        //ע�����ֵ��10��-6��ʾ���� 
	{
		pi=pi+term;
		n=n+2;
		sign=-sign;                 //-1��n�η���ʾ������������������ֵĽ����������ѭ���и�ֵ�෴��  
		term=1/n*sign;
}	pi=pi*4;
	printf("%f",pi);
	return 0;
} */ 
// 1/n�����  
//1-1/2+1/3...����һ��-1��n�η�    

/*int main(){
	int n,i,sign=1;
	double sum=0.0;                //sum�Ѿ�����һ�������� 
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		sum+=1.0/i*sign;           //���߶�Ҫ�Ǹ�������Ҫ��1.0
		sign=-sign;				   //Ҳ���԰�sign���ڷ��� 
		}
 	printf("%d %f",n,sum);
	return 0;}*/
	//���������4x5
	 /*int i,j,x;
	 for(i=1;i<=4;i++){
	 	for(j=1;j<=5;j++){
	 		printf("%-3d",i*j);
	 		if(j>=5)
	 		printf("\n");
		 }
	 }return 0;
	 }                                         //���ʵ�����ɵ����������Ԫ�أ����������� 
	
	
	 
	//��������ֽ�       ��������ֽ�˼·��������ͷֽ��Ϊ�������衣   
	/*int main(){
		int x,i,t,y;
		scanf("%d",&y);
		while(y>0){	                 //��һ��ѭ�������� 
			i=y%10;
			x=x*10+i;
			y/=10;
		} printf("%d\n",x);
		for(;x>0;x/=10){             //�ڶ���ѭ����� 
			t=x%10;
			printf("%d",t);	//Ҫ�������Ŀո����⣬�͵��������һ���ж�����ʹ���һ�β�����ո�
			if(x>=10) 
			printf(" ");    //�������һ�ξ�û�пո�		
			}return 0; 
	} *///��������Ͳ���ʹ��
	

		/*int mask,a,f,r;
		scanf("%d %d",&a,&mask);
	while(mask>0){
		f=a/mask;
		printf("%d",f);
		r=a%mask;
		mask/=10;
		printf("f=%d,r=%d,mask=%d\n",f,r,mask); 
	}*/
	
           //������for ��д 
	
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
						c=0;                    //Ҫ��c���ÿ�ж�Ҫ�жϵ�����ִ�к���� 
					}else{
						printf(" ");
					}
					
					
				}
			}
		}
	}return 0;
}
	*/ 
	
	
	 
 

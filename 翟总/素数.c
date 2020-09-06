#include <stdio.h>
int main(){
/*
{
    int x,n;
    scanf("%d",&x);
    for(n=2;n<=x-1;n++){
        if(x%n==0){
            break;
        }
        }if(n==x){
            printf("%d是素数",x);
        }else{printf("%d是合数",x);}
    return 0;}*/                              //最后通过n有没有全部走完来判断 



/*{
    int x,n;
    scanf("%d",&x);
    int t=1;                //想要表达的是素数所以赋值1 
    for(n=2;n<=x-1;n++){
        if(x%n==0){
          t=0;
        }
    }	
		if(t==1){
            printf("%d是素数",x);
    }else{
		printf("%d是合数",x);
	 }
    return 0;}*/
    	


/*
	int sushu(int x);
	int a,b;
	scanf("%d",&a);
	b=sushu(a);
	if(b==0) printf("%d不是素数",a);
	else printf("%d是素数",a);
	return 0;
} int sushu(int x){
	int t,i;
	for(i=2;i<=x-1;i++){
		t=x%i;
		if(t==0)
		break;
	}return (t);
}      */                               //success!!!  
//升级版保留判断函数，修改主函数达到输出1~200的素数 



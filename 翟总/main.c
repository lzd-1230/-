#include<stdio.h> 

int main(){
	/*int i,j,a[15][15];
		for(i=0;i<15;i++){
			for(j=0;j<=i;j++){
				if(j==0){
					a[i][j]=1;
				}else if(0<j<i){
					a[i][j]=a[i-1][j-1]+a[i-1][j];
				}else {a[i][j]=1;
				}
			}}
		for(i=0;i<15;i++){
			for(j=0;j<=i;j++){ 
		printf("%d",a[i][j]);
				if(j<i) printf(" ");
				else printf("\n"); 
			}}return 0;}*/
	
	               // 失败 
//刘益铭版本 
/*int i,j;
int a[20]={1},f[20]={1};
printf("%5d",a[0]);
for(i=2;i<=15;i++){
	for(j=0;j<=i-1;j++){
		f[j+1]=a[j]+a[j+1];
		a[j]=f[j];
		printf("%5d",f[j]);
	}printf("\n");
}return 0;
}  */ 
                    



//for循环版本 
/*int main(void)
{
long i,j,n,k;
printf("杨辉三角：\n请输入行号，回车：");
scanf("%ld",&n);
for(i=1;i<=n;i++)
{
k=1;
for(j=1;j<i;j++)//从第2行开始才进入该循环
{
printf("%ld ",k);  //从第2行开始每次进入该循环第一次打印的是每行开头的1
k=k*(i-j)/j; //这个用于计算第二行开始每行第一个1和最后一个1之间的数，例如第3行的2，第4
                //行的 3 3
}
printf("1\n");//这个用于打印每行最后一列的1
}
return 0;
}*/

//数组中插入数
/*int x,a[5]={1,3,5,7,9};
scanf("%d",&x);
int b[6]={1,3,5,7,9,x};
int i,j,t;
for(i=0;i<5;i++){
	for(j=0;j<5-i;j++){
		if(b[j]>b[j+1]){
			t=b[j];b[j]=b[j+1];b[j+1]=t;			
		}
	}
}	for(i=0;i<=5;i++){
	printf("%d",b[i]);
}return 0;
}*/
int x,i,j,t,a[6]={1,3,5,7,9};
scanf("%d",&x);
a[5]=x;
for(i=0;i<5;i++){
	for(j=0;j<5-i;j++){
		if(a[j]>a[j+1]){
			t=a[j];a[j]=a[j+1];a[j+1]=t;			
		}
	}for(i=0;i<=5;i++){
	printf("%d",a[i]);
}}return 0;
}


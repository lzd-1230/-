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
	
	               // ʧ�� 
//�������汾 
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
                    



//forѭ���汾 
/*int main(void)
{
long i,j,n,k;
printf("������ǣ�\n�������кţ��س���");
scanf("%ld",&n);
for(i=1;i<=n;i++)
{
k=1;
for(j=1;j<i;j++)//�ӵ�2�п�ʼ�Ž����ѭ��
{
printf("%ld ",k);  //�ӵ�2�п�ʼÿ�ν����ѭ����һ�δ�ӡ����ÿ�п�ͷ��1
k=k*(i-j)/j; //������ڼ���ڶ��п�ʼÿ�е�һ��1�����һ��1֮������������3�е�2����4
                //�е� 3 3
}
printf("1\n");//������ڴ�ӡÿ�����һ�е�1
}
return 0;
}*/

//�����в�����
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


#include<stdio.h>
#include<math.h>
/*int main(){
	int x,i,j,t,a[10];
	double sum; 
	for(i=0;i<10;i++){
		scanf("%d",&x);
		a[i]=x;
		{
			for(j=0;j<=i;j++)
			{
			printf("%d\t",a[j]);           //��������ÿ��������ʲô 
			}
		}	 
			printf("\n");
		sum+=x;
		t=i;
		if(x==-1)    break;
	}
	for(i=0;i<10;i++){
		if(a[i]>sum/t)   printf("%d\n",a[i]);
		if(i>=t)    break;
	}return 0;
	
} */ 
		//���飻�Ŷ���������
		//���ʣ�����Ԫ������ͬ���ͣ���С�ڶ����Ͳ��ܸı䣨��ȱ��ӣ�
		//�ٶ���ڳ�ʼ������ 
		//�����ʼ��Ϊ0ֱ��a[i]=0; 
		//��Ŀ������[0,9]�Ĳ�ȷ��������ͳ��ÿһ�������ֵĴ�����-1����
/*int main(){
	int i,x,a[10];
	for(i=0;i<10;i++){
		a[i]=0;
	}
	for(i=0;i<10;i++){
		scanf("%d",&x);
		a[x]=a[x]+1 ;
	}
	for(i=0;i<10;i++){
		printf("%d�����ˣ�%d��\n",i,a[i]);
	}
	return 0;
} */
		//���ɳ�ʼ���������������С���ñ������������� 
	/*int main (){
		int i;
		int a[10]={[1]=1,4,[4]=8};     //�˷����ʺ�ϡ������Ķ��� 
		for(i=0;i<10;i++){
			printf("%d\t",a[i]);
		}
	return 0;
	} */
	//sizeof���Եĵ�������ֽڴ�С���١�ÿ������������ռ���ֽھͿ��Եõ� 
	//Ҫ��������ĸ�ֵ��ֻ�ܱ���b[i]=a[i] 
	
	//**��������������

int su(int x){
	int i=2,t=1;
	while(i<=sqrt(x)){
		if(x%i==0)	t=0;        
		i++;
		return t;
	}
}/*
int main()
{
	int a[100]={2};
	int i,j=3,k=2;
	while(i<100){
		if(su(j)){
		a[i++]=j;                 //���j�������Ͱ����Ž����飬�����ǾͲ�����һ��j 
		}	 
		j++;
	}

		return 0;
}	
*/
//����������������
/* 
int main(){
	int n,i;
	scanf("%d",&n); 
	int judge[n];
	for(i=0;i<n;i++){
		judge[i]=1;
	}
	int x=2;
	while(x<=n){
		if(su(x)){
			for(i=x;i*x<=n;i++){
				judge[i*x]=0;
			}
		}x++;
	}
	for(i=2;i<n;i++){
		if(judge[i])	printf("%d\t",i);
	}
}*/ 
 //����ͨ˼ά��ͬ��С������������ 
	



	




 

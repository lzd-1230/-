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
			printf("%d\t",a[j]);           //看下我们每次输入了什么 
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
		//数组；放东西的容器
		//性质；所有元素是相同类型，大小在定义后就不能改变（类比杯子）
		//①定义②初始化！！ 
		//若想初始化为0直接a[i]=0; 
		//题目：输入[0,9]的不确定整数，统计每一种数出现的次数，-1结束
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
		printf("%d出现了：%d次\n",i,a[i]);
	}
	return 0;
} */
		//集成初始化：不给出具体大小，让编译器帮我们数 
	/*int main (){
		int i;
		int a[10]={[1]=1,4,[4]=8};     //此方法适合稀疏数组的定义 
		for(i=0;i<10;i++){
			printf("%d\t",a[i]);
		}
	return 0;
	} */
	//sizeof可以的到数组的字节大小，再÷每个数据类型所占的字节就可以得到 
	//要想对数组间的赋值，只能遍历b[i]=a[i] 
	
	//**构造素数表数组

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
		a[i++]=j;                 //如果j是素数就把它放进数组，若不是就测试下一个j 
		}	 
		j++;
	}

		return 0;
}	
*/
//倍数法构造素数表
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
 //和普通思维不同从小到大构造素数表 
	



	




 

#include<stdio.h> 
#include<malloc.h>
void shuchu(int a){
	printf("%d",a);
} 	
/*指针本质就是地址(操作受限的非负整数 
	①地址不一定是int型，要用%p输出 
 	&只能对变量取地址，不等对表达式
指针
	*p是一个指针类型而不是int*
	指针就是保存地址，只是一个值
	指针变量是一个保存指针的变量

讲话时会省略变量二字  

指针的重要性:
	表示一些复杂的数据结构
	快速的传递数据
	使函数返回一个以上的值
	能直接访问硬件
	能够方便处理字符串
	是理解面对对象语言中引用的基础

指针的分类
	1.基本类型指针
	2.指针和数组
	3.指针和函数 
	4.指针和结构体
 	5.多级指针

*的含义	 
	1.乘法	2.定义指针变量	3.指针运算符
	 
定义时的格式规范
	int* p==int *p==int * p
	最好写int * p 
	 
三句话关于 int * p=&i;
	一.p存了i的地址，p指向i
	二.*p就是以p的内容为地址的变量，就是i 
	三. 指针p和i是两个变量
	
指针修改多个函数值
	return最多只能返回一个值
	方法: 
		将主函数中变量的地址传给被调函数
		在被调函数中通过*p操作 
	 
指针和一维数组
	数组名:a就是指针常量 
	！！！如果一个函数要处理一个一维数组则需要接收两个信息
	1地址		2长度	 
	
	下标和指针
	p[i]==*(p+i) 
	
	指针的运算 
	只有当两指针指向同一块连续空间时才能做相减
	没有+和x÷

一个指针变量到底占几个字节？
	什么类型的指针 
	
cpu和内存条之间分为三根线
	控制线:决定数据传输的方向
	数据线:传输数据
	地址线:传到内存的哪个地址
	
地址线
	每一根线只有两种状态0，1
	多少位，就是多少根地址线 eg：32位，64位
	1k=2^10B	1M=2^10k	1G=2^10M	∴2^32=4G 
	32位可以控制2^32个位==4G

一个字节一个编号，其中变量的首字节的地址算作该变量的地址
eg：double变量有8个字节，则以第一个字节的地址作为该变量的地址	 

内存中的编号(32位)从0->2^32(十进制)
	因此需要4个字节(==2^32种)状态的位置来保存 
	因此指针变量占4个字节大小(32位) 

动态内存分配
	传统数组的缺点：
		1.数组长度必须事先制定，且不能更改
		2.数组的内存无法手动释放，只能在所在函数执行之后由系统自动释放
		3.数组不能跨函数使用，当所在函数执行结束后，内存自动被释放 

		 
		 
	为什么需要动态内存分配
		 可以解决静态(传统数组)的缺点
		  
	
 	动态数组的构造
 		int *a=(int *)malloc(sizeof(int)*n);
 		
		realloc补充数组
		 	realloc(a,100);		//给a补充到！！100个字节
		 
	静态内存和动态的比较
		静态内存：由系统自动分配和释放，在栈中分配 
		动态内存：由程序员手动分配和释放，在堆中分配的。
			如果忘记释放，内存就会越来越小 
	跨函数使用内存 
		静态内存不能跨函数使用 
		
搜索=排序+查找
 
malloc函数(深入内存的角度去理解)
	只有一个整型形参，形参代表请求系统分配的字节数
	！返回第一个字节的地址，但一个指针除了地址还需要类型 
 	eg：(int *)malloc(100) 	代表25个int型变量
	 	(char *)malloc(100) 代表100个char型变量 
	 	
	凡是变量前有类型的都是静态
	malloc的都是动态
	eg:int *p=(int *)malloc(4) //p占4个静态	所指的区域占4个
		free(p)					//指把p所指向的区域内存释放 若q和p一样指向该内存，则q也会丢失目标
		 
 	int *p=(int *)malloc(20)	//p指向的是第一个字节的地址，又由于是int型，所以p指向前4个字节
	 							//p+1指向后4个字节
								
多级指针 
	eg：int i;
		int *p=&i;
		int **q=&p;
	总：跟定义一样的就是所指变量
		少一个*就是指针	 
 	
 
 
 翁恺 
#include<stdio.h>
#include<stdlib.h>
/*void point(int*p);
int main(){
	int a=6;
	point(&a);
	printf("改变后a的值=%d",a);
	return 0;
} 
void point(int*p){
	printf("p的地址=%p\n",p);
	printf("p的值=%d\n",*p);
	*p=26;
} */
//用指针函数交换值 
//void swap(int *p,int *q);
//int main(){
//	int a=3,b=8;
//	printf("a=%d b=%d\n",a,b);
//	swap(&a,&b);
//	printf("a=%d b=%d",a,b);
//	return 0;
//}
//void swap(int *p,int *q){
//	int t;
//	t=*p;
//	*p=*q;
//	*q=t;
//}
//函数需要改变多个值

//void minmax(int a[],int length,int *min,int *max);
//int main(){
//	int a[]={1,2,3,4,5,6,7,8,90};
//	int min,max;
//	minmax(a,sizeof(a)/sizeof(a[0]),&min,&max);
//	printf("min=%d\nmax=%d",min,max);
//	return 0;
//} 
//void minmax(int a[],int length,int *min,int *max){
//	int i;
//	*min=a[0];
//	*max=a[0];
//	for(i=0;i<length;i++){
//		if(a[i]<*min)	*min=a[i];
//		if(a[i]>*max)	*max=a[i];
//	}
//} 
//传入函数的数组变成了啥？
//函数参数（）里的数组实际上是指针， sum（int a[]） ==sum(int *a)！！在参数表中等价 
//实际上数组变量本身表达的就是地址,是常量 
//special case:int const*p和const int *p的区别
//前者是表示指针指向关系（指针）不可改变，后者表示不能通过*p改变所指变量（指针所指）的值不可修改
//const int *p是避免函数对外面变量修改的手段（当要传大类型时用到指针） 
//若不想在函数中修改原来变量的值，用const a[]或const int *p
/*int main(){
	char c[]={0,1,2,3,4,5};
	char *p=c;
	printf("p=%p\n",p);
	printf("*p=%p\n",p+1);
	int c1[]={0,1,2,3,4,5};
	int *q=c1;
	printf("p=%p\n",q);
	printf("*（p+1）=%p",q+1);
	return 0;
} */
//指针的运算
//指针++等于加一个sizeof（基础类型） 
//0地址不能随便碰①返回的指针是无效的②指针没有被真正初始化③null来表示
//不同类型的指针不能相互赋值
//！！！！！
//指针哪来做什么？
//需要传入较大数据时用作参数如数组
//传入数组对数组做操作
//函数返回不止一个结果


//动态内存分配---运行时才确定的数组 
//       指针变量=malloc(size的个数 * sizeof（基础类型）） 
//int main(){
//	int i,n;
//	printf("数组大小:");
//	scanf("%d",&n);
//	int *a;
//	a=(int *)malloc(sizeof(int)*n);
//	printf("输入数组"); 
//	for(i=0;i<n;i++){
//		scanf("%d",&a[i]);
//	}
//	printf("输出数组");
//	for(i=0;i<n;i++){
//		printf("%d\t",a[i]);
//	}
//	free(a);
//}

//测试系统最大能给多少空间
/*int main(){
	int *p,t;
	while(p=malloc(100*1024*1024)){
		t++;
	}
	printf("一共申请了%d00M的内存",t);
	free(p);
	return 0;
} */ 
//好习惯：malloc一次就跟一次free 
//free必须时原来的首地址，不能更改 

//指针常见错误
/*不初始化指针，变成野指针 
	很可能指到一个没权限访问的内存 
int main(){
	int *p,i=5;			p可能指向一块没有申请的内存(野区)，造成程序无法运行 
	*p=i;				*p是int型所以编译不报错 
	printf("%d",*p);
	return 0;
} */

//基本类型指针经典程序(互换两个数字)
//void swap(int *a,int *b){
//	int t;
//	t=*a;
//	*a=*b;
//	*b=t;
//}
//int main(){
//	int a=5;
//	int b=3;
//	swap(&a,&b);
//	printf("a=%d\nb=%d",a,b);
//	return 0;
//} 
 

#include<stdio.h>
#include<string.h> 
/*郝斌 
为什么要结构体？
	存储若干个拥有多特性的变量(复合数据类型) 
	
结构体和结构体变量的区别
	结构体是一种类型like int
	~变量是一个变量like  a 
赋值和初始化
	初始化时整体赋值
	之后只能对成员单独赋值 
	 
如何取出成员
	1.结构体变量名.成员名
	2.指针变量名->成员名	在内部其实是(*指针变量名).成员名 

结构体变量的运算
	结构体变量不能加减乘除
	只能相互赋值 
	
结构体变量指针作为参数传递的问题
	发送指针才能在函数中对其进行修改
	用指针会省内存，因为结构体一般比较大，如果再开辟一个结构体形参则会很大 
	不希望在函数中进行修改则用const
	 
动态构造存放学生信息的结构体数组
	用户先输入一个长度然后 
	
链表 

*/










//翁恺 
//作用:将多个数据看成一个整体
//struct date{         				//声明结构类型 ：虚的，类似声明函数(分号不能忘) 
//	int day;
//	int month;						//定义成员变量 
//	int year; 
//}a;									//定义结构变量a：实的 
////初始化方法 
//int main(){
// 		a.day=27;
//		a.month=1;
//		a.year=2020;				//定义结构变量 
//
////或	struct date today={27,1,2020};
//	printf("%d-%d-%d",a.year,a.month,a.day);
//	return 0;
//}
//结构体数组的投票例子(有点问题) 
//struct vote {
//	char name[20];
//	int num;
//}candidate[3]={"li",0,"zhang",0,"wang",0};
//int main(){
//	int i,j;
//	char choice[20];
//	for(i=0;i<2;i++)
//	{
//		scanf("%s",choice);
//		for(j=0;j<3;j++)
//		{
//			if(strcmp(choice,candidate[j].name)==0)
//			{
//				candidate[j].num++;
//			}
//		}
//	}
//	printf("Result:\n");
//	for(j=0;j<=2;j++){
//		printf("%s:%d\n",candidate[j].name,candidate[j].num);
//	}
//	return 0;
//} 
// 
	 

//结构体作为函数参数
/*struct p{
	int x;
	int y;
}; 
struct p getstru(){
	struct p p1;
	scanf("%d",&p1.x);
	scanf("%d",&p1.y);
	return p1;
}

int main(){
	struct p y={0,0};
	y=getstru();
	printf("x=%d\ny=%d",y.x,y.y);
	return 0;
}*/
//结构体指针 
/*
struct p{
	int x;
	int y;
}; 
struct p* get(struct p *a){
	scanf("%d",&a->x);
	scanf("%d",&a->y);
	return a;
}
int  main(){
	struct p a={0,0};
	get(&a);
	printf("x=%i\ny=%i",get(&a)->x,get(&a)->y);
	return 0;
} */

//结构数组和结构嵌套
/*struct time {
	int sec;
	int hou;
}; 

void main(){
	struct time a[2]={
	{10,10},{11,11}		
	};
	int i;
	for(i=0;i<2;i++){
		printf("%d时 %d分\n",a[i].hou,a[i].sec);
	}
}*/
//结构体指针指向数组 
//struct student{
//	char name[20];
//	int score;
//	}stu[3]={"li",90,"wang",80,"zhang",70};
//int main()
//{
//	struct student *p;
//	for(p=stu;p<stu+3;p++){
//		printf("%s:%d\n",p->name,p->score);
//	}
//return 0;			
//} 
//typedef的用法

//typedef struct{
//	int day;
//	int month;
//	int year;
//}d;        						//只有最后一个单词才是我们关心的 
//void main(){
//d a={9,9,2019};
//printf("%d-%d-%d",a.day,a.month,a.year);
//} 

//全局变量
//①不初始化会被默认赋值为0
//②在函数中若出现同名变量则会被隐藏(在小范围的变量会把大范围的给隐藏) 
//③初始化的时候 

//静态本地变量(只会被初始化一次) 
//实质上是特殊的全局变量，因为有全局的生存期，但作用域也只能在本地 
/*f(){
	static int a=1;   
	a+=2;
	printf("a=%d\n",a);
}
void main(){
	f();
	f();
	f();
}*/

//返回指针的函数 
//当返回本地变量的地址时很危险，因为离开了函数就没人保证 a的值还在那里了 
/*int *f(){
	static int a=2;
	return &a;
}
void main(){
	int *p=f();
	printf("%p\n",p);
	printf("%d",*p);
}*/

//编译预处理指令#   		将.c的文件预处理为.i 
//宏#define 名字 文本
//完全的文本替换 
//c中预先定义好的宏:_LINE_ _FILE_ _DATE_ _TIME_ _STDC_

//像函数的宏
/*
#define s(x) ((x)*3.14) 			//要点：整个值要有括号，每个参数出现的地方都要有() 
void main(){
	printf("%f",s(5));
}*/

//程序结构：多个源文件（.c）需要弄到一个项目里去，形成.o文件后再串起来 
//头文件：包含了函数原型eg:int max(int a,int b)
//实质就是将.h文件中的内容原封不动地插入过来 
//代替函数的声明 (头文件里只能放声明) 
//.h文件中只是有函数的模型，只是为了保证你的参数类型是正确的
//标准库里的函数源代码会自动和你的程序链接，所以就算你没引用头文件也一样可以用
//只不过是编译器去猜你的参数类型


//不对外公开的函数(只希望这个.c文件用不希望别的用)+static
//在全局变量上+static->变成只能在该.c文件中使用的

//声明和定义
//声明不产生代码(不能赋值)
//定义①函数②全局变量 

//为了防止重复声明，头文件采用标准头文件格式
/*#ifndef_文件名_H_
#define_文件名_H_

#endif*/ 


 


 

#include<stdio.h>
#include<stdlib.h>
/*
1.内嵌
2.间接嵌套
	以结构体变量为成员
	以结构体指针为成员
*/

//直接嵌套(在结构体里面直接定义另一个结构体)
#if 0
struct  MM
{
	char name[20];
	struct boy1
	{
		char boyname[20];
	}boy;
};

int main()
{
	struct MM mm1 = { "mama","erzi" };
	printf("%s\t%s\t\n", mm1.name, mm1.boy.boyname);

}
#endif // 0
//通常的嵌套情况
//1.变量形式
//访问方法:(剥洋葱)
#if 0
struct score
{
	int math;
	int english;
};
struct student
{
	char name[20];
	int age;
	struct score my_score;
};
int main()
{
	struct student me = { "lzd",18,90,80 };
	printf("%s\t%d\t%d\t%d\n",me.name,me.age,me.my_score.english,me.my_score.math);
}
#endif
//2.嵌套指针
//嵌套别人的指针
#if 1

struct score
{
	int math;
	int english;
};
struct  teacher
{
	char name[20];
	int age;
	int num;
	struct score* pScore;
};
int main()
{
	struct teacher tom = { "jack",19,2019,NULL };
	tom.pScore = (struct score*)malloc(sizeof(struct score));
	tom.pScore->english = 99;
	printf("%d\n", tom.pScore->english);
}
#endif // 1
//嵌套自己的指针(链表基础)
#if 1
struct list
{
	int data;
	struct list* plist;
};
#endif // 1



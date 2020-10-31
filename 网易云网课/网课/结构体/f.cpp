#include"f.h"

//先做菜单
void Menu()
{
	//做系统先做菜单
	printf("-----------管理系统------------\n");
	printf("\t0.退出系统\n");
	printf("\t1.录入信息\n");
	printf("\t2.浏览系统\n");
	printf("\t3.修系统\n");
	printf("\t4.查找显示\n");
	printf("\t5.删除\n");
	printf("\t6.排序后显示\n");
}

//再做交互(每个用到交互的模块都会需要修改这里)
void Key_Down(my_struct* list,int *len)
{
	my_struct temp;	//这个临时变量可以给仍以一个分支使用
	int user_key;
//---------------------
	if (scanf("%d", &user_key) != 1)	//!!!防止用户输入其它键盘上的东西
	{
		printf("请输入数字而不是字母\n");
		while (getchar() != '\n');		
		user_key = 9;		//进入switch后重新输入
	}
//---------------------
	switch (user_key)
	{
	case 0:
		printf("已经退出管理系统,期待下次光临\n");
		system("pause");
		exit(0);
		break;
	case 1:
		printf("请输入学生的信息,格式如(name,age,num,addr)");
		scanf("%s%d%d%s",&temp.name,&temp.age,&temp.num,&temp.addr);
		Append_Data(list, len, temp);	//写到这里的时候发现参数少了!!!!!
		break;
	case 2:
		Print_Data(list, *len);
		break;
	//修改学生信息
	case 3:
		Change(list, *len);
		break;
	case 4:
		printf("请输入查找的姓名:");
		scanf("%s", temp.name);
		Search(list, temp.name, *len);
		break;
	case 5:
		printf("请输入需要删除人的姓名:");
		scanf("%s", temp.name);
		Delete(list,temp.name,len);
		break;
	//排序(根据姓名排序!)
	case 6:
		Sort(list,*len);
		printf("排序后的list:\n");
		Print_Data(list, *len);
	default:
		printf("输入错误,请重新输入");
		break;
	}
}

//封装过程函数---->对于数组的增删改查 
//插入
void Append_Data(my_struct list[], int* index, my_struct target)
{
	list[*index] = target;
	(*index)++;	//从0开始顺序录入
}
//打印
void Print_Data(const my_struct* list,int len)
{
	printf("序号\t姓名\t年龄\t编号\t地址\t\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d.\t%s\t%d\t%d\t%s\t\n",i+1,list[i].name, list[i].age,list[i].num,list[i].addr);
	}
} 

//查找:返回可以有两种形式1.返回在数组中的序号 2.返回改结构体地址
//如何处理重名(不反回,需要返回值的时候再封装一个函数)
void Search(my_struct* list, char* s_name, int len)	
{
	for (int i = 0; i < len; i++)
	{
		if (strcmp(list[i].name, s_name) == 0)
		{
			Print_Data(&list[i], 1);
			return;
		}
	}
	printf("查无此人");
}

int Search_Return_Index(my_struct* list, char* s_name, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (strcmp(list[i].name, s_name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void Delete(my_struct* list, char* s_name,int* len)
{
	int index = Search_Return_Index(list, s_name, *len);
	if (index != -1)
	{
		for (int i = index; i < *(len)-1; i++)
		{
			list[i] = list[i + 1];
		}
		(*len)--;
		printf("删除成功");
	}

	else
	{
		printf("查无此人,无法删除");
	}
}
//排序
/*
strcmp技巧:前-后看正负
*/
void Sort(my_struct* list, int len)
{
	my_struct tmp;
	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (strcmp(list[i].name, list[j].name) == -1)
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}

void Change(my_struct* list, int len)
{
	int choice,index;
	printf("请输入想要修改人的序号");
	scanf("%d", &index);
	index--;	//序号从1开始,对应到数组下标要减小
	printf("请输入你想修改的内容:\n");
	printf("\t1.修改姓名\n");
	printf("\t1.修改年龄\n");
	printf("\t2.修改编号\n");
	printf("\t3.修系地址\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("请输入修改后的姓名:");
		scanf("%s", list[index].name);
		printf("修改后的姓名为:%s", list[index].name);
		break;
	case 2:
		printf("请输入修改后的年龄:");
		scanf("%d", list[index].age);
		printf("修改后的年龄为:%d", &list[index].age);
		break;
	case 3:
		printf("请输入修改后的编号:");
		scanf("%d", &list[index].num);
		printf("修改后的年龄为:%d", list[index].num);
		break;
	case 4:
		printf("请输入修改后的地址:");
		scanf("%d", list[index].addr);
		printf("修改后的年龄为:%d", list[index].num);
		break;
	default:
		printf("输入错误,请重新输入");
		break;
	}
}
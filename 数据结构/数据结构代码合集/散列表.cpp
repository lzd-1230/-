//二叉排序树(待运行)
//Debug:注意要修改的变量送进函数的方式一定要是引用或指针
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
//散列表
typedef struct
{
	int* elem;	//数据元素储存地址
	int count;	//当前元素个数
}HashTable;
int len = 0;		//散列表长
void Init_HashTable(HashTable* H);
int Hash(int key);
bool SearchHash(HashTable H, int key, int& addr);
void InsertHash(HashTable* H, int key);

int main()
{
	int i;
	int a[5] = { 1,2,3,4,5 };
	len = 5;
	int addr;
	HashTable H;
	Init_HashTable(&H);
	for (i = 0; i < len; i++)
	{
		InsertHash(&H, a[i]);
	}
	if (SearchHash(H, 5, addr))
		printf("查找成功,地址为%d", addr);
	return 0;
}
//初始化散列表
void Init_HashTable(HashTable* H)
{
	int i;
	H->count = len;
	H->elem = (int*)malloc(sizeof(HashTable) * len);//因为用的除留余数法,因此只需要长度为len即可

	for (i = 0; i < len; i++)
	{
		H->elem[i] = 0;				//0的位置代表未被赋值 
	}
	return;
}
//哈希函数(选取除留余数法)
int Hash(int key)
{
	return key % len;
}
void InsertHash(HashTable* H, int key)
{
	int addr = Hash(key);

	while (H->elem[addr] != 0)
		addr = Hash(addr + 1);		//线性开放地址法处理冲突

	H->elem[addr] = key;
}
bool SearchHash(HashTable H, int key, int& addr)
{
	addr = Hash(key);		//求散列地址
	while (H.elem[addr] != key)
	{
		addr = Hash(addr + 1);//addr==key%len
		if (H.elem[addr] == 0 || addr == Hash(key))
			printf("查找失败");
		return false;
	}
	return true;
}



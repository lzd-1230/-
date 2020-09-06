#include<malloc.h>
#include<stdio.h>
#include <vcruntime_string.h>
#include <stdlib.h>
//两数之和
//hash 散列
//#define MAX_SIZE 2048
//int* twoSum(int* nums, int numsSize, int target, int* returnSize)
//{
//    int i, hash[MAX_SIZE], * res = (int*)malloc(sizeof(int) * 2);
//    memset(hash, -1, sizeof(hash));     //全部赋值为-1
//    for (i = 0; i < numsSize; i++)      //遍历nums数组
//    {
//        if (hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE] != -1)
//        {
//            res[0] = hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE];
//            res[1] = i;
//            *returnSize = 2;
//            return res;
//        }
//        hash[(nums[i] + MAX_SIZE) % MAX_SIZE] = i;  //防止负数下标越界，循环散列
//    }
//    free(hash);
//    *returnSize = 0;
//    return res;
//}

//用numsSize   hash的方法
//int* twoSum(int* nums, int numsSize, int target, int* returnSize)
//{
//    int i, hash[numsSize];
//    int* res = (int*)malloc(sizeof(int) * 2);
//    memset(hash, 0, sizeof(hash));     //全部赋值为-1
//    for (i = 0; i < numsSize; i++)
//    {
//        =
//    }
//    for (i = 0; i < numsSize; i++)      //遍历nums数组
//    {
//        if (hash[(target - nums[i] + numsSize) %numsSize] != 0)
//        {
//            res[0] = hash[(target - nums[i] + numsSize) % numsSize];
//            res[1] = i;
//            *returnSize = 2;
//            return res;
//        }
//        hash[(nums[i] + numsSize) % numsSize] = i;  //防止负数下标越界，循环散列
//    }
//    free(hash);
//    return res;
//}
//暴力遍历法的小优化
//int* twoSum(int* nums, int numsSize, int target, int* returnSize)
//{
//    int* result = (int*)malloc(2 * sizeof(int));    //返回两个下标
//    int i, j,temp;
//    for (i = 0; i < numsSize; i++)                  //双下标无重复遍历
//    {
//        temp = target - nums[i];
//        for (j = i + 1; j < numsSize; j++)
//        {
//            if (nums[j] == temp)
//            {
//                result[0] = i;
//                result[1] = j;
//                *returnSize = 2;
//            }
//        }
//    }
//    return result;
//}

//正版哈希表
//typedef struct Hash_Data
//{
//	int key;
//	int value;
//}HashData;
//
//typedef struct HashNode
//{
//	HashData data;
//	struct HashNode* next;
//}HashNode;						//链表结点
//
//typedef struct HashMap
//{
//	int size;
//	HashNode* table;			//哈希表,每一个元素都是一个链表结点
//}HashMap;
//
//HashMap* CreateHashMap(int* nums, int numSize)
//{
//	int i;
//	int index = 0;		//用于循环
//
//	HashMap* H = (HashMap*)malloc(sizeof(HashMap));
//
//	H->size = numSize;
//	H->table = (HashNode*)malloc(sizeof(HashNode) * H->size);
//
//	//初始化hash表
//	for (i = 0; i < H->size; i++)
//	{
//		H->table[i].data.value = INT_MIN;
//		H->table[i].next = NULL;
//	}
//
//	//hash表创建
//	while (index < numSize)
//	{
//		int place = abs(nums[index]) % (H->size);//哈希表中的下标
//		if (H->table[place].data.value == INT_MIN)
//		{
//			//不冲突
//			H->table[place].data.value = nums[index];//value记录值的大小
//			H->table[place].data.key = index;	//这个key记录了元素在nums中的下标
//		}
//		else
//		{
//			//冲突
//			//给冲突的元素分配一个节点
//			HashNode* node_1 = (HashNode*)malloc(sizeof(HashNode));
//			HashNode* hashnode;	//用来做连接用的
//			node_1->data.value = nums[index];
//			node_1->data.key = index;
//			node_1->next = NULL;
//
//			//将节点node_1 与next进行连接
//			hashnode = &(H->table[place]);
//			while (hashnode->next != NULL)
//			{
//				hashnode = hashnode->next;
//			}
//			hashnode->next = node_1;	//确保接到链表的尾端
//		}
//		index++;
//	}
//	return H;
//}
//
//int GetHashMap(HashMap* H, int hope)	//返回在nums中的下标
//{
//	int place = abs(hope) % (H->size);	//hope在哈希表中应该的位置
//	HashNode* pointer = &(H->table[place]);
//	while (pointer != NULL)
//	{
//		if (pointer->data.value == hope)	//没有发生冲突
//		{
//			return pointer->data.key;
//		}
//		else
//		{
//			pointer = pointer->next;
//		}
//	}
//	return -1;
//}
//
//void freeHashMap(HashMap* H)
//{
//	int i = 0;
//	HashNode* Fpointer;
//	while (i < H->size)
//	{
//		Fpointer = H->table[i].next;
//		while (Fpointer != NULL)
//		{
//			H->table[i].next = Fpointer->next;
//			free(Fpointer);
//			Fpointer = H->table[i].next;
//		}
//		i++;
//	}
//	free(H->table);
//	free(H);
//}
//
//int* twoSum(int* nums, int numsSize, int target, int* returnSize)
//{
//	int i;
//	int key = 0;
//	HashMap* H = CreateHashMap(nums, numsSize);
//	int* res = (int*)malloc(sizeof(int) * 2);
//	*returnSize = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		int value = target - nums[i];
//		key = GetHashMap(H, value);
//		if (key != -1 && key != i)
//		{
//			res[0] = i;
//			res[1] = key;
//			*returnSize = 2;
//			break;
//		}
//	}
//	freeHashMap(H);
//	return res;
//}



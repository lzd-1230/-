#include<malloc.h>
#include<stdio.h>
#include <vcruntime_string.h>
#include <stdlib.h>
//����֮��
//hash ɢ��
//#define MAX_SIZE 2048
//int* twoSum(int* nums, int numsSize, int target, int* returnSize)
//{
//    int i, hash[MAX_SIZE], * res = (int*)malloc(sizeof(int) * 2);
//    memset(hash, -1, sizeof(hash));     //ȫ����ֵΪ-1
//    for (i = 0; i < numsSize; i++)      //����nums����
//    {
//        if (hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE] != -1)
//        {
//            res[0] = hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE];
//            res[1] = i;
//            *returnSize = 2;
//            return res;
//        }
//        hash[(nums[i] + MAX_SIZE) % MAX_SIZE] = i;  //��ֹ�����±�Խ�磬ѭ��ɢ��
//    }
//    free(hash);
//    *returnSize = 0;
//    return res;
//}

//��numsSize   hash�ķ���
//int* twoSum(int* nums, int numsSize, int target, int* returnSize)
//{
//    int i, hash[numsSize];
//    int* res = (int*)malloc(sizeof(int) * 2);
//    memset(hash, 0, sizeof(hash));     //ȫ����ֵΪ-1
//    for (i = 0; i < numsSize; i++)
//    {
//        =
//    }
//    for (i = 0; i < numsSize; i++)      //����nums����
//    {
//        if (hash[(target - nums[i] + numsSize) %numsSize] != 0)
//        {
//            res[0] = hash[(target - nums[i] + numsSize) % numsSize];
//            res[1] = i;
//            *returnSize = 2;
//            return res;
//        }
//        hash[(nums[i] + numsSize) % numsSize] = i;  //��ֹ�����±�Խ�磬ѭ��ɢ��
//    }
//    free(hash);
//    return res;
//}
//������������С�Ż�
//int* twoSum(int* nums, int numsSize, int target, int* returnSize)
//{
//    int* result = (int*)malloc(2 * sizeof(int));    //���������±�
//    int i, j,temp;
//    for (i = 0; i < numsSize; i++)                  //˫�±����ظ�����
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

//�����ϣ��
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
//}HashNode;						//������
//
//typedef struct HashMap
//{
//	int size;
//	HashNode* table;			//��ϣ��,ÿһ��Ԫ�ض���һ��������
//}HashMap;
//
//HashMap* CreateHashMap(int* nums, int numSize)
//{
//	int i;
//	int index = 0;		//����ѭ��
//
//	HashMap* H = (HashMap*)malloc(sizeof(HashMap));
//
//	H->size = numSize;
//	H->table = (HashNode*)malloc(sizeof(HashNode) * H->size);
//
//	//��ʼ��hash��
//	for (i = 0; i < H->size; i++)
//	{
//		H->table[i].data.value = INT_MIN;
//		H->table[i].next = NULL;
//	}
//
//	//hash����
//	while (index < numSize)
//	{
//		int place = abs(nums[index]) % (H->size);//��ϣ���е��±�
//		if (H->table[place].data.value == INT_MIN)
//		{
//			//����ͻ
//			H->table[place].data.value = nums[index];//value��¼ֵ�Ĵ�С
//			H->table[place].data.key = index;	//���key��¼��Ԫ����nums�е��±�
//		}
//		else
//		{
//			//��ͻ
//			//����ͻ��Ԫ�ط���һ���ڵ�
//			HashNode* node_1 = (HashNode*)malloc(sizeof(HashNode));
//			HashNode* hashnode;	//�����������õ�
//			node_1->data.value = nums[index];
//			node_1->data.key = index;
//			node_1->next = NULL;
//
//			//���ڵ�node_1 ��next��������
//			hashnode = &(H->table[place]);
//			while (hashnode->next != NULL)
//			{
//				hashnode = hashnode->next;
//			}
//			hashnode->next = node_1;	//ȷ���ӵ������β��
//		}
//		index++;
//	}
//	return H;
//}
//
//int GetHashMap(HashMap* H, int hope)	//������nums�е��±�
//{
//	int place = abs(hope) % (H->size);	//hope�ڹ�ϣ����Ӧ�õ�λ��
//	HashNode* pointer = &(H->table[place]);
//	while (pointer != NULL)
//	{
//		if (pointer->data.value == hope)	//û�з�����ͻ
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



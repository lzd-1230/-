
#include<iostream>
#include<vector>
#include <unordered_map>
#include<algorithm>
using namespace std;
//给定一个整数数组 nums和一个目标值 target
//请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//示例
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回[0, 1]


//法一:暴力法
#if 0
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans(2);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                   
                }
            }
        }
        return ans;
    }
};
#endif

//法二:排序+双指针
#if 0
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> temp;
        temp = nums;
        int n = temp.size();
        sort(temp.begin(), temp.end());     //快速排序的标准库
        int i = 0, j = n - 1;               //双指针
        //多了加,少了减去试出i和j
        while (i < j) {
            if (temp[i] + temp[j] > target) j--;
            else if (temp[i] + temp[j] < target)    i++;
            else break;
        }
      //因为重新排过序,所以需要在原数组中再找回来
        if (i < j) {
            for (int k = 0; k < n; k++) {
                if (i < n && nums[k] == temp[i]) {
                    ans.push_back(k);   //ans的末尾插入
                    i = n;
                }
                else if (j < n && nums[k] == temp[j]) {
                    ans.push_back(k);
                    j = n;
                }
                if (i == n && j == n)   return ans; 
            }
        }
        return ans;
    }
};
#endif 

//法三:哈希map
#if 0
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int>hashmap;
        for (int i = 0; i < nums.size(); i++) {
            if (hashmap[target - nums[i]] != 0 
                && hashmap[target - nums[i]] != i + 1)
            {
                //防止利用同个元素
                ans.push_back(i);
                ans.push_back(hashmap[target - nums[i]] - 1);
                return ans;
            }
            hashmap[nums[i]] = i + 1;
            //将hash表对应下标＋1，防止处理下标为0的情况
        }
        return ans;
    }
};
#endif // 0

//用numsSize   hash的方法
#if 0
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, hash[numsSize];
    int* res = (int*)malloc(sizeof(int) * 2);
    memset(hash, 0, sizeof(hash));     //全部赋值为-1
    for (i = 0; i < numsSize; i++)
    {
        =
    }
    for (i = 0; i < numsSize; i++)      //遍历nums数组
    {
        if (hash[(target - nums[i] + numsSize) %numsSize] != 0)
        {
            res[0] = hash[(target - nums[i] + numsSize) % numsSize];
            res[1] = i;
            *returnSize = 2;
            return res;
        }
        hash[(nums[i] + numsSize) % numsSize] = i;  //防止负数下标越界，循环散列
    }
    free(hash);
    return res;
}
#endif

//暴力遍历法的小优化
#if 0
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* result = (int*)malloc(2 * sizeof(int));    //返回两个下标
    int i, j,temp;
    for (i = 0; i < numsSize; i++)                  //双下标无重复遍历
    {
        temp = target - nums[i];
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[j] == temp)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
            }
        }
    }
    return result;
}
#endif

//正版哈希表
#if 0
typedef struct Hash_Data
{
	int key;
	int value;
}HashData;

typedef struct HashNode
{
	HashData data;
	struct HashNode* next;
}HashNode;						//链表结点

typedef struct HashMap
{
	int size;
	HashNode* table;			//哈希表,每一个元素都是一个链表结点
}HashMap;

HashMap* CreateHashMap(int* nums, int numSize)
{
	int i;
	int index = 0;		//用于循环

	HashMap* H = (HashMap*)malloc(sizeof(HashMap));

	H->size = numSize;
	H->table = (HashNode*)malloc(sizeof(HashNode) * H->size);

	//初始化hash表
	for (i = 0; i < H->size; i++)
	{
		H->table[i].data.value = INT_MIN;
		H->table[i].next = NULL;
	}

	//hash表创建
	while (index < numSize)
	{
		int place = abs(nums[index]) % (H->size);//哈希表中的下标
		if (H->table[place].data.value == INT_MIN)
		{
			//不冲突
			H->table[place].data.value = nums[index];//value记录值的大小
			H->table[place].data.key = index;	//这个key记录了元素在nums中的下标
		}
		else
		{
			//冲突
			//给冲突的元素分配一个节点
			HashNode* node_1 = (HashNode*)malloc(sizeof(HashNode));
			HashNode* hashnode;	//用来做连接用的
			node_1->data.value = nums[index];
			node_1->data.key = index;
			node_1->next = NULL;

			//将节点node_1 与next进行连接
			hashnode = &(H->table[place]);
			while (hashnode->next != NULL)
			{
				hashnode = hashnode->next;
			}
			hashnode->next = node_1;	//确保接到链表的尾端
		}
		index++;
	}
	return H;
}

int GetHashMap(HashMap* H, int hope)	//返回在nums中的下标
{
	int place = abs(hope) % (H->size);	//hope在哈希表中应该的位置
	HashNode* pointer = &(H->table[place]);
	while (pointer != NULL)
	{
		if (pointer->data.value == hope)	//没有发生冲突
		{
			return pointer->data.key;
		}
		else
		{
			pointer = pointer->next;
		}
	}
	return -1;
}

void freeHashMap(HashMap* H)
{
	int i = 0;
	HashNode* Fpointer;
	while (i < H->size)
	{
		Fpointer = H->table[i].next;
		while (Fpointer != NULL)
		{
			H->table[i].next = Fpointer->next;
			free(Fpointer);
			Fpointer = H->table[i].next;
		}
		i++;
	}
	free(H->table);
	free(H);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int i;
	int key = 0;
	HashMap* H = CreateHashMap(nums, numsSize);
	int* res = (int*)malloc(sizeof(int) * 2);
	*returnSize = 0;
	for (i = 0; i < numsSize; i++)
	{
		int value = target - nums[i];
		key = GetHashMap(H, value);
		if (key != -1 && key != i)
		{
			res[0] = i;
			res[1] = key;
			*returnSize = 2;
			break;
		}
	}
	freeHashMap(H);
	return res;
}
#endif


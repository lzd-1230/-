
#include<iostream>
#include<vector>
#include <unordered_map>
#include<algorithm>
using namespace std;
//����һ���������� nums��һ��Ŀ��ֵ target
//�����ڸ��������ҳ���ΪĿ��ֵ�����������������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣
//ʾ��
//���� nums = [2, 7, 11, 15], target = 9
//��Ϊ nums[0] + nums[1] = 2 + 7 = 9
//���Է���[0, 1]


//��һ:������
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

//����:����+˫ָ��
#if 0
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> temp;
        temp = nums;
        int n = temp.size();
        sort(temp.begin(), temp.end());     //��������ı�׼��
        int i = 0, j = n - 1;               //˫ָ��
        //���˼�,���˼�ȥ�Գ�i��j
        while (i < j) {
            if (temp[i] + temp[j] > target) j--;
            else if (temp[i] + temp[j] < target)    i++;
            else break;
        }
      //��Ϊ�����Ź���,������Ҫ��ԭ���������һ���
        if (i < j) {
            for (int k = 0; k < n; k++) {
                if (i < n && nums[k] == temp[i]) {
                    ans.push_back(k);   //ans��ĩβ����
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

//����:��ϣmap
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
                //��ֹ����ͬ��Ԫ��
                ans.push_back(i);
                ans.push_back(hashmap[target - nums[i]] - 1);
                return ans;
            }
            hashmap[nums[i]] = i + 1;
            //��hash���Ӧ�±꣫1����ֹ�����±�Ϊ0�����
        }
        return ans;
    }
};
#endif // 0

//��numsSize   hash�ķ���
#if 0
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, hash[numsSize];
    int* res = (int*)malloc(sizeof(int) * 2);
    memset(hash, 0, sizeof(hash));     //ȫ����ֵΪ-1
    for (i = 0; i < numsSize; i++)
    {
        =
    }
    for (i = 0; i < numsSize; i++)      //����nums����
    {
        if (hash[(target - nums[i] + numsSize) %numsSize] != 0)
        {
            res[0] = hash[(target - nums[i] + numsSize) % numsSize];
            res[1] = i;
            *returnSize = 2;
            return res;
        }
        hash[(nums[i] + numsSize) % numsSize] = i;  //��ֹ�����±�Խ�磬ѭ��ɢ��
    }
    free(hash);
    return res;
}
#endif

//������������С�Ż�
#if 0
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* result = (int*)malloc(2 * sizeof(int));    //���������±�
    int i, j,temp;
    for (i = 0; i < numsSize; i++)                  //˫�±����ظ�����
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

//�����ϣ��
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
}HashNode;						//������

typedef struct HashMap
{
	int size;
	HashNode* table;			//��ϣ��,ÿһ��Ԫ�ض���һ��������
}HashMap;

HashMap* CreateHashMap(int* nums, int numSize)
{
	int i;
	int index = 0;		//����ѭ��

	HashMap* H = (HashMap*)malloc(sizeof(HashMap));

	H->size = numSize;
	H->table = (HashNode*)malloc(sizeof(HashNode) * H->size);

	//��ʼ��hash��
	for (i = 0; i < H->size; i++)
	{
		H->table[i].data.value = INT_MIN;
		H->table[i].next = NULL;
	}

	//hash����
	while (index < numSize)
	{
		int place = abs(nums[index]) % (H->size);//��ϣ���е��±�
		if (H->table[place].data.value == INT_MIN)
		{
			//����ͻ
			H->table[place].data.value = nums[index];//value��¼ֵ�Ĵ�С
			H->table[place].data.key = index;	//���key��¼��Ԫ����nums�е��±�
		}
		else
		{
			//��ͻ
			//����ͻ��Ԫ�ط���һ���ڵ�
			HashNode* node_1 = (HashNode*)malloc(sizeof(HashNode));
			HashNode* hashnode;	//�����������õ�
			node_1->data.value = nums[index];
			node_1->data.key = index;
			node_1->next = NULL;

			//���ڵ�node_1 ��next��������
			hashnode = &(H->table[place]);
			while (hashnode->next != NULL)
			{
				hashnode = hashnode->next;
			}
			hashnode->next = node_1;	//ȷ���ӵ������β��
		}
		index++;
	}
	return H;
}

int GetHashMap(HashMap* H, int hope)	//������nums�е��±�
{
	int place = abs(hope) % (H->size);	//hope�ڹ�ϣ����Ӧ�õ�λ��
	HashNode* pointer = &(H->table[place]);
	while (pointer != NULL)
	{
		if (pointer->data.value == hope)	//û�з�����ͻ
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


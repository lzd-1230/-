//����������(������)
//Debug:ע��Ҫ�޸ĵı����ͽ������ķ�ʽһ��Ҫ�����û�ָ��
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
//ɢ�б�
typedef struct
{
	int* elem;	//����Ԫ�ش����ַ
	int count;	//��ǰԪ�ظ���
}HashTable;
int len = 0;		//ɢ�б�
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
		printf("���ҳɹ�,��ַΪ%d", addr);
	return 0;
}
//��ʼ��ɢ�б�
void Init_HashTable(HashTable* H)
{
	int i;
	H->count = len;
	H->elem = (int*)malloc(sizeof(HashTable) * len);//��Ϊ�õĳ���������,���ֻ��Ҫ����Ϊlen����

	for (i = 0; i < len; i++)
	{
		H->elem[i] = 0;				//0��λ�ô���δ����ֵ 
	}
	return;
}
//��ϣ����(ѡȡ����������)
int Hash(int key)
{
	return key % len;
}
void InsertHash(HashTable* H, int key)
{
	int addr = Hash(key);

	while (H->elem[addr] != 0)
		addr = Hash(addr + 1);		//���Կ��ŵ�ַ�������ͻ

	H->elem[addr] = key;
}
bool SearchHash(HashTable H, int key, int& addr)
{
	addr = Hash(key);		//��ɢ�е�ַ
	while (H.elem[addr] != key)
	{
		addr = Hash(addr + 1);//addr==key%len
		if (H.elem[addr] == 0 || addr == Hash(key))
			printf("����ʧ��");
		return false;
	}
	return true;
}



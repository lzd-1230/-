#include"f.h"

//�����˵�
void Menu()
{
	//��ϵͳ�����˵�
	printf("-----------����ϵͳ------------\n");
	printf("\t0.�˳�ϵͳ\n");
	printf("\t1.¼����Ϣ\n");
	printf("\t2.���ϵͳ\n");
	printf("\t3.��ϵͳ\n");
	printf("\t4.������ʾ\n");
	printf("\t5.ɾ��\n");
	printf("\t6.�������ʾ\n");
}

//��������(ÿ���õ�������ģ�鶼����Ҫ�޸�����)
void Key_Down(my_struct* list,int *len)
{
	my_struct temp;	//�����ʱ�������Ը�����һ����֧ʹ��
	int user_key;
//---------------------
	if (scanf("%d", &user_key) != 1)	//!!!��ֹ�û��������������ϵĶ���
	{
		printf("���������ֶ�������ĸ\n");
		while (getchar() != '\n');		
		user_key = 9;		//����switch����������
	}
//---------------------
	switch (user_key)
	{
	case 0:
		printf("�Ѿ��˳�����ϵͳ,�ڴ��´ι���\n");
		system("pause");
		exit(0);
		break;
	case 1:
		printf("������ѧ������Ϣ,��ʽ��(name,age,num,addr)");
		scanf("%s%d%d%s",&temp.name,&temp.age,&temp.num,&temp.addr);
		Append_Data(list, len, temp);	//д�������ʱ���ֲ�������!!!!!
		break;
	case 2:
		Print_Data(list, *len);
		break;
	//�޸�ѧ����Ϣ
	case 3:
		Change(list, *len);
		break;
	case 4:
		printf("��������ҵ�����:");
		scanf("%s", temp.name);
		Search(list, temp.name, *len);
		break;
	case 5:
		printf("��������Ҫɾ���˵�����:");
		scanf("%s", temp.name);
		Delete(list,temp.name,len);
		break;
	//����(������������!)
	case 6:
		Sort(list,*len);
		printf("������list:\n");
		Print_Data(list, *len);
	default:
		printf("�������,����������");
		break;
	}
}

//��װ���̺���---->�����������ɾ�Ĳ� 
//����
void Append_Data(my_struct list[], int* index, my_struct target)
{
	list[*index] = target;
	(*index)++;	//��0��ʼ˳��¼��
}
//��ӡ
void Print_Data(const my_struct* list,int len)
{
	printf("���\t����\t����\t���\t��ַ\t\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d.\t%s\t%d\t%d\t%s\t\n",i+1,list[i].name, list[i].age,list[i].num,list[i].addr);
	}
} 

//����:���ؿ�����������ʽ1.�����������е���� 2.���ظĽṹ���ַ
//��δ�������(������,��Ҫ����ֵ��ʱ���ٷ�װһ������)
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
	printf("���޴���");
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
		printf("ɾ���ɹ�");
	}

	else
	{
		printf("���޴���,�޷�ɾ��");
	}
}
//����
/*
strcmp����:ǰ-������
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
	printf("��������Ҫ�޸��˵����");
	scanf("%d", &index);
	index--;	//��Ŵ�1��ʼ,��Ӧ�������±�Ҫ��С
	printf("�����������޸ĵ�����:\n");
	printf("\t1.�޸�����\n");
	printf("\t1.�޸�����\n");
	printf("\t2.�޸ı��\n");
	printf("\t3.��ϵ��ַ\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("�������޸ĺ������:");
		scanf("%s", list[index].name);
		printf("�޸ĺ������Ϊ:%s", list[index].name);
		break;
	case 2:
		printf("�������޸ĺ������:");
		scanf("%d", list[index].age);
		printf("�޸ĺ������Ϊ:%d", &list[index].age);
		break;
	case 3:
		printf("�������޸ĺ�ı��:");
		scanf("%d", &list[index].num);
		printf("�޸ĺ������Ϊ:%d", list[index].num);
		break;
	case 4:
		printf("�������޸ĺ�ĵ�ַ:");
		scanf("%d", list[index].addr);
		printf("�޸ĺ������Ϊ:%d", list[index].num);
		break;
	default:
		printf("�������,����������");
		break;
	}
}
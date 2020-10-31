#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct My
{
	char name[20];
	int age;
	int num;
	char addr[20];
}my_struct;

void Key_Down(my_struct* list, int* len);
void Menu();
void Append_Data(my_struct list[], int* index, my_struct target);
void Print_Data(const my_struct* list, int len);
void Search(my_struct* list, char* s_name, int len);
void Delete(my_struct* list, char* s_name, int* len);
void Sort(my_struct* list,int len);
void Change(my_struct* list, int len);



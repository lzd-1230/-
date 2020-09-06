#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

void print(const char *p, int s)		//s很关键 
{
    for(int i = 0; i < s; i++)
        printf(" ");
    printf("%s\n",p);
}

/**********************************************
    d[i]:p[0]~p[i]共计i+1个字符的最大公共前后缀
**********************************************/
void calc_lps(int d[], const char *p)
{
    int i = 1, j = 0, np = strlen(p);
    memset(d,0, sizeof(int)*np);			//初始化数组 
    while(i < np)
    {
        if(p[j] == p[i])
		{ 
            d[i] =j+1;
            i++; 
        } 
        else
        {
            if(j > 0)   j = d[j-1];
            else        i++;
        }
    }
}

void kmp(const char *t, const char *p)
{
    printf("**********************************************\n");
    printf("%s\n",t);

    int d[100];
    calc_lps(d, p);
    int i = 0, j = 0, nt = strlen(t), np = strlen(p);
    while(i < nt)
    {
        if(p[j] == t[i])
        {
            i++;
			j++;
        }
        else
        {
            if(j > 0)   j = d[j-1];
            else        i++;
        }
         if(j == np)
            {
                print(p, i-j);
                j = d[np-1];
            }
    }
}

int main()
{
    kmp("abababca", "caaa");
//    kmp("ABABCABAB", "ABAB");
//    kmp("AAAAAAA", "AAA");
//    kmp("ABABABC", "ABABC");
//    kmp("XYXZdeOXZZKWXYZ", "WXYZ");
//    kmp("GCAATGCCTATGTGACCTATGTG", "TATGTG");
//    kmp("AGATACGATATATAC", "ATATA");
//    kmp("CATCGCGGAGAGTATAGCAGAGAG", "GCAGAGAG");
    return 0;
}


#include<stdio.h>
#include<string.h>
#include <stdlib.h>
/*
�㷨���:
�ٹ�ϣ�������:û���ֹ����ַ�����0,�ַ����־ͻḳֵΪ���ַ��±�+1(if�ڶ��γ��ֵĸ��µ�����:Զ��(�ظ�)���ֵ���һλ)
��start��ʼ��Ϊ0,ÿ�θ���Ϊ�����ظ����ֵ���һλ,�ټ������컬�������Ҷ�
*/
//��ϣ+����(��΢����)
//int lengthOfLongestSubstring(char* s) {
//    int i, count = 0, start = 0, index[128] = { 0 }, max = 0;
//    for (i = 0; s[i] != '\0'; i++)
//    {
//        if (index[s[i]] > start)
//        {
//            count = i - start;  //�������䳤��
//            if (count > max)
//                max = count;
//            start = index[s[i]]; //start���ɴ���һ���ַ���ʼ�����ִ�����,start�ĸ�����Ϊ�������ظ�,��˸�ֵΪ�ظ��ַ���һ���ַ����±�
//        }
//        index[s[i]] = i + 1;    //�������ĸ��ֵ���õı�start��,����ָ������һ���ַ��ĵ�ַ,��������Ӯ��֮���start��ֵʱstartҲ��Ȼ�ʹ���һ����ʼ
//    }
//    count = i - start;
//    return max > count ? max : count;
//}

//��������
/*
int lengthOfLongestSubstring(char* s) {
        int max = 0;
        int i = 0;
        int len = strlen(s);
        for(int j = 0; j < len; j++)
        {
            for(int k = i; k < j; k++)
            {
                if(s[k] == s[j])
                {
                    max = max > (j-i) ? max : j-i;  ���ƻ�Լ������������k֮ǰ�ĸ���
                    i = k+1;
                }
            }
            max = max > (j-i+1) ? max : j-i+1;      ������ÿ�����Ŵ��ں�,����û���ƻ�Լ����ĸ���
        }
        return max;
    }
};
*/

//С��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000

/*
��ʱʾ��
ASCII���ַ�����ʹ��һ���ֽ�����ʾ��
��Чȡֵ��ΧΪ0~127���ܹ�128���ַ���
����˼·Ϊ��
����һ��128�ֽڴ�Сchar�����飬�����ʼ��Ϊ0��
*/
int allUnique(char* s, int i, int j)
{
    char flag[128]; //ASC��ֻ��0-127
    int ret = 0;
    memset(flag, 0, sizeof(flag)); //����Ϊ0;
    for (; i <= j; i++)
    {
        if (flag[*(s + i)])
        {
            ret = 1; //���ظ�
            break;
        }
        else
        {
            flag[*(s + i)] = 1;     //û���ֹ��͸�ֵ,�ٳ��־��ظ�
        }
    }
    return ret;
}

//̰���㷨
int lengthOfLongestSubstring1(char* s)
{
    int length = 0;
    int n = strlen(s);  //ԭʼ�ж೤
    //printf("%d\n",n);
    int i, j;
    //�������е����ַ�������¼û���ظ���ĸ�����ַ��������ĳ���
    //��ȡ���ַ���ʱ��ʹ��������ǩ���ֱ�������ַ����Ŀ�ͷ�ͽ�β
    if (n == 1)
    {
        length = 1;
        return length;
    }

    for (i = 0; i < n; i++)
    {
        length = (length > (1) ? length : (1));
        for (j = i + 1; j < n; j++)
        {
            //�����ַ���û���ظ���ĸʱ��ans��¼���ĳ���
            if (!allUnique(s, i, j))    //������û���ظ�
            {
                length = (length > (j - i + 1) ? length : (j - i + 1));
                //  printf("%d  %d----------  %d\n",i,j,length);
            }
        }

    }
    return length;

}

/*1.��Ҫ�����ȽϵĽ����ԭ���ݽṹ�����������еģ��ַ����е��������ظ��Ӵ��������е�����Ԫ�����ͣ�
2. ÿ�δ��ڻ���ʱ��ֻ��۲촰������Ԫ�صı仯�����۴��ڶ೤��ÿ��ֻ��������ͷβԪ�أ����õ��Ĵ��ڱȽϳ�ʱ�������������ٲ�������
*/
int lengthOfLongestSubstring2(char* s)
{
    int L = 0, R = 0, k;
    int maxlen = 0;
    int curlen = 0;
    int n = strlen(s);
    if (n == 0)
        return 0;
    // for(; R < n &&(maxlen+L)<n; R++) //���һ��ʼ�벻��Ҳ�������ɣ������Ż���L+�������Ķ�����n�˻�������ɶ��
    for (; R < n; R++)  //�������С����Ӷ��Ӷ�ģ�Ŀ����ɶ���ǵ�ѭ����ɣ�
    {
        curlen++;  //����һ�£����Ⱦ�+1��һ��ʼ����һ�������ˣ�����ģ����ܵÿ���ɶ�ǳ��ɣ��Ͱ�L--R֮�����ǳ��Ȱ�
        for (k = L; k <= R; k++)  //����߿�ʼ�Ƚϣ���������û�к�Ҫ��������ȵ�
        {
            // printf("%d %d\n",L,R);
            if (s[k] == s[R + 1])  //�Ի������������˵,�����������˾͸���
            {
                //  printf("%c\n",s[R+1]);
                if (curlen > maxlen)   //��ǰ���ȱ�֮ǰ�Ĵ���
                {
                    maxlen = curlen;
                }

                L = k + 1;           //k�Ƿ����ظ�����˵�
                curlen = R - L + 1; //��˵��ƶ������һ�³���
                break;      //���for��������ˣ���һ��curlen++��S[R+1]�����������ˡ�
            }
        }
    }
    //��ط�Ҳ��Ѿ����ˣ�������Щ��ǰ�ĳ��ȺͶ������󳤶ȣ�˭����˭��
    if (curlen > maxlen)    
        return curlen;
    else
        return maxlen;
}

int main()
{
    //char s1[MAXSIZE];
    //scanf("%s\n",s1);  //scanf�����ո��Ͽ�������,���λ�ò�Ҫ��\n,��������
    //printf("%s %c\n",s1,s1[2]);  //

    //char st[3];
    //printf("input string:\n");
    //scanf("%s",st);
    //printf("�������%s\n",st);
    printf("��������Ĳ������� abcabcbb    bbbbbb  pwwkew");
    char* s;
    s = (char*)malloc(sizeof(char));
    //scanf("%s",s);  //�����˿ո�
    
    printf("%s\n", s);

    printf("����������ֱ��������%d\n", lengthOfLongestSubstring1(s));//pointer,p

    printf("�������ڣ�С��㣩��%d��\n", lengthOfLongestSubstring2(s));//pointer,p
    return 0;
}
//֪����������ģ��α����
//��ʼ�����ڶ˵�L��R��һ��LΪ0��RΪ1
//��ʼ������ֵ
//for (R = 0; R < len; R++)
//{
//    if ״̬�������� :
//        ��ѡ�ĸ�������ֵ��λ��
//
//    if R == len(Array) : # ��ѭ���������ƶ�������ĩβ��������ֹͣ����������Ϊ֮���Ѿ������п��ܵĽ�
//        break
//    while L < R:
//    ����״̬    # �ƶ���˵㣬��Ҫ����״̬
//        L += 1
//        if ״̬����������
//            ��ѡ�ĸ�������ֵ��λ��
//            else��  # һ�������������䲻������������������ȥ�ƶ��Ҷ˵�
//            break
//}
//��ѡ�Ķ���L��R�˵�ĺ�������
//return ����ֵ

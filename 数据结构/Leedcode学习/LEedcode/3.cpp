
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
/*
算法理解:
①哈希表的作用:没出现过的字符都是0,字符出现就会赋值为其字符下标+1(if第二次出现的更新的意义:远端(重复)数字的下一位)
②start初始化为0,每次更新为近端重复数字的下一位,再继续延伸滑动区间右端
*/
//哈希+滑动(稍微复杂)
//int lengthOfLongestSubstring(char* s) {
//    int i, count = 0, start = 0, index[128] = { 0 }, max = 0;
//    for (i = 0; s[i] != '\0'; i++)
//    {
//        if (index[s[i]] > start)
//        {
//            count = i - start;  //滑动区间长度
//            if (count > max)
//                max = count;
//            start = index[s[i]]; //start理解成从哪一个字符开始计算字串长度,start的更新因为出现了重复,因此赋值为重复字符下一个字符的下标
//        }
//        index[s[i]] = i + 1;    //将这个字母的值设置的比start大,并且指向它下一个字符的地址,这样在它赢了之后给start赋值时start也自然就从下一个开始
//    }
//    count = i - start;
//    return max > count ? max : count;
//}

//单纯滑动
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
                    max = max > (j-i) ? max : j-i;  是破坏约束条件后左移k之前的更新
                    i = k+1;
                }
            }
            max = max > (j-i+1) ? max : j-i+1;      这里是每次扩张窗口后,发现没有破坏约束后的更新
        }
        return max;
    }
};
*/

//小鹏
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000

/*
超时示例
ASCII码字符可以使用一个字节来表示，
有效取值范围为0~127，总共128个字符。
解题思路为：
定义一个128字节大小char型数组，数组初始化为0。
*/
int allUnique(char* s, int i, int j)
{
    char flag[128]; //ASC码只有0-127
    int ret = 0;
    memset(flag, 0, sizeof(flag)); //复制为0;
    for (; i <= j; i++)
    {
        if (flag[*(s + i)])
        {
            ret = 1; //有重复
            break;
        }
        else
        {
            flag[*(s + i)] = 1;     //没出现过就赋值,再出现就重复
        }
    }
    return ret;
}

//贪心算法
int lengthOfLongestSubstring1(char* s)
{
    int length = 0;
    int n = strlen(s);  //原始有多长
    //printf("%d\n",n);
    int i, j;
    //遍历所有的子字符串，记录没有重复字母的子字符串的最大的长度
    //获取子字符串时，使用两个标签，分别代表子字符串的开头和结尾
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
            //当子字符串没有重复字母时，ans记录最大的长度
            if (!allUnique(s, i, j))    //检验有没有重复
            {
                length = (length > (j - i + 1) ? length : (j - i + 1));
                //  printf("%d  %d----------  %d\n",i,j,length);
            }
        }

    }
    return length;

}

/*1.需要输出或比较的结果在原数据结构中是连续排列的（字符串中的连续不重复子串，数组中的连续元素最大和）
2. 每次窗口滑动时，只需观察窗口两端元素的变化，无论窗口多长，每次只操作两个头尾元素，当用到的窗口比较长时，可以显著减少操作次数
*/
int lengthOfLongestSubstring2(char* s)
{
    int L = 0, R = 0, k;
    int maxlen = 0;
    int curlen = 0;
    int n = strlen(s);
    if (n == 0)
        return 0;
    // for(; R < n &&(maxlen+L)<n; R++) //这个一开始想不到也很正常吧？算是优化？L+现在最大的都大于n了还用你算啥啊
    for (; R < n; R++)  //别光想着小姐姐雇佣雇佣的，目标是啥，是得循环完吧，
    {
        curlen++;  //右移一下，长度就+1，一开始就由一个长度了，求最长的，那总得看看啥是长吧，就把L--R之间算是长度吧
        for (k = L; k <= R; k++)  //从左边开始比较，这里面有没有和要进来的相等的
        {
            // printf("%d %d\n",L,R);
            if (s[k] == s[R + 1])  //对滑动窗口左边来说,不满足条件了就更新
            {
                //  printf("%c\n",s[R+1]);
                if (curlen > maxlen)   //当前长度比之前的大了
                {
                    maxlen = curlen;
                }

                L = k + 1;           //k是发生重复的左端点
                curlen = R - L + 1; //左端点移动后更新一下长度
                break;      //这个for就算完成了，下一个curlen++把S[R+1]带进来就行了。
            }
        }
    }
    //这地方也别费劲想了，就是这些当前的长度和定义的最大长度，谁最长输出谁吧
    if (curlen > maxlen)    
        return curlen;
    else
        return maxlen;
}

int main()
{
    //char s1[MAXSIZE];
    //scanf("%s\n",s1);  //scanf遇到空格会断开！！！,这个位置不要加\n,画蛇添足
    //printf("%s %c\n",s1,s1[2]);  //

    //char st[3];
    //printf("input string:\n");
    //scanf("%s",st);
    //printf("输出测试%s\n",st);
    printf("可以输入的测试数据 abcabcbb    bbbbbb  pwwkew");
    char* s;
    s = (char*)malloc(sizeof(char));
    //scanf("%s",s);  //处理不了空格
    
    printf("%s\n", s);

    printf("最容易理解的直白做法：%d\n", lengthOfLongestSubstring1(s));//pointer,p

    printf("滑动窗口（小姐姐）：%d：\n", lengthOfLongestSubstring2(s));//pointer,p
    return 0;
}
//知乎滑动窗口模板伪代码
//初始化窗口端点L，R，一般L为0，R为1
//初始化最优值
//for (R = 0; R < len; R++)
//{
//    if 状态满足条件 :
//        可选的更新最优值的位置
//
//    if R == len(Array) : # 若循环是由于移动到数组末尾结束，则停止整个程序。因为之后已经不再有可能的解
//        break
//    while L < R:
//    更新状态    # 移动左端点，需要更新状态
//        L += 1
//        if 状态满足条件：
//            可选的更新最优值的位置
//            else：  # 一旦窗口所在区间不再满足条件即跳出，去移动右端点
//            break
//}
//可选的对于L，R端点的后续处理
//return 最优值

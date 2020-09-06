#include<stdio.h>
#include<math.h>
//它是完全平方数
//又至少有两位数字相同，如144、676等。
//如果N满足条件，则该函数必须返回1，否则返回0。
#include <stdio.h>
#include <math.h> 
/*int IsTheNumber(const int N){			//返回值为0或1 
	int x,m,i;
	int a[10]={0};
	x=(int)sqrt(N); 					//x让N先开根号，若是完全平方数就可以无视前面的转换 
	m=x*x;								//错在这，条件一的判断 
	if(m==N){							// 条件一成立后继续执行 
		while(m>0){						//要取遍每一位的数 
			for(i=0;i<10;i++){			 
				if(m%10==i)				//在以每位数为下标的位置+1 
				a[i]++;			
				if(a[i]==2)				//若出现重复，直接return 1 
				return 1;		
			}
			m=m/10;
		}
	}
	return 0;							//有一个条件不满足就直接跳出 
} */

//计算非负整数阶乘的简单函数 
/*int Factorial( const int N ){
	int jie=1;
	int i=1;
	if(N>=0){
		for(i=1;i<=N;i++)
		{
			jie*=i;
		}
		return jie;
	}
	return 0;
}*/
//可统计任一整数中某个位数出现的次数。
#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
	
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}
int Count_Digit ( const int N, const int D ){
	int a[128]={0};
	int i;
	int m=N;
	m=N;
	if(m==0)	return 1;
	while(abs(m)>0){
		for(i=0;i<10;i++)
		{
			if(abs(m%10)==i)
			a[i]++;
		}
		m/=10;
	}
	return a[D];
}



											


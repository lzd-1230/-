#include<stdio.h>
#include<math.h>
//������ȫƽ����
//����������λ������ͬ����144��676�ȡ�
//���N������������ú������뷵��1�����򷵻�0��
#include <stdio.h>
#include <math.h> 
/*int IsTheNumber(const int N){			//����ֵΪ0��1 
	int x,m,i;
	int a[10]={0};
	x=(int)sqrt(N); 					//x��N�ȿ����ţ�������ȫƽ�����Ϳ�������ǰ���ת�� 
	m=x*x;								//�����⣬����һ���ж� 
	if(m==N){							// ����һ���������ִ�� 
		while(m>0){						//Ҫȡ��ÿһλ���� 
			for(i=0;i<10;i++){			 
				if(m%10==i)				//����ÿλ��Ϊ�±��λ��+1 
				a[i]++;			
				if(a[i]==2)				//�������ظ���ֱ��return 1 
				return 1;		
			}
			m=m/10;
		}
	}
	return 0;							//��һ�������������ֱ������ 
} */

//����Ǹ������׳˵ļ򵥺��� 
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
//��ͳ����һ������ĳ��λ�����ֵĴ�����
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



											


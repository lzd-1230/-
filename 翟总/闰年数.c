/*�ж�2000-2100�����Ƿ�Ϊ����  ����������������֮һ�ļ�Ϊ����
1���ܱ�4���������ܱ�100����
2���ܱ�100�������ܱ�400����
ע���������������궼�ܱ�4���������Բ��ܱ�4������һ���������꣡ */
#include<stdio.h>
int main()
{   printf("����������Ҫ�ж��������ֹ���(ע���������֮����Ͽո�Ŷ~)��"); 
	int year,year1;
	scanf("%d %d",&year,&year1); 
	int cnt=0;
	int t=0; 
	for(;year<=year1;year++){
	
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				printf("%d  ",year);
				cnt++;
				t++;
			}
		}else{
			printf("%d  ",year);
			cnt++;
			t++;
		}
	}
	if(cnt==5){printf("\n");
	cnt=0;
	 
	}
	}
	printf("\n�ܼ�������Ϊ��%d",t); 

return 0;	
}
 

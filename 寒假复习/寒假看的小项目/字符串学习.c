#include<stdio.h>
#include<string.h>
//�ַ�������ַ���������
//���ַ�����ĳ�ʼ�����Ӹ�0
//eg��char a[]={'1','2',0}; ������Ϊ�ַ���
//def����0��β�Ľ�β��һ���ַ�
/*�ַ����������巽�� ����˫���������������ַ������ţ�	
			��char *a="hello!";             ���������⣡ 
			��char word[]="hello";
			��char word[10]="hello"; */
//�ַ������ġ����ڵ��ַ�������������ڴ�������ֻ����д
//�����޸��ַ�����Ӧ�����ַ��������ʽ����
//���������Ҫ����һ���ַ����������飬���Ҫ����һ���ַ�������ָ�� 

//���·�ת����Ӣ�� 
/*int main(){
	int i,m;
	char yue[12][10];
	for(i=0;i<12;i++){
		scanf("%s",yue[i]);
	}
	scanf("%d",&m);
	printf("%s",yue	[m-1]);
	return 0;
}*/
 
//�ַ����������Իس��ո�tabΪ�ֽ�
//scanf��%����s�����ֱ�ʾ�������󲻳�����ֵ�������˾Ͷ��� 
//������һ���ַ���ָ�벢���㿪��һ���ַ�����Ҫ��ʼ��

/*�ַ�����
��char **a	��aΪһ��ָ�룬aָ��һ��bָ�룬bָ��*/

//strlen����strlen(const char*p)�����ַ����ĳ���(������0) 
//����strlen���� 
/*int diy(char *p){
	int cnt=0;
	while(p[cnt]!='\0'){
		cnt++;
	}
		return cnt;
	}
	

int main(){
	char s[]="hello!";
	printf("%lu\n",strlen(s));
	printf("%d",diy(s));
	return 0;
}*/ 
//����strcmp���� 
/*int mys(const char*s1,const char*s2){
	int i=0,t;
	while(s1[i]||s2[i]!='\0')		{
		if(s1[i]==s2[i]){
			i++;
		}
		else {
			t=s1[i]-s2[i];
			break;
		}
	}return t;
}
int main(){
	char s1[]="abc";
	char s2[]="Abc";
	printf("%d",mys(s1,s2));
	return 0;
}
*/ 
//��ʦ�� (ָ��) 
/*int mys(const char*s1,const char*s2){
	while(*s1==*s2&&*s1!='\0'){
		s1++;
		s2++;
	}  return *s1-*s2;
}
int main(){
	char s1[]="ab";
	char s2[]="ab ";
	printf("%d",mys(s1,s2));
	return 0;
}*/ 
//����crp����
//������� 
/*void mycrp(char *dst,const char *srp){
		int i=0;
		while(srp[i]!='\0'){
			dst[i]=srp[i];
			i++;
		}dst [i]='\0';	
} return dst;
//��ָ��� 
char *mycrp(char *dst,const char *srp){
	char *ret=*dst;
		while(*srp!='\0'){
			*dst++=*srp++;
		}*dst='\0';	
		return ret;
}  
int main(){
	char *s="hello";
	char *d=(char*)malloc(strlen(s)+1);
	mycrp(d,s);
	//strcpy(d,s);
	printf("%s",d);
	return 0;
	
}*/ 


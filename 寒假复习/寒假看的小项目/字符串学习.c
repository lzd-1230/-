#include<stdio.h>
#include<string.h>
//字符数组和字符串的区别
//在字符数组的初始化最后加个0
//eg：char a[]={'1','2',0}; ——称为字符串
//def：已0结尾的结尾的一串字符
/*字符串常量定义方法 ：用双引号括起来（以字符数组存放）	
			①char *a="hello!";             ！！！特殊！ 
			②char word[]="hello";
			③char word[10]="hello"; */
//字符常量的“”内的字符串被单独存放在代码区，只读不写
//若想修改字符串则应该用字符数组的形式定义
//！！！如果要构造一个字符串就用数组，如果要处理一个字符串则用指针 

//把月份转换成英文 
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
 
//字符串的输入以回车空格tab为分界
//scanf“%数字s”数字表示输入的最大不超过该值，超过了就丢掉 
//单定义一个字符型指针并不算开辟一个字符串，要初始化

/*字符串数
①char **a	：a为一个指针，a指向一个b指针，b指针*/

//strlen函数strlen(const char*p)返回字符串的长度(不包含0) 
//自制strlen函数 
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
//自治strcmp函数 
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
//老师版 (指针) 
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
//自制crp函数
//①数组版 
/*void mycrp(char *dst,const char *srp){
		int i=0;
		while(srp[i]!='\0'){
			dst[i]=srp[i];
			i++;
		}dst [i]='\0';	
} return dst;
//②指针版 
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


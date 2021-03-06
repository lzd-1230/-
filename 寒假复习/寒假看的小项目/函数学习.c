//lzd函数
/*
一.def:一块代码接受若干个值，返回一个或0个值

二.用处：减少出现代码复制的情况，功能模块化

三.定义方法：
	①在main前就写好功能，采用函数头+函数体的方式
	②在manin后的话就需要在main前先声明
		定义时应该写名函数返回类型和引用的参数类型 

四.函数调用
	函数名(参数值)		 
	就算没有函数值也要加括号

五.return 
	返回一个函数类型的数据 	
	！！作用:停止函数的执行，并返回值

六.函数原型
	总希望一开始看到main()，所以把函数头拷贝到前面去声明
	函数原型()中参数可以只写类型，不写名字，因为机器根本不关心变量名 
	 
七.参数传递
	①可以传递表达式的结果
		max(max(1,2),6);
		max(2+3,6);
	
	②类型转换
		大->小 	表面上看上去很人性化，但很可能造成数据损失
	
	传过去的是什么？ 
		只是值，每个函数有自己的参数空间，与其他函数的变量无关
	
	本地变量 
		只是一次函数所独有的变量
		生存期和作用域统一：在大括号内
		
		规则:块外面定义，块里面还存在
			块里面定义，块外面就没了
			c语言中，块内的变量可以覆盖块外的同名变量
			本地变量不会默认初始化 
	
	参数表中没有参数时
		表明()中不知道参数类型
		编译器会猜是int，因此函数原型不要这么写
	
	调用函数时的，不表示逗号运算符
	
	 
		 






#include<stdio.h>
	/*void cheer(){            //()表示前面是一个函数而不是有一个变量 
	printf("cheer");
}
int main(){
	cheer();				//调用函数的时候一定要（） 
	return 0;
}	*/ 
//return最好用单一出口，方便修改
//c的编译器自上而下分析你的代码所以最好最开始就定义函数 
//一般习惯在main函数前声明所用自己的函数即声明函数原型 
//类型的自动转换有些时候不是好事 
//c语言调用函数的时候只能传值过去，参数间没有其他练习
//若函数原型 					


//本地变量的生存期和作用域在块内，出了块就没有该变量了 
//在块外面的变量到里面还有效（若块内定义了与块外重名的变量） 
//调用函数就是进到那个函数的变量空间，调用结束后该函数的空间就没有了


//用数组作为函数参数的时候往往要用另一个变量表示数组大小sizeof(a)/sizeof(a[0])

//头文件(编译预处理指令)将文件内的文本内容原封不动的复制过来 
//c语言的编译器会默认将标准库函数产生的执行文件和我们自己写的执行文件串起来
//使用时有头文件，编译器帮你检查你调用的参数类型是否正确
//定义时有头文件，帮你检查你要调用的和你定义的类型是否正确 

声明：告诉编译器有这个东西，不产生代码 
	全局变量的声明
	eg：extern int i;
		表示在这个项目的某个地方有一个i;
	
	

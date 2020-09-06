#include <iostream>
#include <iomanip>	
using namespace std;

int main()
{
	//任务一:setw和setfill
	//setw默认使用空格填充	setfill在前边填充
	cout << setw(10) <<setfill('#')<< left << "a"<<endl;	//输出内容左对齐	

	//直角三角形
	//cout << setfill('#');	//注意要单引号
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << setw(i) << '\n' ;		//setw(0)等于没用
	//}
	
	//任务二:setprecision、fixed、showpoiont、left、right
	double pi{ 3.1415926535897 };
	cout << setprecision(4) << pi << endl;	//总共4位
	cout << setprecision(4) << fixed << pi << endl;	//小数点后4位
	double y{ 3.0 };
	cout << y << endl;	//之前设置的4位小数仍然成立
	cout << defaultfloat << y << endl;	//舍弃小数
	cout << showpoint << y << endl;		//打开小数
	cout << setw(20) << setfill('#') << left << y << endl;
	cout << setw(20) << setfill('#') << right << y << endl;
	//任务三：hexfloat(以16进制展现浮点数)

}

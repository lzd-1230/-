#include <iostream>
#include<fstream>
#include<filesystem>
#include<string>
namespace fs = std::filesystem;
using namespace std;
/*
任务1:读文件
	1.创建输入流,打开score.txt
	2.用>>从文件读取数据

任务2:用fail()检测文件是否打开

任务3:将文件放入循环使用eof()作为循环条件
*/
int main()
{
	fs::path p{ "score.txt" };
	ifstream input{ p };	//

	if (!input.fail())			//如果打开没有失败,才进入
	{
		string name{ "" };		
		double score{ 0.0 };
		char x;
		//while (!input.get(x).eof())		//没读完内容,循环继续
		//{
			input >> name >> score;
			
			cout << name << " " << score << endl;
		/*	cout << x;
		}*/
	}
	else	//打开失败了提示
		cout << "文件打开失败" << endl;
}

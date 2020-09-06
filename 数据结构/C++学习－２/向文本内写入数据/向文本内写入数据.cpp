#include <iostream>
#include<fstream>
#include<filesystem>
using namespace std;
namespace fs = std::filesystem;
int main()
{
	//path类对象用来保存地址,可以利用类中函数方便操作
	fs::path p{"output.txt"};	

	ofstream output{ p };		//定义
	double score1{ 90.5 };
	double score2{ 91.5 };
	output << "lzd1" <<" "<< score1 << endl;
	output << "lzd2" <<" "<< score2 << endl;
	output.close();
	cout << "文件大小:" << fs::file_size(p) << endl;

}

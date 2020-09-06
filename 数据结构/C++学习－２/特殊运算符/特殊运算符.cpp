#include<string>
#include <iostream>
#include<filesystem>
using namespace std;
int main()
{
	namespace fs = std::filesystem;
	//生字符串方式
	fs::path p1{ R"(C:\temp)" };
	fs::path p2{ R"(C:\temp)" };
	fs::path p3{};
	//正斜杠
	fs::path p4{ "C:/" };
	//append和/=等效		都是在路径后面再追加
	p1.append(R"(users)");
	p1 /= R"(cyd)";
	cout << p1 << endl;

	//concat和+= 
	p2.concat(R"(users)");
	p2 += R"(cyd)";
	cout << p2 << endl;
	//用/拼凑出一个新的路径
	p3 = p3 / R"(C:\temp)" / R"(users)" / R"(cyd)";
	cout << p3 << endl;
	//space获取磁盘大小
	cout << "c盘总大小为:" << fs::space(p4).capacity << endl;
	cout << "c盘可用的空间为:" << fs::space(p4).free << endl;
}


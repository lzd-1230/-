#include<filesystem>
#include<string>
#include <iostream>

int main()
{
	namespace fs = std::filesystem;
	//用正斜杠字符串定义路径
	fs::path p{ "E:/文件集/C语言/数据结构/C++中类的声明和定义/path class/todo.txt"};

	//输出默认文件分隔符(/正斜杠92)
	std::cout << "该系统分隔符为:" << fs::path::preferred_separator << std::endl;

	//是否是常规文件,是就输出文件大小
	if (fs::is_regular_file(p))
		std::cout <<"file's size is:"<< fs::file_size(p) << std::endl;

	//是目录是就输出子目录
	else if (fs::is_directory(p))
	{
		std::cout << p << "is a directory includes:" << std::endl;
		for (auto e : fs::directory_iterator(p))
			std::cout << e.path() << std::endl;
	}

	//是否存在
	else if (fs::exists(p))
		std::cout << p << "is a special file\n";
	else
		std::cout << p << "dose not exist" << std::endl;
}

#include<filesystem>
#include<string>
#include <iostream>
using namespace std;
int main()
{
    namespace fs = std::filesystem;
    //定义路径
    fs::path p{ "E:/文件集/C语言/数据结构/C++中类的声明和定义/分解路径成分/分解路径成分.cpp" };
    //是否为空   是否存在
    if(p.empty())
    {
        cout << "路径为空" << endl;
    }
    if (!fs::exists(p))
    {
        cout << "路径不存在" << endl;
        exit(-1);
    }
    //输出 根名 根路径 相对路径
    cout << "根名为:" << p.root_name() << "\n"
        << "根路径为:" << p.root_path() << "\n"
        << "相对路径为" << p.relative_path() << "\n" << endl;
    //父路径 文件名 文件名主干 扩展名
    cout << "父路径" << p.parent_path() << "\n"
        << "文件名" << p.filename() << "\n"
        << "文件名主干" << p.stem() << "\n"
        << "扩展名" << p.extension() << endl;
}


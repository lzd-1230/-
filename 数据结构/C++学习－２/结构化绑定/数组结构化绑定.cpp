
#include <iostream>
#include<array>
int main()
{
//原生数组
	//int a[]{ 1,2,3 };
	//auto [a1, a2, a3] {a};
	//std::cout << a1 << " " << a2 << " " << a3 << std::endl;

	//const auto [b1, b2, b3] {a};
	//b1 = 3;		不能赋值

	//auto& [c1, c2, c3] {a};
	//c1 = 10;
	//std::cout << a[0] << std::endl;
//模板数组
	std::array<int,3> b{ 4,5,6 };
	auto [a4, a5, a6] {b};
	std::cout << a4 << " " << a5 << " " << a6 << std::endl;
	auto& [b4, b5, b6] {b};
	b4 = 10;
	std::cout << b[0] << std::endl;
}


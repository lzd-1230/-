#include<iostream>
#include <vector>
using namespace std;
int main()
{
//创建vector对象words1
	vector<string> words1{ "Hello","world","welcome","to","c" };

//删除最后一个元素
	words1.erase(words1.end() - 1);		//erase是删除下标的后面一个位置上的元素
	cout << "words: ";
	for (int i = 0 ; i < words1.size(); i++)
	{
		cout <<words1[i] << " ";
	}
	cout << "\n---------------------" << endl;
//在尾部追加一个元素
	words1.push_back("C++");
	cout << "words: ";
	for (int i = 0; i < words1.size(); i++)
	{
		cout << words1[i] << " ";
	}
	cout << "\n---------------------" << endl;
//用迭代器拷贝创建words2
	 vector<string> words2(words1.begin()+2,words1.end());
	 cout << "words2: ";
	 for (int i = 0; i < words2.size(); i++)	//看清楚是谁的size
	 {
		 cout << words2[i] << " ";
	 }
	 cout << "\n---------------------" << endl;
//在words2中插入元素
	 words2.insert(words2.begin(), "Hello!");
	 cout << "words2: ";
	 for (int i = 0; i < words2.size(); i++)
	 {
		 cout << words2[i] << " ";
	 }
	 cout << "\n---------------------" << endl;
//多个重复的字符
	 vector<string> words3{ 3, "C++!" };
	 cout << "words3: ";
	 for (int i = 0; i < words3.size(); i++)
	 {
		 cout << words3[i] << " ";
	 }
	 cout << "\n---------------------" << endl;
//交换words3和wors2
	 words3.swap(words2);

	 cout << "words2: ";
	 for (int i = 0; i < words2.size(); i++)
	 {
		 cout << words2[i] << " ";
	 }
	 cout << "\n---------------------" << endl;

	 cout << "words3: ";
	 for (int i = 0; i < words3.size(); i++)
	 {
		 cout << words3[i] << " ";
	 }
	 cout << "\n---------------------" << endl;
}
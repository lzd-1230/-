#include<string>
#include <iostream>
using namespace std;
class A {
public:
    virtual string toString()//没有virtual关键字输出的全都是A
    {
        return "A";
    }
};

class B :public A {
public:
    string toString() override//重定义虚函数
    {
        return "B";
    }
};

class C :public A{
public:
    string toString() override//重定义虚函数
    {
        return "C";
    }
};
//基类指针和基类引用都可以把派生类的隐式转化为基类
void print(A* p) { cout << p->toString() << endl; }
void print(A& o) { cout << o.toString() << endl; }
int main()
{
    
    A a; B b; C c;
    A* pa = &a;
    A* pb = &b;
    A* pc = &c;
    print(pa);
    print(pb);
    print(pc);
    //输出A B C
    print(a);
    print(b);
    print(c);
    //输出A B C
}

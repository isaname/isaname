#include<iostream>
using namespace std;
int first(){
    return 10;
}
bool secend(){
    return false;
}
int main(){
    int (*first_point)()=first;//这样声明一个函数指针
    bool (*secend_point)()=secend;
    //使用函数指针调用函数
    //方法一：
    cout<<(*first_point)()<<endl;
    //方法二：
    cout<<secend_point()<<endl;
}
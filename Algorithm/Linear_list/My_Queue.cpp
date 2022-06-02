#include<iostream>
using namespace std;
class node{
private:
public:
    int val;
    node* next;
    node(){}
    node(const int a):val(a){}
};
//决定使用链表实现一个队列
class my_queue{
private:
    unsigned int size;//队列长度
    node * head;//头指针
    node * tail;//尾指针
public:
    //使用默认构造函数初始化
    my_queue(){
        //创建头节点
        node headnode(-1);
        head=&headnode;
        tail=head;
        size=0;
    }
    void push(int a){
        //压栈
        node temp(a);
        tail->next=&temp;
        tail=&temp;
        size++;
        //cout<<head<<" "<<tail<<endl;
    }
    int pop(){
        cout<<head<<" "<<tail<<endl;
        //出队
        if(size==0){
            cout<<"error no element in the myqueue!"<<endl;
            return 0;
        }
        int tar=head->val;
        head=head->next;
        size--;
        return tar;

    }
};
int main(){
    //不妨来测试一下
    my_queue test;

    test.push(12);
    cout<<test.pop()<<endl;
    cout<<test.pop()<<endl;
}
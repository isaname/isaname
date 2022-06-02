#include<vector>
#include<iostream>
using namespace std;
int main(){
    std::vector<int> a(10);
    for(int i=0;i<10;i++){
        a.push_back(i);
    }
    cout<<a.size()<<endl;
}
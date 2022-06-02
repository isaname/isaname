#include <iostream>
#include<vector>
#include<string>
using namespace std;
void showvector(vector<int>& a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> a;
    for(int i=0;i<10;i++){
        a.push_back(i);
    }
    showvector(a);
    for(int j=0;j<10;j++){
        a[j]=10-j;
    }
    showvector(a);
    cout<<("hello"<"hello")<<endl;
    return 0;

}
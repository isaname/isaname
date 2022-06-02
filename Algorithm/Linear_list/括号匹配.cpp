#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string str;
    cin>>str;
    vector<char> stack;
    int last=-1;//保存下标
    for(size_t i=0;i<str.size();i++){
        if(last==-1){
            stack.push_back(str[i]);
            last++;
        }else{
            if(stack[last]=='{'&&str[i]=='}'){
                last--;
                stack.pop_back();

            }
            else if(stack[last]=='['&&str[i]==']'){
                last--;
                stack.pop_back();
            }
            else if(stack[last]=='('&&str[i]==')'){
                last--;
                stack.pop_back();
            }else if(stack[last]=='<'&&str[i]=='>'){
                last--;
                stack.pop_back();
            }else{
                stack.push_back(str[i]);
                last++;
            }
        }
    }
    if(last==-1)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
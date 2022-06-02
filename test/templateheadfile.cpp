#include"template.h"
#include<iostream>
int main(){
    base<int> a;

    std::cout<<a.add_base(12,12)<<std::endl;
    return 0;
}
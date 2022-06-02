#include<set>
using namespace std;
bool compareInt(const int& l,const int& r){
    return l<r;
}
int main(){
    multiset<int,decltype(compareInt)*> se(compareInt);
    return 0;
}
#include<iostream>
using namespace std;
int solution[5];
bool use[5] = {false};

void backtrack(int n) {
    if (n == 5) {
        //processing solution
        for(int i = 0; i < n; ++i)
            cout << solution[i] << " ";
        cout << endl;
        return;
    } else
    {
        //列举{0,1,2,3,4}所有可能的值
        for (int i = 0; i < 5; ++i) {
            if (!use[i]) {
                use[i] = true;
                solution[n] = i;
                backtrack(n+1); //进入到下一个维度
                use[i] = false;
            }
        }
    }
}

int main()
{
    backtrack(0);
    return 0;
}
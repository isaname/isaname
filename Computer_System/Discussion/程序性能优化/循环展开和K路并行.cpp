#include <iostream>
using namespace std;
void combine5(double data[], int length)
{
    double sum = 0.0;
    for (int i = 0; i < length; i++)
    {
        sum *= data[i];
    }
    cout << sum << endl;
}
void combine6(double data[], int length)
{
    double sum = 0.0;
    int limit = length - 1;
    int i;
    for (i = 0; i < limit; i += 2)
    {
        sum = sum * data[i] * data[i + 1];
    }
    for (; i < length; i++)
    {
        sum *= data[i];
    }
    cout << sum << endl;
}
void combine7(double data[], int length)
{
    double sum1 = 0.0, sum2 = 0.0;
    int limit = length - 1;
    int i;
    for (i = 0; i < limit; i += 2)
    {
        sum1 *= data[i];     // 合并下标为偶数的值， 0按偶数算
        sum2 *= data[i + 1]; // 合并下标为奇数的值
    }
    double sum = sum1 * sum2;
    for (; i < length; i++)
    {
        sum *= data[i];
    }
    cout << sum << endl;
}
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

inline int findpivot(int *A, int i, int j)
{
    return (i + j) / 2;
}
inline int Partition(int *A, int left, int right, int &pivot)
{
    do
    {
        while (A[++left] < pivot)
            ;
        while ((left < right) && (pivot < A[--right]))
            ;
        swap(A[left], A[right]);
    } while (left < right);
    return left;
}
void qsort(int *A, int left, int right)
{
    if (right > left)
    {
        int i = left+1;
        int j = right;
        int key = A[left];
        int temp;
        bool fg=false;
        while (i < j)
        {

            //要区分找成功和未找成功: 左边找到比key大，右边找到比key小
            while (i <= j && A[i] <= key)
                i++; //停下来时,i指向的值大于key;
            if (i > j)
            {
                //说明j之前的所有的元素均比key小，所以直接放到j的位置
                swap(A[left], A[j]);
                temp = j;
                fg=true;
                break;
            }

            while (i < j && A[j] > key)
                j--; //停下来时,j指向的值小于key;

            if (i >= j)
            {
                //说明所有i-1之后的元素均比key大，所以直接放到i-1的位置
                swap(A[left], A[i - 1]);
                temp = i - 1;
                fg=true;
                break;
            }

            swap(A[i], A[j]);
        } //跳出循环时,i和j相等
        swap(A[left], A[i]);
        if(!fg)temp=j;
        qsort(A,left,temp-1);
        qsort(A,temp+1,right);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *a;
    a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    qsort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
    return 0;
}

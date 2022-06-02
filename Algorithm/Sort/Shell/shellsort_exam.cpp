#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;

void inssort(int *A, int n, int incr)
{
    for (int i = incr; i < n; i += incr)
        for (int j = i; (j >= incr) && (A[j] < A[j - incr]); j -= incr)
            swap(A[j], A[j - incr]);
}

void shellsort(int *A, int n)
{
    int h=1;
    while(h<n/3)h=h*3+1;
    while(h>=1){
        inssort(A,n,h);
        h/=3;
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

    shellsort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
    return 0;
}
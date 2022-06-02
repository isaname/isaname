int aprod(int a[], int n) {

int i, x, y, z;

int r = 1;

for (i = 0; i<n-2; i+=3) {

x=a[i];

y=a[i+1];

z=a[i+2];

r=x*y*z;

 }

    for (; i < n; i++)

      z=z*a[i];

    return r;
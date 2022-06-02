int saturating_add (int a,int b){
    if(a/2+b/2>=2147483647/2)return 2147483647;
    if(a/2+b/2<=-2147483648/2)return 2147483648;
    return a+b;
}
int uadd_ok(unsigned int a,unsigned int b){
    if(a/2+b/2>=2147483648)return 0;
    return 1;
}
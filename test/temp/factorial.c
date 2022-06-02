int factorial(int a){
    if(a==1)return 1;
    if(a==2)return 1;
    return factorial(a-1)+factorial(a-2);
}
int f(int a,int b,int c,int n){
    if(a==0)return((b/c)*(n+1));
    if(a>=c||b>=c)return f(a%c,b%c,c,n)+(a/c)*n*(n+1)/2+(b/c)*(n+1);
    int m=(a*n+b)/c;
    return n*m-f(c,c-b-1,a,m-1);
}
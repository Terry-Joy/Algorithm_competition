#include<bits/stdc++.h>
using namespace std;
typedef double db;
int n,k,d,s;
int main(){
    scanf("%d%d",&n,&k);
    scanf("%d%d",&d,&s);
    int del=n*d-k*s;
    if(del<0){
        puts("impossible");return 0;
    }else{
        db x=1.0*del/(n-k);
        if(x>100||x<0){
            puts("impossible");return 0;
        }else{
            printf("%.9f\n",x);
        }
    }
    return 0;
}
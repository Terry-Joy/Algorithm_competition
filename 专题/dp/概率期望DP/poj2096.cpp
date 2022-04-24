#include<iostream>
#include<cstdio>
using namespace std;
int n,s;
double dp[1005][1005];
int main(){ 
    scanf("%d%d",&n,&s);
    for(int i=n;i>=0;--i){ 
        for(int j=s;j>=0;--j){ 
            if(i==n&&j==s)continue;
            dp[i][j]=(dp[i+1][j]*1.0*(n-i)*j+dp[i][j+1]*1.0*(i*(s-j))+dp[i+1][j+1]*1.0*(n-i)*(s-j)+n*s)/(n*s-i*j);
        }
    }
    printf("%.4f",dp[0][0]);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100],cnt,dp[400];
int main(){
    int n;
    for(int i=1;i*i<=300;++i){
        a[++cnt]=i*i;
    }
    dp[0]=1;
    for(int i=1;i<=cnt;++i){
        for(int j=a[i];j<=300;++j){
            dp[j]+=dp[j-a[i]];
        }
    } 
    while(~scanf("%d",&n)&&n){
       cout<<dp[n]<<"\n";     
    }  
    return 0;
}
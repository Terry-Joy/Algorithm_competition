#include<bits/stdc++.h>

using namespace std;
int a[100],n;
int main(){ 
    int mx=-2e9;
    for(int i=1;i<=n;++i){ 
        if(dp[i-1]>0)dp[i]=dp[i-1]+a[i];
        else dp[i]=a[i];
        if(dp[i]>mx)mx=dp[i];
    }
}

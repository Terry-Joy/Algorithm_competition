#include<bits/stdc++.h>

using namespace std;
int dp[2050];
const int mod=1e9+7;
int main(){
    int n;
    cin>>n;
    dp[0]=1;
    for(int i=3;i<=n;++i)
        for(int j=3;j<=i;++j){
            dp[i]+=dp[i-j];
            if(dp[i]>=mod)dp[i]-=mod;
        }
    cout<<dp[n]<<endl;
    return 0;
}
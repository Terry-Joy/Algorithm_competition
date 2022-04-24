#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[100];
int n;
int main(){
    dp[1]=1;dp[2]=2;dp[3]=3;
    dp[4]=4;
    for(int i=5;i<=80;++i)
        dp[i]=dp[i-1]+dp[i-3];
    while(cin>>n&&n){
        cout<<dp[n]<<endl;
    }
    return 0;
}
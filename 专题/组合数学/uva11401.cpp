#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
ll dp[maxn];
void init(){ 
    dp[4]=1;
    for(int i=5;i<maxn;++i)dp[i]=dp[i-1]+(i/2-1);
    for(int i=4;i<maxn;++i)dp[i]+=dp[i-1];
}
int main(){ 
    init();
    int n;
    while(~scanf("%d",&n)&&n>=3){ 
        if(n==3)puts("0");
        else cout<<dp[n]<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int t,n,dp[maxn],cnt[maxn],a[maxn],l[maxn],r[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>n;
    for(int i=1;i<=n;++i){ 
        cin>>a[i];
        if(!l[a[i]])l[a[i]]=i;
        r[a[i]]=i;
    }
    for(int i=n;i>=1;--i){
        cnt[a[i]]++;
        dp[i]=dp[i+1];
        if(i==l[a[i]])dp[i]=max(dp[i],cnt[a[i]]+dp[r[a[i]]+1]);
        else dp[i]=max(dp[i],cnt[a[i]]);
    }
    cout<<n-dp[1]<<"\n";
    return 0;
}

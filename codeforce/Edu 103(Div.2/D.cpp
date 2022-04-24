#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=3e5+5;
int t,n,dp[maxn][2];
char s[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n;
        cin>>(s+1);
        for(int i=1;i<=n+1;++i)dp[i][0]=dp[i][1]=i;
        for(int i=1;i<=n+1;++i){ 
            if(i==1||s[i-1]=='R')dp[i][0]=i;
            else if(i==2||s[i-2]=='L')dp[i][0]=i-1;
            else dp[i][0]=dp[i-2][0];
        }
        for(int i=n+1;i;--i){ 
            if(i==n+1||s[i]=='L')dp[i][1]=i;
            else if(i==n||s[i+1]=='R')dp[i][1]=i+1;
            else dp[i][1]=dp[i+2][1];
        }
        for(int i=1;i<=n+1;++i){ 
            cout<<dp[i][1]-dp[i][0]+1<<" ";
        }
        cout<<"\n";
    } 
    return 0;
}

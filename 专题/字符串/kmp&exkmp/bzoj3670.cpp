#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
const int mod=1e9+7;
int dp[maxn],n,nxt[maxn];//dp[i]表示[1,i]的border数量
char s[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        ll ans=1;
        scanf("%s",s+1);
        int len=strlen(s+1),li=len/2;
        dp[1]=1;
        for(int i=2,j=0;i<=len;++i){
            while(j&&(s[i]!=s[j+1]))j=nxt[j];
            if(s[i]==s[j+1])j++;
            nxt[i]=j;
            dp[i]=dp[j]+1;
        }
        for(int i=2,j=0;i<=len;++i){
            while(j&&s[i]!=s[j+1])j=nxt[j];
            if(s[i]==s[j+1])j++;
            while((j<<1)>i&&j)j=nxt[j];
            ans=ans*(dp[j]+1)%mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
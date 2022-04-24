#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5005;
const ll mod=1e9+7;
ll dp[maxn][62][62];
int len1,len2,m,g[maxn],a[maxn],t;
char s1[maxn],s2[maxn];
ll dfs(int pos,int sum,int del,bool limit){
    if(pos==-1)return !del;
    if(!limit&&dp[pos][sum][del]!=-1)return dp[pos][sum][del];
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;++i){
        ans+=dfs(pos-1,(sum+i)%m,((del+i*sum-i*g[pos])%m+m)%m,i==up&&limit);
    }
    while(ans>=mod)ans-=mod;
    if(!limit)dp[pos][sum][del]=ans;
    return ans;
}
ll solve(char s[],int n){
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            for(int k=0;k<m;++k)
                dp[i][j][k]=-1;
    for(int i=0;i<n;++i)
        a[i]=s[n-1-i]-'0';
    return dfs(n-1,0,0,1);
}
int main(){
    scanf("%d",&t);
    g[0]=1;
    while(t--){
        scanf("%s%s%d",s1,s2,&m);
        len1=strlen(s1);
        len2=strlen(s2);
        s1[len1-1]--;
        for(int i=len1-1;i>=0;--i){
            if(s1[i]<'0'){
                s1[i]+=10;
                s1[i-1]--;
            }else break;
        }
        for(int i=1;i<=len2;++i){
            g[i]=g[i-1]*10%m;
        }
        cout<<((solve(s2,len2)-solve(s1,len1))%mod+mod)%mod<<"\n";
    }
    return 0;
}
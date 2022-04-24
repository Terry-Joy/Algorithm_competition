#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=32;
const ll mod=1e9+7;
int a[maxn],b[maxn],pos1,pos2,t;
ll dp[2][2][2][32];
ll dfs(int pos,bool mx,bool limit1,bool limit2){
    if(pos==-1)return 1;
    if(dp[mx][limit1][limit2][pos]!=-1)return dp[mx][limit1][limit2][pos];
    int up1=limit1?a[pos]:1,up2=limit2?b[pos]:1;
    ll ans=0,len=0;
    for(int i=0;i<=up1;++i){
        for(int j=0;j<=up2;++j){
            if(i&j)continue;
            if(mx&&(i||j))len=pos+1;
            else len=1;
            ans+=dfs(pos-1,mx&&i==0&&j==0,limit1&&i==up1,limit2&&j==up2)*len%mod;
            if(ans>=mod)ans-=mod;
        }
    }
    return dp[mx][limit1][limit2][pos]=ans;
}
ll solve(int x,int y){
    memset(dp,-1,sizeof(dp));
    pos1=0,pos2=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    while(x){
        a[pos1++]=x&1;
        x>>=1;
    }
    while(y){
        b[pos2++]=y&1;
        y>>=1;
    }
    return dfs(max(pos1-1,pos2-1),1,1,1);
}
int main(){
    scanf("%d",&t);
    while(t--){
        int i,j;
        scanf("%d%d",&i,&j);
        cout<<(solve(i,j)-1+mod)%mod<<"\n";
    }
    return 0;
}
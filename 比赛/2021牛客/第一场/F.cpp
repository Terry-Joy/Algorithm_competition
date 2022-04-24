#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=90;
ll dp[maxn][2][2][2][3];
int a[maxn];
ll dfs(int pos,bool limit,bool is0,bool is1,bool is2,int sum){
    if(pos==-1&&is0)return 1;
    if(!limit&&dp[pos][is0][is1][is2][sum]!=-1)return dp[pos][is0][is1][is2][sum];
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;++i){ 
        int nxt=(sum+i)%3;
        bool f=(is2||(nxt==0&&is2)||(nxt==1&&is1)||(nxt==2&&is0));
        ans+=dfs(pos-1,limit&&(i==up),is0||(nxt==0||(nxt==1&&is1)||(nxt==2&&is2)),is1||(nxt==1&&is0)||(nxt==2&&is1)||(nxt==1&&is0),f,nxt);
    }
    if(!limit)dp[pos][is0][is1][is2][sum]=ans;
    return ans;
}
ll solve(ll x){ 
    int pos=0;
    while(x){ 
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,1,0,0,0,0);
}
int main(){ 
    int t;
    scanf("%d",&t);
    while(t--){ 
        ll l,r;
        scanf("%lld%lld",&l,&r);
        cout<<solve(r)-solve(l-1);
    }
    return 0;
}

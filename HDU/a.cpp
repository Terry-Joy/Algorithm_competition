
#pragma GCC optimize(2)
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define PI atan(1.0) * 4
#define E 2.718281828
#define rp(i, s, t) for (register int i = (s); i <= (t); i++)
#define RP(i, t, s) for (register int i = (t); i >= (s); i--)
#define ll long long
#define ull unsigned long long
#define mst(a, b) memset(a, b, sizeof(a))
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define debug printf("ac\n");
using namespace std;
inline int read()
{
    int a = 0, b = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            b = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        a = (a << 3) + (a << 1) + c - '0';
        c = getchar();
    }
    return a * b;
}
const ll mod = 1e9+7;
int a[20],num;
ll fac[20];//预处理10的幂次
struct node{
    ll cnt;//与7无关的数的个数
    ll sum;//与7无关的数的和
    ll sqr;//与7无关的数的平方和。
    node(int c=0,int s=0,int ss=0):cnt(c),sum(s),sqr(ss){}
    // node():{}
}dp[20][20][20];
node dfs(int pos,int pre1,int pre2,int lead,int limit){
    if(pos==-1) return node(pre1!=0&&pre2!=0);
    if(!lead&&!limit&&dp[pos][pre1][pre2].cnt!=-1) return dp[pos][pre1][pre2];
    int up=limit?a[pos]:9;
    node ans;
    rp(i,0,up) {
        if(i==7) continue;
        node tmp=dfs(pos-1,(pre1+i)%7,(pre2*10+i)%7,lead&&i==0,limit&&i==a[pos]);
        //简单数位dp求与7无关的数的个数
        ans.cnt=(tmp.cnt+ans.cnt)%mod;
        //求与7无关的数的和
        //处理到第pos个数位时，加上i*10^pos * 后面的个数
        ans.sum=(ans.sum+tmp.sum+tmp.cnt*fac[pos]%mod*i%mod)%mod;//相当于给后面数位的每个数都加上一个i*10^pos
        //求与7无关的数的平方和
        //(pre*10^pos + next)^2= (pre*10^pos)^2+2*pre*10^pos*next +next^2
        ans.sqr=(ans.sqr+tmp.sqr+2*i%mod*fac[pos]%mod*tmp.sum%mod)%mod;
        ans.sqr=(ans.sqr+(tmp.cnt*fac[pos]%mod*fac[pos]%mod*i%mod*i%mod))%mod;
    }
    if(!limit&&!lead) return dp[pos][pre1][pre2]=ans;
    return ans;
}
ll solve(ll x){
    num=0;
    while(x) a[num++]=x%10,x/=10;
    return dfs(num-1,0,0,1,1).sqr;
}
int main(){
    mst(dp,-1);
    int T=read();
    ll l,r;
    fac[0]=1;
    rp(i,1,19) fac[i]=fac[i-1]*10%mod;
    rp(i,0,19) rp(j,0,19) rp(k,0,19) dp[i][j][k].cnt=-1;
    while(T--){
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",((solve(r)-solve(l-1))%mod+mod)%mod);
    }
    return 0;
}

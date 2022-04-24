#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long 
using namespace std;
const ll MOD=1000000007ll ;

struct Node
{
    ll cnt;//与7无关的数的个数
    ll sum;//与7无关的数的和
    ll sqsum;//平方和
}dp[20][10][10];//分别是处理的数位、数字和%7,数%7
int a[20];
ll p[20];//p[i]=10^i

Node dfs(int pos,int sum,int mod,bool limit)
{
    if(pos==-1)
    {
        Node tmp;
        tmp.cnt=(sum!=0 && mod!=0);
        tmp.sum=tmp.sqsum=0;
        return tmp;
    }
    if(!limit && dp[pos][sum][mod].cnt!=-1)
        return dp[pos][sum][mod];
    int end=limit?a[pos]:9;
    Node ans;
    Node tmp;
    ans.cnt=ans.sqsum=ans.sum=0;
    for(int i=0;i<=end;i++)
    {
        if(i==7)continue;
        tmp=dfs(pos-1,(sum+i)%7,(mod*10+i)%7,limit&&i==end);
        ans.cnt+=tmp.cnt;
        ans.cnt%=MOD;
        ans.sum+=(tmp.sum+ ((p[pos]*i)%MOD)*tmp.cnt%MOD )%MOD;
        ans.sum%=MOD;

        ans.sqsum+=(tmp.sqsum + ( (2*p[pos]*i)%MOD )*tmp.sum)%MOD;
        ans.sqsum%=MOD;
        ans.sqsum+=( (tmp.cnt*p[pos])%MOD*p[pos]%MOD*i*i%MOD );
        ans.sqsum%=MOD;
    }
    if(!limit)dp[pos][sum][mod]=ans;
    return ans;
}
ll solve(ll x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,0,0,1).sqsum;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    ll l,r;
    p[0]=1;
    for(int i=1;i<20;i++)
        p[i]=(p[i-1]*10)%MOD;
    for(int i=0;i<20;i++)
        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
                dp[i][j][k].cnt=-1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",(solve(r)-solve(l-1)+MOD)%MOD);
    }
    return 0;
}

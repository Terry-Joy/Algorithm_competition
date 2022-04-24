#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;
bool v[maxn];
int phi[maxn],cnt=0,prime[maxn],n,m,num,p[10],sum,i;
ll ans;

void init()
{
    v[1]=v[0]=1;phi[1]=1;
    for(int i=2;i<=maxn-9;++i)
    {
        if(!v[i])phi[i]=i-1,prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<=maxn-9;++j)
        {
            v[prime[j]*i]=1;
            if(i%prime[j]==0)
            {
                phi[prime[j]*i]=phi[i]*prime[j];
                break; 
            } 
            else phi[prime[j]*i]=phi[prime[j]]*phi[i];
        } 
    } 
}
void dfs(int pos,int lcm,int id)
{
    if(id==0)
    {
       if(i&1)num+=(m/lcm);
       else num-=(m/lcm); 
       return;
    }
    if(pos>sum)return;
    if(lcm*p[pos]<=m)
        dfs(pos+1,lcm*p[pos],id-1);
    dfs(pos+1,lcm,id);
    return;
}
int getans(int k)
{
    for(int i=2;i*i<=k;++i)
    {
       if(k%i==0){ 
          p[++sum]=i;   
          while(k%i==0)k/=i; 
       }
    } 
    if(k>1)p[++sum]=k;
    for(i=1;i<=sum;++i)
        dfs(1,1,i);
    return m-num;
}
int main()
{
    init(); 
    int t;
    scanf("%d",&t);
    while(t--)
    { 
        scanf("%d%d",&m,&n);
        ans=1;
        if(m>n)swap(n,m);
        for(int i=2;i<=m;++i)
            ans+=2ll*phi[i];
        for(int i=m+1;i<=n;++i)
        { 
            num=sum=0;
            ans+=getans(i);
        }
        printf("%lld\n",ans);
    }
    return 0; 
}

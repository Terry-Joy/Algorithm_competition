#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=250005;
ll n,k,a[maxn],fac[maxn];
int cnt;
bool kill[maxn];
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a; 
}
int main()
{ 
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=k;++i)
        scanf("%lld",&a[i]);
    a[k]=gcd(a[k],n);
    for(int i=1;i<k;++i)
        a[i]=gcd(a[k],a[i]);
    for(ll i=1;i*i<=a[k];++i)
        if(a[k]%i==0)
        { 
            fac[++cnt]=i;
            if(i!=a[k]/i)fac[++cnt]=a[k]/i; 
        }
    sort(fac+1,fac+cnt+1);
    for(int i=1;i<k;++i)
        kill[lower_bound(fac+1,fac+1+cnt,a[i])-fac]=1;
    for(int i=1;i<=cnt;++i)
    {
        if(kill[i])
        {
            for(int j=1;j<i;++j)
                if(fac[i]%fac[j]==0)
                    kill[j]=1; 
        } 
    }
    for(int i=1;i<=cnt;++i)
        if(!kill[i])
        {
            printf("%lld\n",n/fac[i]); 
            return 0;
        }
}   

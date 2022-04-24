#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<stack>
#define ll long long
using namespace std;
const int maxn=1e7/2;
const int mod=1e9+7;
ll f[maxn];
ll sum[maxn];
int main()
{  
    int n;  
    scanf("%d",&n);
    f[0]=1,f[2]=3,f[3]=11;
    for(int i=2;i<=n/2;++i)
    {
       sum[i]=(sum[i-1]+f[i-2])%mod;
       f[i]=(3*f[i-1]+2*sum[i])%mod; 
    }
    if(n&1)
        puts("0");
    else
        printf("%lld\n",f[n/2]%mod);
    return 0;
}

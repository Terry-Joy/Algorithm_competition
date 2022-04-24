#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long 
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
       	ll ans=1,t=log2(n);
       	for(int i=0;i<t;++i)
       		ans=ans*((1<<i)+1)%m;
       	ans=ans*(n-(1<<t)+2)%m;
       	ans=(ans-1+m)%m;
       	printf("%lld\n",ans);
    }
    return 0; 
}

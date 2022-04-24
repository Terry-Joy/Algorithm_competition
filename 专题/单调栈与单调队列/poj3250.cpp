#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=8e4+5;
int st[maxn],a,t;
int main()
{
   int n,t=0;
   ll ans=0;
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
   {
       scanf("%d",&a);
       while(t>0&&st[t]<=a)t--;
       ans+=t;
       st[++t]=a;
   } 
   printf("%lld\n",ans);
   return 0; 
}

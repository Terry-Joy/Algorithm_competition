#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;
const int maxn=1e5+10;
int a[maxn],c[maxn],ll[maxn],n,lb[maxn];
void add(int x)
{ 
    for(;x<=n;x+=x&-x)c[x]++;
}
int ask(int x)
{
   int ans=0;
   for(;x;x-=x&-x)ans+=c[x];
   return ans; 
}
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
       scanf("%d",&a[i]); 
   for(int i=1;i<=n;++i)
   {
        ll[i]+=ask(a[i]-1);
        add(a[i]);
   }
   for(int i=1;i<=n;++i)
       printf("%d\n",1+ll[i]);
   return 0; 
}

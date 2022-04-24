#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
bool cmp(int a,int b){ 
    return a>b;
}
const int maxn=2e5+5;
int a[maxn];
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;++i)
      scanf("%d",&a[i]);
   ll ans=0;
   sort(a+1,a+1+n,cmp);
   ans+=a[1];
   for(int i=3;i<=n;++i)
      ans+=a[(i+1)/2];
   printf("%lld\n",ans); 
   return 0; 
}

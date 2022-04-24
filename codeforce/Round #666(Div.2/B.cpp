#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
const ll INF=1e14;
int a[maxn];
int main()
{
   int t,n;
      scanf("%d",&n);
      ll ans=INF,s=0;
      for(int i=1;i<=n;++i)scanf("%d",&a[i]),s+=a[i];
      sort(a+1,a+1+n);
      int limit=pow(INF,1.0/n);
      for(ll i=1;i<=limit;++i){ 
        ll loc=llabs(1-a[1]),k=1;
        for(int j=2;j<=n;++j){ 
            k*=i;loc+=llabs(a[j]-k);
            if(loc>ans)break;
        }
        ans=min(ans,loc);
      }
      printf("%lld",ans);
   return 0; 
}

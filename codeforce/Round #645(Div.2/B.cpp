#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       int n;
      scanf("%d",&n);
      for(int i=1;i<=n;++i)
         scanf("%d",&a[i]);
      sort(a+1,a+1+n);
      int ans=1;
      for(int j=n;j>=1;--j)
      {
         if(j>=a[j])
         {
            ans=j+1; 
            break;
         }
      }
      printf("%d\n",ans);
    }
   return 0; 
}

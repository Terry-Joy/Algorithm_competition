#include<bits/stdc++.h>

using namespace std;
const int maxn=2e5+10;
const int maxm=1e6;
int a[maxn];
bool flag[maxm+5];
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
      scanf("%d",&a[i]);
   sort(a+1,a+n+1);
   int ans=0;
   for(int i=1;i<=n;++i)
   {
      if(flag[a[i]]==0)
      {
         if(a[i]!=a[i+1])
            ans++; 
       
      for(int j=1;a[i]*j<=maxm;++j)
          flag[a[i]*j]=1;
      }
   } 
   printf("%d\n",ans);
   return 0; 
}

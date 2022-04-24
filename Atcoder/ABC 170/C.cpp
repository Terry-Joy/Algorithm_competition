#include<bits/stdc++.h>

using namespace std;
const int maxn=102;
int a[maxn];
int main()
{
   int x,n;
   cin>>x>>n;
   int b;
   for(int i=1;i<=n;++i)
   {
      cin>>b;
      a[b]++; 
   } 
   int ans=0;
   int minn=100;
   for(int i=0;i<102;++i)
   {
      if(!a[i])
      {
         if(minn>abs(i-x))
         {
            ans=i;
            minn=abs(i-x); 
         } 
      } 
   }
   cout<<ans<<endl;
   return 0; 
}

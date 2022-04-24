#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
   int n;
   scanf("%d",&n);
   int mx=-1,ans=0;
   for(int i=1;i<=n;++i)
   {
      int a;
      cin>>a;
      if(a>mx)
         mx=a;
      if(mx==i)
          ans++;
   }
   cout<<ans;
   return 0; 
}

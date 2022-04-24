#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#define ll long long
using namespace std;
map<ll,ll>mp;
int main()
{
   int n;
   cin>>n;
   ll ans=0;
   for(int i=0;i<n;++i)
   {
      int x;
      cin>>x;
      mp[x-i]+=x; 
   }
   for(auto x:mp)ans=max(ans,x.second);
   cout<<ans<<"\n";
   return 0; 
}

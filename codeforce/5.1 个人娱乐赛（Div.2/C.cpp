#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#define ll long long 

using namespace std;
map<string,int>mp;
int n,a[20];
char s[10];
int main()
{
   mp["red"]=1,mp["yellow"]=2,mp["green"]=3,mp["brown"]=4,mp["blue"]=5,mp["pink"]=6,mp["black"]=7;
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
   {
      scanf("%s",s);
      a[mp[s]]++;
   }
   int mos=1;
   for(int i=2;i<=7;++i)
       if(a[i])mos=i;
   int ans=0;
   if(mos==1)cout<<1;
   else { 
       ans=(1+mos)*a[1];
       for(int i=2;i<=7;++i)
          ans+=a[i]*i; 
       cout<<ans;
   }
   return 0; 
}

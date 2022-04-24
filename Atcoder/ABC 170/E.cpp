#include<bits/stdc++.h>

using namespace std;
const int maxn=2e5+10;
int a[maxn],zu[maxn];
multiset<int>s[maxn];
multiset<int>sm;
int main()
{
   int n,q;
   scanf("%d%d",&n,&q);
   for(int i=1;i<=n;++i)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      s[y].insert(x);
      zu[i]=y,a[i]=x; 
   } 
   for(int i=0;i<maxn;++i)
       if(s[i].size())
           sm.insert(*s[i].rbegin());
   for(int i=0;i<q;++i)
   {
      int c,d;
      scanf("%d%d",&c,&d);
      s[zu[c]].erase(s[zu[c]].find(a[c]));
      if(s[zu[c]].size()==0) 
          sm.erase(sm.find(a[c]));
      else if(*s[zu[c]].rbegin()<a[c])
      {
          
      }
   }
   return 0; 
}

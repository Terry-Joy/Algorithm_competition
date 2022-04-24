#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#define ll long long
const int maxn=2e5+10;
using namespace std;
int n,m,t;
vector<int>rel[maxn];
set<int>xs;
bool die[maxn],zl[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        xs.insert(i);
    for(int i=1;i<=m;++i)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       rel[a].push_back(b);
       rel[b].push_back(a); 
    }
    scanf("%d",&t);
    for(int j=1;j<=t;++j)
    {
       int x;
       scanf("%d",&x);
       die[x]=1;
       for(auto i:rel[x])
           zl[i]=1;
       if(!zl[x])
       {
          set<int>newxs;
          for(auto i:rel[x])
          {
             if(!die[i]&&xs.count(i))
                newxs.insert(i); 
          }
          xs=newxs;
       }
       else xs.erase(x);
       /*
        * for(auto i:rel[x])
        *   cout<<i<<" ";
        */
       if(xs.size()==1)
       {
          cout<<j<<" "<<(*xs.begin());
          return 0; 
       }
    }
    cout<<-1<<"\n";
    return 0;
}

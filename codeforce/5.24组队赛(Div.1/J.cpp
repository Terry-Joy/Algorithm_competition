#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<map>

using namespace std;
typedef long long ll;
vector<char>ans;
const int maxn=1e5+10;
bool vis[maxn];
   int n;
void dfs(int x)
{
   for(int i=0;i<2;++i)
   {
      int y=(2*x+i)%n;
      if(vis[y])continue;//欧拉回路
      vis[y]=1;
      dfs(y);//此处边点一致
      ans.push_back(i+'0'); 
   } 
}
int main()
{
   freopen("unique.in","r",stdin);
   int t;
   scanf("%d",&t);
   while(t--)
   {
       ans.clear();
       scanf("%d",&n); 
       for(int i=0;i<n;++i)
           vis[i]=0;
       vis[1]=1;
       dfs(1);
       reverse(ans.begin(),ans.end());
       putchar('1');
       for(auto&v:ans)putchar(v);
       putchar('\n');
   }
   return 0; 
}

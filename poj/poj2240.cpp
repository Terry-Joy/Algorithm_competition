#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<string>//×¢Òâdouble 
using namespace std;
const int N=35,M=2*N*N;
int head[N],ver[M],next1[M],tot,cnt[N],v[N],n;double edge[M],d[N];
map<string,int>mp;
void add(int x,int y,double z)
{
   ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
bool spfa()
{
    queue<int>q;
    memset(v,0,sizeof(v));
    memset(cnt,0,sizeof(cnt));
    memset(d,0,sizeof(d));
    d[1]=1,cnt[1]=0;
    q.push(1),v[1]=1;
    while(q.size())
    {
       int x=q.front();q.pop();
       v[x]=0;
      for(int i=head[x];i;i=next1[i])
      {
         int y=ver[i];double z=edge[i];
         if(d[y]<1.0*d[x]*z)
         {
            d[y]=1.0*d[x]*z;
            if(!v[y])
            {
               v[y]=1;
               q.push(y);
               if(++cnt[y]>=n)
                return true;
            }
         } 
      } 
    }
    return false;
}
int main()
{ 
    int k=1;
    while(~scanf("%d",&n)&&n)
    { 
        memset(head,0,sizeof(head));
        tot=0;
        string s;
        int num=0;
        for(int i=1;i<=n;++i)
        {
           cin>>s;
            mp[s]=++num; 
        }
        int f;
        cin>>f; 
        for(int i=1;i<=f;++i)
        {
           string s1,s2;
           double rate;
           cin>>s1>>rate>>s2;
           add(mp[s1],mp[s2],rate); 
        }
        if(spfa())
            printf("Case %d: Yes\n",k++);
        else 
            printf("Case %d: No\n",k++);
    }
    return 0;
}

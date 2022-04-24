#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=6010;
int fa[N],s[N];
struct Node
{
   int x,y,z; 
   bool operator<(const Node&a)const
   {
       return z<a.z;
   }
}edge[N];
int find(int x)
{
   if(x==fa[x])return x;
   return fa[x]=find(fa[x]); 
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<n;++i)
        {
           cin>>edge[i].x>>edge[i].y>>edge[i].z; 
        }
        sort(edge+1,edge+n);
        for(int i=1;i<n;++i)
            fa[i]=i,s[i]=1;
        ll ans=0;
        for(int i=1;i<n;++i)
        {
           int fx=find(edge[i].x);
           int fy=find(edge[i].y);
           if(fx==fy)continue;
           ans+=(edge[i].z+1)*(s[fx]*s[fy]-1);
           fa[fy]=fx;
           s[fx]+=s[fy]; 
        }
        cout<<ans<<"\n";
    }
    return 0;
}

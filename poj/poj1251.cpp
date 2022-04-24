#include<iostream>
#include<cstdio>
#include<algorithm>
struct Node{ 
    int x,y,z;
}edge[1000];
bool operator<(Node a,Node b)
{
   return a.z<b.z; 
}
using namespace std;
int fa[4000],n;
void init()
{
   
}
int find(int x)
{
   if(x==fa[x])return x;
   return fa[x]=find(fa[x]); 
}
int main()
{
    
    while(cin>>n&&n)
    {
    	for(int i=1;i<=n;++i)
      fa[i]=i; 
       char s1,e1;
       int k,len=0,d,ans=0;
       for(int i=1;i<=n-1;++i)
       {
            cin>>s1>>k;
            for(int j=1;j<=k;++j)
            {
               cin>>e1>>d;
               int e11=e1-64;int s11=s1-64;
               edge[++len].x=s11,edge[len].y=e11,edge[len].z=d; 
            }
       } 
       sort(edge+1,edge+len+1);
       for(int j=1;j<=len;++j)
       {
          int fx=find(edge[j].x);
          int fy=find(edge[j].y);
          if(fx==fy)continue;
          fa[fx]=fy;
          ans+=edge[j].z;
       }
       cout<<ans<<"\n";
    }
    return 0;
}

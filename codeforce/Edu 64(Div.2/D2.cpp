#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int maxn=2e5+10;
int f[maxn][2],size[maxn][2];
int find(int x,int k)
{
   if(f[x][k]==x)return x;
   return f[x][k]=find(f[x][k],k); 
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        f[i][1]=f[i][0]=i,size[i][0]=size[i][1]=1;
    for(int i=1;i<n;++i)
    {
       int a,b,c;
       scanf("%d%d%d",&a,&b,&c);
       int fx=find(a,c),fy=find(b,c);
       if(fx!=fy)
       {
           f[fy][c]=f[fx][c];
           size[fx][c]+=size[fy][c];
       } 
    }
    ll ans=0;
    for(int i=1;i<=n;++i)
    {
       int k1=find(i,0),k2=find(i,1);
       if(k1==i)ans+=1ll*size[i][0]*(size[i][0]-1);
       if(k2==i)ans+=1ll*size[i][1]*(size[i][1]-1);
       ans+=(ll)(size[k1][0]-1)*(size[k2][1]-1); 
    }
    cout<<ans<<"\n";
    return 0;
}

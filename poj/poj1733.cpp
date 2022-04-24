#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
const int N=2e4+5000;
int fa[N],road[N];
int find(int x)
{
    if(x==fa[x])return x;
    else { 
        int t=fa[x];
        fa[x]=find(fa[x]);
        road[x]^=road[t];
        return fa[x];
    } 
}
int Union(int a,int b,int d)
{ 
    int fx=find(a);
    int fy=find(b);
    if(fx==fy)
    {
        if(road[a]^road[b]!=d)
            return 0;
        else  
            return 1;
    }
    else
    {
        fa[fy]=fx;
        road[fy]=road[a]^d^road[b]; 
    }
    return 1;
}
int main()
{
    int gg=0;
    int n,m,d;
    scanf("%d%d",&n,&m);
    int flag=m;
    map<int,int>mp;

    mp.clear();
    int k=1,ans=0;
    for(int i=0;i<N-100;++i)
    {
        fa[i]=i;
        road[i]=0; 
    }
    for(int i=1;i<=m;++i)
    {
        int a,b;
        char s[20];
        scanf("%d%d%s",&a,&b,s);
        if(!mp[a-1]){ 
            mp[a-1]=k++;
        }    
        if(!mp[b]){ 
            mp[b]=k++;
        }
        if(s[0]=='e')
        {   
            d=0;
        }
        else d=1;
        if(!Union(mp[a-1],mp[b],d))
        {
           flag=i-1;
           break;
        }
    }
    printf("%d\n",flag);
    return 0;
}

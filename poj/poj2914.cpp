#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=520;
int fa[maxn],road[maxn],n,m;
struct Node
{
    int x,y;
    char c; 
}a[2010];
int find(int x)
{
    if(x==fa[x])return x;
    else
    {
        int t=fa[x];
        fa[x]=find(fa[x]);
        road[x]=(road[x]+road[t])%3;            //路径压缩时手算即可
        return fa[x]; 
    }
}
bool isCon(int x,int y,int d)
{
    int fx=find(x);
    int fy=find(y);
    if(fx==fy)
    {
        if((road[y]-road[x]+3)%3!=d)            //向量减法，加3防负数
            return false;
    } 
    else
    {
        fa[fy]=fx;
        road[fy]=(road[x]+d-road[y]+3)%3;       //菱形计算
    }
    return true;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    { 
        for(int i=0;i<m;++i)
        {
            scanf("%d%c%d",&a[i].x,&a[i].c,&a[i].y); 
        }
        int linem=0,num=0,id=0;
        for(int i=0;i<n;++i)
        {
            bool flag=1;
            int d=0;
            for(int k=0;k<n;++k)
            {
                fa[k]=k;
                road[k]=0; 
            }
            for(int j=0;j<m;++j)
            {
                if(i==a[j].x||i==a[j].y)continue;
                if(a[j].c=='<')
                    d=1;
                else if(a[j].c=='=')
                    d=0;
                else d=2;
                if(!isCon(a[j].x,a[j].y,d))
                {
                    flag=0;
                    linem=max(linem,j+1);//只要取不满足中最大的行数
                    break;
                }
            } 
            if(flag)
            {
                num++;
                id=i; 
            }
        }
        if(num==0)
            puts("Impossible");
        else if(num>1)
            puts("Can not determine");
        else if(num==1)
            printf("Player %d can be determined to be the judge after %d lines\n",id,linem);
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int M=1000007;
int n,k,i,j,a[35][100010],p,head[1000010],Next[100010],adj[35][100010],s,m,ans,l[100010];
void Push(int u,int i)//Hash插入
{
    int j;
    Next[++p]=head[u];
    head[u]=p;
    l[p]=i;
    for(j=1;j<=k;j++)
        adj[j][p]=a[j][i];
}
int main(){
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p);
        for(j=1;j<=k;j++)
            a[j][i]=a[j][i-1]+((p>>(j-1))&1);
    }
    p=0;
    Push(0,0);//注意第0天也要加进去
    for(i=1;i<=n;i++)
    {
        s=0;
        for(j=2;j<=k;j++)
            s=((s+a[j][i]-a[1][i])*j%M+M)%M;
        for(j=head[s];j!=0;j=Next[j])
        {
            for(m=2;m<=k;m++)
                if(adj[m][j]-a[m][i]!=adj[1][j]-a[1][i])
                    break;
            if(m>k)
            {
                ans=max(ans,i-l[j]);
                break;
            }
        }
        if(j==0)//如果i能找到与它相同的序列，就不要加了，只要最早的，要不然会WA
            Push(s,i);
    }
    printf("%d",ans);
}

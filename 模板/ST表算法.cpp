#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1e5+10;
int f[maxn][25];//[i,i+2^j-1]里的数的最大值
int a[maxn],Log[maxn];
int n,m,ans=0;
void RMQ(){//预处理
    for(int i=1;i<=n;++i)f[i][0]=a[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]); 
    Log[1]=0;
    for(int i=2;i<=n+1;++i)
        Log[i]=Log[i/2]+1; 
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    RMQ();
    for(int i=1;i<=m;++i){
        int l,r;
        scanf("%d%d",&l,&r);
        int k=Log[r-l+1];
        ans=max(f[l][k],f[r-(1<<k)+1][k]);
        printf("%d\n",ans);
    }
    return 0;
}

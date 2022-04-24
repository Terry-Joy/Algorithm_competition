#include<bits/stdc++.h>

using namespace std;
const int maxn=1e4+5;
double A[maxn],B[maxn],C[maxn];
double k[maxn],e[maxn];
double eps=1e-9;
int t,n,a,b,tot,deg[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1];
void add(int x,int y){ 
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot,deg[x]++;
}
bool dfs(int x,int fa){ 
    int m=deg[x];
    A[x]=k[x];
    double tmp=(1-k[x]-e[x])/m;
    B[x]=tmp;
    C[x]=(1-k[x]-e[x]);
    double sumA=0,sumB=0,sumC=0;
    for(int i=head[x];i;i=next1[i]){ 
        int y=ver[i];
        if(y==fa)continue;
        if(!dfs(y,x))return false;
        sumA+=A[y];sumB+=B[y];sumC+=C[y];
    }
    if(fabs(1-tmp*sumB)<eps)return false;
    A[x]=(A[x]+tmp*sumA)/(1-tmp*sumB);
    B[x]=B[x]/(1-tmp*sumB);
    C[x]=(C[x]+tmp*sumC)/(1-tmp*sumB);
    return true;
}
int main(){ 
    scanf("%d",&t);
    int cnt=0;
    while(t--){
        scanf("%d",&n);
        tot=0;
        for(int i=1;i<=n;++i)head[i]=0,deg[i]=0;
        for(int i=1;i<=n-1;++i){ 
            scanf("%d%d",&a,&b);
            add(a,b);add(b,a);
        }
        for(int i=1;i<=n;++i){ 
            scanf("%lf%lf",&k[i],&e[i]);
            k[i]/=100;e[i]/=100;
        }
        printf("Case %d: ",++cnt); 
        if(dfs(1,-1)&&fabs(1-A[1])>eps)
            printf("%.6lf\n",C[1]/(1-A[1]));
        else puts("impossible");
    }
    return 0;
}

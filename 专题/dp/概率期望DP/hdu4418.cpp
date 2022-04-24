#include<bits/stdc++.h>

using namespace std;
const int maxn=205;
const int INF=0x3f3f3f3f;
double a[maxn*2][maxn*2],p[maxn],tmp,ans[maxn*2];
double eps=1e-6;
int t,n,m,y,x,d;
bool vis[maxn];
bool bfs(){ //bfs是必要的 高斯消元假设走了无穷后E[i]能收敛，不跑bfs代表全部收敛，解不同
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(x);
    vis[x]=1;
    while(!q.empty()){ 
        int u=q.front();q.pop();
        for(int i=1;i<=m;++i){ 
            if(fabs(p[i])<eps)continue;
            if(!vis[(u+i)%n]){ 
                vis[(u+i)%n]=1;
                q.push((u+i)%n);
            }
        }
    }
    return vis[y]||vis[(n-y)%n];
}
void make(){ 
    memset(a,0,sizeof(a));
    for(int i=0;i<n;++i){ 
        a[i][i]=1;
        if(!vis[i]){ 
            a[i][n]=INF;continue;
        }
        if((i==y)||i==(n-y)%n){ 
            a[i][n]=0;continue;
        }
        a[i][n]=tmp;
        for(int j=1;j<=m;++j){ 
            a[i][(i+j)%n]-=p[j];
        }
    }
}
void swap(int x,int y){ 
    double t;
    for(int i=0;i<=n;++i){ 
        t=a[x][i];a[x][i]=a[y][i];
        a[y][i]=t;
    }
}
int gauss(){ //浮点数高斯消元真板子
    int r=n;
    double t;
    for(int i=0;i<n;++i){ 
        int pos=i;
        for(int j=i+1;j<n;++j)
            if(fabs(a[pos][i])<fabs(a[j][i]))pos=j;
        if(fabs(a[pos][i]<eps)){ 
            for(int j=i;j<n;++j)
                if(fabs(a[j][n])>=eps)return 0;
            r--;continue;
        }
        if(pos!=i)swap(pos,i);
        for(int j=i+1;j<n;++j){ 
            if(fabs(a[j][i])>=eps){ 
                t=a[j][i]/a[i][i];
                for(int k=i;k<=n;++k)
                    a[j][k]-=t*a[i][k];
            }
        }
    }
    for(int i=n-1;i>=0;--i){ 
        ans[i]=a[i][n]/a[i][i];
        for(int j=i-1;j>=0;--j){ 
            a[j][n]-=ans[i]*a[j][i];
        }
    }
    return r;
}
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        tmp=0;
        scanf("%d%d%d%d%d",&n,&m,&y,&x,&d);
        for(int i=1;i<=m;++i){ 
            scanf("%lf",&p[i]);
            p[i]/=100;
            tmp+=p[i]*i;
        }
        if(x==y){ 
            puts("0.00");continue;
        }
        n=2*(n-1);
        if(d==1)x=(n-x)%n;
        if(!bfs()){ 
            puts("Impossible !");continue;
        }else{ 
            make();
            if(!gauss())
                puts("Impossible !");
            else 
                printf("%.2lf\n",ans[x]);
        }
    }
    return 0;
}

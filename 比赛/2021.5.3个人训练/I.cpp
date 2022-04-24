#include<bits/stdc++.h>
using namespace std;
const int maxn=405;
int n,d[maxn],i,t[3][maxn],in[3][maxn][maxn],out[3][maxn][maxn];
bool f[3][maxn][maxn];
void init(int x,int s){
    int now=s,cost=0;
    for(int i=1;i<=n;++i){
        in[x][s][now]=cost;
        out[x][s][now]=cost+t[x][now];
        cost+=t[x][now]+d[now];
        now=(now+1)%n;
    }
}
bool check(int x,int s,int e){
    int y=(x+1)%3;
    for(int i=0;i<n;++i){
        if(out[x][s][i]<=in[y][e][i]||in[x][s][i]>=out[y][e][i])continue;
        return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&d[i]);
    for(int i=0;i<3;++i){
        for(int j=0;j<n;++j)
            scanf("%d",&t[i][j]);
    }
    for(int k=0;k<3;++k)
        for(int i=0;i<n;++i){
                init(k,i);
        }
    for(int k=0;k<3;++k){
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j){
                if(check(k,i,j))
                    f[k][i][j]=1;
            }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            for(int k=0;k<n;++k){
                if(f[0][i][j]&&f[1][j][k]&&f[2][k][i]){
                    cout<<i+1<<" "<<j+1<<" "<<k+1<<"\n";
                    return 0;
                }
            }
    }
    puts("impossible");
    return 0;
}
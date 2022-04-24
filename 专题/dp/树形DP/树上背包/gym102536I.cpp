#include<bits/stdc++.h>

using namespace std;
const int maxn=1e4+5;
const int INF=1e9;
vector<int>G[maxn];
int q,dpmn[maxn][maxn],dpmx[maxn][maxn],a,sz[maxn],b,c,n;
char s[maxn];
void dfs(int x,int fa){
    sz[x]=1;dpmn[x][1]=dpmx[x][1]=(s[x-1]=='C');
    for(auto&v:G[x]){
        if(v==fa)continue;
        dfs(v,x);
        for(int i=1;i<=sz[v];++i)dpmn[x][i+sz[x]]=INF;
        for(int j=sz[x];j;--j)//转移到0会造成错误转移
            for(int k=sz[v];k;--k){
                dpmn[x][j+k]=min(dpmn[x][j+k],dpmn[x][j]+dpmn[v][k]);
                dpmx[x][j+k]=max(dpmx[x][j+k],dpmx[x][j]+dpmx[v][k]);
            }
        sz[x]+=sz[v];
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a;
        if(a==0)continue;
        G[a].push_back(i);
        G[i].push_back(a);
    }
    cin>>s;
    dfs(1,-1);
    for(int i=1;i<=q;++i){
        cin>>a>>b>>c;
        c+=b;
        if(c<=sz[a]&&(b>=dpmn[a][c]&&b<=dpmx[a][c])){
            puts("COMPROMISED");
        }else puts("NOT COMPROMISED");
    }
    return 0;
}
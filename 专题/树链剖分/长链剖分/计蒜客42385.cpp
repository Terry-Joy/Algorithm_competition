#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef unsigned long long ull;
int head[maxn],ver[maxn<<1],next1[maxn<<1],tot,n,K,a[maxn],cnt[maxn][4],dfn[maxn],st[maxn],ti,k1,k2;
ull ans[maxn];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
struct LCD{
    int md[maxn],hson[maxn];
    void dfs1(int x,int f){
        for(int i=head[x];i;i=next1[i]){
            int y=ver[i];
            if(y==f)continue;
            dfs1(y,x);
            if(md[y]>md[hson[x]])hson[x]=y;
        }
        md[x]=md[hson[x]]+1;
    }
}lcd;
ull getS(int x,int k,int sta){
    if(k<lcd.md[x]-1)return cnt[dfn[x]][sta]-cnt[dfn[x]+k+1][sta];
    return cnt[dfn[x]][sta];
}
void dfs(int x,int f){//cnt[i]表示以i为根数字某两位状态的数量
    dfn[x]=++ti;
    cnt[dfn[x]][st[x]]++;
    if(lcd.hson[x]){
        dfs(lcd.hson[x],x);
        for(int i=0;i<4;++i)
            cnt[dfn[x]][i]+=cnt[dfn[lcd.hson[x]]][i];
    }
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||y==lcd.hson[x])continue;
        dfs(y,x);
        for(int j=0;j<4;++j)cnt[dfn[x]][j]+=cnt[dfn[y]][j];//短儿子更新dp
        for(int j=0;j<lcd.md[y];++j)
            for(int k=0;k<4;++k)//全部转移给长儿子链上,维护后缀和
                cnt[dfn[x]+j+1][k]+=cnt[dfn[y]+j][k];//长儿子链上cnt[i]维护dep>=i且x子树内的结点的和
    }
    for(int i=0;i<2;++i)ans[x]+=getS(x,K,i)*getS(x,K,3^i)<<(k1+k2);
}
int main(){
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    int x;
    for(int i=2;i<=n;++i){
        scanf("%d",&x);
        add(i,x);add(x,i);
    }
    lcd.dfs1(1,0);
    for(k1=0;k1<=29;++k1){
        for(k2=k1+1;k2<=29;++k2){
            for(int k=1;k<=n;++k){
                st[k]=0;
                if(a[k]&(1<<k1))st[k]|=1;
                if(a[k]&(1<<k2))st[k]|=2;
                for(int i=0;i<4;++i)cnt[k][i]=0;
            }
        	ti=0;
       		dfs(1,0);
        }
    }
    for(int i=1;i<=n;++i)ans[i]<<=1;
    for(k1=k2=0;k1<=29;k1++,k2++){
        for(int k=1;k<=n;++k){
            if(a[k]&(1<<k1))st[k]=3;
            else st[k]=0;
            for(int i=0;i<4;++i)cnt[k][i]=0;
        }
        ti=0;
        dfs(1,0);
    }
    for(int i=1;i<=n;++i)cout<<ans[i]<<'\n';
    return 0;
}

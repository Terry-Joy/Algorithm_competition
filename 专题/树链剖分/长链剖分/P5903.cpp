//树上k级祖先 O(nlogn)~O(1)
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
#define ui unsigned int
ui S;
inline ui get() {
	S ^= S << 13;
	S ^= S >> 17;
	S ^= S << 5;
	return S; 
}
int f[maxn][20],n,u,v,len[maxn],head[maxn],next1[maxn<<1],ver[maxn<<1],tot,hbit[maxn],m,lg[maxn];
vector<int>U[maxn],D[maxn];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}

struct LCD{
    int fa[maxn],dep[maxn],md[maxn],hson[maxn],top[maxn];//md[x]表示该点子树的最深深度
    void dfs1(int x,int fat){
        f[x][0]=fa[x]=fat;
        md[x]=dep[x]=dep[fat]+1;
        for(int i=1;i<=lg[dep[x]];++i)
            f[x][i]=f[f[x][i-1]][i-1];
        for(int i=head[x];i;i=next1[i]){
            int y=ver[i];
            if(y==fat)continue;
            dfs1(y,x);
            if(md[y]>md[hson[x]])hson[x]=y,md[x]=md[y];
        }
    }
    void dfs2(int x,int t){
        top[x]=t;
        len[x]=md[x]-dep[top[x]];//链长
        if(!hson[x])return;
        dfs2(hson[x],t);
        for(int i=head[x];i;i=next1[i]){
            int y=ver[i];
            if(y==fa[x]||y==hson[x])continue;
            dfs2(y,y);
        }
    }
    void init(int x){
        dfs1(x,0);dfs2(x,x);
    }
    int query(int x,int k){//x的k级祖先
        if(k>dep[x])return 0;
        if(!k)return x;
        x=f[x][hbit[k]];k^=(1<<hbit[k]);
        if(dep[x]-dep[top[x]]==k)return top[x];
        if(dep[x]-dep[top[x]]>k)return D[top[x]][dep[x]-dep[top[x]]-k-1];
        return U[top[x]][k-(dep[x]-dep[top[x]])-1];
    }
}lcd;
int main(){
    cin>>n>>m>>S;
    int rt=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&u);
        if(!u)rt=i;
        else{
            add(i,u);
            add(u,i);
        }
    }
    for(int i=1;i<=n;++i)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    lcd.init(rt);
    for(int i=1;i<=n;++i){
        if(i==lcd.top[i]){
            int l=0,x=i;
            while(l<len[i]&&x)x=f[x][0],++l,U[i].pb(x);
            l=0,x=i;
            while(l<len[i])x=lcd.hson[x],++l,D[i].pb(x);
        }
    }
    int mx=1;
    for(int i=1;i<=n;++i){
        if((i>>mx)&1)++mx;
        hbit[i]=mx-1;
    }
    ll ans=0;
    int preans=0;
    for(int i=1;i<=m;++i){
        u=(get()^preans)%n+1,v=(get()^preans)%lcd.dep[u];
        preans=lcd.query(u,v);
        ans^=1ll*i*preans;
    }
    cout<<ans;
    return 0;
}
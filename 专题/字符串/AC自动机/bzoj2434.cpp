#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
char s[maxn];
vector<int>G[maxn],G2[maxn];
vector<pair<int,int>>Q[maxn];
vector<int>pos[maxn];
int dfn[maxn],ti,sz[maxn];
int ans[maxn];
struct AC{ 
    int tr[maxn][26],pre[maxn],cnt,num,ed[maxn],fail[maxn];
    void insert(char *s){ 
        int now=0,len=strlen(s);
        for(int i=0;i<len;++i){ 
            if(s[i]=='P')ed[++num]=now,pos[now].pb(num);
            else if(s[i]=='B')now=pre[now];
            else{ 
                int ch=s[i]-'a';
                if(!tr[now][ch])tr[now][ch]=++cnt,pre[cnt]=now,G2[now].pb(cnt);
                now=tr[now][ch];
            }
        }
    }
    queue<int>q;
    void build(){ 
        for(int i=0;i<26;++i)
            if(tr[0][i])q.push(tr[0][i]);
        while(!q.empty()){ 
            int x=q.front();q.pop();
            for(int i=0;i<26;++i){ 
                if(tr[x][i])fail[tr[x][i]]=tr[fail[x]][i],q.push(tr[x][i]);
                else tr[x][i]=tr[fail[x]][i];
            }
        }
        for(int i=cnt;i>=1;--i)G[fail[i]].pb(i);
    }
}ac;
struct BIT{
    #define lowb(x) (x&(-x))
    int M,c[maxn];
    void init(int x){ 
        M=x+1;
    }
    void add(int x,int val){
       for(int i=x;i<=M;i+=lowb(i))
           c[i]+=val;
    }
    int query(int x){ 
        int ans=0;
        for(int i=x;i;i-=lowb(i))ans+=c[i];
        return ans;
    }
}bit;
void dfs(int x){ 
    dfn[x]=++ti;
    sz[x]=1;
    for(auto&v:G[x]){ 
        dfs(v);
        sz[x]+=sz[v];
    }
}
void dfs2(int x){
    bit.add(dfn[x],1); 
    for(auto&u:pos[x]){ 
        for(auto&v:Q[u]){ 
            ans[v.fi]+=bit.query(dfn[ac.ed[v.se]]+sz[ac.ed[v.se]]-1)-bit.query(dfn[ac.ed[v.se]]-1);
        }
    }
    for(auto&v:G2[x]){ 
        dfs2(v);
    }
    bit.add(dfn[x],-1);
}
int main(){
    int m,l,r;
    scanf("%s",s);
    ac.insert(s);
    ac.build();
    dfs(0);
    scanf("%d",&m);
    for(int i=1;i<=m;++i){ 
        scanf("%d%d",&l,&r);
        Q[r].pb({i,l});
    }
    bit.init(ac.cnt+1);
    dfs2(0);
    for(int i=1;i<=m;++i)cout<<ans[i]<<"\n";
    return 0;
}

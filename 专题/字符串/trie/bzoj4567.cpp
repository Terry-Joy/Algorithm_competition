#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=510005;
int tr[maxn][26],cnt,n,pre[maxn],sz[maxn],ti;
ll ans;
bool f[maxn];
char s[100005];
vector<int>G[maxn];
void insert(){ 
    int now=0,len=strlen(s+1);
    for(int i=1;i<=len;++i){ 
        int ch=s[i]-'a';
        if(!tr[now][ch])tr[now][ch]=++cnt;
        now=tr[now][ch];
    }
    f[now]=1;
}
bool cmp(int x,int y){ 
    return sz[x]<sz[y];
}
void rsort(int x){ 
    sz[x]=1;
    for(auto&v:G[x]){ 
        rsort(v);
        sz[x]+=sz[v];
    }
    sort(G[x].begin(),G[x].end(),cmp);
}
void rebuild(int x){ 
    if(f[x]&&x)
        G[pre[x]].pb(x),pre[x]=x;
    for(int i=0;i<26;++i){ 
        if(tr[x][i]){ 
            pre[tr[x][i]]=pre[x];
            rebuild(tr[x][i]);
        }
    }
}
void dfs(int x,int now,int fa){ 
    ti++;
    ans+=now-fa;
    for(auto&v:G[x]){ 
        dfs(v,ti+1,now);
    }
}
int main(){ 
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%s",s+1);
        reverse(s+1,s+1+strlen(s+1));
        insert();
    }
    f[0]=1;
    rebuild(0);
    rsort(0);
    dfs(0,1,1);
    cout<<ans;
    return 0;
}

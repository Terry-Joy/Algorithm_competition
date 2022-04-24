#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const int INF=2e9;
int n;
char s[maxn];
struct AC{ 
    int tr[maxn][2],cnt,fail[maxn],f[maxn];
    bool ed[maxn],in[maxn],vis[maxn];
    void insert(char *s){ 
        int now=0,len=strlen(s);
        for(int i=0;i<len;++i){ 
            int ch=s[i]-'0';
            if(!tr[now][ch])tr[now][ch]=++cnt;
            now=tr[now][ch];
        }
        ed[now]=1;
    }
    queue<int>q;
    void build(){ 
        for(int i=0;i<2;++i){ 
            if(tr[0][i])q.push(tr[0][i]);
        }
        while(!q.empty()){ 
            int x=q.front();q.pop();
            for(int i=0;i<2;++i){ 
                if(tr[x][i]){ 
                    fail[tr[x][i]]=tr[fail[x]][i],q.push(tr[x][i]);
                    ed[tr[x][i]]|=ed[tr[fail[x]][i]];
                }else
                    tr[x][i]=tr[fail[x]][i];
            }
        }
    }
    int dp(int x){ 
        if(in[x]){ 
            puts("-1");exit(0);
        }
        if(vis[x])return f[x];
        vis[x]=1;
        in[x]=1;
        if(!ed[x]){ 
            f[x]=0;
            for(int i=0;i<2;++i){ 
                f[x]=max(f[x],dp(tr[x][i])+1);
            }
        }else f[x]=-INF;
        in[x]=0;
        return f[x];
    }
    void solve(){ 
        int now=0,len=f[0];
        while(len){ 
            for(int i=0;i<2;++i){ 
                int nxt=tr[now][i];
                if(f[nxt]==-INF)continue;
                if(f[nxt]+1==f[now]){ 
                    cout<<i;
                    len--;
                    now=nxt;
                    break;
                }
            }
        }
    }
}ac;
int main(){
    cin>>n;
    for(int i=0;i<n;++i)cin>>s,ac.insert(s);
    ac.build();
    ac.dp(0);
    ac.solve();
    return 0;
}

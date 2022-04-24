#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int maxn=605;
const int maxm=(1<<12)+5;
int n;
char s[60];
struct AC{ 
    int tr[maxn][26],fail[maxn],st[maxn],fa[maxn*maxm],tot,pos[maxn*maxm],cnt;
    bool vis[maxn][maxm];
    void insert(char*s,int bit){ 
        int now=0,len=strlen(s);
        for(int i=0;i<len;++i){ 
            int ch=s[i]-'A';
            if(!tr[now][ch])tr[now][ch]=++cnt;
            now=tr[now][ch];
        }
        st[now]|=(1<<(bit-1));
    }
    queue<int>q;
    queue<pair<int,int>>q1;
    void build(){ 
        for(int i=0;i<26;++i){ 
            if(tr[0][i])q.push(tr[0][i]);
        }
        while(!q.empty()){ 
            int x=q.front();q.pop();
            for(int i=0;i<26;++i){ 
                if(tr[x][i]){ 
                    fail[tr[x][i]]=tr[fail[x]][i];
                    q.push(tr[x][i]);st[tr[x][i]]|=st[tr[fail[x]][i]];
                }else
                    tr[x][i]=tr[fail[x]][i];
            }
        }
    }
    vector<char>ans;
    void bfs(){ 
        vis[0][0]=1;
        q1.push({ 0,0});
        int now=0;
        while(!q1.empty()){ 
            auto it=q1.front();q1.pop();
            if(it.se==(1<<n)-1){ 
                while(now){ 
                    ans.pb(pos[now]+'A');
                    now=fa[now];    
                }     
                reverse(ans.begin(),ans.end());
                for(auto&v:ans) 
                    putchar(v);
                return;
            }
            for(int i=0;i<26;++i){ 
                int nxst=(it.se|st[tr[it.fi][i]]),nxt=tr[it.fi][i];
                if(vis[nxt][nxst])continue;
                vis[nxt][nxst]=1;
                q1.push({nxt,nxst});
                fa[++tot]=now;pos[tot]=i;
            }
            now++;
        }
    }
}ac;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){ 
        scanf("%s",s);
        ac.insert(s,i);
    }
    ac.build();
    ac.bfs();
    return 0;
}

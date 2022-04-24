#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+5;;
char s[maxn];
int v[maxn];
struct AC{ 
    int tr[maxn][2],cnt,fail[maxn];
    bool ed[maxn];
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
        for(int i=0;i<2;++i)
            if(tr[0][i])q.push(tr[0][i]);
        while(!q.empty()){ 
            int x=q.front();q.pop();
            for(int i=0;i<2;++i){ 
                if(tr[x][i]){ 
                    fail[tr[x][i]]=tr[fail[x]][i],q.push(tr[x][i]);
                    ed[tr[x][i]]|=ed[fail[tr[x][i]]];
                }else
                    tr[x][i]=tr[fail[x]][i];
            }
        }
    }
    void dfs(int x){ 
        if(ed[x])return;
        v[x]=1;
        for(int i=0;i<2;++i){ 
            if(v[tr[x][i]]==1){ 
                puts("TAK");exit(0);
            }else if(!v[tr[x][i]])
                dfs(tr[x][i]);
        }
        v[x]=-1;
    }
}ac;
int main(){ 
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%s",s),ac.insert(s);
    ac.build();
    ac.dfs(0);
    puts("NIE");
    return 0;
}

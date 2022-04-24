#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;
const int maxn=2e6+5;
vector<int>G[maxn];
struct SAM{//maxn开2倍
    int len[maxn],link[maxn],ch[maxn][26],last,tot,sz[maxn],num[maxn],cnt;//len指状态内最长长度
    bool vis[maxn];
    SAM(){ //link指向状态内最长字符串的最长的一个在另一个endpos类的后缀
        tot=last=1;//sz endpos大小
    }
    void extend(int c){ 
        int cur=++tot,p=last;last=cur;sz[cur]=1;
        len[cur]=len[p]+1;
        for(;p&&!ch[p][c];p=link[p])ch[p][c]=cur;
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[p]+1==len[q])link[cur]=q;
            else{ 
                int clone=++tot;//==len[p]+1的复制出来
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                len[clone]=len[p]+1;
                link[clone]=link[q];link[q]=link[cur]=clone;
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
            }
        }
    }
    void dfs(int x){ 
        for(auto&v:G[x]){ 
            dfs(v);
            sz[x]+=sz[v];
        }
    }
    void calSZ(){ 
        for(int i=2;i<=tot;++i)G[link[i]].pb(i);
        dfs(1);
    }
    void solve(char *s){ 
        ll ans=0;
        int L=strlen(s),p=1,nowlen=0;
        for(int i=0;i<L;++i){ 
            int c=s[i]-'a';
            if(ch[p][c])nowlen++,p=ch[p][c];
            else{ 
                while(p&&!ch[p][c])p=link[p];
                if(!p)p=1,nowlen=0;
                else{ 
                    nowlen=len[p]+1;
                    p=ch[p][c];
                }
            }
        }
        for(int i=0;i<L;++i){ 
            if(nowlen==L){ 
                if(!vis[p]){ 
                    ans+=sz[p],vis[p]=1;
                    num[++cnt]=p;
                }
                if(--nowlen==len[link[p]])p=link[p];
            }
            int c=s[i]-'a';
            if(ch[p][c])nowlen++,p=ch[p][c];
            else{ 
                while(p&&!ch[p][c])p=link[p];
                if(!p)p=1,nowlen=0;
                else{ 
                    nowlen=len[p]+1;
                    p=ch[p][c];
                }
            }
        }
        cout<<ans<<"\n";
        while(cnt){ 
            vis[num[cnt--]]=0;
        }
    }
}sam;
char s[maxn];
int n;
int main(){ 
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;++i)sam.extend(s[i]-'a');
    sam.calSZ();
    scanf("%d",&n);
    for(int i=1;i<=n;++i){ 
        scanf("%s",s);
        sam.solve(s);
    }
    return 0;
}

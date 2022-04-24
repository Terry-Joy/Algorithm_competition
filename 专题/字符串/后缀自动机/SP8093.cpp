#include<bits/stdc++.h>
#define eb emplace_back
#define lowb(i) (i&(-i))
using namespace std;
const int N=6e4+5;
const int maxn=2e5+5;
int pre[maxn],num,c[maxn],M,id[maxn];
vector<int>col[maxn],G[maxn];
void add(int x,int val){         
    for(int i=x;i<=M;i+=lowb(i))c[i]+=val;
}
int ask(int x){         
    int ans=0;
    for(int i=x;i;i-=lowb(i))ans+=c[i];
    return ans;
}

struct Q{ 
    int l,r,id;
    bool operator<(const Q&x)const{ 
        return r<x.r;
    }
}q[N];
struct GSAM{ 
    int link[maxn],ch[maxn][26],tot,len[maxn],in[maxn],out[maxn],ti;
    GSAM(){ tot=1;}
        int extend(int c,int last){ 
        if(ch[last][c]){ 
            int p=last,q=ch[p][c];
            if(len[p]+1==len[q])return q;
            else{ 
                int clone=++tot;
                len[clone]=len[p]+1;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                while(p&&ch[p][c]==q)ch[p][c]=clone,p=link[p];
                link[clone]=link[q];link[q]=clone;
                return clone; 
            }
        }
        int cur=++tot,p=last;
        len[cur]=len[p]+1;
        while(p&&!ch[p][c])ch[p][c]=cur,p=link[p];
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[q]==len[p]+1)link[cur]=q;
            else{ 
                int clone=++tot;
                len[clone]=len[p]+1;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                while(p&&ch[p][c]==q)ch[p][c]=clone,p=link[p];
                link[clone]=link[q];link[q]=link[cur]=clone;
            }
        }
        return cur;
    }
    void dfs(int x){ 
        in[x]=++ti;id[ti]=x;
        for(auto&v:G[x]){ 
            dfs(v);
        }
        out[x]=ti;
    }
    void init(){ 
        for(int i=2;i<=tot;++i)G[link[i]].eb(i);
        dfs(1);
    }
    int query(char *s){ 
        int L=strlen(s),p=1;
        for(int i=0;i<L;++i){ 
            int c=s[i]-'a';
            p=ch[p][c];
            if(!p)return 0;
        }
        return p;
    }
}sam;
char s[maxn<<1];
int ans[60005];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){ 
        cin>>s;
        int L=strlen(s),las=1;
        for(int j=0;j<L;++j){ 
            las=sam.extend(s[j]-'a',las);
            col[las].eb(i);
        }
    }
    sam.init();
     for(int i=1;i<=m;++i){ 
        cin>>s;
        int pos=sam.query(s);
        if(!pos)ans[i]=0;
        else q[++num]={sam.in[pos],sam.out[pos],i};
    }
    sort(q+1,q+1+num); 
    M=sam.tot;
    int p=0;
    for(int i=1;i<=num;++i){ 
        while(p<q[i].r){ 
            p++;
            int pos=id[p];
            for(auto&u:col[pos]){ 
                if(pre[u])add(pre[u],-1);
                add(p,1);
                pre[u]=p;
            }
        }
        ans[q[i].id]=ask(q[i].r)-ask(q[i].l-1);
    }
    for(int i=1;i<=m;++i)cout<<ans[i]<<"\n";
    return 0;
}

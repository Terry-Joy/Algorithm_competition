#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=2e5+5;
const int maxm=2e6+5;
char s[maxm];
int ans[maxn],q[maxn],h=1,t=0;
struct AC{ 
    int tr[maxn][26],fail[maxn],cnt,ed[maxn],sz[maxn];
    void insert(char*s,int pos){ 
        int now=0,len=strlen(s+1);
        for(int i=1;i<=len;++i){ 
            int ch=s[i]-'a';
            if(!tr[now][ch])tr[now][ch]=++cnt;
            now=tr[now][ch];
        }
        ed[pos]=now;
    }
    void build(){ 
        for(int i=0;i<26;++i){ 
            if(tr[0][i])q[++t]=tr[0][i];
        }
        while(h<=t){ 
            int x=q[h++];
            for(int i=0;i<26;++i){ 
                if(tr[x][i])fail[tr[x][i]]=tr[fail[x]][i],q[++t]=tr[x][i];
                else tr[x][i]=tr[fail[x]][i];
            }
        }
    }
    void query(char *s){ 
        int now=0,len=strlen(s+1);
        for(int i=1;i<=len;++i){ 
            int ch=s[i]-'a';
            now=tr[now][ch];
            sz[now]++;
        }
        for(int i=cnt;i>=1;--i)sz[fail[q[i]]]+=sz[q[i]];
    }
}ac;
int main(){ 
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%s",s+1),ac.insert(s,i);
    ac.build();
    scanf("%s",s+1);
    ac.query(s);
    for(int i=1;i<=n;++i)cout<<ac.sz[ac.ed[i]]<<"\n";
    return 0;
}

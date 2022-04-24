#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e6+5;
char s[maxn];
vector<int>G[maxn];
int ans[maxn],q[maxn],head=1,tail=0;
struct AC{ 
    int tr[maxn][26],fail[maxn],cnt,ed[maxn],sz[maxn];
    void insert(char*s,int pos){ 
        int now=0,len=strlen(s);
        for(int i=0;i<len;++i){ 
            int ch=s[i]-'a';
            if(!tr[now][ch])tr[now][ch]=++cnt;
            now=tr[now][ch];
            sz[now]++;
        }
        ed[pos]=now;
    }
    void build(){ 
        for(int i=0;i<26;++i){ 
            if(tr[0][i])q[++tail]=tr[0][i];
        }
        while(head<=tail){ 
            int x=q[head++];
            for(int i=0;i<26;++i){ 
                if(tr[x][i])fail[tr[x][i]]=tr[fail[x]][i],q[++tail]=tr[x][i];
                else tr[x][i]=tr[fail[x]][i];
            }
        }
    }
    void solve(){ 
        for(int i=cnt;i>=1;--i)sz[fail[q[i]]]+=sz[q[i]];
    }
}ac;
int main(){ 
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)scanf("%s",s),ac.insert(s,i);
    ac.build();
    ac.solve();
    for(int i=1;i<=n;++i)cout<<ac.sz[ac.ed[i]]<<"\n";
    return 0;
}

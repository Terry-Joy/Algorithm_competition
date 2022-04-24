#include<bits/stdc++.h>
using namespace std;
const int maxn=6005;
const int mod=1e4+7;
int mypow(int a,int b){ 
    int ans=1;
    while(b){ 
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int dp[105][maxn],n,m;
char s[105];
void add(int&x,int y){ 
    x+=y;
    if(x>=mod)x-=mod;
}
struct AC{ 
    int tr[maxn][26],cnt,fail[maxn];
    bool ed[maxn];
    void insert(char *s){ 
        int now=0,len=strlen(s);
        for(int i=0;i<len;++i){ 
            int ch=s[i]-'A';
            if(!tr[now][ch])tr[now][ch]=++cnt;
            now=tr[now][ch];
        }
        ed[now]=1;
    }
    queue<int>q;
    void build(){ 
        for(int i=0;i<26;++i){ 
            if(tr[0][i])q.push(tr[0][i]);
        }
        while(!q.empty()){ 
            int x=q.front();q.pop();
            for(int i=0;i<26;++i){ 
                if(tr[x][i]){ 
                    fail[tr[x][i]]=tr[fail[x]][i];q.push(tr[x][i]);
                    ed[tr[x][i]]|=ed[tr[fail[x]][i]];
                }else
                    tr[x][i]=tr[fail[x]][i];
            }
        }
    }
    void solve(){ 
        dp[0][0]=1;
        for(int i=0;i<=m-1;++i){ 
            for(int j=0;j<=cnt;++j){ 
                for(int k=0;k<26;++k){ 
                    if(!dp[i][j])continue;
                    int nxt=tr[j][k];
                    if(ed[nxt])continue;
                    add(dp[i+1][nxt],dp[i][j]);
                }
            }
        }
    
    }
}ac;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>s,ac.insert(s);
    ac.build();
    int ans=mypow(26,m),ans1=0;
    ac.solve();
    for(int i=0;i<=ac.cnt;++i){ 
        if(!dp[m][i])continue;
        add(ans1,dp[m][i]);
    }
    cout<<(ans-ans1+mod)%mod;
    return 0;
}


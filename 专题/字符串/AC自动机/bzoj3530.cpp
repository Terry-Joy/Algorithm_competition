#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1205;
const int N=1505;
const int mod=1e9+7;
int m,a[maxn];
char s[maxn],s1[N];
int dp[maxn][1510][2][2];
struct AC{ 
    int tr[N][10],cnt,fail[N];
    bool ed[N];
    void insert(char *s){ 
        int now=0,len=strlen(s);
        for(int i=0;i<len;++i){ 
            int ch=s[i]-'0';
            if(!tr[now][ch])tr[now][ch]=++cnt;
            now=tr[now][ch];
        }
        ed[now]|=1;
    }
    queue<int>q;
    void build(){ 
        for(int i=0;i<10;++i){ 
            if(tr[0][i])q.push(tr[0][i]);
        }
        while(!q.empty()){ 
            int x=q.front();q.pop();
            for(int i=0;i<10;++i){ 
                if(tr[x][i]){ 
                    fail[tr[x][i]]=tr[fail[x]][i];q.push(tr[x][i]);
                    ed[tr[x][i]]|=ed[fail[tr[x][i]]];
                }else
                    tr[x][i]=tr[fail[x]][i];
            }
        }
    }
    int dfs(int pos,int x1,bool limit,bool lead){ 
        if(pos==-1)return !ed[x1];
        if(ed[x1])return 0;
        if(dp[pos][x1][limit][lead]!=-1)return dp[pos][x1][limit][lead];
        int up=limit?(s[pos]-'0'):9;
        int ans=0;
        for(int i=0;i<=up;++i){ 
            ans+=dfs(pos-1,(lead&&i==0)?0:tr[x1][i],limit&&i==up,lead&&i==0);
            if(ans>=mod)ans-=mod;
        }
        return dp[pos][x1][limit][lead]=ans;
    }   
}ac;
int main(){ 
    scanf("%s",s);
    int len=strlen(s);
    reverse(s,s+len);
    scanf("%d",&m);
    for(int i=1;i<=m;++i){ 
        scanf("%s",s1);
        ac.insert(s1);
    }
    ac.build();
    memset(dp,-1,sizeof(dp));
    int ans=ac.dfs(len-1,0,1,1);
    cout<<(ans-1+mod)%mod;
    return 0;
}

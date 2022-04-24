#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int nxt[maxn][26];
char s1[maxn],s2[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>(s1+1)>>(s2+1);
    for(int i=n;i>=1;--i){ 
        for(int j=0;j<26;++j){ 
            nxt[i-1][j]=nxt[i][j];
        }
        nxt[i-1][s1[i]-'a']=i;
    }
    int now=0,ans=0;
    bool f=1;
    for(int i=1;i<=m;++i){ 
        int c=s2[i]-'a';
        for(int j=c+1;j<26;++j){ 
            if(nxt[now][j]>0)ans=max(ans,n-nxt[now][j]+i);
        }
        now=nxt[now][c];
        if(!now){ 
            f=0;break;
        }
    }
    if(f&&now!=n)ans=max(ans,n-now+m);
    if(!ans)cout<<-1<<"\n";
    else cout<<ans<<"\n";
    return 0;
}

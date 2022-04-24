#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=3e5+5;
int tr[maxn][26],n,cnt,deg[26];
bool ed[maxn],G[26][26];
string s[maxn/10+100];
vector<int>sans;
void insert(string&x){ 
    int len=x.length();
    int p=0;
    for(int i=0;i<len;++i){ 
        int now=x[i]-'a';
        if(!tr[p][now])tr[p][now]=++cnt;
        p=tr[p][now];
    }
    ed[p]=1;
}
bool topsort(){ 
    queue<int>q;
    for(int i=0;i<26;++i){ 
        if(!deg[i])q.push(i);
    }
    while(!q.empty()){ 
        int x=q.front();q.pop();
        for(int j=0;j<26;++j){ 
            if(x!=j&&G[x][j]){ 
                if(--deg[j]==0)   
                    q.push(j);
            }
        }
    }
    for(int i=0;i<26;++i){ 
        if(deg[i])return 0;
    }
    return 1;
}
bool find(string&x){ 
    memset(G,0,sizeof(G));
    memset(deg,0,sizeof(deg));
    int len=x.length();
    int p=0;
    for(int i=0;i<len;++i){ 
        if(ed[p])return 0;
        int now=x[i]-'a';
        for(int j=0;j<26;++j){ 
            if(tr[p][j]&&(now!=j)&&(!G[now][j])){ 
               G[now][j]=1;
               ++deg[j];
            }
        }
        p=tr[p][now];
    }
    return topsort();
}
int main(){ 
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){ 
        cin>>s[i];
        insert(s[i]);   
    }
    int ans=0;
    for(int i=1;i<=n;++i){ 
        if(find(s[i]))ans++,sans.pb(i);
    }
    cout<<ans<<"\n";
    for(auto &v:sans)
        cout<<s[v]<<"\n";
    return 0;
}

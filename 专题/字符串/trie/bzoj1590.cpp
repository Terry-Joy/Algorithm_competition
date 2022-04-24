#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int trie[maxn][2],cnt=1,m,n,a[10005],flag[maxn],sz[maxn],ans[50005];
void insert(int len){ 
    int now=1;
    for(int i=len-1;i>=0;--i){ 
        if(!trie[now][a[i]])trie[now][a[i]]=++cnt;
        now=trie[now][a[i]];
    }
    flag[now]++;
}
void dfs(int x){ 
    sz[x]=flag[x];
    if(!trie[x][0]&&!trie[x][1])return;
    if(trie[x][0])dfs(trie[x][0]);
    sz[x]+=sz[trie[x][0]];
    if(trie[x][1])dfs(trie[x][1]);
    sz[x]+=sz[trie[x][1]];
}
int query(int len){ 
    int ans=0,now=1;
    for(int i=len-1;i>=0;--i){ 
        if(trie[now][a[i]]){ 
            now=trie[now][a[i]];
            ans+=flag[now];
        }else return ans;//只有一个地方为空不代表flag[x]=sz[x]
    }
    ans+=(sz[now]-flag[now]);
    return ans;
}
int main(){ 
    scanf("%d%d",&m,&n);
    int bi,ci,x;
    for(int i=1;i<=m;++i){ 
        scanf("%d",&bi);
        for(int j=bi-1;j>=0;--j){ 
            scanf("%d",&a[j]);
        }
        insert(bi);
    }
    dfs(1);
    //for(int i=1;i<=cnt;++i)cout<<sz[i]<<">>>>\n";
    sz[1]=0;
    for(int i=1;i<=n;++i){ 
        scanf("%d",&ci);
        for(int j=ci-1;j>=0;--j){ 
            scanf("%d",&a[j]);
        }
        ans[i]=query(ci);
    }    
    for(int i=1;i<=n;++i)cout<<ans[i]<<"\n";
    return 0;
}

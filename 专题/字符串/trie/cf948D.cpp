#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
struct Trie{ 
    int tr[maxn*32][2],cnt,sz[maxn*32];
    Trie(){ cnt=1;}
    void insert(int val){ 
        int p=1;
        for(int i=30;i>=0;--i){ 
            int c=(val>>i)&1;
            if(!tr[p][c])tr[p][c]=++cnt;
            p=tr[p][c];
            sz[p]++;
        }
    }
    int query(int val){ 
        int p=1,ans=0;
        for(int i=30;i>=0;--i){ 
            int c=(val>>i)&1;
            if(sz[tr[p][c]])p=tr[p][c];
            else p=tr[p][c^1],ans|=(1<<i);
            sz[p]--;
        }
        return ans;
    }
}trie;
int a[maxn],p[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>p[i],trie.insert(p[i]);
    for(int i=1;i<=n;++i)cout<<trie.query(a[i])<<" ";
    return 0;
}

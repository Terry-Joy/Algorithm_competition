#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int maxm=1e4+5;
char s[60];
int n,m;
struct Trie{
    int nxt[maxn][26],cnt=1,st[maxn];
    void insert(char*s){
        int len=strlen(s+1),p=1;
        for(int i=1;i<=len;++i){
            int c=s[i]-'a';
            if(!nxt[p][c])nxt[p][c]=++cnt;
            p=nxt[p][c];
        }
    }
    int find(char*s){
        int len=strlen(s+1),p=1;
        for(int i=1;i<=len;++i){
            int c=s[i]-'a';
            if(!nxt[p][c])return 0;
            p=nxt[p][c];
        }
        if(!st[p]){
            st[p]=1;return 1;
        }
        return 2;
    }
}trie;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%s",s+1);
        trie.insert(s);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        scanf("%s",s+1);
        int b=trie.find(s);
        if(!b)puts("WRONG");
        else if(b==1)puts("OK");
        else puts("REPEAT");
    }
    return 0;
}
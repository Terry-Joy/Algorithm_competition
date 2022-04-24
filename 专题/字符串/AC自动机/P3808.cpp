#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
struct AC{ 
    int tr[maxn][26],cnt,fail[maxn],ed[maxn];
    void insert(char *s){ 
        int now=0,len=strlen(s+1);
        for(int i=1;i<=len;++i){ 
            int ch=s[i]-'a';
            if(!tr[now][ch])tr[now][ch]=++cnt;
            now=tr[now][ch];
        }
        ed[now]++;
    }
    queue<int>q;
    void build(){ 
        for(int i=0;i<26;++i)
            if(tr[0][i])q.push(tr[0][i]);
        while(!q.empty()){ 
            int x=q.front();q.pop();
            for(int i=0;i<26;++i){ 
                if(tr[x][i])
                    fail[tr[x][i]]=tr[fail[x]][i],q.push(tr[x][i]);
                else
                    tr[x][i]=tr[fail[x]][i];
            }
        }
    }
    int query(char *s){ 
        int now=0,sum=0,len=strlen(s+1);
        for(int i=1;i<=len;++i){ 
            now=tr[now][s[i]-'a'];
            for(int j=now;j&&ed[j]!=-1;j=fail[j])
                sum+=ed[j],ed[j]=-1;
        }
        return sum;
    }
}ac;
char s[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%s",s+1),ac.insert(s);
    ac.build();
    scanf("%s",s+1);
    cout<<ac.query(s);
    return 0;
}

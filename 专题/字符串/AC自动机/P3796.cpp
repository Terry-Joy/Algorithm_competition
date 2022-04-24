#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=150*70*26+10;
const int maxm=1e6+5;
char s[maxm];
char s1[155][80];
int mx,sum[160];
vector<int>ans;
struct AC{ 
    int tr[maxn][26],cnt,ed[maxn],fail[maxn];
    void insert(char *s,int pos){ 
        int len=strlen(s+1),now=0;
        for(int i=1;i<=len;++i){ 
            int ch=s[i]-'a';
            if(!tr[now][ch])tr[now][ch]=++cnt;
            now=tr[now][ch];
        }
        ed[now]=pos;
    }
    queue<int>q;
    void build(){ 
        for(int i=0;i<26;++i)
            if(tr[0][i])
                q.push(tr[0][i]);
        while(!q.empty()){ 
            int x=q.front();q.pop();
            for(int i=0;i<26;++i){ 
                if(tr[x][i])fail[tr[x][i]]=tr[fail[x]][i],q.push(tr[x][i]);
                else
                    tr[x][i]=tr[fail[x]][i];
            }
        }
    }
    void query(char *s){ 
        int now=0,len=strlen(s+1);
        for(int i=1;i<=len;++i){
            int ch=s[i]-'a';
            now=tr[now][ch];
            for(int j=now;j;j=fail[j]){ 
                if(!ed[j])continue;
                sum[ed[j]]++;
                if(sum[ed[j]]>mx){ 
                    mx=sum[ed[j]];
                    ans.clear();
                    ans.pb(ed[j]); 
                }else if(sum[ed[j]]==mx){ 
                    ans.pb(ed[j]);
                }
            }
        }
    }
    void init(){ 
        for(int i=0;i<=cnt;++i){ 
            fail[i]=ed[i]=0;
            for(int j=0;j<26;++j){ 
                tr[i][j]=0;
            }
        }
        cnt=0;
    }
}ac;
int main(){ 
    //freopen("P3796_1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t,n;
    while(~scanf("%d",&n)&&n){ 
        ac.init();
        mx=0;
        ans.clear();
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;++i){ 
            scanf("%s",s1[i]+1);
            ac.insert(s1[i],i);        
        }
        ac.build();
        scanf("%s",s+1);
        ac.query(s);
        cout<<mx<<"\n";
        sort(ans.begin(),ans.end());
        for(auto&v:ans){ 
            //cout<<v;
            int len=strlen(s1[v]+1);
            for(int i=1;i<=len;++i)putchar(s1[v][i]);
            puts("");
        }
    }
    return 0;
}

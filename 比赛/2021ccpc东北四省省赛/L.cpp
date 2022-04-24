#include<bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define ll long long
using namespace std;
typedef pair<ll,int>P;
const int maxn=4e5+100;
struct SAM{ 
    vector<int>G[maxn];
    vector<P>sum;
    SAM(){ 
        tot=last=1;
    }
    int pos[maxn],len[maxn],link[maxn],ch[maxn][26],last,tot,mx[maxn],minlen[maxn],cnt[maxn],tag[maxn],tr[maxn][26];
    int n;
    void extend(int c,int id){ 
        int cur=++tot,p=last;last=cur;
        pos[cur]=id;
        len[cur]=len[p]+1;
        for(;p&&!ch[p][c];p=link[p])ch[p][c]=cur;
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[p]+1==len[q])link[cur]=q;
            else{ 
                int clone=++tot;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                len[clone]=len[p]+1;
                link[clone]=link[q];link[q]=link[cur]=clone;
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
            }
        }
    }
    void init(){ 
        for(int i=1;i<=tot;++i)pos[i]=len[i]=link[i]=mx[i]=cnt[i]=tag[i]=0,G[i].clear();
        sum.clear();
        for(int i=1;i<=tot;++i){ 
            memset(ch[i],0,sizeof(ch[i]));
            memset(tr[i],0,sizeof(tr[i]));
        }
        for(int i=1;i<=tot;++i)minlen[i]=1e9;
        tot=last=1;
    }
    void match(const string&s,int id){ 
        int p=1,nowlen=0;
        vector<int>node;
        for(auto v:s){ 
            int c=v-'a';
            if(ch[p][c])nowlen++,p=ch[p][c];
            else{ 
                while(p&&!ch[p][c])p=link[p];
                if(!p)nowlen=0,p=1;
                else{ 
                    nowlen=len[p]+1;p=ch[p][c];
                }
            }
            mx[p]=max(mx[p],nowlen);
            node.eb(p);
        }
        sort(node.begin(),node.end(),[&](int a,int b){ 
                    return len[a]>len[b];
                });
        vector<int>path;
        for(auto u:node){ 
            while(u&&tag[u]!=id){ 
                path.eb(u);
                tag[u]=id;
                u=link[u];
            }
        }
        sort(path.begin(),path.end(),[&](int a,int b){ 
                return len[a]>len[b];
                });
        for(auto u:path){ 
            cnt[u]++;
            mx[link[u]]=max(mx[link[u]],len[link[u]]);
            minlen[u]=min(minlen[u],mx[u]);
            mx[u]=0;
        }
    }
    void dfs(int x){ 
        for(auto v:G[x]){ 
            dfs(v);
            pos[x]=max(pos[x],pos[v]);
        }
    }
    void dfs1(int x){ 
        for(int i=0;i<26;++i){ 
            if(!tr[x][i])continue;
            if(cnt[tr[x][i]]==n-1){ 
                sum.eb(make_pair(minlen[tr[x][i]]-len[link[tr[x][i]]],tr[x][i]));
            }
            dfs1(tr[x][i]);
        }
    }
    char s[maxn];
    void solve(){
        cin>>n;
        cin>>s;
        int L=strlen(s);
        reverse(s,s+L);
        for(int i=0;i<L;++i)extend(s[i]-'a',i);
        string s2;
        for(int i=2;i<=tot;++i)G[link[i]].eb(i),minlen[i]=len[i],mx[i]=0;
        for(int i=1;i<n;++i){ 
            cin>>s2;
            reverse(s2.begin(),s2.end());
            match(s2,i);
        }
        //for(int i=2;i<=tot;++i)cout<<minlen[i]<<" "<<i<<"\n";;
       // for(int i=2;i<=tot;++i)cout<<cnt[i]<<"\n";
        dfs(1);
        for(int i=2;i<=tot;++i){ 
            int c=s[pos[i]-len[link[i]]]-'a';
            tr[link[i]][c]=i;
        }
        dfs1(1);
        for(int i=1;i<sum.size();++i){ 
            sum[i].fi+=sum[i-1].fi;
        }
        //for(int i=0;i<sum.size();++i)cout<<sum[i].fi<<" ";
        //cout<<endl;
        int q,k;
        cin>>q;
        for(int i=1;i<=q;++i){ 
            cin>>k;
            auto it=lower_bound(sum.begin(),sum.end(),make_pair( (ll)k,-1));
            if(it==sum.end()){ 
                cout<<"-1\n";
            }else{ 
                if(it==sum.begin())k=k;
                else{ 
                    auto v=it;
                    v--;
                    k-=(*v).fi;
                }
                int l=pos[(*it).se],r=l-len[link[(*it).se]]-k+1;
                cout<<L-1-l<<" "<<L-r<<"\n";
            }
        }
    }
}sam;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){ 
        sam.solve();
        sam.init();
    }
    return 0;
}

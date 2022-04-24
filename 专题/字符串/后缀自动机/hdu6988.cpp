#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
int t,n;
ll k;
char s[maxn];
struct SAM{ 
    vector<int>G[maxn];
    int len[maxn],link[maxn],ch[maxn][26],last,tot,pos[maxn],sum[maxn],val[100];
    ll num=0;
    SAM(){ 
        tot=last=1;
    }
    void extend(int c,int id){ 
        int cur=++tot,p=last;last=cur;
        len[cur]=len[p]+1;
        pos[cur]=id;
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
    void dfs(int x){ 
        for(auto&v:G[x]){ 
            dfs(v);
            pos[x]=max(pos[x],pos[v]);
        }
    }
    /*
    void dfs1(int x,int lim){ 
        if(x!=1){ 
            int r=pos[x]-len[link[x]]+1,l=pos[x]-len[x]+1;
            while(l<r){ 
                int mid=l+r>>1;
                if(sum[pos[x]]-sum[mid-1]<lim)r=mid;
                else l=mid+1;
            }
            if(r!=pos[x]-len[link[x]]+1)
                num+=(pos[x]-len[link[x]]-r+1);
        }
        for(auto &v:G[x]){ 
            dfs1(v,lim);
        }
    }*/
    bool check(int x){ 
        num=0;
        for(int i=2;i<=tot;++i){ 
            int r=pos[i]-len[link[i]]+1,l=pos[i]-len[i]+1;
            while(l<r){ 
                int mid=l+r>>1;
                if(sum[pos[i]]-sum[mid-1]<x)r=mid;
                else l=mid+1;
            }
            if(r!=pos[i]-len[link[i]]+1)
                num+=(pos[i]-len[link[i]]-r+1);
        }
        //dfs1(1,x);
        return num<k;
    }
    void solve(){ 
        for(int i=2;i<=tot;++i)G[link[i]].eb(i);
        int mx=0;
        for(int i=0;i<26;++i)cin>>val[i],mx=max(mx,val[i]);
        ll all=0;
        for(int i=2;i<=tot;++i)all+=len[i]-len[link[i]];
        if(k<=all){ 
            for(int i=1;i<=n;++i)sum[i]=sum[i-1]+val[s[i]-'a'];
            dfs(1);
            int l=1,r=n*mx;
            while(l<r){ 
                int mid=(l+r+1)>>1;
                if(check(mid))l=mid;
                else r=mid-1;
            }
            cout<<l<<"\n"; 
        }else
            cout<<"-1\n";
    }
    void init(){ 
        for(int i=1;i<=tot;++i)G[i].clear();
        for(int i=1;i<=tot;++i)len[i]=link[i]=pos[i]=0;
        for(int i=1;i<=n;++i)sum[i]=0;
        for(int i=1;i<=tot;++i){ 
            memset(ch[i],0,sizeof(ch[i]));
        }
        last=tot=1;
    }
}sam;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n>>k;
        cin>>(s+1);
        for(int i=1;i<=n;++i){ 
            sam.extend(s[i]-'a',i);
        }
        sam.solve();
        sam.init();
    } 
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5+5;
struct SA{ 
    char s[maxn];
    int n,m,a[maxn],sa[maxn],rank[maxn],Height[maxn],tax[maxn],tp[maxn];
    void init(){ 
        scanf("%d",&n);
        scanf("%s",s+1);
        m=(int)'z';
    }
    int cmp(int *f,int x,int y,int w){ 
        return f[x]==f[y]&&f[x+w]==f[y+w];
    }
    void rsort(){ 
        for(int i=0;i<=m;++i)tax[i]=0;
        for(int i=1;i<=n;++i)tax[rank[tp[i]]]++;
        for(int i=1;i<=m;++i)tax[i]+=tax[i-1];
        for(int i=n;i;--i)sa[tax[rank[tp[i]]]--]=tp[i];
    }
    void Suffix(){ 
        for(int i=1;i<=n;++i)a[i]=s[i];
        for(int i=1;i<=n;++i)rank[i]=a[i],tp[i]=i;
        rsort();
        for(int w=1,p=1,i;p<n;w+=w,m=p){ 
            for(p=0,i=n-w+1;i<=n;++i)tp[++p]=i;
            for(i=1;i<=n;++i)if(sa[i]>w)tp[++p]=sa[i]-w;
            rsort(),swap(rank,tp),rank[sa[1]]=p=1;
            for(int i=2;i<=n;++i)
                rank[sa[i]]=cmp(tp,sa[i],sa[i-1],w)?p:++p;
        }
        int j,k=0;
        for(int i=1;i<=n;Height[rank[i++]]=k)
            for(k=k?k-1:k,j=sa[rank[i]-1];a[i+k]==a[j+k];++k);
    }
    void solve(){ 
        ll ans=0;
        for(int i=1;i<=n;++i){ 
            ans+=n+1-sa[i]-Height[i];
        }
        cout<<ans;
    }
}sa;
int main(){ 
    sa.init();
    sa.Suffix();
    sa.solve();
}

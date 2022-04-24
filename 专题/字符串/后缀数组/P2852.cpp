#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
const int M=1e6+5;
struct SA{ 
    int n,m,a[maxn],sa[maxn],rank[maxn],Height[maxn],tax[M],tp[maxn],k,mx=0,q[maxn],h=1,t=0;
    void init(){ 
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]),mx=max(a[i],mx);
        m=mx;
    }
    int cmp(int*f,int x,int y,int w){ 
        return f[x]==f[y]&&f[x+w]==f[y+w];
    }
    void rsort(){ 
        for(int i=0;i<=m;++i)tax[i]=0;
        for(int i=1;i<=n;++i)tax[rank[tp[i]]]++;
        for(int i=1;i<=m;++i)tax[i]+=tax[i-1];
        for(int i=n;i;--i)sa[tax[rank[tp[i]]]--]=tp[i];
    }
    void Suffix(){ 
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
    int solve(){ 
        h=1,t=0;
        int mx=0;
        for(int i=1;i<=n;++i){ 
            while(h<=t&&q[h]<i-k+2)h++;
            while(h<=t&&Height[q[t]]>=Height[i])t--;
            q[++t]=i;
            if(i>=k-1){ 
                mx=max(mx,Height[q[h]]);
            }
        }
        return mx;
    }
}sa;
int main(){
    sa.init();
    sa.Suffix();
    /*for(int i=1;i<=sa.n;++i){ 
        cout<<sa.Height[i]<<"\n";
    }*/
    cout<<sa.solve(); 
    return 0;
}

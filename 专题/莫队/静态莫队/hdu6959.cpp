#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,big1,big2,pos1[maxn],pos2[maxn],a[maxn],ans[maxn],num,f[maxn],sum[maxn/5],L[maxn],R[maxn],m;
struct Q{ 
    int x0,y0,x1,y1,id;
    bool operator<(const Q&a)const{ 
        if(pos1[x0]!=pos1[a.x0])return pos1[x0]<pos1[a.x0];
        if(pos1[x0]&1)return x1>a.x1;
        return x1<a.x1;
    }
}q[maxn];
void add(int x){ 
    f[a[x]]++;
    if(f[a[x]]==1)sum[pos2[a[x]]]++;
}
void del(int x){ 
    f[a[x]]--;
    if(!f[a[x]])sum[pos2[a[x]]]--;
}
int query(int l,int r){ 
    int pl=pos2[l],pr=pos2[r];
    int ans=0;
    if(pl==pr){ 
        for(int i=l;i<=r;++i)
            ans+=(f[i]>=1);
    }else{ 
        for(int i=pl+1;i<=pr-1;++i)ans+=sum[i];
        for(int i=l;i<=R[pl];++i)ans+=(f[i]>=1);
        for(int i=L[pr];i<=r;++i)ans+=(f[i]>=1);
    }
    return ans;
}
int main(){ 
    scanf("%d",&t);
    int mx=0;
    while(t--){ 
        scanf("%d%d",&n,&m);
        big1=n/sqrt(m*2/3);
        for(int i=1;i<=n;++i)pos1[i]=(i-1)/big1+1;
        for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]++,mx=max(mx,a[i]);
        big2=sqrt(mx);
        num=(mx-1)/big2+1;
        for(int i=1;i<=num;++i){ 
            L[i]=R[i-1]+1;
            R[i]=i*big2;
        }
        R[num]=mx;
        for(int i=1;i<=num;++i)
            for(int j=L[i];j<=R[i];++j)
                pos2[j]=i;
        for(int i=1;i<=m;++i){ 
            scanf("%d%d%d%d",&q[i].x0,&q[i].y0,&q[i].x1,&q[i].y1),q[i].id=i;
            q[i].y0++;q[i].y1++;
        }
        sort(q+1,q+1+m);
        int pl=1,pr=0;
        for(int i=1;i<=m;++i){ 
            int l=q[i].x0,r=q[i].x1;
            while(pl>l)add(--pl);
            while(pr<r)add(++pr);
            while(pl<l)del(pl++);
            while(pr>r)del(pr--);
            ans[q[i].id]=query(q[i].y0,q[i].y1);
        }
        for(int i=1;i<=m;++i)cout<<ans[i]<<"\n";
        for(int i=1;i<=mx;++i)f[i]=0;
        for(int i=1;i<=num;++i)sum[i]=0;
    }
    return 0;
}

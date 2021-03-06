#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int L[maxn],R[maxn],a[maxn],b[maxn],p[maxn],n,m,big,num,pos[maxn],add[maxn],cnt1,cnt2,t1[maxn],t2[maxn],mn=2e5,mx=-2e5;
bool cmp(int x,int y){return a[x]<a[y];}
inline int read(){
    char c=getchar();int x=0,s=1;
    while(c<'0'||c>'9'){if(c=='-')s=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*s;
}
inline void in(int&x){
    x=read();
}
void init(){
    num=(n-1)/big+1;
    for(int i=1;i<=num;++i){
        L[i]=(i-1)*big+1;
        R[i]=i*big;
    }
    R[num]=n;
    for(int i=1;i<=num;++i){
        for(int j=L[i];j<=R[i];++j)
            pos[j]=i;
        sort(p+L[i],p+R[i]+1,cmp);
        for(int j=L[i];j<=R[i];++j)
            b[j]=a[p[j]];
    }
}
void rebuild(int x,int l,int r){
    cnt1=cnt2=0;
    for(int i=L[x];i<=R[x];++i){
        if(p[i]>=l&&p[i]<=r)t1[++cnt1]=p[i];
        else t2[++cnt2]=p[i];
    }
    merge(t1+1,t1+cnt1+1,t2+1,t2+1+cnt2,p+L[x],cmp);
    for(int i=L[x];i<=R[x];++i)b[i]=a[p[i]];
}
void update(int l,int r,int val){
    val>0?mx+=val:mn+=val;
    int pl=pos[l],pr=pos[r];
    if(pl==pr){
        for(int i=l;i<=r;++i)a[i]+=val;
        rebuild(pl,l,r);
    }else{
        for(int i=pl+1;i<=pr-1;++i)add[i]+=val;
        for(int i=l;i<=R[pl];++i)a[i]+=val;
        rebuild(pl,l,r);
        for(int i=L[pr];i<=r;++i)a[i]+=val;
        rebuild(pr,l,r);
    }
}
int ask(int l,int r,int w){
    int pl=pos[l],pr=pos[r];
    int sum=0;
    for(int i=pl+1;i<=pr-1;++i)
        sum+=upper_bound(b+L[i],b+R[i]+1,w-add[i])-b-L[i];
    sum+=upper_bound(t1+1,t1+cnt1+1,w-add[pl])-t1-1;
    sum+=upper_bound(t2+1,t2+cnt2+1,w-add[pr])-t2-1;
    return sum;
}
int query(int l,int r,int k){
    if(k>r-l+1)return -1;
    int pl=pos[l],pr=pos[r];
    cnt1=cnt2=0;
    if(pl==pr){
        for(int i=L[pl];i<=R[pl];++i)
            if(p[i]>=l&&p[i]<=r)t1[++cnt1]=b[i];
        return t1[k]+add[pl];
    }else{
        int l1=mn,r1=mx,mid,res;
        for(int i=L[pl];i<=R[pl];++i)
            if(p[i]>=l&&p[i]<=r)t1[++cnt1]=b[i];
        for(int i=L[pr];i<=R[pr];++i)
            if(p[i]>=l&&p[i]<=r)t2[++cnt2]=b[i];
        while(l1<=r1){
            mid=l1+r1>>1;
            int f=ask(l,r,mid);
            if(f>=k)res=mid,r1=mid-1;
            else l1=mid+1;
        }
        return res;
    }
}
int main(){
    in(n);in(m);
    big=sqrt(n)*log2(n)*0.17;
    big=max(1,big);
    for(int i=1;i<=n;++i)in(a[i]),p[i]=i,mx=max(mx,a[i]),mn=min(mn,a[i]);
    int op,l1,r1,k;
    init();
    for(int i=1;i<=m;++i){
        in(op);in(l1);in(r1);in(k);
        if(op==1)
            cout<<query(l1,r1,k)<<'\n';
        else
            update(l1,r1,k);
    }
    return 0;
}
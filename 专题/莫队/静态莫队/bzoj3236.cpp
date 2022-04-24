#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
const int maxm=1e6+5;
int n,m,a[maxn],big1,big2,pos1[maxn],pos2[maxn],cnt1[maxn],sum1[maxm],sum2[maxm],L[maxm],R[maxm],num,pl,pr,ans1[maxn],ans2[maxn],mx;//big1,pos1莫队 big2,pos2用于分块
inline int read() {
    int x=0,f=1;char c=getchar();
    while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}
struct Q{
    int L,R,id,x,y;
    bool operator<(const Q&a)const{
        if(pos1[L]!=pos1[a.L])return pos1[L]<pos1[a.L];
        if(pos1[L]&1)return R>a.R;
        return R<a.R;
    }
}q[maxn];
void init(){  
    big1=n/sqrt(m)+1;//防一手m=0
    big2=sqrt(mx);
    for(int i=1;i<=n;++i)pos1[i]=(i-1)/big1+1;
    num=(mx-1)/big2+1;
    for(int i=1;i<=num;++i){
        L[i]=R[i-1]+1;
        R[i]=i*big2;
    }
    R[num]=mx;
    for(int i=1;i<=num;++i){
        for(int j=L[i];j<=R[i];++j)
            pos2[j]=i;
    }
    sort(q+1,q+1+m);
}
void add(int x){
    cnt1[a[x]]++;//第一个询问修改
    sum1[pos2[a[x]]]++;
    if(cnt1[a[x]]==1)
        sum2[pos2[a[x]]]++;
    //cout<<x<<sum2[1]<<"\n";
}
void del(int x){
    cnt1[a[x]]--;
    sum1[pos2[a[x]]]--;
    if(!cnt1[a[x]])
        sum2[pos2[a[x]]]--;
}
int query1(int l,int r){
    if(l>r)return 0;
    int psl=pos2[l],psr=pos2[r];
    int num=0;
    if(psl==psr){
        for(int i=l;i<=r;++i)num+=cnt1[i];
    }else{
        for(int i=psl+1;i<=psr-1;++i)num+=sum1[i];
        for(int i=l;i<=R[psl];++i)num+=cnt1[i];
        for(int i=L[psr];i<=r;++i)num+=cnt1[i];
    }
    return num;
}
int query2(int l,int r){
    if(l>r)return 0;
    int psl=pos2[l],psr=pos2[r];
    int num=0;
    if(psl==psr){
        for(int i=l;i<=r;++i)num+=(cnt1[i]>=1);
    }else{
        for(int i=psl+1;i<=psr-1;++i)num+=sum2[i];
        for(int i=l;i<=R[psl];++i)num+=(cnt1[i]>=1);
        for(int i=L[psr];i<=r;++i)num+=(cnt1[i]>=1);
    }
    return num;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)a[i]=read(),mx=max(mx,a[i]);
    for(int i=1;i<=m;++i){
        q[i].L=read();q[i].R=read();q[i].x=read();q[i].y=read();
        q[i].id=i;
    }
    init();
    pl=1,pr=0;
    for(int i=1;i<=m;++i){
        int l=q[i].L,r=q[i].R;
        while(pl>l)add(--pl);
        while(pr<r)add(++pr);
        while(pl<l)del(pl++);
        while(pr>r)del(pr--);
        ans1[q[i].id]=query1(q[i].x,min(q[i].y,mx));
        ans2[q[i].id]=query2(q[i].x,min(q[i].y,mx));
    }
    for(int i=1;i<=m;++i){
        cout<<ans1[i]<<" "<<ans2[i]<<"\n";
    }
    return 0;
}
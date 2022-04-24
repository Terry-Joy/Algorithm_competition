#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+5;
int pos[maxn],a[maxn],cnt1[maxn],big,m,n,num,cnt2[maxn];
ll ans[maxn],sum=0;
struct Q{
    int L,R,id;
    bool op;
    bool operator<(const Q&a)const{
        return pos[L]^pos[a.L]?pos[L]<pos[a.L]:pos[L]&1?R<a.R:R>a.R;
        //if(pos[L]!=pos[a.L])return pos[L]<pos[a.L];
        //if(pos[L]&1)return R>a.R;
        //return R<a.R;
    }
}q[maxn*4];
void add(int x,bool is){
    if(is){
        sum+=cnt2[a[x]];
        cnt1[a[x]]++;
    }else{
        sum+=cnt1[a[x]];
        cnt2[a[x]]++;
    }
}
void del(int x,bool is){
    if(is){
        sum-=cnt2[a[x]];
        cnt1[a[x]]--;
    }else{
        sum-=cnt1[a[x]];
        cnt2[a[x]]--;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    scanf("%d",&num);
    for(int i=1;i<=num;++i){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        q[++m]={min(r1,r2),max(r1,r2),i,1};
        q[++m]={min(r1,l2-1),max(r1,l2-1),i,0};
        q[++m]={min(l1-1,r2),max(l1-1,r2),i,0};
        q[++m]={min(l1-1,l2-1),max(l1-1,l2-1),i,1};
    }
    big=n/sqrt(m);
    for(int i=1;i<=n;++i)pos[i]=(i-1)/big+1;
    sort(q+1,q+1+m);
    int pl=0,pr=0;//空区间
    for(int i=1;i<=m;++i){
        int l=q[i].L,r=q[i].R;
        while(pl<l)add(++pl,1);
        while(pr<r)add(++pr,0);
        while(pl>l)del(pl--,1);
        while(pr>r)del(pr--,0);
        ans[q[i].id]+=(q[i].op?1:-1)*sum;
        //cout<<pl<<" "<<pr<<" "<<l<<" "<<r<<"\n";
    }
    for(int i=1;i<=num;++i)cout<<ans[i]<<"\n";
    return 0;
}
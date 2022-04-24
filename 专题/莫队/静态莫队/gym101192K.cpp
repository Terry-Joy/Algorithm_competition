#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const int maxm=3e4+5;
int pos[maxn],a[maxn],cnt1[maxn],big,m,n,num,cnt2[maxn];
ll ans[maxn],sum=0;
struct Q{
    int L,R,id;
    bool op;
    bool operator<(const Q&a)const{
        return pos[L]^pos[a.L]?pos[L]<pos[a.L]:pos[L]&1?R<a.R:R>a.R;
    }
}q[maxm*4];
void add0(int x){
    sum+=cnt2[a[x]];
    cnt1[a[x]]++;
}
void add1(int x){
    sum+=cnt1[a[x]];
    cnt2[a[x]]++;
}
void del0(int x){
    sum-=cnt2[a[x]];
    cnt1[a[x]]--;
}
void del1(int x){
    sum-=cnt1[a[x]];
    cnt2[a[x]]--;
}
int main(){
    scanf("%d%d",&n,&num);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
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
        while(pl<l)add0(++pl);
        while(pr<r)add1(++pr);
        while(pl>l)del0(pl--);
        while(pr>r)del1(pr--);
        ans[q[i].id]+=(q[i].op?1:-1)*sum;
    }
    for(int i=1;i<=num;++i)cout<<ans[i]<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int pos[maxn],big,a[maxn],n,m,cnt[maxn],pl,pr,ans[maxn],nowans;
struct Q{
    int L,R,id;
    bool operator<(const Q&a){
        if(pos[L]!=pos[a.L])return pos[L]<pos[a.L];
        if(pos[L]&1)return R>a.R;
        return R<a.R;
    }
}q[maxn];
void init(){
    big=n/sqrt(m);
    for(int i=1;i<=n;++i)pos[i]=(i-1)/big+1;
}
void add(int x){
    if((++cnt[a[x]])==1)nowans++;
}
void del(int x){
    if((--cnt[a[x]])==0)nowans--;
} 
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    init();
    for(int i=1;i<=m;++i)scanf("%d%d",&q[i].L,&q[i].R),q[i].id=i;
    sort(q+1,q+1+m);
    for(int i=1;i<=m;++i){
        int l=q[i].L,r=q[i].R;
        while(pl<l)del(pl++);
        while(pl>l)add(--pl);
        while(pr<r)add(++pr);
        while(pr>r)del(pr--);
        if(nowans==(r-l+1))ans[q[i].id]=1;
    }
    for(int i=1;i<=m;++i)
        puts(ans[i]?"Yes":"No");
    return 0;
}

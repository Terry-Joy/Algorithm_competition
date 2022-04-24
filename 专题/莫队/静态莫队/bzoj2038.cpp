#include<bits/stdc++.h>
using namespace std;
const int maxn=50005;
int n,m,c[maxn],pos[maxn],cnt[maxn],ans[2][maxn],big,pl=1,pr,fz,fm,len;
struct Q{
    int L,R,id;
    bool operator<(const Q&a)const{
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
    fz+=cnt[x];
    cnt[x]++;
    fm+=len;
    len++;
}
void del(int x){
    cnt[x]--;
    fz-=cnt[x];
    len--;
    fm-=len;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&c[i]);
    init();
    for(int i=1;i<=m;++i){
        scanf("%d%d",&q[i].L,&q[i].R),q[i].id=i;
    }
    sort(q+1,q+1+m);
    for(int i=1;i<=m;++i){
        int l=q[i].L,r=q[i].R;
        if(l==r){
            ans[0][q[i].id]=0;
            ans[1][q[i].id]=1;continue;
        }
        while(pl>l)add(c[--pl]);
        while(pr<r)add(c[++pr]);
        while(pl<l)del(c[pl++]);
        while(pr>r)del(c[pr--]);
        int g=gcd(fz,fm);
        ans[0][q[i].id]=fz/g;
        ans[1][q[i].id]=fm/g;
    }
    for(int i=1;i<=m;++i){
        cout<<ans[0][i]<<"/"<<ans[1][i]<<"\n";
    }
    return 0;
}
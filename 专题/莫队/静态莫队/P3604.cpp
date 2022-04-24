#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=6e4+5;
int n,m,big,pos[maxn],pl,pr,a[maxn],sum[maxn];
unsigned short cnt[(1<<26)+2];
ll ans=0;
char s[maxn];
struct Q{
    int L,R,id;
    bool operator<(const Q&a)const{
        if(pos[L]!=pos[a.L])return pos[L]<pos[a.L];
        if(pos[L]&1)return R>a.R;
        return R<a.R;
    }
}q[maxn];
void add(int x){
    ans+=cnt[a[x]];
    for(int i=0;i<26;++i)ans+=cnt[a[x]^(1<<i)];
    cnt[a[x]]++;//自己和自己的贡献
}
void del(int x){
    cnt[a[x]]--;
    for(int i=0;i<26;++i)ans-=cnt[a[x]^(1<<i)];
    ans-=cnt[a[x]];
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i){
        a[i]=a[i-1]^(1<<(s[i]-'a'));
    }
    for(int i=1;i<=m;++i){
        scanf("%d%d",&q[i].L,&q[i].R),q[i].id=i;
    }
    big=n/sqrt(m);
    for(int i=1;i<=n;++i)pos[i]=(i-1)/big+1;
    sort(q+1,q+1+m);
    pl=1,pr=0;
    cnt[0]=1;
    for(int i=1;i<=m;++i){
        int l=q[i].L,r=q[i].R;
        while(pl>l)add(--pl-1);
        while(pr<r)add(++pr);
        while(pl<l)del(pl++-1);
        while(pr>r)del(pr--);
        sum[q[i].id]=ans;
    }
    for(int i=1;i<=m;++i)cout<<sum[i]<<"\n";
    return 0;
}
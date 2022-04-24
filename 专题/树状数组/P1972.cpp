#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,a[maxn],m,ans[maxn],pre[maxn];
struct Q{
    int l,r,id;
    bool operator<(const Q&a)const{
        return r<a.r;
    }
}q[maxn];
struct BIT{
    int c[maxn];
    #define lowb(x) (x&(-x))
    void add(int x,int val){
        for(int i=x;i<=n;i+=lowb(i))c[i]+=val;
    }
    int ask(int x){
        int ans=0;
        for(int i=x;i;i-=lowb(i))ans+=c[i];
        return ans;
    }
}bit;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;++i)scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
    sort(q+1,q+1+m);
    int now=1;
    for(int i=1;i<=m;++i){
        while(now<=q[i].r){
            if(pre[a[now]])bit.add(pre[a[now]],-1),pre[a[now]]=now,bit.add(now,1);
            else pre[a[now]]=now,bit.add(now,1);
            now++;
        }   
        ans[q[i].id]=bit.ask(q[i].r)-bit.ask(q[i].l-1);
    }
    for(int i=1;i<=m;++i)cout<<ans[i]<<"\n";
    return 0;
}
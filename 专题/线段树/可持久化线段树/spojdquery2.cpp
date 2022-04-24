//树状数组离线求区间不同数个数
#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define N 3e4
using namespace std;
const int maxn=3e4+5;
const int maxm=2e5+5;
int pre[maxm*5],n,a[maxn],q,ans[maxm];
struct BIT{
    int c[maxn];
    void add(int x,int val){
        while(x<=N){
            c[x]+=val;
            x+=lowbit(x);
        }
    }
    int query(int x){
        int ans=0;
        while(x){
            ans+=c[x];
            x-=lowbit(x);
        }
        return ans;
    }
}bit;
struct Q{
    int l,r,id;
    bool operator<(const Q&a)const{
        return r<a.r;
    }
}qi[maxm];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    cin>>q;
    for(int i=1;i<=q;++i)cin>>qi[i].l>>qi[i].r,qi[i].id=i;
    sort(qi+1,qi+1+q);
    int now=1;
    for(int i=1;i<=q;++i){
        while(now<=qi[i].r){
            if(pre[a[now]]){
                bit.add(pre[a[now]],-1);
                bit.add(now,1);
            }else
                bit.add(now,1);
            pre[a[now]]=now;
            now++;
        }
        ans[qi[i].id]=bit.query(qi[i].r)-bit.query(qi[i].l-1);
    }
    for(int i=1;i<=q;++i)cout<<ans[i]<<"\n";
    return 0;
}
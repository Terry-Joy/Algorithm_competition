#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,qu,a[maxn],b[maxn],pos[maxn],L[maxn/5],R[maxn/5],big,num,val[maxn],cnt[maxn];
ll ans[maxn];
struct Q{ 
    int l,r,id;
    bool operator<(const Q&x)const{ 
        return (pos[l]^pos[x.l])?l<x.l:r<x.r;
    }
}q[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>qu;
    for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
    big=sqrt(n);
    num=(n-1)/big+1;
    for(int i=1;i<=num;++i){ 
        L[i]=R[i-1]+1;
        R[i]=i*big;
    }
    R[num]=n;
    for(int i=1;i<=num;++i){ 
        for(int j=L[i];j<=R[i];++j)
            pos[j]=i;
    }
    sort(b+1,b+1+n);
    int m=unique(b+1,b+1+n)-(b+1);
    for(int i=1;i<=n;++i){ 
        int x=lower_bound(b+1,b+1+m,a[i])-b;
        val[x]=a[i];
        a[i]=x;
    }
    for(int i=1;i<=qu;++i)cin>>q[i].l>>q[i].r,q[i].id=i;
    sort(q+1,q+1+qu);
    for(int i=1,now=1;i<=num;++i){ //枚举每块处理询问
        int pl=R[i]+1,pr=R[i];
        ll sum=0;
        for(;pos[q[now].l]==i;now++){ 
            if(pos[q[now].l]==pos[q[now].r]){//左右同块 
                ll tmpsum=0;//暴力的答案和用于拓展的不要共用
                for(int j=q[now].l;j<=q[now].r;++j){ 
                    cnt[a[j]]++;
                    tmpsum=max(tmpsum,(ll)cnt[a[j]]*val[a[j]]);
                }
                for(int j=q[now].l;j<=q[now].r;++j)cnt[a[j]]--;
                ans[q[now].id]=tmpsum;
            }else{ //左右都延伸
                while(pr<q[now].r){ 
                    cnt[a[++pr]]++;
                    sum=max(sum,(ll)cnt[a[pr]]*val[a[pr]]);
                }
                int tmp=pl;//记下要回滚的状态
                ll rsum=sum;
                while(pl>q[now].l){ 
                    cnt[a[--pl]]++;
                    sum=max(sum,(ll)cnt[a[pl]]*val[a[pl]]);
                }
                ans[q[now].id]=sum;
                sum=rsum;//回滚
                if(pos[q[now+1].l]==i)
                    while(pl<tmp)//只回滚左端点
                        cnt[a[pl++]]--;
                else//注意每块的最后一次回滚要清所有！！
                    for(int j=pl;j<=pr;++j)cnt[a[j]]--;
            }
        }
    }
    for(int i=1;i<=qu;++i)cout<<ans[i]<<"\n";
    return 0;
}

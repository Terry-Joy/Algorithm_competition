#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+5;
int n,m,a[maxn],pos[maxn],L[maxn/5],R[maxn/5],num,big,ans[maxn],b[maxn],mn[maxn],mx[maxn];
int tmpmx[maxn],tmpmn[maxn],tmpcnt,tmpval[maxn];
struct Q{ 
    int l,r,id;
    bool operator<(const Q&x)const{ 
        return (pos[l]^pos[x.l])?l<x.l:r<x.r;
    }
}q[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
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
    for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    int cnt=unique(b+1,b+1+n)-(b+1);
    for(int i=1;i<=n;++i)a[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
    cin>>m;
    for(int i=1;i<=m;++i)cin>>q[i].l>>q[i].r,q[i].id=i;
    sort(q+1,q+1+m);
    for(int i=1,now=1;i<=num;++i){ 
        int pl=R[i]+1,pr=R[i];
        int sum=0;
        for(;pos[q[now].l]==i;now++){ 
            if(pos[q[now].l]==pos[q[now].r]){ 
                int tmpsum=0;
                for(int j=q[now].l;j<=q[now].r;++j){ 
                    if(!mx[a[j]])
                        mx[a[j]]=mn[a[j]]=j;
                    else{ 
                        mx[a[j]]=j;
                        tmpsum=max(tmpsum,mx[a[j]]-mn[a[j]]);
                    }
                }
                for(int j=q[now].l;j<=q[now].r;++j)mn[a[j]]=mx[a[j]]=0;
                ans[q[now].id]=tmpsum;
            }else{ 
                while(pr<q[now].r){ 
                    pr++;
                    if(!mx[a[pr]])
                        mx[a[pr]]=mn[a[pr]]=pr;
                    else{ 
                        mx[a[pr]]=pr;
                        sum=max(sum,mx[a[pr]]-mn[a[pr]]);
                    }
                }
                int tmp=pl,tmpsum=sum;//答案、最值、指针全部回滚
                for(int j=q[now].l;j<=R[i];++j){ 
                    tmpval[++tmpcnt]=a[j];
                    tmpmn[tmpcnt]=mn[a[j]];
                    tmpmx[tmpcnt]=mx[a[j]];
                }
                while(pl>q[now].l){ 
                    pl--;
                    if(!mx[a[pl]])
                        mx[a[pl]]=mn[a[pl]]=pl;
                    else{ 
                        mn[a[pl]]=pl;
                        sum=max(sum,mx[a[pl]]-mn[a[pl]]);
                    }
                }
                ans[q[now].id]=sum;
                pl=tmp;sum=tmpsum;
                if(pos[q[now+1].l]==i){ 
                    while(tmpcnt){ 
                        mx[tmpval[tmpcnt]]=tmpmx[tmpcnt];
                        mn[tmpval[tmpcnt]]=tmpmn[tmpcnt];
                        tmpcnt--;
                    }
                }else{ 
                    tmpcnt=0;
                    for(int j=q[now].l;j<=pr;++j)
                        mn[a[j]]=mx[a[j]]=0;
                }
            }
        }
    }
    for(int i=1;i<=m;++i)cout<<ans[i]<<"\n";
    return 0;
}

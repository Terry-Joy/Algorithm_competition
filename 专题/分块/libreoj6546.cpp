#include<bits/stdc++.h>
#define cha(p1,p2,p3) det(p2-p1,p3-p1)
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],pos[maxn],mxpos[maxn],cnt[maxn],cnt1=0,cnt2=0,add[maxn],n,m,L[maxn],R[maxn],big,num;
typedef long long ll;
struct P{
    ll x,y;
    P(ll _x=0,ll _y=0):x(_x),y(_y){}
    P operator-(P p){return P(x-p.x,y-p.y);}
    bool operator<(const P&a)const{
        return x==a.x?y<a.y:x<a.x;
    }
}ch[1300][400],p[1300][400];
ll mx[maxn];
ll det(P a,P b){return a.x*b.y-a.y*b.x;}
void Andrew(int d,int x){
    cnt[x]=0;
    for(int i=1;i<=d;++i){
        while(cnt[x]>1&&cha(ch[x][cnt[x]-2],ch[x][cnt[x]-1],p[x][i])<=0)cnt[x]--;
        ch[x][cnt[x]++]=p[x][i];
    }
	cnt[x]--;
    mxpos[x]=0;
    while(mxpos[x]<cnt[x]&&ch[x][mxpos[x]].y>=ch[x][mxpos[x]+1].y)mxpos[x]++;
    mx[x]=-ch[x][mxpos[x]].y;
}
void pushDown(int x){
    if(add[x]){
        for(int i=L[x];i<=R[x];++i)a[i]+=add[x];
        add[x]=0;
    }
}
void rebuild(int x){
    pushDown(x);
    int sz=0;
    for(int i=L[x];i<=R[x];++i){
        p[x][++sz].x=b[i];
        p[x][sz].y=-1ll*b[i]*a[i];
    }
    sort(p[x]+1,p[x]+sz+1);
    Andrew(sz,x);
}
bool check(int k,P a,P b){
    return a.x*k-a.y<=b.x*k-b.y;
}
void update(int l,int r,int val){
    int pl=pos[l],pr=pos[r];
    if(pl==pr){
        for(int i=l;i<=r;++i)a[i]+=val;
        rebuild(pl);
    }else{
        for(int i=l;i<=R[pl];++i)a[i]+=val;
        rebuild(pl);
        for(int i=L[pr];i<=r;++i)a[i]+=val;
        rebuild(pr);
        for(int i=pl+1;i<=pr-1;++i){
            add[i]+=val;
            while(mxpos[i]<cnt[i]&&check(add[i],ch[i][mxpos[i]],ch[i][mxpos[i]+1]))++mxpos[i];
            mx[i]=add[i]*ch[i][mxpos[i]].x-ch[i][mxpos[i]].y;
        }
    }
}
void Swap(int x,int y){
    swap(b[x],b[y]);
    int pl=pos[x],pr=pos[y];
    if(pl==pr)rebuild(pl);
    else{
        rebuild(pl);rebuild(pr);
    }
}
ll query(int l,int r){
    int pl=pos[l],pr=pos[r];
    ll ans=0;
    if(pl==pr){
        rebuild(pl);
        for(int i=l;i<=r;++i)ans=max(ans,1ll*a[i]*b[i]);
    }else{
        rebuild(pl);
        for(int i=l;i<=R[pl];++i)ans=max(ans,1ll*a[i]*b[i]);
        rebuild(pr);
        for(int i=L[pr];i<=r;++i)ans=max(ans,1ll*a[i]*b[i]);
        for(int i=pl+1;i<=pr-1;++i)ans=max(ans,mx[i]);
    }
    return ans;
}
void init(){
    big=sqrt(n/16)+1;
    num=(n-1)/big+1;
    for(int i=1;i<=num;++i){
        L[i]=(i-1)*big+1;
        R[i]=i*big;
    }
    R[num]=n; 
    for(int i=1;i<=num;++i){
        for(int j=L[i];j<=R[i];++j){
            pos[j]=i;
        }
    }
    for(int i=1;i<=num;++i)rebuild(i);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)scanf("%d",&b[i]);
    init();
    int op,l,r,x;
    for(int i=1;i<=m;++i){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%d",&l,&r,&x);
            update(l,r,x);
        }else if(op==2){
            scanf("%d%d",&l,&r);
            Swap(l,r);
        }else{
            scanf("%d%d",&l,&r);
            cout<<query(l,r)<<"\n";
        }
    }
    return 0;
}
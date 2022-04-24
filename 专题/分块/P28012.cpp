#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn],b[maxn],L[maxn],R[maxn],pos[maxn],add[maxn+10],num,n,q,p[maxn],c[maxn],cnt1,cnt2,big;
char s[2];
void change(int x,int l,int r){
    for(int i=L[x];i<=R[x];++i){
        if(p[i]>=l&&p[i]<=r)c[++cnt1]=a[p[i]];
        else c[++cnt2]=a[p[i]];
    }
    merge(c+1,c+cnt1+1,c+cnt1+1,c+cnt2+1,b+L[x]);
}
void update(int l,int r,int val){
    int pl=pos[l],pr=pos[r];
    cnt1=0,cnt2=r-l+1;
    if(pl==pr){
        for(int i=l;i<=r;++i)a[i]+=val;
        change(pl,l,r);
    }else{
        for(int i=pl+1;i<=pr-1;++i)add[i]+=val;
        for(int i=l;i<=R[pl];++i)a[i]+=val;
        cnt2=R[pl]-l+1;
        change(pl,l,r);
        cnt1=0;cnt2=r-L[pr]+1;
        for(int i=L[pr];i<=r;++i)a[i]+=val;
        change(pr,l,r);
    }
}
int query(int l,int r,int k){
    int ans=0;
    int pl=pos[l],pr=pos[r];
    if(pl==pr){
        for(int i=l;i<=r;++i)ans+=((a[i]+add[pl])>=k);
    }else{
        for(int i=l;i<=R[pl];++i)ans+=((a[i]+add[pl])>=k);
        for(int i=L[pr];i<=r;++i)ans+=((a[i]+add[pr])>=k);
        for(int i=pl+1;i<=pr-1;++i){
            ans+=(R[i]-(lower_bound(b+L[i],b+R[i]+1,k-add[i])-b)+1);
        }
    }
    return ans;
}
bool cmp(int x,int y){return a[x]<a[y];}
void init(){
    big=sqrt(n*log2(n)*1.65)+1;//防止分不了块 
    num=(n-1)/big+1;
    for(int i=1;i<=num;++i){
        L[i]=R[i-1]+1;
        R[i]=i*big;
    }
    R[num]=n;
    for(int i=1;i<=num;++i){
        for(int j=L[i];j<=R[i];++j){
            pos[j]=i;
        }
        sort(p+L[i],p+R[i]+1,cmp);
    }
    for(int i=1;i<=n;++i)b[i]=a[p[i]];
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]),p[i]=i;
    init();
    int l,r,x;
    for(int i=1;i<=q;++i){
        scanf("%s",s);
        scanf("%d%d%d",&l,&r,&x);
        if(s[0]=='A'){
            cout<<query(l,r,x)<<"\n";
        }else{
            update(l,r,x);
        }
    }
    return 0;
}
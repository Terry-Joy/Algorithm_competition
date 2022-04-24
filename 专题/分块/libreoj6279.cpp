#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],op,l,r,L[1500],R[1500],pos[maxn],add[1500],b[maxn],p[maxn],c[1500],cnt1,cnt2;
bool cmp(int x,int y){return a[x]<a[y];}
void change(int x,int l,int r){
    for(int i=L[x];i<=R[x];++i){
        if(p[i]>=l&&p[i]<=r)c[++cnt1]=p[i];
        else c[++cnt2]=p[i];
    }
    merge(c+1,c+cnt1+1,c+cnt1+1,c+R[x]-L[x]+2,p+L[x],cmp);
    for(int i=L[x];i<=R[x];++i)b[i]=a[p[i]];
}
void update(int l,int r,int val){
    int pl=pos[l],pr=pos[r];
    if(pl==pr){
        cnt1=0;cnt2=r-l+1;
        for(int i=l;i<=r;++i)a[i]+=val;
        change(pl,l,r);
    }else{
        for(int i=pl+1;i<=pr-1;++i)add[i]+=val;
        for(int i=l;i<=R[pl];++i)a[i]+=val;
        cnt1=0;cnt2=R[pl]-l+1;
        change(pl,l,r);
        for(int i=L[pr];i<=r;++i)a[i]+=val;
        cnt1=0;cnt2=r-L[pr]+1;
        change(pr,l,r);
    }
}
int query(int l,int r,int k){
    int pl=pos[l],pr=pos[r],ans=-1;
    if(pl==pr){
        for(int i=l;i<=r;++i)
            ans=(a[i]+add[pl]<k)?max(ans,a[i]+add[pl]):ans;
    }else{
        for(int i=pl+1;i<=pr-1;++i){
            int x=lower_bound(b+L[i],b+R[i]+1,k-add[i])-b-1;
            ans=((x<L[i])?ans:max(b[x]+add[i],ans));
        }
        for(int i=l;i<=R[pl];++i)
            ans=(a[i]+add[pl]<k)?max(ans,a[i]+add[pl]):ans;
        for(int i=L[pr];i<=r;++i)
            ans=(a[i]+add[pr]<k)?max(ans,a[i]+add[pr]):ans;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],p[i]=i;
    int big=sqrt(n*log2(n)*1.65),num=0;
    for(int i=1;i;++i){
        L[i]=(i-1)*big+1;
        R[i]=i*big;
        if(R[i]>=n){
            R[i]=n;num=i;break;
        }
    }
    for(int i=1;i<=num;++i){
        for(int j=L[i];j<=R[i];++j)
            pos[j]=i;
        sort(p+L[i],p+R[i]+1,cmp);//记得传cmp
    }
    for(int i=1;i<=n;++i)b[i]=a[p[i]];
    int d;
    for(int i=1;i<=n;++i){
        cin>>op>>l>>r>>d;
        if(op==1){
            cout<<query(l,r,d)<<"\n";
        }else{
            update(l,r,d);
        }
    }
    return 0;
}
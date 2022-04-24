#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn],b[maxn],L[maxn+10],R[maxn+10],pos[maxn],add[maxn+10],num,n,q;
char s[2];
void update(int l,int r,int val){
    int pl=pos[l],pr=pos[r];
    if(pl==pr){
        for(int i=l;i<=r;++i)a[i]+=val;
        for(int i=L[pl];i<=R[pl];++i)b[i]=a[i];
        sort(b+L[pl],b+R[pl]+1);
    }else{
        for(int i=pl+1;i<=pr-1;++i)add[i]+=val;
        for(int i=l;i<=R[pl];++i)a[i]+=val;
        for(int i=L[pl];i<=R[pl];++i)b[i]=a[i];
        sort(b+L[pl],b+R[pl]+1);
        for(int i=L[pr];i<=r;++i)a[i]+=val;
        for(int i=L[pr];i<=R[pr];++i)b[i]=a[i];
        sort(b+L[pr],b+R[pr]+1);
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
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    num=sqrt(n);
    for(int i=1;i<=num;++i){
        L[i]=(i-1)*num+1;
        R[i]=i*num;
    }
    if(R[num]<n){
        ++num;
        L[num]=R[num-1]+1;
        R[num]=n;
    }
    for(int i=1;i<=num;++i){
        for(int j=L[i];j<=R[i];++j){
            b[j]=a[j];
            pos[j]=i;
        }
        sort(b+L[i],b+R[i]+1);
    }
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
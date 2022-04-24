#include<bits/stdc++.h>
using namespace std;
const int maxn=40005;
int cnt[250][maxn],mx[250][250],ans[250][250],tmp[maxn];
int a[maxn],n,m,big,pos[maxn],num,L[250],R[250],b[maxn],id[maxn],c;
void init(){
    big=sqrt(n);
    num=(n-1)/big+1;
    for(int i=1;i<=num;++i){
        L[i]=(i-1)*big+1;
        R[i]=i*big;
    }
    R[num]=n;
    for(int i=1;i<=num;++i)
        for(int j=L[i];j<=R[i];++j)pos[j]=i;
    sort(b+1,b+1+n);
    c=unique(b+1,b+1+n)-(b+1);
    for(int i=1;i<=n;++i){
        int x=lower_bound(b+1,b+1+c,a[i])-b;
        id[x]=a[i];
        a[i]=x;
    }
    for(int i=1;i<=n;++i){
        cnt[pos[i]][a[i]]++;
    } 
    for(int i=2;i<=num;++i){
        for(int j=1;j<=c;++j)
            cnt[i][j]+=cnt[i-1][j];
    }
    for(int i=1;i<=num;++i){
        int x=0,z=0;//mx ans
        for(int j=L[i];j<=n;++j){
            tmp[a[j]]++;
            if(tmp[a[j]]>x)x=tmp[a[j]],z=a[j];
            else if(tmp[a[j]]==x&&z!=a[j]){
                z=min(z,a[j]);
            }
            mx[i][pos[j]]=x;ans[i][pos[j]]=z;
        }
        for(int j=L[i];j<=n;++j)tmp[a[j]]--;
    }
}
int query(int l,int r){
    int pl=pos[l],pr=pos[r];
    if(pl==pr){
        int x=0,z=0;
        for(int i=l;i<=r;++i){
            tmp[a[i]]++;
            if(tmp[a[i]]>x)x=tmp[a[i]],z=a[i];
            else if(tmp[a[i]]==x&&z!=a[i]){
                z=min(z,a[i]);
            }
        }
        for(int i=l;i<=r;++i)tmp[a[i]]--;
        return z;
    }else{
        int x=mx[pl+1][pr-1],z=ans[pl+1][pr-1];
        for(int i=l;i<=R[pl];++i)tmp[a[i]]=cnt[pr-1][a[i]]-cnt[pl][a[i]];
        for(int i=l;i<=R[pl];++i){
            tmp[a[i]]++;
            if(tmp[a[i]]>x)x=tmp[a[i]],z=a[i];
            else if(tmp[a[i]]==x&&a[i]!=z)z=min(z,a[i]);
        }
        for(int i=L[pr];i<=r;++i)
            tmp[a[i]]=tmp[a[i]]?tmp[a[i]]:cnt[pr-1][a[i]]-cnt[pl][a[i]];
        for(int i=L[pr];i<=r;++i){
            tmp[a[i]]++;
            if(tmp[a[i]]>x)x=tmp[a[i]],z=a[i];
            else if(tmp[a[i]]==x&&a[i]!=z)z=min(z,a[i]);
        }
        for(int i=l;i<=R[pl];++i)tmp[a[i]]=0;
        for(int i=L[pr];i<=r;++i)tmp[a[i]]=0;
        return z;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]),b[i]=a[i];
    init();
    int l,r,anss=0;
    for(int i=1;i<=m;++i){
        scanf("%d%d",&l,&r);
        l=(l+anss-1)%n+1;r=(r+anss-1)%n+1;
        if(l>r)swap(l,r);
        cout<<(anss=id[query(l,r)])<<"\n";
    }
    return 0;
}
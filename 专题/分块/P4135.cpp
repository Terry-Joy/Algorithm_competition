#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int cnt[400][maxn],ans[400][400],a[maxn],big,num,L[400],R[400],pos[maxn],sum[maxn],n,c,m;
void init(){
    big=sqrt(n);
    num=(n-1)/big+1;
    for(int i=1;i<=num;++i){
        L[i]=(i-1)*big+1;
        R[i]=i*big;
    }
    R[num]=n;
    for(int i=1;i<=num;++i){
        for(int j=L[i];j<=R[i];++j)
            pos[j]=i;
    }
    for(int i=1;i<=n;++i){
        cnt[pos[i]][a[i]]++;
    }
    for(int i=2;i<=num;++i){
        for(int j=1;j<=c;++j)
            cnt[i][j]+=cnt[i-1][j];
    }
    for(int i=1;i<=num;++i){
        int s=0;
        for(int j=L[i];j<=n;++j){
            sum[a[j]]++;
            if((sum[a[j]]&1)==0)s++;//维护到当前为止的个数！
            else if(sum[a[j]]>2)s--;//&的优先级比==低
            ans[i][pos[j]]=s;
        }
        for(int j=L[i];j<=n;++j)sum[a[j]]=0;       
    }
}
int query(int l,int r){
    int pl=pos[l],pr=pos[r],res=0;
    if(pl==pr){
        for(int i=l;i<=r;++i){
            sum[a[i]]++;
            if((sum[a[i]]&1)==0)res++;
            else if(sum[a[i]]>2)res--;
        }
        for(int i=l;i<=r;++i)sum[a[i]]--;
    }else{
        res=ans[pl+1][pr-1];
        for(int i=l;i<=R[pl];++i)sum[a[i]]=cnt[pr-1][a[i]]-cnt[pl][a[i]];
        for(int i=l;i<=R[pl];++i){
            sum[a[i]]++;
            if((sum[a[i]]&1)==0)res++;
            else if(sum[a[i]]>2)res--;
        }
        for(int i=L[pr];i<=r;++i)
            sum[a[i]]=sum[a[i]]?sum[a[i]]:cnt[pr-1][a[i]]-cnt[pl][a[i]];
        for(int i=L[pr];i<=r;++i){
            sum[a[i]]++;
            if((sum[a[i]]&1)==0)res++;
            else if(sum[a[i]]>2)res--;
        }
        for(int i=l;i<=R[pl];++i)sum[a[i]]=0;
        for(int i=L[pr];i<=r;++i)sum[a[i]]=0;
    }
    return res;
}
int main(){
    scanf("%d%d%d",&n,&c,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    init();
    int l,r,anss=0;
    for(int i=1;i<=m;++i){
        scanf("%d%d",&l,&r);
        l=(l+anss)%n+1;r=(r+anss)%n+1;
        if(l>r)swap(l,r);
        cout<<(anss=query(l,r))<<"\n";
    }
    return 0;
}
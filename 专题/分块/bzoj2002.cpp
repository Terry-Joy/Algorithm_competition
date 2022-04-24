#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,big,num,L[maxn],R[maxn],pos[maxn],ans[maxn],res[maxn],a[maxn],op,x,k,cnt,tmp[maxn];
void init(){
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
    for(int i=n;i>=1;--i){
        if(i+a[i]>R[pos[i]]){
            ans[i]=1;
            res[i]=i+a[i];
        }else{
            ans[i]=ans[i+a[i]]+1;
            res[i]=res[i+a[i]];
        }
    }
}
int query(int x){
    int sum=0;  
    while(x<=n){
        sum+=ans[x];
        x=res[x];
    }
    return sum;
}
void update(int x,int k){
    a[x]=k;
    int pl=pos[x];
    for(int i=x;i>=L[pl];--i){
        if(i+a[i]>R[pl]){
            ans[i]=1;
            res[i]=i+a[i];
        }else{
            ans[i]=ans[i+a[i]]+1;
            res[i]=res[i+a[i]];
        }
    }
}
int main(){
    scanf("%d",&n);
    big=sqrt(n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    init();
    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        scanf("%d%d",&op,&x);
        x++;
        if(op==1){
            cout<<query(x)<<"\n";
        }else{
            scanf("%d",&k);
            update(x,k);
        }
    }
    return 0;
}
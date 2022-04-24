#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
int t,n,a[maxn];
int vis[maxn];
int main(){
    cin>>n;
    vis[0]=1;
    int x1=0,x2=0,x3=0,x4=0;
    for(int i=2;i<=n;++i){ 
        printf("XOR 1 %d\n",i);
        fflush(stdout);
        cin>>a[i];
        if(vis[a[i]])  x1=vis[a[i]],x2=i; 
        else vis[a[i]]=i;
        if(a[i]==1)x3=i;
        if(a[i]==2)x4=i;
    }
    if(x1){ //重复
        printf("AND %d %d\n",x1,x2);
        fflush(stdout);
        cin>>x2;
        a[1]=x2^a[x1];
        for(int i=2;i<=n;++i)a[i]^=a[1];
    }
    else{ //不重
        printf("AND 1 %d\n",x3);
        fflush(stdout);
        cin>>x2;
        printf("AND 1 %d\n",x4);
        fflush(stdout);
        cin>>x1;
        if(x1&1)x2++;
        a[1]=x2;
        for(int i=2;i<=n;++i)a[i]^=a[1];
    }
    cout<<"! ";
    for(int i=1;i<=n;++i)cout<<a[i]<<" ";
    fflush(stdout);
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e5+5;
int a[maxn],n,q;
bool v[maxn];
ll ans=0;
void del(int x){
    if(!v[x])return;
    v[x]=0;
    if(a[x]<a[x-1]&&a[x]<a[x+1])ans+=a[x];
    else if(a[x]>a[x-1]&&a[x]>a[x+1])ans-=a[x];
}   
void add(int x){
    if(v[x])return;
    v[x]=1;
    if(a[x]<a[x-1]&&a[x]<a[x+1])ans-=a[x];
    else if(a[x]>a[x-1]&&a[x]>a[x+1])ans+=a[x];
}
int main(){ 
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        ans=0;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]),v[i]=0;
        a[n+1]=a[0]=0;
        for(int i=1;i<=n;++i){
            if(a[i]>a[i-1]&&a[i]>a[i+1])ans+=a[i],v[i]=1;
            else if(a[i]<a[i-1]&&a[i]<a[i+1])ans-=a[i],v[i]=1;
        }
        cout<<ans<<endl;
        for(int i=1;i<=q;++i){
            int l,r;
            scanf("%d%d",&l,&r);
            if(l==r){cout<<ans<<endl;continue;}
            del(l-1);del(l);del(l+1);
            del(r-1);del(r);del(r+1);
            swap(a[l],a[r]);
            add(l-1);add(l);add(l+1);
            add(r-1);add(r);add(r+1);
            cout<<ans<<endl;
        }
    }
    return 0;
}

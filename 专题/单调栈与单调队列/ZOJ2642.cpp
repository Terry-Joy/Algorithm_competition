#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int INF=-1;
int n,q[maxn],t,a[maxn],l[maxn],r[maxn];
ll sum[maxn];
int main()
{
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]),sum[i]=sum[i-1]+1ll*a[i],l[i]=r[i]=i;
        a[n+1]=INF;
        t=0;
        for(int i=1;i<=n+1;++i){
           int cnt=q[t]; 
           while(t>0&&a[i]<a[q[t]])r[q[t--]]=cnt;
           q[++t]=i; 
        }
        t=0;
        a[0]=INF;
        for(int i=n;i>=0;--i){ 
            int cnt=q[t];
            while(t>0&&a[i]<a[q[t]])l[q[t--]]=cnt;
            q[++t]=i;
        }
        ll ans=-1;
        int ans1,ans2;
        for(int i=1;i<=n;++i)
            if(1ll*a[i]*(sum[r[i]]-sum[l[i]-1])>ans)
                ans=1ll*a[i]*(sum[r[i]]-sum[l[i]-1]),ans1=l[i],ans2=r[i];
        printf("%lld\n",ans);
        printf("%d %d\n",ans1,ans2);
    }
    return 0; 
}

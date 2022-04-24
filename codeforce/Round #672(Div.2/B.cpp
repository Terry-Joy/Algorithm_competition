#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int a[maxn],cnt[34];
void ins(int x){
    int ans=0;
    while(x){
        ans++;
        x>>=1;
    }
    cnt[ans]++;
}
int main(){ 
    int t;
    scanf("%d",&t);
    while(t--){ 
        memset(cnt,0,sizeof(cnt));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=1;i<=n;++i)ins(a[i]);
        ll ans=0;
        for(int i=1;i<=32;++i){
            ans+=1ll*cnt[i]*(cnt[i]-1)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}

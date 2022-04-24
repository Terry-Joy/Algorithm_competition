#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+5;
int t,n;
ll d[maxn];//两倍数组
map<ll,int>cnt,cnt2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    while(t--){
        cnt.clear();
        cnt2.clear();
        cin>>n;
        for(int i=1;i<=2*n;++i)cin>>d[i],cnt[d[i]]++;
        sort(d+1,d+1+2*n);
        bool f=1;
        for(int i=1;i<=2*n;++i){ 
            if(cnt[d[i]]%2!=0||d[i]%2!=0)f=0;
        }
        if(!f){ 
            cout<<"NO"<<"\n";
            continue;
        }
        ll D=d[2*n];
        if(D%(2*n)!=0)f=0;
        ll now=D/(2*n);
        cnt2[now]++;
        ll sum=now;
        for(int i=n-1;i>=1;--i){ 
            if(!f)break;
            ll D=d[2*i];
            if((D-2*sum)%(2*i)!=0)f=0;
            now=(D-2*sum)/(2*i);
            sum+=now;
            if(cnt2[now]==1)f=0;
            cnt2[now]++;
            if(now<=0)f=0;
        }
        cout<<(f?"YES":"NO")<<"\n";
    }
    return 0;
}

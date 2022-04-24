#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
typedef pair<int,int>P;
map<P,int>mp;
int x[maxn],y[maxn];
const int inf=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
    if(n<3){cout<<"0\n";return 0;}
    int cnt=0;
    for(int i=1;i<=n;++i){
        mp.clear();
        for(int j=i+1;j<=n;++j){
            int dx=x[j]-x[i],dy=y[j]-y[i];
            if(dx<0){
                dx=-dx;dy=-dy;
            }
            if(!dx)dy=1;
            if(!dy)dx=1;
            if(dx&&dy){
                int g=__gcd(abs(dx),abs(dy));
                dx/=g;dy/=g;
            }
            cnt=max(cnt,++mp[{dx,dy}]);
        }
    }
    int ans=n/3;
    cnt++;
    if(cnt*3/2>n)ans=min(ans,n-cnt);
    cout<<ans<<"\n";
    return 0;
}
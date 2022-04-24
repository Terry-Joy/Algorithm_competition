#include<bits/stdc++.h>
#define fi first 
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,int>P;
priority_queue<P,vector<P>,greater<P> >q;
ll ans;
const int maxn=2e5+5;
const int INF=1e9;
int a[maxn],n,k;
inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}//是符号
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}//是数字
    return x*s;
}
inline void in(int&x){
    x=read();
}
int main(){
    in(n);in(k);
    for(int i=1;i<=n;++i){
        in(a[i]);
    }
    sort(a+1,a+1+n);
    q.push({a[1],1});
    for(int i=1;i<k;++i){
        P x=q.top();
        q.pop();
        if(x.se<n){
            q.push({x.fi-a[x.se]+a[x.se+1],x.se+1});
            q.push({x.fi+a[x.se+1],x.se+1});
        }
    }
    cout<<q.top().fi<<"\n";
    return 0;
}
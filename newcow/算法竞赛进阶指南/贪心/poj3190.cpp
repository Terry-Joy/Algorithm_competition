#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
struct P{
    int fi,se,id;
    bool operator<(const P&a)const{ 
        return se>a.se;
    }
}a[maxn];
bool cmp(P&a,P&b){ 
    if(a.fi==b.fi)return a.se<b.se;
    return a.fi<b.fi;
}
int n,work[maxn];
priority_queue<P>q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i].fi>>a[i].se,a[i].id=i;
    sort(a+1,a+1+n,cmp);
    int ans=0;
    ans++;
    work[a[1].id]=1;
    q.push(a[1]);
    for(int i=2;i<=n;++i){
        if(!q.empty()){
            P x=q.top();
            if(x.se<a[i].fi){ 
                work[a[i].id]=work[x.id];
                q.pop();
            }
            else{
                ans++;
                work[a[i].id]=ans;
            }
        }
        q.push(a[i]);
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;++i)
        cout<<work[i]<<"\n";
    return 0;
}

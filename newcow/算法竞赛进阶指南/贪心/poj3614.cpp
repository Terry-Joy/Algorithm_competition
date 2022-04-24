#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int maxn=2505; 
typedef pair<int,int> P;
P cow[maxn],sc[maxn];
priority_queue<int,vector<int>,greater<int> >q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,l;
    cin>>c>>l;
    for(int i=1;i<=c;++i)cin>>cow[i].fi>>cow[i].se;
    for(int i=1;i<=l;++i)cin>>sc[i].fi>>sc[i].se;
    sort(cow+1,cow+1+c);
    sort(sc+1,sc+1+l);
    int ans=0;
    int j=1;
    for(int i=1;i<=l;++i){
        while(j<=c&&cow[j].fi<=sc[i].fi){
            q.push(cow[j].se);
            ++j;
        }
        while(!q.empty()&&sc[i].se){
            int x=q.top();
            q.pop();
            if(x>=sc[i].fi)ans++,sc[i].se--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
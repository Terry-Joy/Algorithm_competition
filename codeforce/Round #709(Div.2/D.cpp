#include<bits/stdc++.h>
#define fi first 
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int>P;
int n,t;
const int maxn=1e5+5;
int nxt[maxn],a[maxn];
bool v[maxn];
vector<int>ans;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
queue<P>q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        ans.clear();
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i){
            nxt[i]=(i==n)?1:i+1;
            v[i]=0;
        }
        for(int i=1;i<=n;++i){
            if(gcd(a[i],a[nxt[i]])==1){
                q.push({i,nxt[i]});
            }
        }
        int sum=0;
        while(!q.empty()){
            int x1=q.front().fi,x2=q.front().se;
            q.pop();   
            if(v[x2]||v[x1])continue;
            v[x2]=1;
            sum++;
            ans.pb(x2);
            nxt[x1]=nxt[x2];
            if(gcd(a[x1],a[nxt[x1]])==1)q.push({x1,nxt[x1]});
        }
        cout<<sum;
        for(auto&v:ans)cout<<" "<<v;
        cout<<"\n";
    }
    return 0;
}
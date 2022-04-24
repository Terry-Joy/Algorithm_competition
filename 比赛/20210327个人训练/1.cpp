#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
const int N = 1e5+100, lg = 30;
 
struct Gauss{
    int a[lg];
    Gauss(){
        memset(a, 0, sizeof a);
    }
    void add(int x){
        for(int i = lg - 1; i >= 0; i--)
            if(x >> i & 1){
                if(a[i])
                    x ^= a[i];
                else{
                    a[i] = x;
                    break;
                }
            }
    }
    int mx(){
        int ans = 0;
        for(int i = lg - 1; i >= 0; i--)
            ans = max(ans, ans ^ a[i]);
        return ans;
    }
    int prune(int x){
    	for(int i=lg-1 ; i>=0 ; i--)
    		if(x >> i & 1)
    			if(a[i])
    				x ^= a[i];
    	return x;
    }
    int all(){
    	int ret=0;
    	for(int i=lg-1 ; i>=0 ; i--)
    		if(!(ret >> i & 1) && a[i])
    			ret ^= a[i];
    	return ret;
    }
} gs;
 
int a[N];
bool mark[N];
 
vector<ii> g[N];
 
void dfs(int v){
	mark[v] = true;
	for(auto U : g[v]){
		int u = U.first, w = U.second;
		if(!mark[u]){
			a[u] = a[v] ^ w;
			dfs(u);
		}
		else
			gs.add(w^a[v]^a[u]);
	}
}
 
ll sum[N];
 
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, q;cin >> n >> m >> q;
    for(int i=0 ; i<m ; i++){
    	int v, u, w;cin >> v >> u >> w;v --;u --;
    	g[v].push_back(ii(u, w));
    	g[u].push_back(ii(v, w));
    }
    dfs(0);
    for(int i=0 ; i<n ; i++)
    	a[i] = gs.prune(a[i]);
    int f = gs.all();
    // cerr << "f: ";
    // for(int i=lg-1 ; i>=0 ; i--)
    // 	if(gs.a[i])
    // 		cerr << "1";
    // 	else
    // 		cerr << "0";
    // cerr << "\n";
    for(int i=0 ; i<n ; i++){
    	sum[i] = sum[i-1] ^ a[i];
    	// cerr << i << ": " << bitset<30>(a[i]) << "\n";
    }
    while(q --){
    	int l, r;cin >> l >> r;l --;
    	ll cur = (r-l)*(r-l-1)/2, ans=0;
    	if(cur&1)
    		ans ^= f;
    	if((r-l)%2 == 0)
    		ans ^= sum[r-1] ^ (l ? sum[l-1] : 0);
    	cout << ans << "\n";
    }
}
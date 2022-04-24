#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn =1e6+5;
ll c1[maxn<<1], c2[maxn<<1], c3[maxn<<1];
ll sum(int x) {
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i) {
        res += c1[i] * (x + 2) * (x + 1) - c2[i] * (2 * x + 3) + c3[i];
    }
    return res / 2;
}
void add(int x, ll d, int n) {
    for (int i = x; i <= n; i += i & -i) {
        c1[i] += d;
        c2[i] += d * x;
        c3[i] += d * x * x;
    }
}
int a[maxn],e[maxn];
vector<int> pos[maxn];
int read(){ 
    char c=getchar();int x=0;
    while(c<'0'||c>'9'){ c=getchar();}
    while(c>='0'&&c<='9'){ x=x*10+c-'0';c=getchar();}
    return x;
}
int main() {
    int n,t;
  	t=read();
    while(t--){
    	n=read();
   		for (int i = 1; i <= n; i++) a[i]=read(),e[i]=a[i];
   		sort(e+1,e+1+n);
   		int m=unique(e+1,e+1+n)-(e+1);
		for(int i=1;i<=n;++i)a[i]=lower_bound(e+1,e+1+m,a[i])-(e+1),pos[a[i]].pb(i);
    	int wc = n + 1; 
    	ll ans = 0;
    	for (int i = 0; i < n; i++) {
        	pos[i].push_back(n + 1);
        	int pre = 0;
        	for (int j = 0; j < pos[i].size(); j++) {
            	int y = 2 * j - pre + wc, x = 2 * j - (pos[i][j] - 1) + wc;
            	ans += sum(y - 1) - (x >= 3 ? sum(x - 2) : 0);
            	add(x, 1, 2 * n + 1);
            	add(y + 1, -1, 2 * n + 1);
            	pre = pos[i][j];
        	}
        	pre = 0;
        	for (int j = 0; j < pos[i].size(); j++) {
            	int y = 2 * j - pre + wc, x = 2 * j - (pos[i][j] - 1) + wc;
            	add(x, -1, 2 * n + 1);
            	add(y + 1, 1, 2 * n + 1);
            	pre = pos[i][j];
        	}
    	}
    	for(int i=0;i<=n;++i)pos[i].clear();
    	for(int i=0;i<=2*n+1;++i)c1[i]=c2[i]=c3[i]=0;
    	cout<<ans<<"\n";
	}
    return 0;
}

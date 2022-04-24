#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
int Add(int x,int y){
	x+=y;
	if(x>=mod)x-=mod;
	return x;
}
struct BIT{
	#define lowb(x) (x&(-x))
	vector<int>c;
	void init(int x){
		c.resize(x);
	}
	void add(int x,int val){
		for(int i=x;i<c.size();i+=lowb(i)){
			c[i]=Add(c[i],val);
		}
	}
	int ask(int x){
		int ans=0;
		for(int i=x;i;i-=lowb(i)){
			ans=Add(ans,c[i]);
		}
		return ans;
	}
}bit1,bit2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,t;
	cin>>n;
	vector<tuple<int,int,int>>x(n);
	for(int i=0;i<n;++i)cin>>get<0>(x[i])>>get<1>(x[i]);
	for(int i=0;i<n;++i)get<2>(x[i])=i;
	sort(x.begin(),x.end(),[&](tuple<int,int,int>a,tuple<int,int,int>b){ 
		return get<0>(a)<get<0>(b);
	});
	cin>>t;
	vector<bool>vis(n+1,0);
	for(int i=1;i<=t;++i){
		int id;
		cin>>id;
		vis[id-1]=1;		
	}
	bit1.init(2*n+1);bit2.init(2*n+1);
	vector<int>dp(n,0);
	int ans=0;
	for(int i=n-1;i>=0;--i){
		dp[i]=Add(bit1.ask(get<1>(x[i])),1);
		bit1.add(get<1>(x[i]),dp[i]);
		if(vis[get<2>(x[i])])
			bit2.add(get<1>(x[i]),1);
		if(bit2.ask(n<<1)-bit2.ask(get<1>(x[i])-1))
			ans=Add(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
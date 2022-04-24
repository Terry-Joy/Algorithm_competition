#include<bits/stdc++.h>
using namespace std;
using ll=long long;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rand_num(seed);  // 大随机数
uniform_int_distribution<long long> WW(0,1000000);
uniform_int_distribution<long long> vi(0,1000000);
// 给定范围
uniform_int_distribution<int>dist(0,50000);
int main(){ 
    int n;
    ll W;
    W=WW(rand_num);
	int t=5;
	cout<<t<<"\n";
	while(t--){
		int T=5000;
		uniform_int_distribution<int>nn(0,T);
		n=nn(rand_num);
		cout<<n<<" "<<W<<"\n";
		uniform_int_distribution<long long>ww(0,W);
		for(int i=1;i<=n;++i){ 
			ll wi=WW(rand_num);
			ll v=vi(rand_num);
			cout<<wi<<" "<<v<<"\n";
		}
	}
    return 0;
}

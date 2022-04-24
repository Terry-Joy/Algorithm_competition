#include<bits/stdc++.h>
using namespace std;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rand_num(seed);  // 大随机数
uniform_int_distribution<int> WW(0,1000000000);
uniform_int_distribution<int> vi(0,1000000000);
int main(){
	freopen("6.in","w",stdout);
	int T=100000;
	cout<<T<<"\n";
	while(T--){
		int a=WW(rand_num),b=WW(rand_num);
		if(a>b)swap(a,b);
		if(!b)b++;
		int c=WW(rand_num),d=WW(rand_num);
		if(c>d)swap(c,d);
		if(!d)d++;
		int x=__gcd(c,d);
		c/=x;d/=x;
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
	}
	return 0;
}
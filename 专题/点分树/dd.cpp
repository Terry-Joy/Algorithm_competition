#include<bits/stdc++.h>
using namespace std;
using P=tuple<int,int,int>;
int main(){
	P a(0,0,0), b(1,2,3);
	a=max(a,b);
	cout<<(get<0>(a))<<" "<<(get<1>(a))<<" "<<(get<2>(a))<<" ";
	return 0;
}
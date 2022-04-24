#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>ans;
	int fi=(n&1)?n:n-1,sum=0;
	while(fi!=-1){
		sum++;
		ans.push_back(fi);
		fi-=2;
	}
	int se=(n&1)?n-1:n;
	if(se!=2){
		while(se!=0){
			sum++;
			ans.push_back(se);
			se-=2;
		}
	}
	cout<<sum<<"\n";
	for(auto&u:ans)cout<<u<<" ";
	return 0;
}
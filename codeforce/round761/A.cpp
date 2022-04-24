#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		string s1,s2,s3="abc";
		cin>>s1>>s2;
		sort(s1.begin(),s1.end());
		bool v[3]={0,0,0};
		for(auto u:s1){
			if(u=='a'||u=='b'||u=='c')
				v[u-'a']=1;
		}
		if((v[0]&v[1]&v[2])&&(s2==s3)){
			int L1=s1.find_first_of('a'),R1=s1.find_last_of('a');
			int L2=s1.find_first_of('b'),R2=s1.find_last_of('b');
			int L3=s1.find_first_of('c'),R3=s1.find_last_of('c');
			string res=s1.substr(0,R1-L1+1),res1=s1.substr(L2,R2-L2+1),res2=s1.substr(L3,R3-L3+1),res3=s1.substr(R3+1);
			string ans=res+res2+res1+res3;
			cout<<ans<<'\n';
		}else{
			cout<<s1<<"\n";
		}
	}
	return 0;
}
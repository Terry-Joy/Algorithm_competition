#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5],b[5],t;
ll ans=0;
int main(){
	cin>>t;
	while(t--){
		ans=0;
		for(int i=0;i<3;++i)scanf("%d",&a[i]);
		for(int i=0;i<3;++i)scanf("%d",&b[i]);
		for(int i=0;i<3;++i){
			int j=(i+1)%3;
			ans+=min(a[i],b[j]);
			if(a[i]>=b[j]){
				a[i]-=b[j];b[j]=0;
			}else{
				b[j]-=a[i];a[i]=0;
			}
		}
		for(int i=0;i<3;++i){
			if(a[i]>=b[i])a[i]-=b[i];
			else a[i]=0;
			ans-=a[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
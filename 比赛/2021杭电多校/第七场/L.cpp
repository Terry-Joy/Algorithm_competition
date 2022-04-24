#include<bits/stdc++.h>
using namespace std;
int n;
const int mod = 998244353;
const int maxn=1e5+5;
char ch[maxn];
int solve(vector<int> vec){
	vec.push_back(n+1);
	int ans=0,per=0,dif=0;
	for (int i=1;i<vec.size();i++){
		ans=(1ll*ans+1ll*per*(vec[i]-vec[i-1]))%mod;
		dif=(1ll*dif+2ll*vec[i-1]+vec[i]-vec[i-1])%mod;
		per=(per+dif)%mod;	
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--) { 
        scanf("%s",ch+1);
        n=strlen(ch+1);
     	ch[n+1]='\0';
    	vector<int> a[28];
    	for (int i=0;i<=25;i++) a[i].push_back(0);
    	for (int i=1;i<=n;i++) {
		    a[ch[i]-'a'].push_back(i);
    	}
	    int ans=0;
	    for (int i=0;i<=25;i++) {
	    	ans=(ans+solve(a[i]))%mod;
    	}
        cout<<ans<<"\n";
    }
}


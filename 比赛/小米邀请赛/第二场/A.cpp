#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
int n;
char s[maxn];
bool check(int mid){
	int a=0,b=0,c=0,d=0,f=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='2'){
			if(f<mid)a++,f++;
			else if(b>0)b--,c++;
		}else if(s[i]=='0'){
			if(a>0)a--,b++;
			else if(c>0)c--,d++;
		}
		if(d>=mid)return 1;
	}
	return 0;
}
int main(){

	while(~scanf("%d",&n)){
		scanf("%s",s+1);
		int l=0,r=n/4;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(mid))l=mid;
			else r=mid-1;
		}
		cout<<l<<"\n";
	}
	return 0;
} 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int ans=0,now=0;
	for(int i=1;i<=n;++i){
		ans+=now;
		now+=a[i];
	}
	printf("%.2f\n",ans*1.0/n);
	return 0;
}
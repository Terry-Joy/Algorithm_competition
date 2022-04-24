
#include<iostream>
typedef long long ll;
const int maxn=5e5+10;
int a[maxn],n,t[maxn];
ll ans=0;
using namespace std;
void msort(int l,int r){
	if(l>=r)return;
	int mid=l+r>>1;
	msort(l,mid);
	msort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
 		if(a[i]<=a[j])
		t[k++]=a[i++];
		else {
 			t[k++]=a[j++];
			ans+=mid-i+1;
		}
	}
	while(i<=mid)t[k++]=a[i++];
	while(j<=r)t[k++]=a[j++];
	for(int i=l;i<=r;++i)
		a[i]=t[i];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
 	cin>>n;
	for(int i=1;i<=n;++i)
	cin>>a[i];
	msort(1,n);
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5; 
int a[N];
int main(){
	int t;cin>>t;
	while(t--){
		int n,k,ans;
        scanf("%d%d",&n,&k);
        int mx=0x3f3f3f3f;
        k++;
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for(int i=1;i<=n-k+1;++i)
        {
           int l=a[i],r=a[i+k-1];
           int mid=l+r>>1;
           if(max(mid-l,r-mid)<mx) 
           {
              mx=max(mid-l,r-mid);
              ans=mid; 
           }
        }
        printf("%d\n",ans);
	} 
}

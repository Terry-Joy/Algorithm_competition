//dp[i]表示以长度为i的上升子序列中末尾元素的最小值（不存在则是INF） 
memset(dp,0x3f,sizeof(dp));
			for(int i=1;i<=p;++i)
				scanf("%d",&a[i]);
			dp[1]=a[1];
			int ans=1;
			for(int i=2;i<=p;++i)
			{
				if(a[i]>=dp[ans])
					dp[++ans]=a[i];
				else 
				        dp[upper_bound(dp+1,dp+len+1,a[i])-dp]=a[i];
			}
			printf("%d\n",ans);

//7_1的优化 树状数组优化DP O(nlogn) 
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn=1e5;
int dp[maxn],a[maxn],b[maxn],n,ans,cnt;
void add(int x,int val){
    while(x<=cnt){
        dp[x]=max(dp[x],val);
        x+=x&-x;
    }
}
int ask(int x){
    int ans=0;
    while(x){
        ans=max(dp[x],ans);
        x-=x&-x;
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    cnt=unique(b+1,b+1+n)-(b+1);
    for(int i=1;i<=n;++i)
        a[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
    for(int i=1;i<=n;++i){
        dp[i]=ask(a[i]-1)+1;
        ans=max(ans,dp[i]);
        add(a[i],dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
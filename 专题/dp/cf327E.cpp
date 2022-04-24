#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=1e9+7;
int dp[1<<24],a[25],id[2];
ll sum[1<<24];
inline int lowbit(int x){
    return x&(-x);
}
int main(){
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        sum[1<<i]=a[i];
    }
    scanf("%d",&k);
    for(int i=0;i<k;++i)
        scanf("%d",&id[i]);
    for(int i=0;i<n;++i)
        dp[1<<i]=(a[i]!=id[0]&&a[i]!=id[1])?1:0;
    for(int i=1;i<(1<<n);++i){
        sum[i]=sum[i^lowbit(i)]+sum[lowbit(i)];//自小到大真子集枚举
        if(sum[i]==id[0]||sum[i]==id[1])continue;
        for(int j=i;j;j-=lowbit(j)){//枚举每一个1
            dp[i]+=dp[i^lowbit(j)];
            if(dp[i]>=mod)dp[i]-=mod;//小常
        }
    }    
    printf("%d\n",dp[(1<<n)-1]);
    return 0;
}
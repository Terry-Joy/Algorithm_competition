#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e3+5;
int n,a[maxn];
ll ans=0;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;i+=2){ 
        ll sum=0,num=a[i];
        for(int j=i+1;j<=n;++j){ 
            if(j&1)sum+=a[j];
            else{ 
                if(a[j]<sum)sum-=a[j];
                else{ 
                    if(sum)ans++;//第2轮左括号出现 i必定有用于抵消
                    ans+=min(num,a[j]-sum);
                    num-=(a[j]-sum);
                    sum=0;
                    if(num<0)break;//=不能break 还有i不与右边匹配的贡献
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

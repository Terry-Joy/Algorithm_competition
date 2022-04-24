#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int maxn=1e6+5;
db f[maxn],sum[maxn];
int n,a,b;
int main(){
    f[0]=sum[0]=0;
    cin>>n>>a>>b;
    for(int i=1;i<=a;++i)f[i]=1,sum[i]=f[i]+sum[i-1];
    for(int i=a+1;i<=n;++i){
        if(!a){
            f[i]=1.0*(b-a+1)/(b-a)+(1.0/(b-a))*(sum[max(i-1,0)]-sum[max(i-b-1,0)]);
        }else{
            f[i]=1+(1.0/(b-a+1)*(sum[max(i-a,0)]-sum[max(i-b-1,0)]));
        }
        sum[i]=f[i]+sum[i-1];
    }
    printf("%.5lf\n",f[n]);
    return 0;
}   
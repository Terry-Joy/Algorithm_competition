#include<bits/stdc++.h>

using namespace std;
const double eps=1e-12;
double dp[(1<<20)+5];
double p[22];
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i)scanf("%lf",&p[i]);
        for(int i=((1<<n)-1);i>=0;--i){
            if(i==(1<<n)-1){dp[i]=0;continue;}
            dp[i]=1;
            double sum=0;
            for(int j=1;j<=n;++j){
                if(!((1<<(j-1))&i)){
                    sum+=p[j];
                    dp[i]+=p[j]*dp[i|(1<<(j-1))];
                }
            }
            /*if(fabs(sum)<eps){dp[i]=0;continue;}*/
            dp[i]/=sum;
        }
        printf("%.3lf\n",dp[0]);
    }
    return 0;
}
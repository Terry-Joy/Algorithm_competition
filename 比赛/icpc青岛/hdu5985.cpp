#include<bits/stdc++.h>

using namespace std;
typedef double db;
db f[12][105],g[12][105],p[12],ans[12];//f[i][k]第i种>=k步活,g[i][k]表示第i种在<=k已经无
int cnt[12],t,n;
db mypow(db a,int b){
    db ans=1;
    while(b){
        if(b&1)ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main(){
    scanf("%d",&t);
    while(t--){
        memset(ans,0,sizeof(ans));
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d%lf",&cnt[i],&p[i]);
        }
        if(n==1){
            puts("1.000000");continue;
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=100;++j)
               g[i][j]=mypow(1-mypow(p[i],j),cnt[i]),f[i][j]=1-g[i][j];
        for(int i=1;i<=n;++i){
            for(int j=1;j<=100;++j){
                db tmp=1;
                for(int k=1;k<=n;++k){
                    if(k!=i)tmp*=g[k][j];
                }
                ans[i]+=(f[i][j]-f[i][j+1])*tmp;
            }
        }           
        printf("%.6lf",ans[1]);
        for(int i=2;i<=n;++i)
            printf(" %.6lf",ans[i]);
        puts("");
    }
    return 0;
}
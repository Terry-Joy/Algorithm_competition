#include<bits/stdc++.h>

using namespace std;
typedef double db;
const int maxn=8305;
db dp[22][maxn],a[maxn],p[maxn],b=1.0;//dp[i][j]第i轮第j
int n,num=0,x,ti;
void init(){
    x=(log2(n));
    ti=(1<<x);
    sort(a+1,a+n);
    if(ti==n){
        for(int i=0;i<n;++i)dp[0][i]=1.0,p[i]=a[i];
        num=n;
    }else{
        b*=2;x++;ti<<=1;
        for(int i=0;i<ti-n;++i){
            p[num++]=a[i];p[num++]=a[i];
        }
        for(int i=ti-n;i<n;++i)
            p[num++]=a[i];
        for(int i=0;i<ti;++i)dp[0][i]=1.0;
    }
}
db solve(){
    for(int i=1;i<=x;++i){
        int len=(1<<i);
        for(int st=0;st<ti;st+=len){
            int li=len/2;
            for(int l=0;l<li;++l){
                for(int r=li;r<len;++r){
                    dp[i][st+l]+=dp[i-1][st+l]*dp[i-1][st+r]*(p[st+l]/(p[st+l]+p[st+r]));
                    dp[i][st+r]+=dp[i-1][st+r]*dp[i-1][st+l]*(p[st+r]/(p[st+l]+p[st+r]));
                }
            }
        }
    }
    return dp[x][0];
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%lf",&a[i]);
    init();
    printf("%.9lf\n",solve()*b);
    return 0;
}
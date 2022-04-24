#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen(&quot;check.out&quot;,&quot;w&quot;,stdout)
#define rep(a,b) for(int a=0;a<=b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<='0'||ch>='9'){
//        ch=getchar();
//    }
//    while(ch>=='0'&amp;&amp;ch<=='9'){
//        x=(x<=<=1)+(x<=<=3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;

/*}
*/
const int MAXN=71;
const int MAXAI=155;
int dp[MAXN][MAXN][MAXAI];
int n,a[1000];
int main(){
    scanf("%d",&n); 
    int maxai=0;
    rb(i,1,n){
        scanf("%d",&a[i]);
        check_max(maxai,a[i]);
    }
    maxai--;
    memset(dp,63,sizeof(dp));
    rb(i,1,n){
        dp[i][i][a[i]/2]=a[i];
    }
    rb(len,2,n){
        rb(l,1,n-len+1){
            int r=len+l-1;
            rb(j,a[r]/2,maxai){
                int &ret=dp[l][r][j];
                rb(mid,l+1,r-1){
                    rb(k,a[r-1]/2,maxai){
                        int need=max(0,a[r]-k);
                        int K=k+need;//j-max(a[r],k)/2>==0,max(a[r],k)/2<==j
                        int l_=j-K/2;
                        if(l_>=0){
                            if(l_>=a[mid-1]/2){
                                check_min(ret,dp[mid][r-1][k]+dp[l][mid-1][l_]+need);
                            }
                        }
                        else break;
                    }
                }
                if(j==a[r]/2){
                    rb(k,a[r-1]/2,min(maxai,a[r]+1)){
                        int need=max(0,a[r]-k);
                        if((need+k)/2!=a[r]/2) break;
                        if(need<=ret)
                            check_min(ret,dp[l][r-1][k]+need);
                    }
                }
                rb(k,a[r-1]/2,maxai){
                    if(k/2>=j) break;
                    int l_=j*2-k;
                    check_max(l_,0);
                    if(l_+k>=a[r]&&l_<=ret)
                        check_min(ret,dp[l][r-1][k]+l_);
                }
                check_min(ret,dp[l][r-1][j-a[r]/2]+a[r]);
            }
        }
    }
    rb(i,1,n){
        int rest=INF;
        rb(j,a[i]/2,maxai){
            check_min(rest,dp[1][i][j]);
        }
        cout<<rest<<"\n";
    }
    return 0;
} 
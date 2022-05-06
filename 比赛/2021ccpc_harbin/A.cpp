#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=110,MAXM=1e5+10,mod=1e9+7,base=13331;
int n,len[MAXN];
string s[MAXN],rs[MAXN];
vector<ull>h[MAXN],rh[MAXN];
ull power[MAXM];
vector<ll>f[MAXN][MAXN],g[MAXN][MAXN],sumf[MAXN][MAXN],sumg[MAXN][MAXN];
ll ans;
ull gethash(const vector<ull>& h,int i,int j){return h[j]-h[i-1]*power[j-i+1];}
int valid(int x,int y,int l1,int r1,int l2,int r2){return gethash(h[x],l1,r1)==gethash(rh[y],len[y]-r2+1,len[y]-l2+1);}
void add(ll& x,ll y){x=(x+y)%mod;}
int main(){
    power[0]=1;rep(i,1,1e5)power[i]=power[i-1]*base;
    cin>>n;
    rep(i,1,n){
        cin>>s[i];len[i]=s[i].length();rs[i]=s[i];reverse(rs[i].begin(),rs[i].end());
        s[i]=" "+s[i];rs[i]=" "+rs[i];
        h[i].resize(len[i]+10);rh[i].resize(len[i]+10);
        rep(j,1,len[i])h[i][j]=h[i][j-1]*base+(s[i][j]-'a'+1);
        rep(j,1,len[i])rh[i][j]=rh[i][j-1]*base+(rs[i][j]-'a'+1);
    }
    rep(i,1,n)rep(j,i,n){
        f[i][j].resize(len[i]+10);g[i][j].resize(len[j]+10);
        fill(f[i][j].begin(),f[i][j].end(),0);
        fill(f[i][j].begin(),f[i][j].end(),0);
        sumf[i][j].resize(len[i]+10);sumg[i][j].resize(len[j]+10);
        fill(sumf[i][j].begin(),sumf[i][j].end(),0);
        fill(sumg[i][j].begin(),sumg[i][j].end(),0);
    }
    //初始化
    //两个串的
    rep(i,1,n)rep(j,i+1,n){
        int l=min(len[i],len[j]);
        if(!valid(i,j,len[i]-l+1,len[i],1,l))continue;
        if(len[i]>=len[j])add(f[i][j][len[i]-len[j]],1);
        else add(g[i][j][len[j]-len[i]],1);
    }
    
    //一个串的
    rep(i,1,n){
        rep(j,1,len[i]-1){
            int l=min(j,len[i]-j);
            if(!valid(i,i,j-l+1,j,j+1,j+l))continue;
            if(j>=len[i]-j)add(f[i][i][j-len[i]+j],1);
            else add(g[i][i][len[i]-j-j],1);
        }
        //以某个字符为回文中心的
        if(len[i]==1){
            add(f[i][i][0],1);
            continue;
        }
        add(f[i][i][len[i]-1],1);add(g[i][i][len[i]-1],1);
        rep(j,2,len[i]-1){
            int l=min(j-1,len[i]-j);
            if(!valid(i,i,j-l,j-1,j+1,j+l))continue;
            if(j-1 >= len[i]-j)add(f[i][i][j-1-len[i]+j],1);
            else add(g[i][i][len[i]-j-j+1],1);
        }
    }
    
    //转移
    rep(l,2,n){
        rep(i,1,n){
            int j=i+l-1;if(j>n)break;
            rep(d,0,len[i]){
                sumf[i][j][d]=sumf[i][j-1][d];
                add(sumf[i][j][d],f[i][j-1][d]);
            }
            rep(d,0,len[j]){
                sumg[i][j][d]=sumg[i+1][j][d];
                add(sumg[i][j][d],g[i+1][j][d]);
            }
            rep(d,0,len[i]){
                if(len[j]<len[i]-d){
                    //删除右边的j  
                    if(valid(i,j,d+1,d+len[j],1,len[j])){
                        add(f[i][j][d],sumf[i][j][d+len[j]]);
                    }  
                }else{
                    //删除左边的i
                    if(valid(i,j,d+1,len[i],len[j]-(len[i]-d)+1,len[j])){
                        add(f[i][j][d],sumg[i][j][len[i]-d]);
                    }
                }
            }
            rep(d,1,len[j]){
                if(len[i]<=len[j]-d){
                    //删除左边的i
                    if(valid(i,j,1,len[i],len[j]-d-len[i]+1,len[j]-d)){
                        add(g[i][j][d],sumg[i][j][d+len[i]]);
                    }
                }else{
                    //删除左边的j
                    if(valid(i,j,1,len[j]-d,1,len[j]-d)){
                        add(g[i][j][d],sumf[i][j][len[j]-d]);
                    }
                }
            }
        }
    }
    //统计
    rep(i,1,n)rep(j,i,n){
        add(ans,f[i][j][0]);
    }
    printf("%lld\n",ans);
    
    return 0;
}
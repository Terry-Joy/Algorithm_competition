#include<bits/stdc++.h>
#define lowb(x) (x&(-x))
using namespace std;
const int maxm=650;
const int maxn=1e5+5;
typedef long long ll;
int n,m,pre[maxn],suf[maxn],big,num,L[maxm],R[maxm],pos[maxn],a[maxn],c[maxn],cnt[maxm][maxn];
ll dp[maxm][maxm];

    
    int bit[maxn];
    void add(int x,int val){
        for(int i=x;i<=n;i+=lowb(i))bit[i]+=val;
    }
    int ask(int x){
        int ans=0;
        for(int i=x;i;i-=lowb(i))ans+=bit[i];
        return ans;
    }
struct Node{
    int val,id;
    bool operator<(const Node&a)const{
        return val<a.val;
    }
}b[maxn];
inline int read(){
    char c=getchar();int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x;
}
inline void write(ll x){
    if(x>=10) write(x/10);putchar(x%10+'0');
}
inline ll readll(){
    char c=getchar();ll x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x;
}
int merge(int l1,int r1,int l2,int r2){
    int sum=0;
    while(l1<=r1&&l2<=r2){
        if(c[l1]<c[l2])l1++;
        else sum+=(r1-l1+1),l2++;
    }
    return sum;
}
void init(){
    num=(n-1)/big+1;
    for(int i=1;i<=num;++i){
        L[i]=R[i-1]+1;
        R[i]=i*big;
    }
    R[num]=n;
    for(int i=1;i<=num;++i){
        for(int j=L[i];j<=R[i];++j)
            pos[j]=i;
    }
    for(int i=1;i<=n;++i)b[i]={a[i],i};
    for(int i=1;i<=num;++i){
        sort(b+L[i],b+R[i]+1);
        for(int j=L[i];j<=R[i];++j){
            ++cnt[i][a[j]],c[j]=b[j].val;
        }
        int now=0;
        for(int j=L[i];j<=R[i];++j){//预处理前后缀和用于散块内部初始化
            add(a[j],1);
            now+=ask(n)-ask(a[j]);
            pre[j]=now;
        }
        dp[i][i]=now;
        for(int j=L[i];j<=R[i];++j){
            suf[j]=now;
            add(a[j],-1);
            now-=ask(a[j]-1);
        }
    }
    for(int i=1;i<=num;++i){
        for(int j=2;j<=n;++j)cnt[i][j]+=cnt[i][j-1];
    }
    for(int i=2;i<=num;++i){//处理cnt[i][j]前i个块<=j的个数
        for(int j=1;j<=n;++j)
            cnt[i][j]+=cnt[i-1][j];
    }
    for(int len=2;len<=num;++len){
        for(int i=1;i+len-1<=num;++i){//整块内部和整块之间处理
            int j=i+len-1;
            dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+merge(L[i],R[i],L[j],R[j]);
        }
    }
}
ll query(int l,int r){
    int pl=pos[l],pr=pos[r];
    if(pl==pr){
        int cnt1=0,cnt2=l-1-L[pl]+1;
        if(l==L[pl])return pre[r];
        else if(r==R[pl])return suf[l];
        for(int i=L[pl];i<=R[pl];++i){
            if(b[i].id>=l&&b[i].id<=r){
                c[++cnt2]=b[i].val;
            }else if(b[i].id<l){
                c[++cnt1]=b[i].val;
            }
        }
        return pre[r]-(l==L[pl]?0:pre[l-1])-merge(1,cnt1,cnt1+1,cnt2);
    }else{
        ll res=0;
        int cnt1=0,cnt2;
        res+=dp[pl+1][pr-1]+pre[r]+suf[l];
        for(int i=l;i<=R[pl];++i)
            res+=cnt[pr-1][a[i]-1]-cnt[pl][a[i]-1];
        for(int i=L[pr];i<=r;++i)
            res+=(cnt[pr-1][n]-cnt[pl][n])-(cnt[pr-1][a[i]]-cnt[pl][a[i]]);
        int aa=R[pl]-l+1,bb=R[pl]-l+1+r-L[pr]+1;
        for(int i=L[pl];i<=R[pl];++i){
            if(b[i].id>=l)
                c[++cnt1]=b[i].val;
            if(cnt1==aa)break;
		}
        cnt2=cnt1;
        for(int i=L[pr];i<=R[pr];++i){
            if(b[i].id<=r)
                c[++cnt2]=b[i].val;
            if(cnt2==bb)break;
		}
        res+=merge(1,cnt1,cnt1+1,cnt2);
        return res;
    }
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    big=0.55*sqrt(n);
    init();
    ll ans=0,l,r;
    while(m--){
        l=readll()^ans;r=readll()^ans;
        ans=query(l,r);
      	cout<<ans<<"\n";
    }
    return 0;
}
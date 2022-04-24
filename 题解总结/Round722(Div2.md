## A.Eshag Loves Big Arrays

**题意：**

给一个数组，每次可以选一个子序列，将其中所有严格大于平均数的数删去，问最多能删几个数

**思路**

贪心，最后留下来的一定是最小的，所以答案是n-最小的数量，注意只有最小值不能删

时间复杂度$O(n)$

```cpp
#include<bits/stdc++.h>
using namespace std;
int t,n,a[105];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        int mn=*min_element(a+1,a+1+n);
        int ans=0;
        for(int i=1;i<=n;++i)ans+=(a[i]==mn);
        cout<<(ans==n)?0:n-ans<<"\n";
    }
    return 0;
}
```

## B. Sifid and Strange Subsequences

题意：

给定一个数组，从其中选取一个子序列，其满足条件：序列中任意两对数的差值的绝对值不超过序列中的最大值。问最长的这种子序列有多长。 

思路：

显然负数和0可以全选，正数最多选一个，所以把绝对值差值丢进去排序，只要选的正数比<=min(abs)即可

```cpp
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e5+5;
int a[maxn];
vector<int>s,b;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        s.clear();
        b.clear();
        int ans=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            ans+=(a[i]<=0);
            if(a[i]<=0)s.pb(a[i]);
        }
        sort(s.begin(),s.end());
        int mx=2e9;
        for(int i=1;i<s.size();++i){
            mx=min(mx,abs(s[i]-s[i-1]));
        }
        for(int i=1;i<=n;++i){
            if(a[i]>0&&a[i]<=mx){
                ans++;break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
```

## C - Parsa's Humongous Tree

题意：

给定一棵具有![[公式]](https://www.zhihu.com/equation?tex=n(2\leq+n\leq+10^5))个结点的数，每个结点![[公式]](https://www.zhihu.com/equation?tex=u)有两个整数值![[公式]](https://www.zhihu.com/equation?tex=l_u%2Cr%0A_u%2C%281%5Cleq+l_u%5Cleq+r_u%5Cleq+10%5E9%29)。现在你可以为任一结点![[公式]](https://www.zhihu.com/equation?tex=u)分配一个值![[公式]](https://www.zhihu.com/equation?tex=a_u%2C(l_u\leq+a_u\leq+r_u))，使得这棵树的**美丽值**最大。

一棵树的**美丽值**定义为![[公式]](https://www.zhihu.com/equation?tex=\sum_\limits{(u%2Cv\in+E)}|a_u-a_v|)，其中![[公式]](https://www.zhihu.com/equation?tex=E)为这棵树的边集。

思路：裸的树形dp，显然最值是$(l_u,r_v),(r_v,l_u)$这种组合，所以$dp[x][0/1]$分别表示取$l_x,r_x$的取值

```cpp
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
vector<int>G[maxn];
int a[maxn],b[maxn],n,t;
ll dp[maxn][2];
void dfs(int x,int f){
    dp[x][0]=dp[x][1]=0;
    for(auto&v:G[x]){
        if(v==f)continue;
        dfs(v,x);
        dp[x][1]+=max(dp[v][1]+abs(b[x]-b[v]),dp[v][0]+abs(b[x]-a[v]));
        dp[x][0]+=max(dp[v][0]+abs(a[x]-a[v]),dp[v][1]+abs(a[x]-b[v]));
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)G[i].clear();
        for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
        int x,y;
        for(int i=1;i<n;++i){
            scanf("%d%d",&x,&y);
            G[x].pb(y);G[y].pb(x);
        }
        dfs(1,0);
        cout<<max(dp[1][0],dp[1][1])<<"\n";
    }
    return 0;
}
```

## D - Kavi on Pairing Duty

题意：

给$2n$个点，两两匹配，要求两两匹配间要么完全包含，要么长度相等，问合法的方案数

思路：

这题着实卡了一小会...应该多手玩一会样例的。

分类讨论，设第一个的右端点为$x$

1.当$x>n+1$的时候，不可能所有线段长度一样，一定是属于短的被长的包含，即外层一定是对称的，所以答案有$\sum_{i=1}^{n-1}dp[i]$

2.当$x<=n+1$的时候，才可能出现所有线段的相同的情况，此时最右的端点为$x+x-2$个点，所以$2n$%$2(x-1)==0$才有解，为啥不是直接$n=(x-1)$呢，因为1~x间可能没点，所以就是求n的约数个数方案数，可以线性筛但没必要，直接$dp$算就好了复杂度$O(nlnn)$

维护一个$dp$前缀和就可以了

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int f[maxn],dp[maxn],sum;
const int mod=998244353;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;j+=i)
            f[j]++;
    dp[1]=1;
    sum=1;
    for(int i=2;i<=n;++i){
        dp[i]=(sum+f[i])%mod;
        sum=(sum+dp[i])%mod;
    }
    cout<<dp[n]<<"\n";
    return 0;
}
```

## E.Trees of Tranquillity

题意：

给两颗树，加边生成新图，$(u,v)$有边要求第一颗树祖先关系，第二颗树不能为祖先关系

思路：

已经想到了$dfs序$，但是忘记了一些性质导致不会贪心，还是太菜了啊

完全连通图在1中必定是祖先到叶子的链上若干点组成，**1.$(u,v)$不互为祖先说明在2中dfs序不相交 2.树上dfs序区间要么内含，要么不交**

有着两个性质这就是煞笔题了，直接用set维护，显然每次包含的时候保留小的区间，分类讨论，回溯的时候撤销操作即可，这里我没发现题目的一个条件保证编号在树上递增，所以不会出现儿子来个大区间包含小区间的情况，所以一定可以插入，代码中dfs中$if$那里可以不用

```cpp
#include<bits/stdc++.h>
#define pb push_back
#define fi first 
#define se second 
using namespace std;
typedef pair<int,int>P;
const int maxn=3e5+5;
vector<int>G1[maxn],G2[maxn];
int t,n,fa,in[maxn],ti,out[maxn],ans=0;
set<P>s;
void dfs2(int x){
    in[x]=++ti;
    for(auto&v:G2[x]){
        dfs2(v);
    }
    out[x]=ti;
}
void dfs1(int x){
    bool del=0,add=0;
    auto it=s.lower_bound({in[x],out[x]});
    P a;
    if(it==s.end()||out[x]<(*it).fi){
        if(it!=s.begin()){
            it--;
            if(in[x]<=(*it).se){
                a=*it;
                s.erase(it);
                del=1;
            }
        }
        s.insert({in[x],out[x]});
        add=1;
    }
    ans=max(ans,(int)s.size());
    for(auto&v:G1[x]){
        dfs1(v);
    }
    if(add)s.erase({in[x],out[x]});
    if(del)s.insert(a);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=0;
        s.clear();
        for(int i=1;i<=n;++i)G1[i].clear(),G2[i].clear();
        for(int i=2;i<=n;++i){
            scanf("%d",&fa);
            G1[fa].pb(i);
        }
        for(int i=2;i<=n;++i){
            scanf("%d",&fa);
            G2[fa].pb(i);
        }
        ti=0;
        dfs2(1);
        dfs1(1);
        cout<<ans<<"\n";
    }
    return 0;
}
```


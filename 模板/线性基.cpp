//线性基础三大性质
//1.原序列里面的任意一个数都可以由线性基里面的一些数异或得到
//2.线性基里面的任意一些数异或起来都不能得到 0 00
//3.线性基里面的数的个数唯一，并且在保持性质一的前提下，数的个数是最少的

//一.线性基构造 O(位数*n)
//int d[i]中的第i位必定为1且最高位为1(0开始)
//d[i]不为0说明高斯消元对应的第i位为主元
void add(ll x){
    for(int i=60;i>=0;--i){
        if(x&(1ll<<i)){//i>31必须ll
            if(d[i])x^=d[i];
            else{
                d[i]=x;
                break;
            }
        }
    }
}
//判断某个数能否插入线性基
bool check(ll x){
    for(int i=60;i>=0;--i){
        if(x&(1ll<<i)){
            if(!d[i])return false;
            else x^=d[i];
        }
    }
    return true;
}
//二.求异或最大值 贪心
ll get_max(){
    ll ans=0;
    for(int i=60;i>=0;--i)
        if((ans^d[i])>ans)ans^=d[i];
    return ans;
}
//三.求最小值(线性基能异或的最小值)就是最小的d[i]
//若求原序列异或的最小值,看看有没有元素无法插入，假如有，最小值0，否则仍为min(d[i])
ll get_min(){
    if(zero)return 0;
    for(int i=0;i<=64;++i)
        if(d[i])return d[i];
}
//四、查询第k小值 n个元素的线性基最多只能构建出2^n-1的元素
//重构线性基
void rebuild(){
    cnt=0;top=0;
    for(int i=64;i>=0;--i)
        for(int j=i-1;j>=0;--j) 
            if(d[i]&(1ll<<j))d[i]^=d[j];
    for(int i=0;i<=64;++i)
            if(d[i])p[cnt++]=d[i];
            else zero=1;
}
ll get_kth(int k){//tot是重构前的线性基的个数
    if(k>=(1ll<<cnt))return -1;
    ll ans=0;
    for(int i=64;i>=0;--i)
        if(k&(1ll<<i))ans^=p[i];
    return ans;
}
if(cnt<n)k--;//特判0才能求第k小

五、求x在不去重异或集合中的排名（下标）从1开始...
//不去重异或集合是去重异或集合中2^cnt个整数各重复2^(n-cnt)次形成的
//不在基底中的2^(n-cnt)种取法，代表2^(n-cnt)个0，0与x异或得到x
//设异或出来比他小的有rk钟类，答案就是(rank*2^(n-cnt)+1)
  for(int i=0;i<=30;++i){ 
        if(d[i])p[top++]=i;
    }
    ll rk=0;
    for(int i=0;i<top;++i){//枚举最高的被删去的位 前面的位随便选
        if((1<<p[i])&ask)rk+=(1<<i);
    }
    cout<<(rk*mypow(2,n-top)+1)%mod;

六.查询连通图上1到n的最大异或和
//容易证明这条路径必定1到n的一条主链和环所有构成，把环和主链上的全部丢进去就好了
void dfs(int now,ll x){
    val[now]=x;v[now]=1;
    for(int i=head[now];i;i=next1[i]){
        int y=ver[i];
        if(!v[y])dfs(y,x^edge[i]);
        else insert(x^edge[i]^val[y]);
    }
}
dfs(1,0);
cout<<get_max(val[n]);

六.线性空间下的线性基
本质其实只是一个高斯消元
下面是洛谷P3265贪心下的线性基
  for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(fabs(node[i].a[j])>esp){
                if(!d[j]){//枚举行，每一行直接找第一个变元
                   d[j]=i;++cnt;sum+=node[i].cost;
                   break;
                }else{
                    double t=node[i].a[j]/node[d[j]].a[j];
                    for(int k=j;k<=m;++k)
                        node[i].a[k]-=t*node[d[j]].a[k];
                }
            }
        }
    }

//七.线性基求交
//求V1,V2线性空间的交的基，

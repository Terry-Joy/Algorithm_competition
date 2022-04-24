bool is_prime(int n)		 {
	if(n<2)return false;	//0,1非质数非合数 
	for(int i=2;i*i<=n;++i)
		if(n%i==0)return false;
	return true;
}
//埃筛 
const int maxn=1e6;
int vis[maxn];//是否被筛 
void is_prime(){
	memset(vis,0,sizeof(v));//先都标记为质数 
	vis[1]=vis[0]=1;//如果有需要特判1、0不是质数
	for(int i=2;i<=maxn;++i){
		if(!vis[i]){
			prime[++cnt]=i;
			for(int j=2*i;j<=maxn;j+=i)
				vis[j]=1;//合数标记	
		}
	}	 
} 
//O(N)线性筛 
const int maxn=1e6;
bool v[MAX_N];int prime[MAX_N],cnt=0;//prime存储质数，v为0表示质数
void init(){
	for(int i=2;i<=maxn;++i){ 
		if(!v[i])prime[++cnt]=i; 
			for(int j=1;j<=cnt&&prime[j]*i<=maxn;+ +j){
				v[prime[j]*i]=1;//  prime里面纪录的素数，升序来当做要消去合数的最小素因子。
					if(i%prime[j]==0)break;
			}
	}	
} 
 
 //数组	v存储最小质因子
void init(){
    memset(v,0,sizeof(v));
    int cnt=0;
    for(int i=2;i<=n;++i){
       if(!v[i])v[i]=i,prime[++cnt]=i;
       for(int j=1;j<=cnt&&prime[j]*i<=n;++j){
          if(prime[j]>v[i])break;
          v[i*prime[j]]=prime[j]; 
       } 
    }
}

//线性筛欧拉函数
void get_phi(){ 
    v[1]=v[0]=1;phi[1]=1;
    for(int i=2;i<maxn;++i){ 
        if(!v[i])prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){ 
            v[prime[j]*i]=1;
            if(i%prime[j]==0){ 
                phi[prime[j]*i]=phi[i]*prime[j];
                break;
            }else
                phi[i*prime[j]]=phi[prime[j]]*phi[i];
        }
    }
}

//线性筛莫比乌斯
void get_mu(){ 
    mu[1]=1;
    for(int i=2;i<maxn;++i){
       if(!v[i]){ 
           prime[++cnt]=i;
           mu[i]=-1;
       } 
       for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
          v[prime[j]*i]=1;
          if(i%prime[j]==0){ 
              mu[i*prime[j]]=0;break;
          } 
          else mu[i*prime[j]]=-mu[i];
       }
    }
}
int mu(int n)//求单个数的莫比乌斯{
    if(n==1)return 1;
    int sq=0;
    for(int i=2;i*i<maxn;++i){ 
       if(n%i==0){
          sq++; 
          int cnt=0;
          while(n%i==0)n/=i,cnt++;
          if(cnt>=2)return 0; 
       } 
    }
    if(n>1)sq++;
    return (sq&1)?-1:1;
}

//线性筛约数个数
//a[i]表示i的最小质因子的指数
int N, prime[MAXN], vis[MAXN], D[MAXN], a[MAXN], tot;
void GetD(int N) {
    vis[1] = D[1] = a[1] = 1;
    for(int i = 2; i <= N; i++) {
        if(!vis[i]) prime[++cnt] = i, D[i] = 2, a[i] = 1;
        for(int j = 1; j <= cnt && i * prime[j] <= N; j++) {
            vis[i * prime[j]] = 1;
            if(i % prime[j]==0) {
                D[i * prime[j]] = D[i] / (a[i] + 1) * (a[i] + 2);
                a[i * prime[j]] = a[i] + 1;
                break;
            }
            D[i * prime[j]] = D[i] * D[prime[j]];
            a[i * prime[j]] = 1;
        }
    }
}

//线性筛约数和
int N, prime[MAXN], vis[MAXN], SD[MAXN], sum[MAXN], low[MAXN], tot;
void GetSumD(int N) {//low[i]表示i最小质因子p1^a1 sum[i]=最小质因子p的∑(i=0到ai)p^i求和
    vis[1] = SD[1] = low[1] = sum[1] = 1;
    for(int i = 2; i <= N; i++) {
        if(!vis[i]) prime[++tot] = i, sum[i] = SD[i] = i + 1, low[i] = i;
        for(int j = 1; j <= tot && i * prime[j] <= N; j++) {
            vis[i * prime[j]] = 1;
            if(i % prime[j]==0) {
                low[i * prime[j]] = low[i] * prime[j];
                sum[i * prime[j]] = sum[i] + low[i * prime[j]];
                SD[i * prime[j]] = SD[i] / sum[i] * sum[i * prime[j]];
                break;
            }
            low[i * prime[j]] = prime[j];
            sum[i * prime[j]] = prime[j] + 1;
            //这里low和sum不是积性函数 
            SD[i * prime[j]] = SD[i] * SD[prime[j]];
        }
    }
}

//利用最小质因子线性筛筛一般函数
vis[1] = low[1] = 1; H[1] = 初始化 
for(int i = 2; i <= N; i++) {
    if(!vis[i]) prime[++tot] = i, mu[i] = -1, H[i] = 质数的情况, low[i] = i;
    for(int j = 1; j <= tot && i * prime[j] <= N; j++) {
        vis[i * prime[j]] = 1;
        if(!(i % prime[j])) {
            low[i * prime[j]] = (low[i] * prime[j]); 
            if(low[i] == i) H[i * prime[j]] = 特殊判断;//由f(p^k)到f(p^(k+1))
            else H[i * prime[j]] = H[i / low[i]] * H[prime[j] * low[i]];
            break;
        } 
        H[i * prime[j]] = H[i] * H[prime[j]];
        low[i * prime[j]] = prime[j];
    }
}



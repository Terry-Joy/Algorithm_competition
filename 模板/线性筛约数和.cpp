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
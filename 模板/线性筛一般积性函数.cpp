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
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
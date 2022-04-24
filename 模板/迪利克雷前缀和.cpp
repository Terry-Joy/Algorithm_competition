//Dirichlet 前缀和
for(int i = 1; i <= cnt && primes[i] <= n; ++ i) 
        for(int j = 1; j * primes[i] <= n; ++ j) 
            a[j * primes[i]] += a[j];   

//Dirichlet 后缀和
 for(int i = 1; i <= cnt && primes[i] <= n; ++ i) 
        for(int j = n / primes[i]; j ; -- j) 
            a[j] += a[j * primes[i]];

倒推 Dirichlet 前缀和
 for(int i = cnt; i ; -- i) 
        for(int j = n / primes[i]; j ; -- j) 
            a[j * primes[i]] -= a[j];

 倒推 Dirichlet 后缀和
    for(int i = cnt; i ; -- i) 
        for(int j = 1; j * primes[i] <= n; ++ j) 
            a[j] -= a[j * primes[i]];	
#include<cstdio>
#include<cmath>
#include<algorithm>
const int MAXN = 10000 + 6;
int P[MAXN],C[MAXN],cnt,P2[MAXN],C2[MAXN],cnt2;//P -> factor,C -> power,cnt -> num of prime

int epsilon(int p,int m){
    int ret = 0,delta = 0,k = 0;
    while(true){
        delta = m / pow(p,++k);
        if(!delta) break;
        ret += delta;
    }
    return ret;
}

void divide(int n){
    cnt = 0;
    int sqr = sqrt(n);
    for(int i = 2;i <= sqr;i++){
        if(n % i == 0){//i is prime
            P[++cnt] = i,C[cnt] = 0;
            while(n % i == 0) n /= i,C[cnt]++;
        }
    }
    if(n > 1) P[++cnt] = n,C[cnt] = 1;
}

bool isPrime(int n){
    int sqr = sqrt(n);
    if(n == 0 || n == 1) return false;
    if(n == 2) return true;
    for(int i = 2;i <= sqr;i++) if(n % i == 0) return false;
    return true;
}

int main(){
    int n,m,T,ans = 0x7fffffff,id = 0;scanf("%d",&T);
    while(T--){
        ans = 0x7fffffff;
        scanf("%d %d",&m,&n);
        if(isPrime(m)){
            ans = epsilon(m,n);
            if(ans == 0) printf("Case %d:\nImpossible to divide\n",++id);
            else printf("Case %d:\n%d\n",++id,ans);
            continue;
        }
        divide(m);
        for(int i = 1;i <= cnt;i++) ans = std::min(ans,epsilon(P[i],n) / C[i]);
        if(ans == 0) printf("Case %d:\nImpossible to divide\n",++id);
        else printf("Case %d:\n%d\n",++id,ans);
    }

    return 0;
}

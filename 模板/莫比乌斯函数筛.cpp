bool v[maxn];
int prime[maxn],mu[maxn],cnt=0;
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

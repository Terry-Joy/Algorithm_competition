bool is_prime(int n)		 {
	if(n<2)return false;	//0,1�������Ǻ��� 
	for(int i=2;i*i<=n;++i)
		if(n%i==0)return false;
	return true;
}
//��ɸ 
const int maxn=1e6;
int vis[maxn];//�Ƿ�ɸ 
void is_prime(){
	memset(vis,0,sizeof(v));//�ȶ����Ϊ���� 
	vis[1]=vis[0]=1;//�������Ҫ����1��0��������
	for(int i=2;i<=maxn;++i){
		if(!vis[i]){
			prime[++cnt]=i;
			for(int j=2*i;j<=maxn;j+=i)
				vis[j]=1;//�������	
		}
	}	 
} 
//O(N)����ɸ 
const int maxn=1e6;
bool v[MAX_N];int prime[MAX_N],cnt=0;//prime�洢������vΪ0��ʾ����
void init(){
	for(int i=2;i<=maxn;++i){ 
		if(!v[i])prime[++cnt]=i; 
			for(int j=1;j<=cnt&&prime[j]*i<=maxn;+ +j){
				v[prime[j]*i]=1;//  prime�����¼������������������Ҫ��ȥ��������С�����ӡ�
					if(i%prime[j]==0)break;
			}
	}	
} 
 
 //����	v�洢��С������
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

//����ɸŷ������
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

//����ɸĪ����˹
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
int mu(int n)//�󵥸�����Ī����˹{
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

//����ɸԼ������
//a[i]��ʾi����С�����ӵ�ָ��
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

//����ɸԼ����
int N, prime[MAXN], vis[MAXN], SD[MAXN], sum[MAXN], low[MAXN], tot;
void GetSumD(int N) {//low[i]��ʾi��С������p1^a1 sum[i]=��С������p�ġ�(i=0��ai)p^i���
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
            //����low��sum���ǻ��Ժ��� 
            SD[i * prime[j]] = SD[i] * SD[prime[j]];
        }
    }
}

//������С����������ɸɸһ�㺯��
vis[1] = low[1] = 1; H[1] = ��ʼ�� 
for(int i = 2; i <= N; i++) {
    if(!vis[i]) prime[++tot] = i, mu[i] = -1, H[i] = ���������, low[i] = i;
    for(int j = 1; j <= tot && i * prime[j] <= N; j++) {
        vis[i * prime[j]] = 1;
        if(!(i % prime[j])) {
            low[i * prime[j]] = (low[i] * prime[j]); 
            if(low[i] == i) H[i * prime[j]] = �����ж�;//��f(p^k)��f(p^(k+1))
            else H[i * prime[j]] = H[i / low[i]] * H[prime[j] * low[i]];
            break;
        } 
        H[i * prime[j]] = H[i] * H[prime[j]];
        low[i * prime[j]] = prime[j];
    }
}



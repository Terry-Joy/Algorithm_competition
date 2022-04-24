//求所有原根   O(n^1/4 *log(n)+phi[n]*log(phi[n])
//优化第四第五步后应该快10倍左右
//1.线性筛 phi[]和有原根的数
//2.分解 phi[n]的质因子
//3.枚举[1,n-1]的底数^(phi[n]/pi)看是否有模同余1找最小原根,都没有的话就是满足的,注意底数必须和n互质,即满足欧拉定理
//4.由最小原根找到所有原根,设mn,mn^k为mod n的原根的充要条件为，gcd(k,phi[n])=1,k属于[1,phi[n]);
//第四步如果要更快可以利用筛出的phi[n]的质因数直接找指数
//5.排序原根从小到大输出  如果用计数排序可以优化至O(n)
const int maxn=1e6+5;
int prime[maxn],phi[maxn],cnt=0,n,d,fac[50],facnt,ans[maxn],ctans;
bool v[maxn],gen[maxn];
void init(){//第一步
   gen[2]=gen[4]=phi[1]=1;
   v[1]=v[0]=1;
   for(int i=2;i<=maxn-5;++i){
      if(!v[i])phi[i]=i-1,prime[++cnt]=i;
      for(int j=1;j<=cnt&&prime[j]*i<=maxn-5;++j){
         v[i*prime[j]]=1;
         if(i%prime[j]==0) {
            phi[i*prime[j]]=phi[i]*prime[j];
            break; 
         } 
         else phi[prime[j]*i]=(prime[j]-1)*phi[i];
      } 
   } 
   for(int i=2;i<=cnt;++i){
      for(int j=1;(1ll*j*prime[i])<=maxn-5;j*=prime[i]){gen[j*prime[i]]=1;}//p^a
      for(int j=2;(1ll*j*prime[i])<=maxn-5;j*=prime[i]){ gen[j*prime[i]]=1;}//2*p^a 
   }
}
int mypow(int a,int b,int p){
   int ans=1;
   while(b) {
      if(b&1)ans=1ll*ans*a%p;//中间小心爆ll
      a=1ll*a*a%p;
      b>>=1; 
   } 
   return ans;
}
void divide(int x)//第二步{
   for(int i=2;i*i<=x;++i){
      if(x%i==0) { 
          fac[++facnt]=i;
          while(x%i==0)x/=i;    
      } 
   } 
   if(x>1)fac[++facnt]=x;
   return;
}
bool check(int a,int p){
   if(mypow(a,phi[p],p)!=1)return 0;//不满足互质
   for(int i=1;i<=facnt;++i)
      if(mypow(a,phi[p]/fac[i],p)==1)return 0;//存在更小的阶
   return 1; 
}
int findmn(int x){
   for(int i=1;i<x;++i)//枚举底数
      if(check(i,x)) return i;
   return 0; 
}
int gcd(int a,int b){ return b?gcd(b,a%b):a;}
void getgen(int p,int x)//第四步求所有原根{
   int pro=1;
   for(int i=1;i<=phi[p];++i) {
      pro=(1ll*pro*x)%p;
      if(gcd(i,phi[p])==1)
         ans[++ctans]=pro; 
   } 
   return;
}
int main(){
   init();
   int t;
   scanf("%d",&t);
   while(t--){
       scanf("%d%d",&n,&d);
       if(gen[n])//有原根 第三步找出最小原根{
           ctans=0;
           facnt=0;
           divide(phi[n]); 
           int mn=findmn(n); 
           getgen(n,mn);
           sort(ans+1,ans+1+ctans);//第五步
           printf("%d\n",ctans);
           for(int i=1;i<=ctans/d;++i)
               printf("%d ",ans[i*d]);//ans存储n的原根
           puts("");
       } 
       else printf("0\n\n");
   } 
   return 0;
}

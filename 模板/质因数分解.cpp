p[n],c[n]//唯一分解定义 n=p1^c1*p2^c2..... 
void divide(int n){//质因数分解  一般加素数打表用 
	m=0;
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			p[++m]=i,c[m]=0;
			while(n%i==0)n/=i,c[m]++;
		}
	}
} 
if(n>1)//n是质数  形如2*2*2*3只剩下一个质因子的时候 
	p[++m]=n,c[m]=1;
for(int i=1;i<=m;++i)
	cout<<p[i]<<"^"<<c[i]<<"\n";
	
	

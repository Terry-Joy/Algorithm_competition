p[n],c[n]//Ψһ�ֽⶨ�� n=p1^c1*p2^c2..... 
void divide(int n){//�������ֽ�  һ������������ 
	m=0;
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			p[++m]=i,c[m]=0;
			while(n%i==0)n/=i,c[m]++;
		}
	}
} 
if(n>1)//n������  ����2*2*2*3ֻʣ��һ�������ӵ�ʱ�� 
	p[++m]=n,c[m]=1;
for(int i=1;i<=m;++i)
	cout<<p[i]<<"^"<<c[i]<<"\n";
	
	

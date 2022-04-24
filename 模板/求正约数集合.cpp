#include<vector>
//求n的正约数集合 o(根号n) 
int factor[1600],m=0;
for(int i=1;i*i<=n;++i){
	if(n%i==0){
		factor[++m]=i;
		if(i!=n/i)factor[++m]=n/i;
	}
}

//求1~n每个数的正约数集合-倍数法 o(nlogn)
//以1~n中的每个数为其约数的为其倍数
vector<int>factor[500010];
for(int i=1;i<=n;++i)
	for(int j=1;j<=n/i;++j)
		factor[i*j].push_back(i);
for(int i=1;i<=n;++i)
	for(int j=0;j<factor[i].size;++i)
		printf("%d ",factor[i][j]);


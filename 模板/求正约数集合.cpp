#include<vector>
//��n����Լ������ o(����n) 
int factor[1600],m=0;
for(int i=1;i*i<=n;++i){
	if(n%i==0){
		factor[++m]=i;
		if(i!=n/i)factor[++m]=n/i;
	}
}

//��1~nÿ��������Լ������-������ o(nlogn)
//��1~n�е�ÿ����Ϊ��Լ����Ϊ�䱶��
vector<int>factor[500010];
for(int i=1;i<=n;++i)
	for(int j=1;j<=n/i;++j)
		factor[i*j].push_back(i);
for(int i=1;i<=n;++i)
	for(int j=0;j<factor[i].size;++i)
		printf("%d ",factor[i][j]);


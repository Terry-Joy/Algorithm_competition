#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long    //��״����ͳ���������߶��ٸ����������С  
using namespace std;	//�ı����˳�� 
const int maxn=2e5+10;
LL a[maxn],n,num[maxn],ans1,ans2;
LL rb[maxn],rl[maxn],lb[maxn],ll[maxn];
void add(LL x)//�Ը���������ֵ������״���� 
{			//ͳ���������߳��ִ��� 
	for(;x<=n;x+=x&-x)num[x]++;
}
LL ask(int x)
{
	LL ans=0;
	for(;x;x-=x&-x)ans+=num[x];
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{	
		ll[i]=ask(a[i]-1);//ǰС 
		lb[i]=i-ll[i]-1;	//ǰ��
		add(a[i]);         //�Ȳ�ѯ����� 
	}
	memset(num,0,sizeof(num));
	for(int i=n;i;--i)
	{
		rl[i]=ask(a[i]-1);//��С
		rb[i]=n-rl[i]-i;
		add(a[i]); 
	}
	for(int i=1;i<=n;++i)
	{
		ans1+=rb[i]*lb[i];
		ans2+=ll[i]*rl[i];
	}
	printf("%lld %lld",ans1,ans2);
	return 0;
} 

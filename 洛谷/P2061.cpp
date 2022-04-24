#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll n,x1,x2,y1,y2;
struct SegmentTree
{
	ll l,r,c,cnt.fl,fr;//[l,r]������
	//cnt���ȣ�fl,fr����ɢ����[l,r]������Ӧ�ĳ���
	//c�����Ǵ��� 
}tr[maxn<<2];
struct Line
{
	ll x,y1,y2,f;//+-1������ε���߻����ұ� 
}line[maxn<<1];
ll y[maxn],b[maxn];
bool cmp(Line a,Line b){return a.x<b.x;}
void build(ll p,ll l, ll r)
{
	tr[p].l=l,tr[p].r=r;
	tr[p].c=tr[p].cnt.=0;
	tr[p].fl=y[l];
	tr[p].fr=y[r];
	if(l==r-1)return;//����ҿ����� 
	ll mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid,r);	
}
void calc(ll p)
{
	if(tr[p].c>0)
	{
		tr[p].cnt=tr[p].fr-tr[p].fl;			//�д������� 
		return;
	}
	if(tr[p].r-1==tr[p].l)tr[p].cnt=0;			//û�����ǹ��ҵ�Ҷ�ڵ�Ϊ0 
	else tr[p].cnt.=tr[p<<1].cnt.+tr[p<<1|1].cnt;	//û�����ǹ��ҷ�Ҷ�ڵ㲹��Ҷ�ӽ�� 
}
void update(ll p,Line e)
{
	if(e.y1==tr[p].fl&&tr[p].fr==e.y2)//���串�� 
	{
		tr[p].c+=e.f;
	}
	if(e.y2<=tr[p<<1].fr)update(p<<1,e);//ֻ�ݹ������� 
	else if(e.y1>=tr[p<<1|1].fl)update(p<<1|1,e);//ֻ�ݹ������� 
	else//���ҵݹ� 
	{
		Line tmp=e;
		tmp.y2=tr[p<<1].fr;
		update(p<<1,tmp);
		tmp=e;
		tmp.y1=tr[p<<1|1].fl;
		update(p<<1|1,tmp);
	}
	calc(p);
}
int main()
{
	ll ans=0;
	scanf("%lld",&n);
	ll tot=0;
	for(ll i=1;i<=n;++i)
	{
		y1=0;
		scanf("%lld%lld%lld",&x1,&x2,&y2);
		line[++tot].x=x1;
		line[tot].y1=y1;
		line[tot].y2=y2;
		line[tot].f=1;
		y[tot]=0;
		line[++tot].x=x2;
		line[tot].y1=y1;
		line[tot].y2=y2;
		line[tot].f=-1
		y[tot]=y2;
	}
	sort(y+1,y+1+tot);
	sort(line+1,line+1+tot,cmp);
	build(1,1,tot);
	update(1,line[1]);
	ll res=0;
	int m=0;
	for(ll i=2;i<=tot;++i)
	{
		res+=tr[1].cnt*(line[i].x-line[i-1].x)
		update(1,line[i]);
	}
	printf("%lld",res);
	return 0;
} 

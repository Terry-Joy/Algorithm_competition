#define ll long long
struct rec
{
	int l,r;
	ll sum,lazy;
}tr[4*maxn+10];
void PushUp(int p)
{ 
	tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
void build(int p,int l,int r)
{
	tr[p].l=l;tr[p].r=r;
	if(r==l){tr[p].sum=1;return;}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	PushUp(p);
}

void PushDown(int p,int ln,int rn)			//���������¸��� 
{
	if(tr[p].lazy)
	{
		tr[p<<1].lazy=tr[p].lazy;
		tr[p<<1|1].lazy=tr[p].lazy;
		tr[p<<1].sum=ln*tr[p].lazy;
		tr[p<<1|1].sum=rn*tr[p].lazy;
		tr[p].lazy=0;
	}
}
void update(int L,int R,int ln,int rn,int p,int v)
{
	if(L<=ln&&rn<=R){tr[p].sum=(ll)v*(rn-ln+1);tr[p].lazy=v;return;}//���ϱ�� 
	int mid=ln+rn>>1;
	PushDown(p,mid-ln+1,rn-mid);		//����֮ǰ����ǹ��Ľ�������
	if(L<=mid)update(L,R,ln,mid,p<<1,v);
	if(R>mid)update(L,R,mid+1,rn,p<<1|1,v);
	PushUp(p);						//�Ե����ϸ��� 
}
ll query(int L,int R,int l,int r,int p)
{
	if(L<=l&&R>=r)return tr[p].sum;
	int mid=l+r>>1;
	PushDown(p,mid-l+1,r-mid);		//ֻ�б�ѯ�ʵ��Ÿ������� 
	ll ans=0;
	if(l<=mid)ans+=query(L,R,l,mid,p<<1);			//���������ۼ� 
	if(r>mid)ans+=query(L,R,mid+1,r,p<<1|1);
	return ans;		
}

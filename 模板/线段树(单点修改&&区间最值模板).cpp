void build(int p,int l,int r)
{
	tr[p].l=l,tr[p].r=r;
	if(l==r){tr[p].sum=a[l];return;}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
void update(int p,int l,int r,int ln,int rn)
{
	if(l<=ln&&rn<=r&&tr[p].sum==rn-ln+1)//¼ôÖ¦µ±Çø¼ä¸²¸Ç 
	return;
	if(ln==rn){tr[p].sum=sqrt(tr[p].sum);return;}
	int mid=ln+rn>>1;
	if(l<=mid)update(p<<1,l,r,ln,mid);
	if(r>mid)update(p<<1|1,l,r,mid+1,rn);
	tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
LL query(int p,int l,int r,int ln,int rn)
{
	if(l<=ln&&rn<=r)return tr[p].sum;
	int mid=ln+rn>>1;
	LL ans=0;
	if(l<=mid)ans+=query(p<<1,l,r,ln,mid);
	if(r>mid)ans+=query(p<<1|1,l,r,mid+1,rn);
	return ans;
}

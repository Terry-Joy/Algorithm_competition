struct SegmentTree{
	int lc,r;
	int dat;
};
int build(){
	tot++;
	tr[tot].lc=tr[tot].rc=tr[tot].dat=0;
	return tot;
}
tot=0;
root=build();
insert(root,1,n,val,delta);
void insert(int p,int l,int r,int val,int delta){
	if(l==r){
		tr[p].dat+=delta;
		return;
	}
	int mid=(l+r)>>1;
	if(val<=mid){
		if(!tr[p].lc){
			tr[p].lc=build();
			insert(tr[p].lc,l,mid,val,delta);
		}
	}
	else{
		if(!tr[p].rc)tr[p].rc=build();
		insert(tr[p].rc,mid+1,r,val,delta);
	}
	tr[p].dat=max(tr[tr[p].lc].dat,tr[tr[p].rc].dat);
}
insert(root,1,n,val,delta);

int merge(int p,int q,int l,int r){
	if(!p)return p;
	if(!q)return q;
	if(l==r){
		tr[p].dat+=tr[q].dat;
		return p;
	}
	int mid=(l+r)>>1;
	tr[p].lc=merge(tr[p].lc,tr[q].lc,l,mid);
	tr[p].rc=merge(tr[p].rc,tr[q].rc,mid+1,r);
	tr[p].dat=max(tr[tr[p].lc].dat,tr[tr[p].rc].dat);
	return p;
}

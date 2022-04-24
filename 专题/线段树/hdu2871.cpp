#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define len(x) (tr[x].r-tr[x].l+1)
using namespace std;
const int maxn=5e4+5;
const int INF=1e9;
struct Node{ 
    int sum,lsum,rsum,add,l,r,num;//权值出现次数
}tr[maxn<<2];
char s[10];
set<pair<int,int>>p;
void pushDown(int p){ 
    if(tr[p].add!=-1){ 
        tr[ls].add=tr[rs].add=tr[p].add;
        if(tr[p].add==1){ 
            tr[ls].sum=tr[rs].sum=tr[ls].lsum=tr[ls].rsum=tr[rs].lsum=tr[rs].rsum=0;
        }else{ 
            tr[ls].sum=tr[ls].lsum=tr[ls].rsum=len(ls);
            tr[rs].sum=tr[rs].lsum=tr[rs].rsum=len(rs);
            tr[ls].num=tr[rs].num=0;
        }
        tr[p].add=-1;
    }
}
void pushUp(int p){ 
    tr[p].sum=max(tr[ls].sum,max(tr[rs].sum,tr[ls].rsum+tr[rs].lsum));
    tr[p].lsum=tr[ls].lsum;
    tr[p].rsum=tr[rs].rsum;
    if(tr[p].lsum==len(ls))tr[p].lsum+=tr[rs].lsum;
    if(tr[p].rsum==len(rs))tr[p].rsum+=tr[ls].rsum;
    tr[p].num=(tr[ls].num+tr[rs].num);
}
void build(int p,int l,int r){ 
    tr[p].l=l,tr[p].r=r,tr[p].add=-1;
    tr[p].sum=tr[p].lsum=tr[p].rsum=len(p);
    tr[p].num=0;
    if(l==r)return;
    int mid=l+r>>1;
    build(lson);
    build(rson);
}
int query1(int p,int l,int r,int val){ //new操作
    if(l==r&&val==1){ return l;}
    int mid=l+r>>1;
    pushDown(p);
    if(tr[ls].sum>=val)return query1(lson,val);
    else if(tr[ls].rsum+tr[rs].lsum>=val)return mid-tr[ls].rsum+1;
    else if(tr[rs].sum>=val)return query1(rson,val);
    else return 0;
}
void reset(){ 
    tr[1].sum=tr[1].lsum=tr[1].rsum=tr[1].num=tr[1].add=0;
}
void change(int p,int l,int r,int L,int R,int val){ //区间标记
    if(L<=l&&r<=R){ 
        tr[p].add=val;
        if(val)
            tr[p].sum=tr[p].lsum=tr[p].rsum=0;
        else{ 
            tr[p].sum=tr[p].lsum=tr[p].rsum=len(p);
            tr[p].num=0;
        }
        return;
    }
    pushDown(p);
    int mid=l+r>>1;
    if(L<=mid)change(lson,L,R,val);
    if(R>mid)change(rson,L,R,val);
    pushUp(p);
}
void add(int p,int l,int r,int x,int val){ 
    if(l==r){ 
        tr[p].num+=val;
        return;
    }
    pushDown(p);
    int mid=l+r>>1;
    if(x<=mid)add(lson,x,val);
    else add(rson,x,val);
    pushUp(p);
}
int kth(int p,int l,int r,int rank){ 
    if(l==r)return l;
    int mid=l+r>>1;
    if(tr[ls].num>=rank)return kth(lson,rank);
    return kth(rson,rank-tr[ls].num);
}
int main(){ 
    int n,m,x;
    while(~scanf("%d%d",&n,&m)){ 
        p.clear();
        build(1,1,n);
        for(int i=1;i<=m;++i){ 
            scanf("%s",s);
            if(s[0]=='N'){ 
                scanf("%d",&x);
                int L=query1(1,1,n,x);
                if(!L)puts("Reject New");
                else{ 
                    printf("New at %d\n",L);
                    add(1,1,n,L,1);
                    change(1,1,n,L,L+x-1,1);
                    p.insert({L,L+x-1});
                }
            }else if(s[0]=='R'){ 
                puts("Reset Now");
                p.clear();
                reset();
            }else if(s[0]=='F'){ 
                scanf("%d",&x);
                if(p.size()==0){ 
                    puts("Reject Free");continue;
                }
                auto it=p.lower_bound(make_pair(x,-INF));//保证能找到
                if(it==p.end())it--;
                int l=(*it).first,r=(*it).second;
                if(x>=l&&x<=r){ 
                    add(1,1,n,l,-1);
                    change(1,1,n,l,r,0);
                    printf("Free from %d to %d\n",l,r);
                    p.erase(it);
                }else if(it==p.begin()){ 
                    puts("Reject Free");
                }else{ 
                    it--; 
				    int l=(*it).first,r=(*it).second;
                    if(x>=l&&x<=r){ 
                    add(1,1,n,l,-1);
                    change(1,1,n,l,r,0);
                    printf("Free from %d to %d\n",l,r);
                    p.erase(it);
					}	
				    else puts("Reject Free");
                }
            }else{ 
                scanf("%d",&x);
                if(x>tr[1].num)puts("Reject Get");
                else printf("Get at %d\n",kth(1,1,n,x));
            }
        }
        puts("");
    }
    return 0;
}

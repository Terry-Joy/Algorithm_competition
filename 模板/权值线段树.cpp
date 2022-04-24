
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
const int maxn=1e5+10;
int num[maxn*5];
//权值线段树： 
//区间的值是这段值域里的个数的线段树 
//叶子结点的值 是这个数在序列里出现的次数
//可以当平衡树用 比平衡树代码好写 
/* 
没有必要build
多组样例的时候
memset就搞定了 
void build(int p,int l,int r)
{
	if(l==r)
	{
		num[l]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
} 
*/
void update(int p,int l,int r,int v,int op)//op==1或-1,插入或删除 
{
	num[p]+=op;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(v<=mid)update(p<<1,l,mid,v,op);
	else update(p<<1|1,mid+1,r,v,op); 
}
 
int Kth(int p,int l,int r,int rank)//k小值 
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(num[p<<1]>=rank)return Kth(p<<1,l,mid,rank);//左子k小 
	return Kth(p<<1|1,mid+1,r,rank-num[p<<1]);//右子(k-左num)小 
} 
 
//求一个数的最小排名，排名从0起 
int Rank(int p,int l,int r,int v)//[1,v-1]的出现个数 即v-1>mid 即前面3个数v就rank3 
{
	if(r<v)return num[r];
	int mid=(l+r)>>1,res=0;
	if(v>l)res+=Rank(p<<1,l,mid,v);//左段区间得有比v小的值,才有加的意义，比如说rank[1]=0 
	if(v>mid+1)res+=Rank(p<<1|1,mid+1,r,v);//右段区间得有比v小的值,才有加的意义 
	return res;
} 
 
int Findpre(int p,int l,int r)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(num[p<<1|1])return Findpre(p<<1|1,mid+1,r);//右子树非空向右找 
	return Findpre(p<<1,l,mid);//否则向左找 
}
//找前驱 尽可能在小于v的右子树找 
int Pre(int p,int l,int r,int v)
{
	if(r<v)//maxr<v即在p的子树中 p区间内最右非空子树即答案 
	{
		if(num[p])return Findpre(p,l,r);
		return 0;
	}
	int mid=(l+r)>>1,Re;
	//如果v在右子树可能有前驱(至少mid+1比v小)就先查右子树,l=mid+1 
	if(mid+1<v&&num[p<<1|1]&&(Re=Pre(p<<1|1,mid+1,r,v)))return Re;
	//否则查左子树,r=mid,使r不断变小直至满足题意小于v 
	return Pre(p<<1,l,mid,v);
} 
 
int Findnext(int p,int l,int r)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(num[p<<1])return Findnext(p<<1,l,mid);
	return Findnext(p<<1|1,mid+1,r);
} 
 
//找后继 尽可能在大于v的左子树找 
int Next(int p,int l,int r,int v)
{
	if(v<l)//已找到大于v的最小完整区间 
	{
		if(num[p])return Findnext(p,l,r); 
		return 0;
	}
	int mid=(l+r)>>1,Re;
	//如果左子树里有比v大的(至少mid比v大)就查左子树 否则查右子树 
	if(v<mid&&num[p<<1]&&(Re=Next(p<<1,l,mid,v)))return Re;
	return Next(p<<1|1,mid+1,r,v);
}
 
int main()
{
	return 0;
}

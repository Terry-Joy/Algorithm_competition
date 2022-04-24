#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,tot;
ll ans,u,v;
struct SegmentTree{ 
    int ls,rs,size;
}tr[22*N];

int in()
{
   int x=0;char ch=getchar();
   while(ch>'9'||ch<'0')ch=getchar();
   while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
   return x; 
}
int update(int l,int r,int val)
{
   int pos=++tot;
   tr[pos].size++;
   if(l==r)return pos;;
   int mid=(l+r)>>1;
   if(val<=mid)tr[pos].ls=update(l,mid,val);
   else tr[pos].rs=update(mid+1,r,val);
   return pos; 
}
int merge(int p,int q,int l,int r)
{
   if(!q||!p)return (!p)?q:p;
   if(l==r)
   {
      tr[p].size+=tr[q].size;return p; 
   } 
   u+=(ll)tr[tr[p].rs].size*tr[tr[q].ls].size;
   v+=(ll)tr[tr[p].ls].size*tr[tr[q].rs].size;
   int mid=(l+r)>>1;
   tr[p].ls=merge(tr[p].ls,tr[q].ls,l,mid);
   tr[p].rs=merge(tr[p].rs,tr[q].rs,mid+1,r);
   tr[p].size=tr[tr[p].ls].size+tr[tr[p].rs].size;
   return p;
}
int dfs()
{
   int pos,val=in();
   if(val==0)
    {
       int ls=dfs(),rs=dfs();
       u=0;v=0;
       pos=merge(ls,rs,1,n);
       ans+=min(u,v); 
    } 
   else
       pos=update(1,n,val);
       return pos;
}
int main()
{
   n=in();
   dfs();
   printf("%lld",ans);
   return 0; 
}

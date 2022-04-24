#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
struct Node{ 
    int l,r,id;
}q[maxn];
bool cmp1(Node a,Node b){ return a.l<b.l;}
bool cmp2(Node a,Node b){ return a.id<b.id;}

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n;
      scanf("%d",&n);
      for(int i=1;i<=n;++i)
         scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
      sort(q+1,q+1+n,cmp1);
      int pos=0,r=q[1].r;
      for(int i=2;i<=n;++i)
      {
         if(q[i].l>r)
            pos=q[i].l;
         r=max(r,q[i].r); 
      } 
      sort(q+1,q+1+n,cmp2);
      if(pos){ 
         for(int i=1;i<=n;++i)
             if(q[i].l<pos)
                 cout<<"1 ";
             else 
                 cout<<"2 ";
      }
      else cout<<"-1";
      cout<<endl;
   } 
   return 0; 
}

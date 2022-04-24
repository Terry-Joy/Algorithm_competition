#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int q1[maxn],q2[maxn],head,tail,id[maxn];
int n,k,a[maxn];
void minans()
{
    head=1,tail=0;
    for(int i=1;i<=n;++i)
    {
       while(head<=tail&&a[i]<=q1[tail])
            tail--;
       q1[++tail]=a[i];
       id[tail]=i;
       while(id[head]+k<=i)
           head++;
       if(i>=k)
           printf("%d ",q1[head]);
    }
    putchar('\n');
}
void maxans()
{
    head=1,tail=0;
    for(int i=1;i<=n;++i)
    {
       while(head<=tail&&a[i]>=q2[tail])
            tail--;
       q2[++tail]=a[i];
       id[tail]=i;
       while(id[head]+k<=i)
          head++;
       if(i>=k)
          printf("%d ",q2[head]); 
    }
    putchar('\n');
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    minans();
    maxans();
    return 0; 
}

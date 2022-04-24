#include<iostream>
#include<queue>
using namespace std;
const int N=3e5+100;
deque<int>q;
int a[N],sum[N];
int main()
{
    int n,m,ans=-0x3f3f3f3f;
    scanf("%d%d",&n,&m);
    sum[0]=0;
    q.push_back(0);
    for(int i=1;i<=n;++i)
    {
       scanf("%d",&a[i]);
       sum[i]=sum[i-1]+a[i];
       while(!q.empty()&&q.front()+m<i)
          q.pop_front();
       ans=max(ans,sum[i]-sum[q.front()]);
       while(!q.empty()&&sum[q.back()]>=sum[i])
           q.pop_back();
       q.push_back(i);
    }
    cout<<ans<<endl;
}

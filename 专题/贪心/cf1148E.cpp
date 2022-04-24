#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e5+5;
int a,t[maxn],d[maxn],n;
struct Node{ 
    int s,id;
    bool operator<(const Node&b)const{ 
        return s<b.s;
    }
}s1[maxn];
struct tre{ 
    int i,j,dis;
    tre(int a,int b,int c):i(a),j(b),dis(c){ }
};
vector<tre>ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&s1[i].s),s1[i].id=i;
    for(int i=1;i<=n;++i)scanf("%d",&t[i]);
    sort(s1+1,s1+1+n);
    sort(t+1,t+1+n);
    ll sum=0;
    for(int i=1;i<=n;++i)d[i]=s1[i].s-t[i],sum+=d[i];
    if(sum!=0){ puts("NO");return 0;}
    int pos=1;
    for(int i=1;i<=n;++i){ 
        if(d[i]>0){ puts("NO");return 0;}
        else while(d[i]<0){ 
            while(d[pos]<=0)pos++;
            int val=min(-d[i],d[pos]);
            d[i]+=val,d[pos]-=val;
            ans.push_back(tre(s1[i].id,s1[pos].id,val));
        }
    }
    puts("YES");
    cout<<ans.size()<<endl;
    for(auto&v:ans)
        printf("%d %d %d\n",v.i,v.j,v.dis);
    return 0;
}

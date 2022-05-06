#include<bits/stdc++.h>
using namespace std;
#define S 1000005
long long a[S],A,v[S];int n,m,ans[S];
long long read(){
    register long long p=0,f=0;register char ch=getchar();
    while(!isdigit(ch))f=ch=='-',ch=getchar();
    while(isdigit(ch))p=(p<<3)+(p<<1)+ch-48,ch=getchar();
    return f?-p:p;
}
priority_queue<int>q;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)a[i]=read();
    long long lft=0,c=0;
    for(int i=n;i;--i)
        if(a[i]>=0){
            lft+=a[i];
            while(!q.empty()&&lft+q.top()>=0)lft+=q.top(),q.pop();
            if(!q.empty()){int x=q.top();q.pop();q.push(lft+x);}
            lft=0;
        }else q.push(a[i]);
    ans[c=1]=q.size();
    while(!q.empty())c++,v[c]=v[c-1]-q.top(),ans[c]=ans[c-1]-1,q.pop();
    v[++c]=1e17;
    while(m-->0){
        long long x=read();
        printf("%d\n",ans[upper_bound(v+1,v+1+c,x)-1-v]);
    }
}
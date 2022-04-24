#include<bits/stdc++.h>

using namespace std;
int gcd(int a,int b){ return b?gcd(b,a%b):a;}
const int HashMod=123456;//质数
struct HashTable
{
	struct Line{int u,v,next;}e[1000000];
	int h[HashMod],cnt;
	void Add(int u,int v,int w){e[++cnt]=(Line){w,v,h[u]};h[u]=cnt;}
	void clear(){memset(h,0,sizeof(h));cnt=0;}
	void Hash(int x,int k){
		int s=x%HashMod;
	 	Add(s,k,x);
	}
	int Query(int x){
		int s=x%HashMod;
		for(int i=h[s];i;i=e[i].next)
			if(e[i].u==x)return e[i].v;
	 	return -1;
	}  
}Hash;
int mypow(int a,int b,int mod){ 
    int ans=1;
    while(b){ 
        if(b&1)ans=1ll*ans*a%mod;
        a=1ll*a*a%mod;b>>=1;
    }
    return ans;
}
int exbsgs(int A,int B,int p){ 
    if(B==1){return 0; }
    int k=0,a=1;
    while(1){ 
        int d=gcd(A,p);
        if(d==1)break;
        if(B%d){ return -1;}//无解
        B/=d;p/=d;++k;
        a=1ll*a*A/d%p;
        if(B==a)return k;
    }
    Hash.clear();
    int m=sqrt(p)+1;
    for(int i=0,t=B;i<m;++i,t=1ll*t*A%p)Hash.Hash(t,i);
	for(int i=1,tt=mypow(A,m,p),t=1ll*a*tt%p;i<=m;++i,t=1ll*t*tt%p){
		int x=Hash.Query(t);
        if(x==-1){continue; };
		return i*m-x+k;
	}
    return -1;//无解
}
int main(){ 
    int a,b,p;
    cout<<HashMod<<endl;
    while(~scanf("%d%d%d",&a,&b,&p)){ 
        if(a+b+p==0)break;
        int k=exbsgs(a,p,b);
        if(k==-1)puts("No Solution");
        else cout<<k<<"\n";
    }
    return 0;
}

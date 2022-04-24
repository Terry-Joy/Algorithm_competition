#include<bits/stdc++.h>
using namespace std;
using db=double;
using ll=long long;
const int maxn=3e5+10;
ll dp[maxn];
int T[maxn],C[maxn],sumT[maxn],sumC[maxn],q[maxn],h,t,S,n;
int X(int x){ 
    return sumC[x];
}
ll Y(int x){ 
    return dp[x]-(ll)S*sumC[x];
}
db slope(int i,int j){ 
    return 1.0*(Y(j)-Y(i))/(X(j)-X(i));
}
bool check(int i,int j,int k){ 
    return (Y(j)-Y(i))*(X(k)-X(j))>=(Y(k)-Y(j))*(X(j)-X(i));
}
bool check2(int i,int j,int k){ 
    return Y(j)-Y(i)>=(ll)k*(X(j)-X(i));
}
int solve(int k){ 
    if(h==t)return q[h];
    int l=h,r=t;
    while(l<r){ 
        int mid=l+r>>1;
        if(check2(q[mid],q[mid+1],k))r=mid;
        else l=mid+1;
    }
    return q[l];
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>S;
    for(int i=1;i<=n;++i)cin>>T[i]>>C[i];
    h=t=1;
    q[1]=0;
    for(int i=1;i<=n;++i)sumT[i]=sumT[i-1]+T[i];
    for(int i=1;i<=n;++i)sumC[i]=sumC[i-1]+C[i];
    for(int i=1;i<=n;++i){ 
        int j=solve(sumT[i]);
        dp[i]=dp[j]-(ll)S*sumC[j]+(ll)S*sumC[n]+(ll)sumT[i]*sumC[i]-(ll)sumT[i]*sumC[j];
        while(h<t&&check(q[t-1],q[t],i))t--;
        q[++t]=i;
    }
    cout<<dp[n]<<"\n";
    return 0;
}

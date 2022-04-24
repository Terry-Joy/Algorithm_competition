#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e5+5;
int q[maxn],h=1,t=0,L[maxn],R[maxn];
struct SA{ 
    char s[maxn];
    int n,m,a[maxn],sa[maxn],rk[maxn],ht[maxn],tax[maxn],tp[maxn],pos[maxn],sum1[maxn],sum2[maxn];
    int cmp(int*f,int x,int y,int w){ 
        return f[x]==f[y]&&f[x+w]==f[y+w];
    }
    void rsort(){ 
        for(int i=0;i<=m;++i)tax[i]=0;  
        for(int i=1;i<=n;++i)tax[rk[tp[i]]]++;
        for(int i=1;i<=m;++i)tax[i]+=tax[i-1];
        for(int i=n;i>=1;--i)sa[tax[rk[tp[i]]]--]=tp[i];
    }
    void Suffix(){ 
        for(int i=1;i<=n;++i)rk[i]=a[i],tp[i]=i;
        rsort();
        for(int w=1,p=1,i;p<n;w+=w,m=p){ 
            for(p=0,i=n-w+1;i<=n;++i)tp[++p]=i;
            for(i=1;i<=n;++i)if(sa[i]>w)tp[++p]=sa[i]-w;
            rsort(),swap(rk,tp),rk[sa[1]]=p=1;
            for(int i=2;i<=n;++i)
                rk[sa[i]]=cmp(tp,sa[i],sa[i-1],w)?p:++p;
        }
    }
    void getht(){ 
        int j,k=0;
        for(int i=1;i<=n;ht[rk[i++]]=k)
            for(k=k?k-1:k,j=sa[rk[i]-1];a[i+k]==a[j+k];++k);
    }    
    void init(){
        n=0; 
        for(int i=1;i<=2;++i){ 
            scanf("%s",s+1);
            int len=strlen(s+1);
            for(int j=1;j<=len;++j){ 
                a[++n]=s[j],pos[n]=i;
            }
            a[++n]='#'+i;
        }
        n--;
        m=(int)'z';
        Suffix();
        getht();
    }
    ll solve(){ 
        ll ans=0;
        for(int i=1;i<=n;++i){ 
            sum1[i]=sum1[i-1]+(pos[sa[i]]==1);//按排名的pos
            sum2[i]=sum2[i-1]+(pos[sa[i]]==2);
        }
        ht[n+1]=ht[0]=-1;   
        for(int i=1;i<=n+1;++i){ 
            while(h<=t&&ht[q[t]]>=ht[i])
                R[q[t--]]=i;
            q[++t]=i;
        }
        h=1,t=0;
        for(int i=n;i>=0;--i){ 
            while(h<=t&&ht[q[t]]>ht[i])
                L[q[t--]]=max(1,i);
            q[++t]=i;
        }
        /*for(int i=1;i<=n;++i){ 
            cout<<ht[i]<<" "<<L[i]<<" "<<R[i]<<" "<<pos[sa[i]]<<" "<<sum1[i]<<" "<<sum2[i]<<"\n";
        }*/
        for(int i=2;i<=n;++i){ 
            ans+=1ll*ht[i]*(sum1[R[i]-1]-sum1[i-1])*(sum2[i-1]-sum2[L[i]-1]);
            ans+=1ll*ht[i]*(sum2[R[i]-1]-sum2[i-1])*(sum1[i-1]-sum1[L[i]-1]);
        }
        return ans;
    }
}sa;
int main(){ 
    sa.init();
    cout<<sa.solve()<<"\n";
    return 0;
}

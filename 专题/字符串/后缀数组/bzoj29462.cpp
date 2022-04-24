#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int q[maxn],h1=1,t1=0;
struct SA{ 
    int s[(maxn<<1)],sa[maxn],rk[maxn],c[maxn],p[maxn],tmp[maxn],n,m,ht[maxn],pos[maxn],num,sum[10],st=0;
    char str[maxn];
    bool t[maxn<<1];
#define Ar(x,a) sa[p[s[x]]a]=x
    void IS(int*s,int*s1,int n1,int n,int m,bool *t){ 
        memset(sa+1,0,n<<2);memset(c+1,0,m<<2);
        for(int i=1;i<=n;++c[s[i++]]);
        for(int i=2;i<=m;++i)c[i]+=c[i-1];
        memcpy(p+1,c+1,m<<2);
        for(int i=n1;i;Ar(s1[i],--),i--);
        for(int i=1;i<=m;++i)p[i]=c[i-1]+1;
        for(int i=1;i<=n;sa[i]>1&&t[sa[i]-1]?Ar(sa[i]-1,++):0,i++);
        memcpy(p+1,c+1,m<<2);
        for(int i=n;i;sa[i]>1&&!t[sa[i]-1]?Ar(sa[i]-1,--):0,i--);
    }
    void SAIS(int s[],bool t[],int tmp[],int n,int m){ 
        int n1=0,m1=rk[1]=0,*s1=s+n;t[n]=0;
        for(int i=n-1;i;t[i]=s[i]^s[i+1]?s[i]>s[i+1]:t[i+1],i--);
        for(int i=2;i<=n;rk[i]=t[i-1]&&!t[i]?tmp[++n1]=i,n1:0,i++);
        IS(s,tmp,n1,n,m,t);
        for(int i=1,x,y=0;i<=n;++i)
            if(x=rk[sa[i]]){ 
                if(m1<=1||tmp[x+1]-tmp[x]!=tmp[y+1]-tmp[y])++m1;
                else for(int a=tmp[x],b=tmp[y];a<=tmp[x+1];a++,b++)
                    if((s[a]<<1|t[a])^(s[b]<<1|t[b])){ ++m1;break;}
                s1[y=x]=m1;
            }
        if(m1<n1)SAIS(s1,t+n,tmp+n1,n1,m1);
        else for(int i=1;i<=n1;sa[s1[i]]=i,i++);
        for(int i=1;i<=n1;s1[i]=tmp[sa[i]],i++);
        IS(s,s1,n1,n,m,t);
    }
    void MakeSA(){ 
        --n;
        for(int i=1;i<=n;++i)sa[i]=sa[i+1],rk[sa[i]]=i;
    }
    void getHt(){ 
        for(int i=1,k=0;i<=n;ht[rk[i]]=k,i++,k&&--k)
            for(int j=sa[rk[i]-1];s[i+k]==s[j+k];k++);
    }
    void init(){ 
        n=0;
        scanf("%d",&num);
        for(int i=1;i<=num;++i){ 
            scanf("%s",str+1);
            int len=strlen(str+1);
            for(int j=1;j<=len;++j){ 
                s[++n]=str[j];pos[n]=i;
            }
            s[++n]='#'+i;
        }
        if(num==1){ 
            cout<<strlen(str+1)<<"\n";exit(0);
        }
        s[n]=1;
        SAIS(s,t,tmp,n,'z'+1);
        MakeSA();
        getHt();
       // for(int i=1;i<=n;++i)cout<<ht[i]<<" "<<pos[sa[i]]<<"\n";
    }
    void add(int x){ 
        if(!pos[sa[x]])return;
        if(++sum[pos[sa[x]]]==1)
            st|=(1<<(pos[sa[x]]-1));
    }
    void del(int x){ 
        if(!pos[sa[x]])return;
        if(--sum[pos[sa[x]]]==0)
            st^=(1<<(pos[sa[x]]-1));
    }
    int solve(){ 
        st=0;
        int mx=ht[1],all=(1<<num)-1;
        add(1);
        q[++t1]=1;
        int r=1,l=1;
        while(r<=n){ 
            while(r<=n&&st!=all){ 
                add(++r);
                while(h1<=t1&&ht[q[t1]]>=ht[r])t1--;
                q[++t1]=r;
            }
            while(l<=r&&st==all)
                del(l++);
            while(h1<=t1&&q[h1]<l)h1++;
            if(h1<=t1)
                mx=max(mx,ht[q[h1]]);
        }
        return mx;
    }
}sa;
int main(){ 
    sa.init();
    cout<<sa.solve();
    return 0;
}


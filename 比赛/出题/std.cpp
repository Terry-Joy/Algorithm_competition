#include<bits/stdc++.h>

using namespace std;
const int maxn=1e6+5;
int t,n,times;
int a[maxn],ans[maxn];
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        times=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){ 
            scanf("%d",&a[i]);
            ans[i]=a[i];
        }
        for(int i=2;i<=n;++i){ 
            if(a[i]!=a[i-1]){ 
                int len=1,head=i-1;
                while(a[i]!=a[i-1]&&i<=n){ 
                    len++;
                    i++;
                }
                i--;
                if(len&1){ 
                    for(int j=head;j<=i;++j) 
                        ans[j]=a[head];
                    times=max(times,len/2);
                }else{ 
                    for(int j=head;j<=(head+i)/2;++j)
                        ans[j]=a[head];
                    for(int j=(head+i)/2+1;j<=i;++j)
                        ans[j]=a[i];
                    times=max(times,len/2-1);
                }
            }
        }
        cout<<times<<"\n";
        for(int i=1;i<=n;++i)
            cout<<ans[i]<<" ";
        puts("");
    }
    return 0;
}

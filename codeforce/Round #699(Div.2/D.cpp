#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n,m;
const int maxn=1005;
char s[maxn][maxn];
void solve(){ 
    if(m&1){ 
        cout<<"YES\n";
        for(int i=1;i<=m+1;++i){ 
            cout<<(i%2+1)<<" ";
        }
        cout<<"\n";return;
    }
        for(int i=1;i<=n;++i){ 
            for(int j=i+1;j<=n;++j){ 
                if(s[i][j]==s[j][i]){ 
                    cout<<"YES\n";
                    for(int k=1;k<=m+1;++k){ 
                        if(k&1)cout<<j<<" ";
                        else cout<<i<<" ";
                    }
                    cout<<"\n";return;
                }
            }
        }
    for(int i=1;i<=n;++i){ 
        int pa=0,pb=0;
        for(int j=1;j<=n;++j){ 
            if(s[i][j]=='a')pa=j;
            else if(s[i][j]=='b')pb=j;
        }
        if(pa&&pb){ 
            if(m%4==0){ 
                cout<<"YES\n";
                for(int j=1;j<=m/2;++j){ 
                    if(j&1){ 
                        cout<<i<<" ";
                    }else cout<<pa<<" ";
                }
                cout<<i<<" ";
                for(int j=1;j<=m/2;++j){ 
                    if(j&1)cout<<pb<<" ";
                    else cout<<i<<" ";
                }
            }else{ 
                cout<<"YES\n";
                for(int j=1;j<=m/2;++j){ 
                    if(j&1)cout<<pa<<" ";
                    else cout<<i<<" "; 
                }
                cout<<i<<" ";
                for(int j=1;j<=m/2;++j){ 
                    if(j&1)cout<<pb<<" ";
                    else cout<<i<<" ";
                }
            }
            cout<<"\n";return;
        }
    }
    cout<<"NO\n";return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n>>m;
        for(int i=1;i<=n;++i){ 
            cin>>(s[i]+1);
        }
        solve();
    } 
    return 0;
}

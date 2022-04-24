#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
char str[20];
int g[20][20],A[20][20];
int w[20],tag[20],deg[20]; 
vector<int> go[20],con[20];
int ans=2e9;  
int cal(int x,int y) {
 if(!y) return 0; 
 int ans=1;
 for(int i=1;i<=y;++i) 
  ans=(ans*x);
 return ans; 
}
int n;  
void dfs(int cur,int A) {
 if(cur==n+1) { ans=min(ans,A);return; } 
 if(A>=ans) return;
 for(auto &v:go[cur]) {
  if(!tag[v]) {
   for(auto &x:con[v]) tag[x]++;
   deg[v]++;
   dfs(cur+1,A+cal(w[v],deg[v])-cal(w[v],deg[v]-1));
   deg[v]--;
   for(auto &x:con[v]) tag[x]--;
    }
 }
}
void init() {
 memset(tag,0,sizeof(tag));
 memset(deg,0,sizeof(deg)); 
 for(int i=1;i<=n;i++) {
  go[i].clear();
  con[i].clear(); 
 }
}
int main() {
 int T;
 scanf("%d",&T);
 while(T--) {
  init(); 
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {
   scanf("%s",str+1);
   for(int j=1;j<=n;j++)  {
    g[i][j]=str[j]-'0';
    if(g[i][j]) go[j].push_back(i);  
   } 
  }
  for(int i=1;i<=n;i++) {
   scanf("%s",str+1);
   for(int j=1;j<=n;j++) {
    A[i][j]=str[j]-'0'; 
    if(A[i][j]) {
     con[i].push_back(j);
     con[j].push_back(i); 
    }
   } 
  }
  for(int i=1;i<=n;i++)
   scanf("%d",&w[i]); 
  bool ok=1; 
  for(int i=1;i<=n;i++) {
   if(!go[i].size()) {
    ok=0;
    break;
   }
  }
  if(!ok) puts("-1");
  else {
   ans=2e9; 
   dfs(1,0); 
   if(ans==2e9) puts("-1");
   else printf("%d\n",ans);  
  }
 } 
 return 0;
}

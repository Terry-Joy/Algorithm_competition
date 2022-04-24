//O(NM) N左M右
bool vis[N];
int match[N];
bool dfs(int x){
   for(int i=head[x];i;i=next1[i]){
      int y=ver[i];
      if(!vis[y]){
         vis[y]=1;
         if(!match[y]||dfs(match[y])){ //假如没匹配过或者有增广路
            match[y]=x;return true; //找增广路
         } 
      } 
   } 
   return false;
}
int main(){
   int ans=0;
   for(i=1;i<=n;++i){
      memset(vis,0,sizeof(vis));
      if(dfs(i))ans++; 
   }
}

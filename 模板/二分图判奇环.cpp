void dfs(int x,int clo)
{
	 if(!flag)return;
	 for(int i=head[x];i;i=next[i])
	 {
	 		int y=ver[i];
	 	    if(!v[y])dfs(x,3-clo);
	 		else
	 		{
	 			if(clo==v[y])
	 			{
	 				flag=0;
	 				return;
				 }
			 }
	 }
}
for(int i=1;i<=n;++i)
{
	if(!v[i])dfs(i,1);
	if(!flag)break;//不是二分图 
}
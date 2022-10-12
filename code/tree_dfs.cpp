vector<vector<int>>edge;
vector<pair<int,int>>times;
int ti = 0;
void dfs(int x,int fa){
	times[x].fir = times[x].sec = ti++;
	for(int i:edge[x]){
		if(i == fa)continue;
		dfs(i,x);
		times[x].sec = max(times[i].sec,times[x].sec);
	}
}
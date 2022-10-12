vector<vector<int>>edge;   //要建雙向邊
vector<int>dp,sz; 
void dfs1(int fa,int x){
    sz[x] = 1;
    for(int i=0;i<edge[x].size();i++){
        if(edge[x][i] == fa)continue;
        dfs1(x,edge[x][i]);
        dp[x] += dp[edge[x][i]]+sz[edge[x][i]];
        sz[x] += sz[edge[x][i]];
    }
}
ll ans = 0;
void dfs2(int fa,int x,ll sum){
    ans += (sum + dp[x]);
    for(int i=0;i<edge[x].size();i++){
        if(edge[x][i] == fa) continue;
        ll tp = sum + dp[x] - (dp[edge[x][i]] + sz[edge[x][i]]) + (n-sz[edge[x][i]]); //從x到edge[x][i]的距離總和
        dfs2(x,edge[x][i],tp);
    }
}
dfs1(1,1);
dfs2(1,1,0);  //答案是ans/2

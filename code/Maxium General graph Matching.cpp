//一般圖匹配 用在無向圖
//<cf> flow 只能用在2分匹配
// should shuffle vertices and edges  要打亂輸入的邊和點

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

for(int i=1;i<=n;i++) 
	shuffle(edge[i].begin(),edge[i].end(),gen);

把點打亂: shuffle(ind.begin(),ind.end(),gen);   //ind是1~n
edge[ind[a]].push_back(ind[b]);
edge[ind[b]].push_back(ind[a]);

const int N=100005,E=(2e5)*2+40;
struct Graph{ // 1-based; match: i <-> lnk[i]
  int to[E],bro[E],head[N],e,lnk[N],vis[N],stp,n;
  void init(int _n){
    stp=0; e=1; n=_n;
    for(int i=1;i<=n;i++) head[i]=lnk[i]=vis[i]=0;
  }
  void add_edge(int u,int v){
    to[e]=v,bro[e]=head[u],head[u]=e++;
    to[e]=u,bro[e]=head[v],head[v]=e++;
  }
  bool dfs(int x){
    vis[x]=stp;
    for(int i=head[x];i;i=bro[i]){
      int v=to[i];
      if(!lnk[v]){ lnk[x]=v,lnk[v]=x; return true; }
    } 
    for(int i=head[x];i;i=bro[i]){
      int v=to[i];
      if(vis[lnk[v]]<stp){
        int w=lnk[v]; lnk[x]=v,lnk[v]=x,lnk[w]=0;
        if(dfs(w)) return true;
        lnk[w]=v,lnk[v]=w,lnk[x]=0;
      }
    }
    return false;
  }
  int solve(){
    int ans=0;
    for(int i=1;i<=n;i++) if(!lnk[i]) stp++,ans+=dfs(i);
    return ans;
  }
}graph;
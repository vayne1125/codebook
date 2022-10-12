int n;
int sz[MXN], fa[MXN], heavy[MXN], root[MXN], len[MXN], dep[MXN];
vector<pair<int, int>> graph[MXN];
vector<int> tree[MXN]; // 第i個節點為根的線段樹
vector<int> val[MXN];  // 第i個節點為根的序列
vector<pair<int, int>> edges;

void dfs_sz(int x, int f, int d)
{
  sz[x] = 1;
  fa[x] = f;
  dep[x] = d;
  for (pair<int, int> i : graph[x])
  {
    if (i.first == f)
      continue;
    dfs_sz(i.first, x, d + 1);
    sz[x] += sz[i.first];
    if (sz[i.first] > sz[heavy[x]])
      heavy[x] = i.first;
  }
}

void dfs_hld(int x, int f)
{
  for (auto i : graph[x])
  {
    if (i.first == f)
      continue;
    root[i.first] = (i.first == heavy[x] ? root[x] : i.first);
    val[root[i.first]].push_back(i.second);
    dfs_hld(i.first, x);
  }
  len[root[x]]++;
}

int getLca(int x, int y)
{
  while (root[x] != root[y])
  {
    if (dep[root[x]] > dep[root[y]])
      x = fa[root[x]];
    else
      y = fa[root[y]];
  }
  return (dep[x] <= dep[y] ? x : y);
}

void build_segment_tree()
{
  for (int i = 1; i <= n; i++)
  {
    if (root[i] == i)
    {
      tree[i].resize(len[i] * 4, 0);
      build(i, 1, 0, len[i] - 1);
    }
  }
}

cin >> a >> b >> c;
graph[a].emplace_back(b, c);
graph[b].emplace_back(a, c);
edges[i] = make_pair(a, b);
dfs_sz(1, 1, 0);
root[1] = 1;
val[1].push_back(-INF);
dfs_hld(1, 1);
build_segment_tree();
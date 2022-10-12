vector<vector<int>> tree;
vector<vector<int>> anc;
vector<int> timeIn, timeOut;
int ti = 0;
void build(int x, int fa) {
    anc[x].resize(__lg(n)+10);//tle改+1
    for (int i = 0; i < __lg(n) + 10; i++) {
        anc[x][i] = fa;
        fa = anc[fa][i];
    }
}
void dfs(int x, int fa) {
    timeIn[x] = ti++;
    build(x, fa);
    for (int i = 0; i < tree[x].size(); i++) {
        if (tree[x][i] == fa) continue;
        dfs(tree[x][i], x);
    }
    timeOut[x] = ti++;
}
bool isAnc(int a, int b) {
    if (timeIn[a] <= timeIn[b] && timeOut[a] >= timeOut[b])return 1; //a是祖先
    return 0;
}
int query(int a, int b) {
    if (isAnc(a, b))return a;
    if (isAnc(b, a))return b;
    for (int i = __lg(n) + 10 - 1; i >= 0; i--) {
        if (!isAnc(anc[a][i], b)) a = anc[a][i];
    }
    return anc[a][0];
}
int nlca(int x, int y) {   //x's yth anc
    if (y == 0)return x;
    int tp = log2(y);
    if (y == (1 << tp)) return anc[x][tp];
    else return nlca(anc[x][tp], y - (1 << tp));
}
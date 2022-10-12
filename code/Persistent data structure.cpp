
struct node{
    ll val;
    node *l, *r;
};
 
vector<node *> version;    //用一個vector紀錄全部版本的根節點

//線段樹 
void build(node *now_version, l, r);
ll query(node *now_version, l, r, ql, qr);
node *update_version(node *pre_version,int l,int r,int pos,int v); //回傳新建的節點
 
void add_version(int x,int v){    //修改位置 x 的值為 v
    version.push_back(update_version(version.back(), 0, n-1, x, v));
}

node *update_version(node *pre_version,int l,int r,int pos,int v){
    node *x = new node();    //當前位置建立新節點
    if(l == r){
        x->val = v;
        return x;
    }
    int mid = (l+r)>>1;
    if(pos <= mid){ //更新左邊
        x->l = update(pre_version->l, l, mid, pos, v); //左邊節點連向新節點
        x->r = pre->version->r;                        //右邊連到原本的右邊
    }
    else{ //更新右邊
        x->l = pre->version->l;                         //左邊連到原本的左邊
        x->r = update(pre_version->r, r, mid, pos, v);  //右邊節點連向新節點
    }
    x->val = x->l->val + x->r->val;
    return x;
}
//並查集
void build(node* now, int left, int right) {
	if (left == right) {
		now->fa = left;
		now->sz = 1;
		return;
	}
	int mid = (left + right) / 2;
	now->cl = new node;
	now->cr = new node;
	build(now->cl, left, mid);
	build(now->cr, mid + 1, right);
}
node* update_fa(node* pre, int left, int right, int pos, int val) {
	node* x = new node;
	if (left == right) {
		x->fa = val;
		x->sz = 1;
		return x;
	}
	int mid = (left + right) >> 1;
	if (pos <= mid) {
		x->cl = update_fa(pre->cl, left, mid, pos, val);
		x->cr = pre->cr;
	}
	else {
		x->cl = pre->cl;
		x->cr = update_fa(pre->cr, mid + 1, right, pos, val);
	}
	return x;
}
void update_sz(node* now, int left, int right, int pos, int val) {
	if (left == right) {
		now->sz += val;
		return;
	}
	int mid = (left + right) >> 1;
	if (pos <= mid) update_sz(now->cl, left, mid, pos, val);
	else update_sz(now->cr, mid + 1, right, pos, val);
}
pair<int,int> query(node* now, int left, int right, int pos) {
	if (left == right) return { now->fa,now->sz};
	int mid = (left + right) >> 1;
	if (pos <= mid) return query(now->cl, left, mid, pos);
	else return query(now->cr, mid+1, right, pos);
}
pair<int, int> find_(node* now_version,int m,int x) {
	pair<int,int> tp = query(now_version, 1, m, x);
	if (x == tp.first) return tp;
	else return find_(now_version, m, tp.first);
}
void union_(node* now_version,int new_,int n,int x,int y) {
	pair<int, int> X = find_(now_version, n, x);
	pair<int, int> Y = find_(now_version, n, y);
	if (X.first != Y.first) {
		if (X.second < Y.second) {
			version[new_] = update_fa(now_version, 1, n, X.first, Y.first);
			update_sz(version[new_], 1, n, Y.first, X.second);
		}
		else {
			version[new_] = update_fa(now_version, 1, n, Y.first, X.first);
			update_sz(version[new_], 1, n, X.first, Y.second);
		}
	}else version[new_] = now_version;
	
}
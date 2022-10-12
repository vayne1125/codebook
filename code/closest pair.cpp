struct Node{
	long int x, y;
};
bool cmp_y(Node a,Node b){
	if (a.y != b.y)
		return a.y < b.y;
	else
		return a.x < b.x;
}
bool cmp_x(Node a, Node b) {
	if (a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;
}
void update_dis(Node a,Node b){
	mindis = min(mindis, sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}
vector<Node> node;
void closest(int l,int r) {
	if (r-l <= 3) {//點少暴力拆解
		for (int i = l; i < r; i++) {
			for (int j = i + 1; j < r ; j++) {
				update_dis(node[i], node[j]);
			}
		}
		return;
	}
	//點不少就拆2邊(分,治)
	int mid = (l + r) >> 1, midx = node[mid].x;
	closest(l,mid); closest(mid,r);
	//合
	vector<Node> all;
	int k = mid;
	while (midx - node[k].x < mindis) {
		all.push_back(node[k]);
		k--;
		if (k < l)break;
	}
	k = mid + 1;
	while (node[k].x - midx < mindis) {
		all.push_back(node[k]);
		k++;
		if (k >= r)break;
	}
	sort(all.begin(), all.end(), cmp_y);
	for (int i = 0; i < all.size(); i++) {
		for (int j = i+1; j < all.size(); j++) {
			if (all[j].y - all[i].y > mindis)break;
			if ((all[i].x >= node[mid].x && all[j].x <= node[mid].x) || (all[j].x >= node[mid].x && all[i].x <= node[mid].x)) {
				update_dis(all[i], all[j]);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	node.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> node[i].x >> node[i].y;
	}
	sort(node.begin(), node.end(), cmp_x);
	closest(0,n);
	cout << fixed << setprecision(4) << mindis << "\n";
}
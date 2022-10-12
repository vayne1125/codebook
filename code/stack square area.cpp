#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int c, n, m, min_area, head, tail, mid, f, area;
bool check;
unordered_map<int, int>done;
vector<vector<int>>G, h;
vector<int>element;
vector<pair<int, int>>Stack;
pair<long long, long long>ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c;
	while (c--) {
		h.clear();
		G.clear();
		element.clear();
		cin >> n >> m >> min_area;
		G.resize(n);
		done.clear();
		for (int i = 0; i < n; i++) {
			G[i].resize(m);
			for (int j = 0; j < m; j++) {
				cin >> G[i][j];
				element.push_back(G[i][j]);
			}
		}
		sort(element.begin(), element.end());
		ans.first = *element.begin() - 1;
		head = mid = 0;
		tail = element.size();
		while (mid!=((head+tail)>>1)||!done.count(element[mid])) {
			mid = (head + tail) >> 1;
			if (!done.count(element[mid])) {
				area = 0;
				h.clear();
				h.resize(n);
				for (int i = 0; i < n; i++) {
					h[i].resize(m);
					for (int j = 0; j < m; j++) {
						h[i][j] = (G[i][j] >= element[mid] ? 1 : 0);
						if (i != 0 && h[i][j] != 0) h[i][j] += h[i - 1][j];
					}
				}
				for (int i = 0; i < n; i++) {
					Stack.clear();
					for (int j = 0; j < m; j++) {
						f = j;
						while (!Stack.empty() && h[i][j] < Stack.back().second) {
							area = max(area, (j - Stack.back().first)*Stack.back().second);
							f = Stack.back().first;
							Stack.pop_back();
						}
						if (h[i][j] != 0 && (Stack.empty() || h[i][j] != Stack.back().second))Stack.push_back(make_pair(f, h[i][j]));
					}
					while (!Stack.empty()) {
						area = max(area, (m - Stack.back().first)*Stack.back().second);
						Stack.pop_back();
					}
				}
			}
			if (done.count(element[mid])) area = done[element[mid]];
			if (area < min_area) tail = mid;
			else {
				done[element[mid]] = area;
				ans.first = element[mid];
				ans.second = area;
				head = mid;
			}
		}
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}
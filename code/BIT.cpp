void update(int x){
	for (;x < MXN;x+= lowbit(x)) {
		BIT[x] += 1;
	}
}
ll query(int x){
	ll ans = 0;
	for (;x > 0; x -= lowbit(x)) {
		ans += BIT[x];
	}
	return ans;
}
map<ll, int> v_idx;		//點對應的idx(離散化)
for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		v_idx[arr[i]] = 1;		//建點
		v_idx[k * arr[i]] = 1;
	}
	map<ll, int>::iterator iter;
	int idx = 0;
	for (iter = v_idx.begin(); iter != v_idx.end(); iter++)	//儲存idx
		iter->second = ++idx;
	for (int i = 1; i <= n; i ++)
	{
		ans += query(idx) - query(v_idx[k*arr[i]]);//所有已加進去的-符合條件的=不符合的
		//或ans += i-1 - query(v_idx[k*arr[i]]);
		update(v_idx[arr[i]]);
	}